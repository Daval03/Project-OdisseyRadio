#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <QString>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <QDebug>
#include <iostream>
using namespace std;

struct musica{
    string track_title;
    string artist_name;
    string ruta_cancion;
    string genero;
    void deleteClass(){
        track_title.clear();
        artist_name.clear();
        ruta_cancion.clear();
        genero.clear();
    }
};
class Administrador{
private:
    int cont;
    int aux;
    string line;
    int i;
    int linea;

    int j;
public:
    void filtrado();

    int pivote;
    int inicio;
    int limite;
    vector<musica> tracks;

    Administrador();
    void getStrings(int inicio,int limite);
    void doMath(int pivote, int modo);
    void resetData(int limite);
    void read_directory(int inicio,int limite);

    void getData2();
    void modoLibre();
    void getData(int inicio,int fin);
};

#endif // ADMINISTRADOR_H
