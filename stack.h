#ifndef STACK_H
#define STACK_H
#include "labhead.h"
namespace Stack
{
    struct node
    {
        Item key;
        node *next;
        node(Item k, node *n){key = k; next = n;}
    };
    typedef node *link;
    link stack = nullptr;

    void push(Item item)
    {
        if (stack == nullptr)
            stack = new node(item, nullptr);
        else
        {
            link t = new node(item, nullptr);
            t->next = stack;
            stack = t;
        }
    }
    Item pop()
    {
        if (stack != nullptr)
        {
            Item temp = stack->key;
            link t = stack->next;
            delete stack;
            stack = t;
            return temp;
        }
        else 
            return Item();
    }
    bool search(Item s)
    {
        if (stack == nullptr)
            return false;
        link temp = stack;
        while (temp != nullptr)
        {
            if (temp->key == s)
                return true;
            temp = temp->next;
        }
        return false;
    }
    void printS()
    {
        link t = stack;
        while (t != nullptr)
        {
            std::cout << t->key << " ";
            t = t->next;
        }
        std::cout << std::endl;
    }
}
#endif