#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->admi=new Administrador();
    this->admi->pivote=1;
    this->admi->limite=2;
    this->admi->inicio=0;
    this->admi->getStrings(0,30);
    this->msgBox= factory_method->createMessageBox();
    this->msgBox->setText("Info extra de la cancion");

    mMediaPlayer=factory_method->createMediaPlay();
    layout1=factory_method->createLayoutV();
    layout2=factory_method->createLayoutV();

    ui->scrollContents->setLayout(layout1);
    ui->scrollContents2->setLayout(layout2);
    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    ui->scrollArea_2->setBackgroundRole(QPalette::Dark);

    QFont *font=factory_method->createFont();
    font->setPointSize(22);
    font->setStyleName("Arial");
    ui->label_3->setFont(*font);

    connect(mMediaPlayer, &QMediaPlayer::positionChanged,this,&MainWindow::on_positionChanged);
    connect(mMediaPlayer, &QMediaPlayer::durationChanged,this,&MainWindow::on_durationChanged);

    QPushButton *button = factory_method->createButton();
    button->setText("All tracks");
    QObject::connect(button,&QPushButton::clicked,this,[=](){
        meterInfo(admi->tracks,10,20);
    });
    layout1->addWidget(button);
    reajustarPagina();
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::meterInfo(vector<musica> tracks, int inicio, int limite){
    for(int i=inicio;i<limite;i++){
        QHBoxLayout *foo= factory_method->createLayoutH();
        QLabel *label3 =factory_method->createLabel();
        QLabel *label2 = factory_method->createLabel();
        QLabel *label = factory_method->createLabel();
        label3->setText(QString::fromStdString(tracks[i].genero));

        if(tracks[i].artist_name.size()>40){
            label2->setText("Datos corrompidos");
        }else{
            label2->setText(QString::fromStdString(tracks[i].artist_name));
        }

        if(tracks[i].track_title.size()>40){
            label->setText("Datos corrompidos");
        }else{
            label->setText(QString::fromStdString(tracks[i].track_title));
        }
        QPushButton *button=factory_method->createButton();
        button->setText("Play");
        foo->addWidget(label);
        foo->addWidget(label2);
        foo->addWidget(label3);
        foo->addWidget(button);

        QObject::connect(button,&QPushButton::clicked,this,[=](){
            QString rutaxd="/home/aldo/Escritorio/Canciones/";
            rutaxd.append(QString::fromStdString(tracks[i].ruta_cancion));
            this->mostrar(rutaxd,tracks[i]);
        });
        layout2->addLayout(foo);
    }
}

void MainWindow::mostrar(QString file,musica cancion){
    mMediaPlayer->setMedia(QUrl::fromLocalFile(file));
    ui->label_2->setText(QString::fromStdString(cancion.track_title));
    this->res=makeString(cancion);

}
void MainWindow::reajustarPagina(){
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
    }reajustarPagina();
}
void MainWindow::on_ButtonAdelante_clicked(){
    if(nivel<44){
        this->nivel++;
    }reajustarPagina();
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
    else if(3*nivel==0){
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
    }else if(3*nivel==0){
        meterInfo(admi->tracks,10,20);
    }else{
        qDebug()<<"Recalcular";
        this->admi->doMath(1+(3*nivel),30);
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
        this->admi->resetData(30);
        this->admi->getStrings(0,1382);
        meterInfo(admi->tracks,0,1382);
        qDebug()<<"Bien";
    }else{
        ui->pagina1->show();
        ui->pagina2->show();
        ui->pagina3->show();
        ui->BottonAtras->show();
        ui->ButtonAdelante->show();
        paginacionON=true;
        admi->doMath(1,1382);
        this->nivel=0;
        reajustarPagina();
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

QString MainWindow::makeString(musica cancion){
    this->res.clear();

    this->res.append("Album: ");
    this->res.append(QString::fromStdString(cancion.album_name)+"\n");

    this->res.append("Artista: ");
    this->res.append(QString::fromStdString(cancion.artist_name)+"\n");

    this->res.append("Cancion: ");
    this->res.append(QString::fromStdString(cancion.track_title)+"\n");

    this->res.append("Idioma: ");
    this->res.append(QString::fromStdString(cancion.idioma)+"\n");

    this->res.append("Genero: ");
    this->res.append(QString::fromStdString(cancion.genero)+"\n");

    this->res.append("Interes de la cancion: ");
    this->res.append(QString::fromStdString(cancion.track_interest)+"\n");

    return res;
}
void MainWindow::on_Show_info_clicked(){
    msgBox->setInformativeText(res);
    msgBox->exec();
}
