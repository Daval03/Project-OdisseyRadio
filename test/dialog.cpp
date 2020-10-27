#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent):QDialog(parent),ui(new Ui::Dialog){
    ui->setupUi(this);
    this->mMediaPlayer=new QMediaPlayer(this);
    mMediaPlayer->setMedia(QUrl::fromLocalFile(fileSong));
}

Dialog::~Dialog(){
    delete ui;
}
void Dialog::setData(int i){

}
void Dialog::on_pushButton_2_clicked()
{

}

void Dialog::on_horizontalSlider_valueChanged(int value){

}

void Dialog::on_Play_clicked(){

    //mMediaPlayer->setAudioRole(ui->horizontalSlider);
    //mMediaPlayer->play();
}
