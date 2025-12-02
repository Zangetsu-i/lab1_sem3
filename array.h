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
        Item * arr = new Item[len];
        if (m.index > 0)
        {
            for (int i = 0; i < m.length; i++)
                arr[i] = m.ar[i];
            m.ar = arr;
            m.length = len;
        }
        else
        {
            m.ar = arr;
            m.length = len;
            m.index = 0;
            for (int i = 0; i < len; i++)
                m.ar[i] = 0;
        }
    }
    void addtoind(int inde, int value)
    {
        if (inde <= m.length && inde <= m.index)
        {
            if (inde == m.length)
                create(m.length * 2);
            
            m.index++;

            if (m.ar[inde] == 0)
                m.ar[inde] = value;
            else if (m.index >= m.length)
            {
                create(m.length * 2);
                Item temp = m.ar[inde];
                for (int i = inde + 1; i < m.length - 1; i++)
                {
                    Item temp1 = m.ar[i];
                    m.ar[i] = temp;
                    temp = temp1;
                }
                m.ar[inde] = value;
            }
            else 
            {
                Item temp = m.ar[inde];
                for (int i = inde + 1; i < m.length - 1; i++)
                {
                    Item temp1 = m.ar[i];
                    m.ar[i] = temp;
                    temp = temp1;
                }
                m.ar[inde] = value;
            }
        }
    }

    void addtoend(int value)
    {
        if (m.index >= m.length)
            create(m.length * 2);
        
        if (m.index <= m.length)
        {
            if (m.ar[m.index] == 0)
                m.ar[m.index++] = value;
            else
                m.ar[++m.index] = value;
        }
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