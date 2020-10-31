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
<<<<<<< HEAD
    //string track_duration;
    string genero;
    void deleteClass(){
        track_title.clear();
        artist_name.clear();
        //track_duration.clear();
        genero.clear();
=======
    string track_duration;
    void deleteClass(){
        track_title.clear();
        artist_name.clear();
        track_duration.clear();
        //delete this;
>>>>>>> 06db51a059ca40faf93c99259cf11271b741f1eb
    }
};
class Administrador{
private:
<<<<<<< HEAD
    int cont;
    int aux;
    string ruta="/home/aldo/Descargas/metadata/raw_track.csv";
    std::string line;
    int i;
    int linea;

    int j;
public:
    void filtrado();

=======
    int columna;
    int cont;
    int aux;
    string ruta="/home/aldo/Descargas/metadata/raw_tracks.csv";
    std::string line;
    int i;
    int linea;
public:
>>>>>>> 06db51a059ca40faf93c99259cf11271b741f1eb
    int pivote;
    int inicio;
    int limite;
    vector<musica> tracks;
<<<<<<< HEAD

    Administrador();
    void getStrings(int inicio,int limite);
    void doMath(int pivote, int modo);
    void resetData(int limite);
    void casoEspecial(int inicio,int limite);

    void getData2();
    void modoLibre();
    void getData(int inicio,int fin);
=======
    Administrador();
    void doMath(int pivote, int modo);
    void getData2();
    void modoLibre();
    void getData(int inicio,int fin);
    void resetData(int limite);
>>>>>>> 06db51a059ca40faf93c99259cf11271b741f1eb
};

#endif // ADMINISTRADOR_H
