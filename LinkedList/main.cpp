/**
    @author Damian Ellwart
    @version 0.1 2016
    Purpose: Multithreaded tests for the linked list implementation
*/

#include "LinkedList.h"
#include <thread>

const size_t iterationCount = 100000;

template <typename T>
void addEntries(std::shared_ptr<LinkedList<T>> list)
{
    for (int i = 0; i < iterationCount; ++i)
    {
        list->push_front(i);
    }
}

template <typename T>
void removeEntries(std::shared_ptr<LinkedList<T>> list)
{
    for (int i = 0; i < iterationCount; ++i)
    {
        if (!list->empty())
            list->pop_front();
    }
}

int main()
{
    auto list = std::make_shared<LinkedList<int>>();
    list->push_front(40);
    list->push_front(60);
    list->push_front(80);
    list->print();
    list->pop_front();
    std::cout << std::endl;
    list->print();
    list->pop_front();
    std::cout << std::endl;
    list->print();

    std::thread addThread{ addEntries<int>, list };
    std::thread removeThread{ removeEntries<int>, list };
    addThread.join();
    removeThread.join();
    
    std::cout << "Not deleted elements: " << list->size() << "/" << iterationCount << std::endl;

    return 0;
}