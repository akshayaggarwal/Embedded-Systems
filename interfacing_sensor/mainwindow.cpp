  
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QtSerialPort/QSerialPortInfo>
#include <QIntValidator>
#include <QLineEdit>
#include <QThread>


QByteArray replydata;

QT_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/*
void getdata2(char *cmm)
{
    QSerialPort *serial2;



    serial2 = new QSerialPort(this);
    serial2->setPortName("com11");
    serial2->open(QIODevice::ReadWrite);

    serial2->setBaudRate(9600);
    serial2->setDataBits(QSerialPort::Data8);
    serial2->setParity(QSerialPort::NoParity);
    serial2->setStopBits(QSerialPort::OneStop);
    serial2->setFlowControl(QSerialPort::NoFlowControl);

        QByteArray ba;
        QByteArray ba2;
        ba2.resize(2);



        serial2->write(cmm);
        ba2="";


         ba="";
         while (ba2 != "\r")
         {
           ba2=serial2->read(1);
           serial2->waitForReadyRead(1);
           ba=ba+ba2;
         }

         qDebug() << ba;
         ui->textEdit->setPlainText(ba);

         serial2->close();


}

*/


QByteArray MainWindow::getdata(char *cmm)
{
    QSerialPort *serial2;



    serial2 = new QSerialPort(this);
    serial2->setPortName("com11");



    bool aa=serial2->open(QIODevice::ReadWrite);

    qDebug() << aa;
    //if (!(serial2->isOpen()))
    if (!(aa))
        return("Communication failure");


    serial2->setBaudRate(9600);
    serial2->setDataBits(QSerialPort::Data8);
    serial2->setParity(QSerialPort::NoParity);
    serial2->setStopBits(QSerialPort::OneStop);
    serial2->setFlowControl(QSerialPort::NoFlowControl);

        QByteArray ba;
        QByteArray ba2;
        ba2.resize(2);



        int bb=serial2->write(cmm); //
        qDebug()<<bb;
        ba2="";


         ba="";
         while (ba2 != "\r")
         {
           ba2=serial2->read(1);
           serial2->waitForReadyRead(1);
           ba=ba+ba2;
         }

         qDebug() << ba;
         //ui->textEdit->setPlainText(ba);

         serial2->close();
         //QByteArray temp="?";

         return(ba);


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::vslot1()
{


  replydata= getdata(vcmd);

  if (replydata[0] == '?')
  {

      ui->textEdit->setPlainText("error");
  }
  else
  {

      ui->textEdit->setPlainText(replydata);
  }

  //ui->textEdit->setPlainText();
  //qDebug() << replydata;
}


void MainWindow::xslot1()
{

  replydata=getdata(xcmd);
  if (replydata[0] == '?')
  {

      ui->textEdit->setPlainText("error");
  }
  else
  {

      ui->textEdit->setPlainText(replydata);
  }




}

void MainWindow::remoteslot1()
{

  replydata=getdata(remotecmd);
  if (replydata[0] == '?')
  {

      ui->textEdit->setPlainText("error");
  }
  else
  {

      ui->textEdit->setPlainText(replydata);
  }




}

void MainWindow::localslot1()
{

  replydata=getdata(localcmd);
  if (replydata[0] == '?')
  {

      ui->textEdit->setPlainText("error");
  }
  else
  {

      ui->textEdit->setPlainText(replydata);
  }




}


