#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();  //33 Titulo 19 Duracion 5 Nombre 23 Genero
}

//#include <administrador.h>
//#include <QDebug>
//int main(){
//    Administrador *admi=new Administrador();
//    admi->getStrings(0,30);
//    cout<<" ";
    //cout<<admi->tracks.size();
    //admi->read_directory(1320,1350);


//    cout<<" ";
//    cout<<admi->tracks[29].ruta_cancion;
//    admi->resetData(620);
//    cout<<" ";
//    cout<<admi->tracks.size();
//    for(int i=0;i<30;i++){
//        cout<<i;
//        cout<<": ";
//        cout<<admi->tracks.operator[](i).ruta_cancion;
//        cout<<"\n";
//    }
//}
