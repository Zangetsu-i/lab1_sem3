#ifndef LIST_H
#define LIST_H
#include "labhead.h"
namespace List
{
    struct node
    {
        node *prev;
        Item key;
        node *next;
        node(node *p, Item k, node *n){key = k; prev = p; next = n;}
    };
    typedef node *link;
    link h = nullptr;

    void addBef(Item bef, Item ad)
    {
        link current = h;
        while (current != nullptr)
        {
            if (current->key == bef)
            {
                link t = new node(nullptr, ad, nullptr);
                t->next = current;
                t->prev = current->prev;

                if (current->prev != nullptr)
                    current->prev->next = t;
                else
                    h = t;
                current->prev = t;

                break;
            }
            current = current->next;
        }
    }
    void addAft(Item aft, Item ad)
    {
        link ha = h;
        while (ha != nullptr)
        {
            if (ha->key == aft)
            {
                link t = new node(nullptr, ad, nullptr);
                t->next = ha->next;
                ha->next->prev = t;
                ha->next = t;
                t->prev = ha;
                break;
            }
            ha = ha->next;
        }
    }
    void addSta(Item nw)
    {
        if (h == nullptr)
            h = new node(nullptr, nw, nullptr);
        else
        {
            link t = new node(nullptr, nw, nullptr);
            t->next = h;
            h->prev = t;
            h = t;
        }
    }
    void addEnd(Item nw)
    {
        link ha = h;
        if (h == nullptr)
            h = new node(nullptr, nw, nullptr);
        else
        {
            link t = new node(nullptr, nw, nullptr);
            while (ha->next != nullptr)
                ha = ha->next;
            ha->next = t;
            t->prev = ha;
            ha = t;
        }
    }
    void printList(link def = h)
    {
        link ha = def;
        // while (h->prev != nullptr)
        //     h = h->prev;

        while (ha != nullptr)
        {
            std::cout << ha->key << " ";
            ha = ha->next;
        }
        std::cout << std::endl;
    }
    void del(Item d)
    {
        link ha = h;
        while (ha != nullptr)
        {
            if (ha->key == d)
            {
                link temp = ha;
                ha->next->prev = ha->prev;
                ha->prev->next = ha->next;
                delete temp;
                break;
            }
            ha = ha->next;
        }
    }
    bool search(Item s)
    {
        link ha = h;
        while (ha != nullptr)
        {
            if (ha->key == s)
                return true;
            ha = ha->next;
        }
        return false;
    }
}
#endif