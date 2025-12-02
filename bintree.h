#ifndef BINTREE_H
#define BINTREE_H
#include "labhead.h"
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
    void printToFileStraight(std::ofstream& fout, link t = h)
    {
        if (t == nullptr) 
        {
            // fout << "NULL" << " ";
            return;
        }
        fout << t->key << " ";
        printToFileList(fout, t->left);
        printToFileList(fout, t->right);
    }
    void printToFileCross(std::ofstream& fout, link t = h)
    {
        if (t == nullptr) 
        {
            // fout << "NULL" << " ";
            return;
        }
        printToFileList(fout, t->left);
        fout << t->key << " ";
        printToFileList(fout, t->right);
    }
    void printToFileReverse(std::ofstream& fout, link t = h)
    {
        if (t == nullptr) 
        {
            // fout << "NULL" << " ";
            return;
        }
        printToFileList(fout, t->left);
        printToFileList(fout, t->right);
        fout << t->key << " ";
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
#endif