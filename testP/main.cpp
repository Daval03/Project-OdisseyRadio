#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

//#include <administrador.h>
//#include <QDebug>
//int main(){
//    Administrador *admi=new Administrador();
//    admi->getData(0,30);
//    cout<<admi->tracks.size();
//    //admi->resetData();
//    //admi->getData2();
//    //cout<<admi->tracks[0].track_title;
//    //cout<<admi->tracks[0];
//   //admi->getData2();
//}
