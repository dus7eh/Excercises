/**
    @author Damian Ellwart
    @version 0.1 2016
    Purpose: Single linked list implementation using shared_ptr and atomics
             On the basis of Herb Sutter presentation
*/

#pragma once
#include <string>
#include <atomic>
#include <memory>
#include <iostream>
#include <vector>

template <typename T>
class LinkedList
{
public:

    class NodeRef;
    struct Node
    {
        std::shared_ptr<Node> m_next{ nullptr };
        T m_value;
    };

    class NodeRef
    {
        std::shared_ptr<Node> m_node;

    public:
        NodeRef(std::shared_ptr<Node> ptr) : m_node(ptr) {}
        T& operator*() { return m_node->m_value; }
        T* operator->() { return &m_node->m_value; }
    };

    LinkedList() {}
    ~LinkedList()
    {
        while (m_head->m_next)
        {
            m_head = m_head->m_next;
        }
    }

    void push_front(T value)
    {
        std::shared_ptr<Node> node = std::make_shared<Node>();
        node->m_value = value;

        auto head = std::atomic_load(&m_head);
        node->m_next = head;
        while (!std::atomic_compare_exchange_weak(&m_head, &head, node)) {}
    }

    void pop_front()
    {
        auto head = std::atomic_load(&m_head);

        while (!std::atomic_compare_exchange_weak(&m_head, &head, head->m_next)) {}
    }

    NodeRef find(T value)
    {
        ;
    }

    void print()
    {
        auto head = std::atomic_load(&m_head);
        while (head)
        {
            std::cout << head->m_value << std::endl;
            head = head->m_next;
        }
    }

    bool empty() const
    {
        auto head = std::atomic_load(&m_head);
        return head->m_next == nullptr;
    }

    size_t size() const
    {
        auto head = std::atomic_load(&m_head);
        size_t size = 0;
        while (head)
        {
            head = head->m_next;
            ++size;
        }

        return size;
    }

private:
    std::shared_ptr<Node> m_head{ nullptr };
};

