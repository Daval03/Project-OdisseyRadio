#ifndef DIALOG_H
#define DIALOG_H
#include <QFileDialog>
#include <QDialog>
#include <QString>
#include <QMediaPlayer>
#include <QDebug>
namespace Ui {class Dialog;}

class QMediaPlayer;

class Dialog : public QDialog{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void setData(int i);
private slots:
    void on_pushButton_2_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_Play_clicked();

private:
    QString fileSong="/home/aldo/Escritorio/JoJos Bizarre Adventure Openings 1-9 Full.mp3";
    QString artista="Araki";
    QString Grupo="JO-Stars";
    Ui::Dialog *ui;
    QMediaPlayer *mMediaPlayer;
};

#endif // DIALOG_H
