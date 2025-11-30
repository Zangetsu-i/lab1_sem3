#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "labhead.h"
std::string current_filename;
struct Config
{
    std::string request[4];
};
int main(int argc, char *argv[])
{
    std::string operation;
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        if (arg == "--file")
        {
            current_filename = argv[++i];
        }
        else if (arg == "--query")
        {
            operation = argv[++i];
        }
    }
    Config req;
    char ch = operation[0];
    for (int i = 1, j = 0; i < operation.size(); i++)
    {
        if (operation[i] == ' ')
        {
            j++;
            continue;
        }
        req.request[j] += operation[i];
    }

    std::cout << "File: " << current_filename << " Command: " << req.request[0] << std::endl;
    loadFromFile(current_filename);
    
    switch (ch)
    {
        case 'S':
        {
            if (req.request[0] == "PUSH")
                Stack::push(stoi(req.request[2]));
            else if (req.request[0] == "POP")
                Stack::pop();
            else if (req.request[0] == "GET")
                Stack::search(stoi(req.request[2]));
            else if (req.request[0] == "PRINT")
                Stack::printS();
        }
        break;
        case 'F':
        {
            if (req.request[0] == "PUSH")
                Flist::addSta(stoi(req.request[2]));
            else if (req.request[0] == "DEL")
                Flist::del(stoi(req.request[2]));
            else if (req.request[0] == "GET")
                Flist::search(stoi(req.request[2]));
            else if(req.request[0] == "PUSHEND")
                Flist::addEnd(stoi(req.request[2]));
            else if(req.request[0] == "PUSHAFTER")
                Flist::addAft(stoi(req.request[3]), stoi(req.request[2]));
            else if(req.request[0] == "PUSHBEFORE")
                Flist::addBef(stoi(req.request[3]), stoi(req.request[2]));
            else if(req.request[0] == "DELBEFORE")
                Flist::delBef(stoi(req.request[3]), stoi(req.request[2]));
            else if(req.request[0] == "PRINT")
                Flist::printList();
        }
        break;
        case 'L':
        {
            if (req.request[0] == "PUSH")
                List::addSta(stoi(req.request[2]));
            else if (req.request[0] == "DEL")
                List::del(stoi(req.request[2]));
            else if (req.request[0] == "GET")
                List::search(stoi(req.request[2]));
            else if(req.request[0] == "PUSHEND")
                List::addEnd(stoi(req.request[2]));
            else if(req.request[0] == "PUSHAFTER")
                List::addAft(stoi(req.request[3]), stoi(req.request[2]));
            else if(req.request[0] == "PUSHBEFORE")
                List::addBef(stoi(req.request[3]), stoi(req.request[2]));
            else if(req.request[0] == "PRINT")
                List::printList();
        }
        break;
        case 'Q':
        {
            if (req.request[0] == "PUSH")
                Queue::put(stoi(req.request[2]));
            else if (req.request[0] == "POP")
                Queue::get();
            else if (req.request[0] == "GET")
                Queue::search(stoi(req.request[2]));
            else if (req.request[0] == "PRINT")
                Queue::printQ();
        }
        break;
        case 'M':
        {
            if (req.request[0] == "CREATE")
                Massive::create(stoi(req.request[2]));
            else if (req.request[0] == "ADD")
                Massive::addtoend(stoi(req.request[2]));
            else if (req.request[0] == "ADDINDEX")
                Massive::addtoind(stoi(req.request[2]), stoi(req.request[3]));
            else if (req.request[0] == "DEL")
                Massive::delInd(stoi(req.request[2]));
            else if (req.request[0] == "LENGTH")
                Massive::length();
            else if (req.request[0] == "REPLACE")
                Massive::replace(stoi(req.request[2]), stoi(req.request[3]));
            else if (req.request[0] == "PRINT")
                Massive::printArr();
        }
        break;
        case 'T':
        {
            if (req.request[0] == "INSERT")
                Tree::insert(stoi(req.request[2]));
            else if (req.request[0] == "DEL")
                Tree::remove(stoi(req.request[2]));
            else if (req.request[0] == "SEARCH")
                Tree::search(stoi(req.request[2]));
            else if (req.request[0] == "PRINT")
            {
                Tree::printTree();
                std::cout << std::endl;
            }
        }
        break;
        default:
            std::cout << "Unknown command: " << req.request[0] << std::endl;
            break;
    }
    saveFile(current_filename);
}
