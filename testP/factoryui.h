#ifndef FACTORYUI_H
#define FACTORYUI_H
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QMediaPlayer>
class FactoryUi{
public:
    FactoryUi();
    QMediaPlayer *createMediaPlay();
    QPushButton *createButton();
    QVBoxLayout *createLayoutV();
    QHBoxLayout *createLayoutH();
    QFont *createFont();
    QLabel *createLabel();
};

#endif // FACTORYUI_H
