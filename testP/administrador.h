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
    string track_duration;
    void deleteClass(){
        track_title.clear();
        artist_name.clear();
        track_duration.clear();
        //delete this;
    }
};
class Administrador{
private:
    int columna;
    int cont;
    int aux;
    string ruta="/home/aldo/Descargas/metadata/raw_tracks.csv";
    std::string line;
    int i;
    int linea;
public:
    int pivote;
    int inicio;
    int limite;
    vector<musica> tracks;
    Administrador();
    void doMath(int pivote, int modo);
    void getData2();
    void modoLibre();
    void getData(int inicio,int fin);
    void resetData(int limite);
};

#endif // ADMINISTRADOR_H
