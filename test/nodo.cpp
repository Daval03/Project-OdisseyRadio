#include "nodo.h"

Nodo::Nodo(){
    this->nextNodo=nullptr;
}
void Nodo::setData(string data){
    this->data=data;
}
