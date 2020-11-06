#include "factoryui.h"

FactoryUi::FactoryUi(){}

QPushButton *FactoryUi::createButton(){
    return new QPushButton;
}
QVBoxLayout *FactoryUi::createLayoutV(){
    return new QVBoxLayout;
}
QHBoxLayout *FactoryUi::createLayoutH(){
    return new QHBoxLayout;
}
QFont *FactoryUi::createFont(){
    return new QFont();
}
QLabel *FactoryUi::createLabel(){
    return new QLabel;
}
QMediaPlayer *FactoryUi::createMediaPlay(){
    return new QMediaPlayer();
}
QMessageBox *FactoryUi::createMessageBox(){
    return new QMessageBox();
}
