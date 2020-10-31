#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <QString>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <QDebug>
using namespace std;

struct musica{
    string track_title;
    string artist_name;
    //string track_duration;
    string genero;
    void deleteClass(){
        track_title.clear();
        artist_name.clear();
        //track_duration.clear();
        genero.clear();
    }
};
class Administrador{
private:
    int cont;
    int aux;
    string ruta="/home/aldo/Descargas/metadata/raw_track.csv";
    std::string line;
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
    void casoEspecial(int inicio,int limite);

    void getData2();
    void modoLibre();
    void getData(int inicio,int fin);
};

#endif // ADMINISTRADOR_H
