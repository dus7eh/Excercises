/**
    @author Damian Ellwart
    @version 0.1 2016
    Purpose: Various containters and smart pointers test implementation
*/

#pragma once

#include <vector>
#include <memory>
#include <string>

struct Entity
{
    Entity(const std::string& name) :name{ name } {}
    std::string name;
};


class SmartPointerCollection
{
public:
    SmartPointerCollection()
    {
        using std::vector;
        using std::unique_ptr;
        using std::shared_ptr;

        vector<unique_ptr<Entity>> list;
        list.emplace_back(std::move(std::make_unique<Entity>("a")));
        list.emplace_back(std::make_unique<Entity>("b"));

        list.push_back(std::make_unique<Entity>("c"));

        auto local = std::make_unique<Entity>("d");
        list.push_back(std::move(local));
    }

    void processLocalSmartPointer()
    {
        std::shared_ptr<int> sp_local1 = std::make_shared<int>(3);
        processPointerDestroy(sp_local1.get());

        int val = 10;
        std::shared_ptr<int> sp_local2 = std::make_shared<int>(3);
        processPointerReset(sp_local2.get(), &val);
    }

private:

    void processPointerDestroy(int* ptr)
    {
        //delete ptr; // causes crash
        ptr = new int;
        *ptr = 8;
    }

    void processPointerReset(int* ptr, int* val)
    {
        ptr = val;
    }
};