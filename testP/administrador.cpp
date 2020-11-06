#include "administrador.h"
Administrador::Administrador(){
    this->line="";
    this->j=1;
}
void Administrador::getStrings(int inicio,int limite){
    std::ifstream file("/home/aldo/Descargas/metadata/raw_track.csv");
    while(std::getline(file,line)){
        if(inicio<j && j<=limite){
            QString answer= QString::fromStdString(line);
            QStringList list = answer.split(",", QString::SkipEmptyParts);
            int largo=list.size();

            musica track;
            track.idioma="en";
            track.track_interest=list.at(largo-6).toLocal8Bit().constData();
            track.album_name=list.at(2).toLocal8Bit().constData();
            if(largo>23){
                track.track_title=list.at(largo-2).toLocal8Bit().constData();
                track.artist_name=list.at(5).toLocal8Bit().constData();
            }else{
                track.track_title="Sin data";
                track.track_title="Sin data";
            }
            QStringList list2 = answer.split("genre_title",QString::SkipEmptyParts);
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
    read_directory(inicio,limite);
}
void Administrador::read_directory(int inicio,int limite){
    DIR* dirp = opendir("/home/aldo/Escritorio/Canciones");
    struct dirent * dp;
    int i=0;
    int h=0;
    while ((dp = readdir(dirp)) != nullptr) {
        if(inicio<i && i<=limite){
            tracks[h].ruta_cancion=dp->d_name;
            h++;
        }i++;
    }closedir(dirp);
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
