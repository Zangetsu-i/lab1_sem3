#ifndef ARRAY_H
#define ARRAY_H
#include "labhead.h"
namespace Massive
{
    struct massive
    {
        Item *ar;
        int index;
        int length;
    };
    massive m;

    void create(int len)
    {
        m.ar = new Item[len];
        m.length = len;
        m.index = 0;
        for (int i = 0; i < len; i++)
            m.ar[i] = 0;

    }
    void addtoind(int inde, int value)
    {
        if (inde < m.length && inde >= 0)
        {
            m.ar[inde] = value;
            m.index = inde;
        }
        else
            std::cout << "Index biger index!" << std::endl;
    }

    void addtoend(int value)
    {
        if (m.index >= m.length)
            std::cout << "Massive full" << std::endl;
        else if (m.ar[m.index] == 0)
            m.ar[m.index++] = value;
        else
            m.ar[++m.index] = value;
    }

    void delInd(int inde)
    {
        if (inde > m.length || inde < 0)
        {
            std::cout << "Index failure." << std::endl;
            return;
        }

        if (m.ar[inde] != 0)
        {
            int i;
            for (i = inde; i < m.length - 1; i++)
            {
                m.ar[i] = m.ar[++inde];
            }
            m.ar[i] = 0;
        }
        else
            std::cout << "This index is already empty." << std::endl;
    }
    void replace(int index, int value)
    {
        if (index > 0 && index < m.length)
            m.ar[index] = value;
        else
            std::cout << "Invalid index!" << std::endl;
    }
    int length()
    {
        std::cout << m.length << std::endl;
        return m.length;
    }
    void printArr()
    {
        for (int i = 0; i < m.length; i++)
            std::cout << m.ar[i] << " ";
        std::cout << std::endl;
    }
}
#endif