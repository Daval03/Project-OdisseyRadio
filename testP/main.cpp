#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

//#include <QMessageBox>
//#include <administrador.h>
//#include <QDebug>
//using namespace std;

//int main(){
//    Administrador *admi=new Administrador();
//    admi->getStrings(0,30);

//    QString res;
//    int a=6-3;
//    for(int i=0;i<a;i++){//000002.mp3
//        res.append("0");
//    }res.append("123.mp3");
//    qDebug()<< res;
//    cout<<" ";
//    cout<<admi->tracks.size();

//    cout<<" ";
//    cout<<admi->tracks[29].ruta_cancion;
//    admi->resetData(620);
//    cout<<" ";
//    cout<<admi->tracks.size();
//    for(int i=0;i<30;i++){
//        cout<<i;
//        cout<<": ";
//        cout<<admi->tracks.operator[](i).track_interest;
//        cout<<"\n";
//    }
//}
