#include "administrador.h"
Administrador::Administrador(){
    this->i=1;
    this->linea=0;
    //this->columna = 1;
    this->cont = 0;
    this->aux = cont;
    this->line="";
    this->j=1;
}
void Administrador::getStrings(int inicio,int limite){
    std::ifstream file(ruta);
    while(std::getline(file,line)){
        if(inicio<j && j<=limite){
            QString answer= QString::fromStdString(line);
            QStringList list = answer.split(',', QString::SkipEmptyParts);
            musica track;
            if(list.size()>23){
                track.track_title=list.at(list.size()-2).toLocal8Bit().constData();
                track.artist_name=list.at(5).toLocal8Bit().constData();
            }else{
                track.track_title="Sin data";
                track.track_title="Sin data";
            }QStringList list2 = answer.split("genre_title",QString::SkipEmptyParts);
            if(list2.size()>1){
                QString aw2=list2.at(1).toLocal8Bit().constData();
                QStringList list3 = aw2.split(":",QString::SkipEmptyParts);
                QString aw3=list3.at(1).toLocal8Bit().constData();
                QStringList list4 = aw3.split(",",QString::SkipEmptyParts);
                track.genero=list4.at(0).toLocal8Bit().constData();
            }else{
                track.genero="No encontrado";
            }tracks.push_back(track);
        }j++;
    }
}
void Administrador::resetData(int modo){
    this->j=1;
    for(int j=0;j<modo;j++){
        tracks[j].deleteClass();
    }tracks.clear();
}
void Administrador::doMath(int pivote,int modo){
    resetData(modo);
    this->pivote=pivote;
    this->inicio=(this->pivote-1)*10;
    this->limite=(this->pivote+2)*10;
    getStrings(inicio,limite);
}
void Administrador::casoEspecial(int inicio, int limite){
    std::ifstream file(ruta);
    while(std::getline(file,line)){
        if(inicio<=j && j<=limite){
            QString answer= QString::fromStdString(line);
            QStringList list = answer.split(',', QString::SkipEmptyParts);
            musica track;
//            track.track_title=list.at(list.size()-2).toLocal8Bit().constData();
//            track.artist_name=list.at(5).toLocal8Bit().constData();

//            QStringList list2 = answer.split("genre_title",QString::SkipEmptyParts);

//            QString aw2=list2.at(1).toLocal8Bit().constData();
//            QStringList list3 = aw2.split(":",QString::SkipEmptyParts);

//            QString aw3=list3.at(1).toLocal8Bit().constData();
//            QStringList list4 = aw3.split(",",QString::SkipEmptyParts);

//            track.genero=list4.at(0).toLocal8Bit().constData();
//            tracks.push_back(track);

        }j++;
    }
}
void Administrador::getData(int inicio, int fin){
    std::ifstream file(ruta);
    while(std::getline(file,line)){
        if(inicio<i && i<=fin){
            musica track;
            std::stringstream lineStream(line);
            std::string cell;
            linea++;
            int columna=1;
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
                }else if (columna == 6) {
                    track.artist_name = cell;
                }else if (columna == 23){
                    //track.track_duration = cell;
                }else if (columna == 28){
                    cont++;
                }else if (columna == 38 + aux){
                    track.track_title = cell;
                }else if (columna == 40 + aux){
                    break;
                }columna++;
            }tracks.push_back(track);
//            if(track.track_title != "" && track.artist_name != "" && track.track_duration != ""){
//                tracks.push_back(track);
//                //std::cout << "Titulo: " + track.track_title + "; Name: " + track.artist_name + "; Duration: " + track.track_duration << std::endl;
//            }
        }i++;
    }
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
            int columna=1;
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
                   // track.track_duration = cell;
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
//            if(track.track_title != "" && track.artist_name != "" && track.track_duration != ""){
//                tracks.push_back(track);
//                std::cout << "Titulo: " + track.track_title + "; Name: " + track.artist_name + "; Duration: " + track.track_duration << std::endl;
//            }
            //columna = 1;
            if (linea == 650) {
                //std::cout << tracks.size() << std::endl;
                //std::cout << tracks[90].track_duration << std::endl;
                break;
            }
        }
}
