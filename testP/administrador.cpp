#include "administrador.h"
Administrador::Administrador(){
    this->i=0;
    this->linea=0;
    this->columna = 1;
    this->cont = 0;
    this->aux = cont;
    this->line="";
}
void Administrador::getData(int inicio, int fin){
    std::ifstream file(ruta);
    while(std::getline(file,line)){
        if(inicio<=i && i<=fin){
            musica track;
            std::stringstream lineStream(line);
            std::string cell;
            linea++;
            while(std::getline(lineStream,cell, ',')) {
                if (linea == 1) {
                    linea++;
                    break;
                }else if (cont != 0) {
                    cont++;
                    if (cell.find("/'}]") != cell.npos) {
                        cont--;
                        aux = cont;
                        cont = 0;
                    }
                }
                else if (columna == 6) {
                    track.artist_name = cell;
                }
                else if (columna == 23){
                    track.track_duration = cell;
                }
                else if (columna == 28){
                    cont++;
                }
                else if (columna == 38 + aux){
                    track.track_title = cell;
                }
                else if (columna == 40 + aux){
                    break;
                }columna++;
            }if(track.track_title != "" && track.artist_name != "" && track.track_duration != ""){
                tracks.push_back(track);
                //std::cout << "Titulo: " + track.track_title + "; Name: " + track.artist_name + "; Duration: " + track.track_duration << std::endl;
            }
            columna = 1;
            if (linea == 650) {
                std::cout << tracks.size() << std::endl;
                //std::cout << tracks[90].track_duration << std::endl;
                break;
            }
        }i++;
    }
}
void Administrador::resetData(int limite){
    this->i=0;
    this->linea=0;
    this->columna=1;
    this->cont=0;
    this->aux=cont;
    for(int j=0;j<limite;j++){
        tracks[j].deleteClass();
    }tracks.clear();
}
void Administrador::doMath(int pivote,int modo){
    resetData(modo);
    this->pivote=pivote;
    this->inicio=(this->pivote-1)*10;
    this->limite=(this->pivote+2)*10;
    getData(this->inicio,this->limite);
}
void Administrador::modoLibre(){
    resetData(30);
    getData2();
}
void Administrador::getData2(){
    std::ifstream file(ruta);
    while(std::getline(file,line)) {
            musica track;
            std::stringstream lineStream(line);
            std::string cell;
            linea++;
            while(std::getline(lineStream,cell, ',')) {
                if (linea == 1) {
                    linea++;
                    break;
                }
                else if (cont != 0) {
                    cont++;
                    if (cell.find("/'}]") != cell.npos) {
                        cont--;
                        aux = cont;
                        cont = 0;
                    }
                }
                else if (columna == 6) {
                    track.artist_name = cell;
                }
                else if (columna == 23){
                    track.track_duration = cell;
                }
                else if (columna == 28){
                    cont++;
                }
                else if (columna == 38 + aux){
                    track.track_title = cell;
                }
                else if (columna == 40 + aux){
                    break;
                }
                columna++;
            }
            if(track.track_title != "" && track.artist_name != "" && track.track_duration != ""){
                tracks.push_back(track);
                //std::cout << "Titulo: " + track.track_title + "; Name: " + track.artist_name + "; Duration: " + track.track_duration << std::endl;
            }
            columna = 1;
            if (linea == 650) {
                std::cout << tracks.size() << std::endl;
                //std::cout << tracks[90].track_duration << std::endl;
                break;
            }
        }
}