#include <iostream>
#include <string>
using namespace std;
#include <stdio.h>
//int main(){
//    int arr[] = {10, 20, 30, 40, 50, 60};
//    int *ptr1 = arr;
//    int *ptr2 = arr + 5;
//    //printf("Number of elements between two pointer are: %d.",(ptr2 - ptr1));
//    //printf("Number of bytes between two pointers are: %d",(char*)ptr2 - (char*) ptr1);//5*sizeof(int)/sizeof(char)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    char *ptr = "GeeksQuiz";
//    cout<<*(ptr+3);
//}
void swap(int *px, int *py){
    *px = *px - *py;
    *py = *px + *py;
    *px = *py - *px;
}
int f(int x, int *py, int **ppz){
    int y, z;
    **ppz += 1;//**pz=5
    z = **ppz;//z=5 *py=5
    *py += 2;//*py=7
    y = *py;//y=7
    x += 3;//x=7
    return x + y + z;//5+6+7
}
int main(){
    int c, *b, **a;
    c = 4;
    b = &c;//*b=4
    a = &b;//**a=4
    //cout<<**a;
    printf("%d ", f(c, b, a));
    return 0;
}