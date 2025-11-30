#ifndef LABHEAD_H
#define LABHEAD_H
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
typedef int Item;
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
namespace Flist
{
    struct node
    {
        Item key;
        node *next;
        node(Item k, node *n){key = k; next = n;}
    };
    typedef node *link;
    link h = nullptr;

    void addBef(Item bef, Item ad)
    {
        if (h == nullptr)
            return;
        else
        {
            if (h->key == bef)
            {
                link a = new node(ad, nullptr);
                a->next = h;
                h = a;
                return;
            }
            link t = h;
            while (t->next != nullptr)
            {
                if (t->next->key == bef)
                {
                    link a = new node(ad, nullptr);
                    a->next = t->next;
                    t->next = a;
                    break;
                }
                t = t->next;
            }
        }
    }
    void addAft(Item aft, Item ad)
    {
        if (h == nullptr)
            return;
        else
        {
            link t = h;
            while (t != nullptr)
            {
                if (t->key == aft)
                {
                    link a = new node(ad, nullptr);
                    a->next = t->next;
                    t->next = a;
                    break;
                }
                t = t->next;
            }
        }
    }
    void addSta(Item nw)
    {
        if (h == nullptr)
            h = new node(nw, nullptr);
        else
        {
            link t = new node(nw, nullptr);
            t->next = h;
            h = t;
        }
    }
    void addEnd(Item nw)
    {
        if (h == nullptr)
            h = new node(nw, nullptr);
        else
        {
            link t = h;
            while (t->next != nullptr)
                t = t->next;
            link temp = new node(nw, nullptr);
            t->next = temp;
        }
    }
    void printList(link ha = h)
    {
        if (ha == nullptr)
            return;
        link t = ha;
        while (t != nullptr)
        {
            std::cout << t->key << " ";
            t = t->next;
        }
        std::cout << std::endl;
    }
    void del(Item d)
    {
        if (h == nullptr)
            return ;
        else
        {
            link t = h;
            while (t != nullptr)
            {
                if (t->next->key == d)
                {
                    link temp = t->next;
                    t->next = t->next->next;
                    delete temp;
                    break;
                }
                t = t->next;
            }
        }
    }
    void delBef(Item bef, Item ad)
    {
        if (h == nullptr)
            return;
        else
        {
            if (h->key == bef)
            {
                return;
            }
            link t = h;
            while (t->next != nullptr)
            {
                if (t->next->key == bef)
                {
                    link temp = t;
                    t = t->next;
                    delete temp;
                    break;
                }
                t = t->next;
            }
        }
    }
    void delAft(Item aft, Item ad)
    {
        if (h == nullptr)
            return;
        else
        {
            link t = h;
            while (t != nullptr)
            {
                if (t->key == aft && t->next->next != nullptr)
                {
                    link temp = t->next;
                    t = t->next->next;
                    delete temp;
                    break;
                }
                t = t->next;
            }
        }
    }
    void delSta(Item del)
    {
        if (h == nullptr)
            return;
        else
        {
            link temp = h->next;
            delete h;
            h = temp;
        }
    }
    void delEnd(Item del)
    {
        if (h == nullptr)
            return;
        else
        {
            link t = h;
            while (t->next->next != nullptr)
                t = t->next;
            link temp = t->next;
            t->next = t->next->next;
        }
    }
    bool search(Item s)
    {
        if (h == nullptr)
            return 0;
        else
        {
            bool check = false;
            link t = h;
            while (t != nullptr)
            {
                if (t->key == s)
                {
                    check = true;
                    break;
                }
                t = t->next;
            }
            return check;
        }
    }

}
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
namespace Tree
{
    struct node
    {
        Item key;
        node *left;
        node *right;
        node(Item k){key = k; left = nullptr; right = nullptr;}
    };
    typedef node *link;
    link h = nullptr;

    void insert(Item item) 
    {
        if (h == nullptr) 
        {
            h = new node(item);
            return;
        }
        
        link current = h;
        link parent = nullptr;
        
        while (current != nullptr) 
        {
            parent = current;
            if (item < current->key) 
            {
                current = current->left;
            } 
            else if (item > current->key) 
            {
                current = current->right;
            } 
            else 
            {
                return;
            }
        }
        
        link newNode = new node(item);
        if (item < parent->key) 
        {
            parent->left = newNode;
        }
        else 
        {
            parent->right = newNode;
        }
    }

    link findMin(link node) 
    {
        while (node != nullptr && node->left != nullptr) 
        {
            node = node->left;
        }
        return node;
    }
    link deleteNode(link node, Item item) 
    {
        if (node == nullptr) return nullptr;
        
        if (item < node->key) 
        {
            node->left = deleteNode(node->left, item);
        }
        else if (item > node->key) 
        {
            node->right = deleteNode(node->right, item);
        }
        else 
        {            
            if (node->left == nullptr) 
            {
                link temp = node->right;
                delete node;
                return temp;
            } 
            else if (node->right == nullptr) 
            {
                link temp = node->left;
                delete node;
                return temp;
            }
            
            link temp = findMin(node->right);
            
            node->key = temp->key;
            
            node->right = deleteNode(node->right, temp->key);
        }
        return node;
    }

    void remove(Item item) 
    {
        h = deleteNode(h, item);
    }

