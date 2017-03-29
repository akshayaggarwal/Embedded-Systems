#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QDialog>
#include <QtSerialPort/QSerialPort>


#define vcmd "v\r"
#define xcmd "X\r"
#define remotecmd "C1\r"
#define localcmd "C0\r"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QByteArray getdata(char *);
    ~MainWindow();

private slots:
    void vslot1();
    void xslot1();
    void remoteslot1();
    void localslot1();


private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
