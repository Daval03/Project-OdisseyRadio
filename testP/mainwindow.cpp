#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->admi=new Administrador();
    this->admi->pivote=1;
    this->admi->limite=2;
    this->admi->inicio=0;
    this->admi->getStrings(0,30);

    mMediaPlayer=new QMediaPlayer(this);
    layout1=new QVBoxLayout();
    layout2=new QVBoxLayout();
    ui->scrollContents->setLayout(layout1);
    ui->scrollContents2->setLayout(layout2);
    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    ui->scrollArea_2->setBackgroundRole(QPalette::Dark);
    QFont *font=new QFont("Arial",20);
    ui->label_3->setFont(*font);
    connect(mMediaPlayer, &QMediaPlayer::positionChanged,this,&MainWindow::on_positionChanged);
    connect(mMediaPlayer, &QMediaPlayer::durationChanged,this,&MainWindow::on_durationChanged);

    QPushButton *button=createBotton(cont);
    button->setText(tr("Libreria %1").arg(cont));
    QObject::connect(button,&QPushButton::clicked,this,[=](){
        meterInfo(admi->tracks,10,20);
    });layout1->addWidget(button);

    ReajustarPagina();
}
MainWindow::~MainWindow(){
    delete ui;
}
QPushButton* MainWindow::createBotton(int i){
    QPushButton* button = new QPushButton(tr("Button%1").arg(i),this);
    return button;
}

void MainWindow::meterInfo(vector<musica> tracks, int inicio, int limite){
    for(int i=inicio;i<limite;i++){
        QHBoxLayout *foo=new QHBoxLayout();
        QLabel *label2 = new QLabel(QString::fromStdString(tracks[i].artist_name));
        QLabel *label = new QLabel(QString::fromStdString(tracks[i].track_title));
        QLabel *label3 = new QLabel(QString::fromStdString(tracks[i].genero));

        QPushButton *button=createBotton(i);
        button->setText("Play");
//        button->setText("");//.../Resorces/play.png
//        QPixmap pixmap("/home/aldo/Documentos/Proyecto 1/Resorces/play.png");//Cambiar ruta
//        QIcon ButtonIcon(pixmap);
//        button->setIcon(ButtonIcon);
//        button->setIconSize(button->rect().size());

        foo->addWidget(label);
        foo->addWidget(label2);
        foo->addWidget(label3);
        foo->addWidget(button);
//        QObject::connect(button,&QPushButton::clicked,this,[=](){
//            this->mostrar(filesong,cancion1);
//        });
        layout2->addLayout(foo);
    }
}

void MainWindow::mostrar(QString file,QString cancion){
    mMediaPlayer->setMedia(QUrl::fromLocalFile(file));
    ui->label_2->setText(cancion);
}
void MainWindow::ReajustarPagina(){
    ui->pagina1->setText(QString::number(3*nivel));
    ui->pagina2->setText(QString::number(1+(3*nivel)));
    ui->pagina3->setText(QString::number(2+(3*nivel)));
}

void MainWindow::on_positionChanged(qint64 position){
    ui->slider->setValue(position);
}
void MainWindow::on_durationChanged(qint64 position){
    ui->slider->setMaximum(position);
}
void MainWindow::on_BottonAtras_clicked(){
    if(nivel!=0){
        this->nivel--;
    }ReajustarPagina();
}
void MainWindow::on_ButtonAdelante_clicked(){
    if(nivel<21){
        this->nivel++;
    }ReajustarPagina();
}

void MainWindow::on_pagina1_clicked(){
    eliminarLayout();
    if(admi->pivote-1==(3*nivel)){
        meterInfo(admi->tracks,0,10);
    }
    else if(admi->pivote+1==(3*nivel)){
        meterInfo(admi->tracks,20,30);
    }
    else if(admi->pivote==3*nivel){
        qDebug()<<"caso base";
        meterInfo(admi->tracks,10,20);
    }
    else if(admi->pivote==0){
        this->admi->doMath(1,30);
        meterInfo(admi->tracks,0,10);
    }
    else{
        qDebug()<<"Recalcular";
        this->admi->doMath(3*nivel,30);
        meterInfo(admi->tracks,10,20);
    }
}
void MainWindow::on_pagina2_clicked(){
    eliminarLayout();
    if(admi->pivote-1==(1+(3*nivel))){
        qDebug()<<"Izq";
        meterInfo(admi->tracks,0,10);
    }
    else if(admi->pivote+1==(1+(3*nivel))){
        qDebug()<<"Der";
        meterInfo(admi->tracks,20,30);
    }
    else if(admi->pivote==1+(3*nivel)){
        qDebug()<<"caso base";
        meterInfo(admi->tracks,10,20);
    }else if(admi->pivote==1){
        meterInfo(admi->tracks,10,20);
    }else{
        qDebug()<<"Recalcular";
        this->admi->doMath(1+(3*nivel),30);
        qDebug()<<admi->tracks.size();
        meterInfo(admi->tracks,10,20);
    }
}
void MainWindow::on_pagina3_clicked(){
    eliminarLayout();
    if(admi->pivote-1==(2+(3*nivel))){
        qDebug()<<"Izq";
        meterInfo(admi->tracks,0,10);
    }
    else if(admi->pivote+1==(2+(3*nivel))){
        qDebug()<<"Der";
        meterInfo(admi->tracks,20,30);
    }
    else if(admi->pivote==2+(3*nivel)){
        qDebug()<<"caso base";
        meterInfo(admi->tracks,10,20);
    }
    else{
        qDebug()<<"Recalcular";
        this->admi->doMath(2+(3*nivel),30);
        meterInfo(admi->tracks,10,20);
    }
}

void MainWindow::on_Library_clicked(){
    qDebug()<<"Hola mundo";
}

void MainWindow::on_Play_clicked(){
    if(playsong){
        mMediaPlayer->play();
        playsong=false;
    }else{
        mMediaPlayer->pause();
        playsong=true;
    }
}
void MainWindow::on_slider_sliderMoved(int position){
    mMediaPlayer->setPosition(position);
}
void MainWindow::on_checkBox_clicked(){
    eliminarLayout();
    if(paginacionON){
        ui->pagina1->hide();
        ui->pagina2->hide();
        ui->pagina3->hide();
        ui->BottonAtras->hide();
        ui->ButtonAdelante->hide();
        paginacionON=false;
        admi->resetData(30);
        admi->getData2();
        meterInfo(admi->tracks,0,620);
        qDebug()<<"Bien";
    }else{
        ui->pagina1->show();
        ui->pagina2->show();
        ui->pagina3->show();
        ui->BottonAtras->show();
        ui->ButtonAdelante->show();
        paginacionON=true;
        admi->doMath(1,620);
        meterInfo(admi->tracks,10,19);
    }
}

void MainWindow::eliminarLayout(){
    while(!layout2->isEmpty()) {
        QLayout *hb = layout2->takeAt(0)->layout();
        while(!hb->isEmpty()) {
            QWidget *w = hb->takeAt(0)->widget();
            delete w;
        }
        delete hb;
    }
}
void MainWindow::on_Show_info_clicked(){}
