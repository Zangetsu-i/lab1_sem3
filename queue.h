#ifndef QUEUE_H
#define QUEUE_H
#include "labhead.h"
namespace Queue
{
    struct node
    {
        Item key;
        node *next;
        node(Item k, node *n){key = k; next = n;}
    };
    typedef node *link;
    link head = nullptr;
    link tail = nullptr;

    void put(Item item)
    {
        if (head == nullptr)
        {
            head = new node(item, nullptr);
            tail = head;
        }
        else
            tail = (tail->next = new node(item, nullptr));
    }
    Item get()
    {
        if (head == tail)
        {
            Item t = head->key;
            delete head;
            head = tail = nullptr;
            return t;
        }
        else if (head != nullptr)
        {
            Item t = head->key;
            link temp = head->next;
            delete head;
            head = temp;
            return t;
        }
        else
            return Item();
    }
    bool search(Item s)
    {
        if (head == nullptr)
            return false;
        link temp = head;
        while (temp != nullptr)
        {
            if (temp->key == s)
                return true;
            temp = temp->next;
        }
        return false;
    }
    void printQ()
    {
        link t = head;
        while (t != nullptr)
        {
            std::cout << t->key << " ";
            t = t->next;
        }
        std::cout << std::endl;
    }
}
#endif