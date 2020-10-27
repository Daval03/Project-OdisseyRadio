#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <nodo.h>
class LinkedList{
public:
    LinkedList();
    void addData(string data);
    string getData(int i);
private:
    Nodo *First;
    Nodo *Last;
    int cont;
};
#endif // LINKEDLIST_H
