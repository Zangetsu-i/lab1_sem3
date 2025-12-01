#ifndef LOADINTOFILE_H
#define LOADINTOFILE_H
#include "labhead.h"
#include "allatd.h"
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