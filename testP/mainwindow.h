#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QDebug>
#include <string>
#include <QMediaPlayer>
#include <administrador.h>

using namespace std;

QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }

QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();
    QPushButton* createBotton(int i);
    void meterInfo(vector<musica> data,int inicio, int limite);
    void mostrar(QString file,QString cancion);
    void reajustarPagina();
    void eliminarLayout();

private slots:

    void on_positionChanged(qint64 position);
    void on_durationChanged(qint64 position);
    void on_BottonAtras_clicked();
    void on_ButtonAdelante_clicked();
    void on_pagina1_clicked();
    void on_pagina2_clicked();
    void on_pagina3_clicked();
    void on_Library_clicked();
    void on_Play_clicked();
    void on_slider_sliderMoved(int position);
    void on_checkBox_clicked();
    void on_Show_info_clicked();

private:
    Administrador *admi;
    int nivel=0;
    int cont=1;
    bool playsong=true;
    bool paginacionON=true;
    QVBoxLayout *layout1;
    QVBoxLayout *layout2;
    Ui::MainWindow *ui;
    QMediaPlayer *mMediaPlayer;

    //Ejemplo cambiar rutas para ejemplos

    QString filesong2="/home/aldo/Escritorio/From-Nowhere-SertOne-Remix.mp3";
    QString filesong="/home/aldo/Escritorio/JoJos Bizarre Adventure Openings 1-9 Full.mp3";
    QString cancion1="JoJos Bizarre Adventure Openings";
    QString cancion2="From Nowhere SertOne Remix";
};
#endif // MAINWINDOW_H
