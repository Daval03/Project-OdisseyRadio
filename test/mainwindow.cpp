#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    mMediaPlayer=new QMediaPlayer(this);
    layout1=new QVBoxLayout();
    layout2=new QVBoxLayout();
    ui->scrollContents->setLayout(layout1);
    ui->scrollContents2->setLayout(layout2);
    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    ui->scrollArea_2->setBackgroundRole(QPalette::Dark);
    ReajustarPagina();
    QFont *font=new QFont("Arial",20);
    ui->label_3->setFont(*font);
    connect(mMediaPlayer, &QMediaPlayer::positionChanged,this,&MainWindow::on_positionChanged);
    connect(mMediaPlayer, &QMediaPlayer::durationChanged,this,&MainWindow::on_durationChanged);

}
MainWindow::~MainWindow(){
    delete ui;
}
QPushButton* MainWindow::createBotton(int i){
    QPushButton* button = new QPushButton(tr("Button%1").arg(i),this);
    return button;
}
void MainWindow::accionButton(int cont){
    for(int i=1;i<=cont;i++){
        QHBoxLayout *foo=new QHBoxLayout();
        QLabel *label2 = new QLabel(tr("Artista %1").arg(i));
        QLabel *label = new QLabel(tr("Cancion %1").arg(i));
        QPushButton *button=createBotton(i);

        button->setText("");//.../Resorces/play.png
        QPixmap pixmap("/home/aldo/Documentos/Proyecto 1/Resorces/play.png");//Cambiar ruta
        QIcon ButtonIcon(pixmap);
        button->setIcon(ButtonIcon);
        button->setIconSize(button->rect().size());

        foo->addWidget(label);
        foo->addWidget(label2);
        foo->addWidget(button);
        QObject::connect(button,&QPushButton::clicked,this,[=](){
            this->mostrar(filesong,cancion1);
        });layout2->addLayout(foo);
    }
}
void MainWindow::mostrar(QString file,QString cancion){
    mMediaPlayer->setMedia(QUrl::fromLocalFile(file));
    ui->label_2->setText(cancion);
}
void MainWindow::ReajustarPagina(){
    ui->pagina1->setText(QString::number(1+(3*nivel)));
    ui->pagina2->setText(QString::number(2+(3*nivel)));
    ui->pagina3->setText(QString::number(3+(3*nivel)));
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
    if(nivel<20){
        this->nivel++;
    }ReajustarPagina();
}
void MainWindow::on_pagina1_clicked(){
    if(pivote-1==1+(3*nivel)){
        qDebug()<<"Mostrar de la lista del 0-9";
            //admsetPagina(18,27);
    }else if(pivote+1==1+(3*nivel)){
        qDebug()<<"Mostrar de la lista del 20-29";
    }else{
        this->pivote=1+(3*nivel);
        qDebug()<<"Es mi nuevo centro";
        qDebug()<<"Mostrar de la lista del 10-19";
    }
}

void MainWindow::on_pagina2_clicked(){
    if(pivote-1==2+(3*nivel)){
        qDebug()<<"Mostrar de la lista del 0-9";
            //admsetPagina(18,27);
    }else if(pivote+1==2+(3*nivel)){
        qDebug()<<"Mostrar de la lista del 20-29";
    }else{
        this->pivote=2+(3*nivel);
        qDebug()<<"Es mi nuevo centro";
        qDebug()<<"Mostrar de la lista del 10-19";
    }
}

void MainWindow::on_pagina3_clicked(){
    if(pivote-1==3+(3*nivel)){
        qDebug()<<"Mostrar de la lista del 0-9";
            //admsetPagina(18,27);
    }else if(pivote+1==3+(3*nivel)){
        qDebug()<<"Mostrar de la lista del 20-29";
    }else{
        this->pivote=3+(3*nivel);
        qDebug()<<"Es mi nuevo centro";
        qDebug()<<"Mostrar de la lista del 10-19";
    }
}

void MainWindow::on_Library_clicked(){
    QPushButton *button=createBotton(cont);
    button->setText(tr("Libreria %1").arg(cont));
    QObject::connect(button,&QPushButton::clicked,this,[=](){
        accionButton(15);
    });layout1->addWidget(button);
    cont++;
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
        accionButton(500);

    }else{
        ui->pagina1->show();
        ui->pagina2->show();
        ui->pagina3->show();
        ui->BottonAtras->show();
        ui->ButtonAdelante->show();
        paginacionON=true;
        accionButton(15);
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

