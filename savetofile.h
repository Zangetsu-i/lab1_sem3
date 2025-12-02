#ifndef SAVETOFILE_H
#define SAVETOFILE_H
#include "labhead.h"
#include "allatd.h"
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
    fout << "=== TREE OUTPUT ===" << std::endl;
    fout << "Straight: ";
    Tree::printToFileStraight(fout);
    fout << std::endl;
    fout << "Cross: ";
    Tree::printToFileCross(fout);
    fout << std::endl;
    fout << "Reverse: ";
    Tree::printToFileReverse(fout);
    fout << std::endl;
    
    fout.close();
    std::cout << "Data saved to " << filename << std::endl;
}
#endif