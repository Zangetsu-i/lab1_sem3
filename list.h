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
        if (h == nullptr)
            return;
        else
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
    }
    void addAft(Item aft, Item ad)
    {
        if (h == nullptr)
            return;
        else
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
        if (h == nullptr)
            return;
        else
        {
            if (h->key == d && h->next != nullptr)
            {
                link temp = h;
                h->next->prev = nullptr;
                h = h->next;
                delete temp;
                return;
            }
            link ha = h;
            while (ha != nullptr)
            {
                if (ha->key == d && ha->next != nullptr)
                {
                    link temp = ha;
                    ha->next->prev = ha->prev;
                    ha->prev->next = ha->next;
                    delete temp;
                    break;
                }
                else if (ha->next == nullptr && ha->key == d)
                {
                    link temp = ha;
                    ha->prev->next = ha->next;
                    delete temp;
                    break;
                }
                ha = ha->next;
            }
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
    void delBef(Item bef)
    {
        if (h == nullptr)
            return;
        else
        {
            if (h->key == bef)
            {
                return;
            }
            link current = h;
            while (current != nullptr)
            {
                if (current->next->key == bef)
                {
                    if (current->prev != nullptr)
                    {
                        current->prev->next = current->next;
                    }
                    else
                        h = current->next;
                    if (current->next != nullptr)
                        current->next->prev = current->prev;

                    delete current;
                    return;
                }
                current = current->next;
            }
        }
    }
    void delAft(Item aft)
    {
        if (h == nullptr)
            return;
        else
        {
            link ha = h;
            while (ha->next != nullptr)
            {
                if (ha->key == aft)
                {
                    if (ha->next->next != nullptr)
                    {
                        link temp = ha->next;
                        ha->next = ha->next->next;
                        ha->next->next->prev = ha;
                        delete temp;
                        return;
                    }
                }
                ha = ha->next;
            }
        }
    }
    void delSta()
    {

    }
    void delEnd()
    {

    }
}
#endif