    bool search(Item item) 
    {
        link current = h;
        while (current != nullptr) 
        {
            if (item == current->key) 
            {
                return true;
            } else if (item < current->key) 
            {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }

    void clearTree(link node) 
    {
        if (node == nullptr) return;
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }

    void clear() 
    {
        clearTree(h);
        h = nullptr;
    }

    void printTree(link t = h) 
    {
        if (t == nullptr) return;
        std::cout << t->key << " ";
        printTree(t->left);
        printTree(t->right);
    }

    void printToFileList(std::ofstream& fout, link t = h) 
    {
        if (t == nullptr) 
        {
            fout << "NULL" << " ";
            return;
        }
        fout << t->key << " ";
        printToFileList(fout, t->left);
        printToFileList(fout, t->right);
    }


    link loadFromPreorder(std::istringstream& iss) 
    {
        std::string token;
        iss >> token;
        
        if (token == "NULL" || token.empty()) 
        {
            return nullptr;
        }
        
        link nod = new node(stoi(token));
        nod->left = loadFromPreorder(iss);
        nod->right = loadFromPreorder(iss);
        
        return nod;
    }

    void loadFromString(const std::string& data) 
    {
        clear();
        if (data.empty()) return;
        
        std::istringstream iss(data);
        h = loadFromPreorder(iss);
    }
}
void saveFile(const std::string & filename)
{
    std::ofstream fout;
    fout.open(filename);
    if (!fout.is_open())
    {
        std::cerr << filename << " could not be opened --bye.\n";
        exit(EXIT_FAILURE);
    }

    fout << "=== MASSIVE ===" << std::endl;
    for (int i = 0; i < Massive::m.length; i++) {
        fout << Massive::m.ar[i] << " ";
    }
    fout << std::endl;
    
    fout << "=== STACK ===" << std::endl;
    Stack::link stack_temp = Stack::stack;
    while (stack_temp != nullptr) {
        fout << stack_temp->key << " ";
        stack_temp = stack_temp->next;
    }
    fout << std::endl;
    
    fout << "=== QUEUE ===" << std::endl;
    Queue::link queue_temp = Queue::head;
    while (queue_temp != nullptr) {
        fout << queue_temp->key << " ";
        queue_temp = queue_temp->next;
    }
    fout << std::endl;
    
    fout << "=== FLIST ===" << std::endl;
    Flist::link flist_temp = Flist::h;
    while (flist_temp != nullptr) {
        fout << flist_temp->key << " ";
        flist_temp = flist_temp->next;
    }
    fout << std::endl;
    
    fout << "=== LIST ===" << std::endl;
    List::link list_temp = List::h;
    while (list_temp != nullptr) {
        fout << list_temp->key << " ";
        list_temp = list_temp->next;
    }
    fout << std::endl;
    
    fout << "=== TREE ===" << std::endl;
    Tree::printToFileList(fout);
    fout << std::endl;
    
    fout.close();
    std::cout << "Data saved to " << filename << std::endl;
}
void loadFromFile(const std::string & filename) 
{
    std::ifstream fin(filename);
    if (!fin.is_open()) 
    {
        std::cerr << "INFO: Starting with empty structures" << std::endl;
        return;
    }
    
    std::string line;
    std::string current_section;
    
    while (std::getline(fin, line)) 
    {
        if (line.empty()) continue;
        
        if (line.find("=== MASSIVE ===") != std::string::npos) {
            current_section = "MASSIVE";
            continue;
        }
        else if (line.find("=== STACK ===") != std::string::npos) {
            current_section = "STACK";
            continue;
        }
        else if (line.find("=== QUEUE ===") != std::string::npos) {
            current_section = "QUEUE";
            continue;
        }
        else if (line.find("=== FLIST ===") != std::string::npos) {
            current_section = "FLIST";
            continue;
        }
        else if (line.find("=== LIST ===") != std::string::npos) {
            current_section = "LIST";
            continue;
        }
        else if (line.find("=== TREE ===") != std::string::npos) {
            current_section = "TREE";
            continue;
        }
        
        if (current_section == "MASSIVE") 
        {
            std::istringstream iss(line);
            int value;
            int temp[100];
            int cnt = 0;
            int ind = 0;

            while (iss >> value && cnt < 100)
                temp[cnt++] = value;

            Massive::create(cnt);

            for (int i = 0; i < cnt; i++)
            {
                Massive::m.ar[i] = temp[i];
                if (temp[i] != 0)
                    ind++;
            }
            Massive::m.length = cnt;
            Massive::m.index = ind;
        }

        else if (current_section == "STACK") 
        {
            std::istringstream iss(line);
            int value;
            int values[100];
            int count = 0;
            while (iss >> value && count < 100) 
            {
                values[count++] = value;
            }

            while (Stack::stack != nullptr) 
            {
                Stack::pop();
            }

            for (int i = count - 1; i >= 0; i--) 
            {
                Stack::push(values[i]);
            }
        }
        else if (current_section == "QUEUE") 
        {
            std::istringstream iss(line);
            int value;

            while (Queue::head != nullptr) 
            {
                Queue::get();
            }

            while (iss >> value) 
            {
                Queue::put(value);
            }
        }
        else if (current_section == "FLIST") 
        {
            std::istringstream iss(line);
            int value;

            Flist::link current = Flist::h;
            while (current != nullptr) 
            {
                Flist::link temp = current;
                current = current->next;
                delete temp;
            }
            Flist::h = nullptr;

            while (iss >> value) 
            {
                Flist::addEnd(value);
            }
        }
        else if (current_section == "LIST") 
        {
            std::istringstream iss(line);
            int value;

            List::link current = List::h;
            while (current != nullptr) 
            {
                List::link temp = current;
                current = current->next;
                delete temp;
            }
            List::h = nullptr;

            while (iss >> value) 
            {
                List::addEnd(value);
            }
        }
        else if (current_section == "TREE") 
        {
            if (!line.empty()) {
                Tree::loadFromString(line);
                std::cout << "Tree loaded from preorder: " << line << std::endl;
            }
        }
    }
    
    fin.close();
    std::cout << "Data loaded from " << filename << std::endl;
}
#endif