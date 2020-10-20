#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    layout1=new QVBoxLayout();
    layout2=new QVBoxLayout();
    ui->scrollContents->setLayout(layout1);
    ui->scrollContents2->setLayout(layout2);
    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    ui->scrollArea_2->setBackgroundRole(QPalette::Dark);
}
MainWindow::~MainWindow(){
    delete ui;
}
QPushButton* MainWindow::createBotton(int i){
    QPushButton* button = new QPushButton(tr("Button%1").arg(i),this);
    return button;
}
void MainWindow::on_pushButton_clicked(){
    QPushButton *button=createBotton(cont);

    QObject::connect(button,&QPushButton::clicked,this,[=](){
        this->accionButton();
    });layout1->addWidget(button);
    cont++;
}
void MainWindow::accionButton(){
    for(int i=0;i<50;i++){
        QHBoxLayout *foo=new QHBoxLayout();
        QLabel *label2 = new QLabel(tr("Artista%1").arg(i));
        QLabel *label = new QLabel(tr("Cancion%1").arg(i));
        QPushButton *button=createBotton(i);

        foo->addWidget(label);
        foo->addWidget(label2);
        foo->addWidget(button);

        QObject::connect(button,&QPushButton::clicked,this,[=](){
            this->mostrar(button->text());
        });layout2->addLayout(foo);
    }
}
void MainWindow::mostrar(QString i){
    qDebug()<<i;
}
