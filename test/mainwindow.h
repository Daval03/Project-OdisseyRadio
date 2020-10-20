#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QDebug>
#include <QSignalMapper>
#include <string>
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
    void accionButton();
    void mostrar(QString i);
public slots:
    void on_pushButton_clicked();

private:
    int cont=1;
    QVBoxLayout *layout1;
    QVBoxLayout *layout2;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
