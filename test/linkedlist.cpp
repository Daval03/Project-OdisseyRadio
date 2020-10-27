#include "linkedlist.h"

LinkedList::LinkedList(){
    this->First=nullptr;
    this->Last=nullptr;
    this->cont=0;
}
void LinkedList::addData(string data){
    Nodo *temp;
    temp->setData(data);
    if(this->First==nullptr){
        this->First=temp;
        this->Last=temp;
    }
    this->Last->nextNodo=temp;
    this->Last=temp;
    cont++;
}
string LinkedList::getData(int i){
    Nodo *temp=First;
    for(int j=0;i<cont;i++){
        if(j==i){
            return temp->data;
        }temp=temp->nextNodo;
    }return "";
}
