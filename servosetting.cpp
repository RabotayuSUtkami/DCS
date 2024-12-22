#include "servosetting.h"
#include "ui_servosetting.h"
#include "qdebug.h"



Servosetting::Servosetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Servosetting)
{
    ui->setupUi(this);

    connect(ui->buttonAccept, SIGNAL(clicked()), this, SLOT(setRoll()));
    qDebug() << "tut vizov";
    readRoll();
}

Servosetting::~Servosetting()
{
    delete ui;
}

void Servosetting::readRoll(){
  qDebug() << "tut nachalo";
    qDebug() << "one";
    MainWindow s;
    bool roll2 = s.connection;
    qDebug() << roll2;

    qDebug() << m->port;
    m->serialPort.setPortName(m->port);
    m->serialPort.setBaudRate(QSerialPort::Baud9600);
    m->serialPort.write("$getroll$");


}

void Servosetting::setRoll(){
    QString roll = "$setroll" + ui->textEdit->toPlainText() + "$";
    m->serialPort.write(roll.toLatin1());
}
