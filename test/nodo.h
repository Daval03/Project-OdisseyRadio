#ifndef NODO_H
#define NODO_H
#include <string>
using namespace std;
class Nodo{
public:
    Nodo();
    void setData(string data);
    Nodo *nextNodo;
    string data;
};

#endif // NODO_H
