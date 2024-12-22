#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

#include <QMessageBox>
#include <QSerialPortInfo>
#include <SDL2/SDL.h>

#include "mainwindow.h"
#include "servosetting.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // обработка ГУИ кнопок
//    connect(ui->buttonUp, &QPushButton::clicked, this, &MainWindow::keyUp);
//    connect(ui->buttonDown, SIGNAL(clicked()), this, SLOT(keyDown()));

    connect(ui->buttonConnect, SIGNAL(clicked()), this, SLOT(comConnect()));
    connect(ui->buttonSearch, SIGNAL(clicked()), this, SLOT(comSearch()));
    connect(ui->radioButtonJoystick, SIGNAL(clicked()), this, SLOT(comSearch()));

    connect(ui->rollButton, SIGNAL(clicked()), this, SLOT(setRoll()));
    connect(ui->angleButton, SIGNAL(clicked()), this, SLOT(setAngle()));

    // прием радиосообщений
    //connect(&serialPort, SIGNAL(readyRead()),this,SLOT(ReadInPort()));

    auto count = QGamepadManager::instance()->connectedGamepads();
    qDebug() << "Number of connected gamepads:" << count;

    gamepad = new QGamepad(0, this);
    connect(gamepad, &QGamepad::axisLeftXChanged, this,  &MainWindow::onAxisLeftXChanged);
    connect(gamepad, &QGamepad::axisLeftYChanged, this, &MainWindow::onAxisLeftYChanged);
    //connect(gamepad, SIGNAL(axisLeftYChanged()), this, SLOT(onAxisLeftYChanged()));


    connect(ui->servoSettings, SIGNAL(triggered()), this, SLOT(openServoSettings()));

    connect(&serialPort, &QSerialPort::readyRead, this, &MainWindow::readData);


    tmr = new QTimer();
    tmr->setInterval(1500);
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateScreen()));
    tmr->start();

    comSearch();


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
    {
        return;
    }

    if (!event->isAutoRepeat())
    {
        //qDebug() << "[MainWindow::keyPressEvent()] " << event->key() << "; " << event->isAutoRepeat();
        if(event->key() == 87){
            comWrite("$back$");  }//comWrite("$forw$");  }
        else if(event->key() == 83){
            comWrite("$forw$");  }//comWrite("$back$");  }
        else if(event->key() == 65){
            comWrite("$left$");  }
        else if(event->key() == 68){
            comWrite("$right$");  }

    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
    {
        return;
    }
    //qDebug() << "[MainWindow::keyReleaseEvent()] " << event->key() << "; " << event->isAutoRepeat();
    if(event->key() == 87 || event->key() == 83){
        comWrite("$nomove$");  }
    else if(event->key() == 65 || event->key() == 68){
        comWrite("$noroute$");  }

}

//Изменить алгоритм управления на отправку сигнала "начать движение" и "закончить движение"


void MainWindow::onAxisLeftXChanged(double value) {
    qDebug() << "Axis Left X:" << value;
    ui->historyText->appendPlainText("Axis Left X:" + QString::number(value));
    //qDebug() << "Axis Left X:" << value;
}

void MainWindow::onAxisLeftYChanged(double value) {
    ui->historyText->appendPlainText("Axis Left Y:" + QString::number(value));
    //qDebug() << "Axis Left Y:" << value;
}




void MainWindow::comSearch(){

    ui->comboBoxCom->clear();

    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        if (serialPortInfo.productIdentifier() != 0){ // попытка убрать ненужные открытые порты
            ui->comboBoxCom->addItem(serialPortInfo.portName());
        }
    }
}




void MainWindow::comConnect()
{

    if (connection == true){
        serialPort.close();
        connection = false;
        ui->buttonConnect->setText("Подключиться");
        return;

    }
        //return;


    port = ui->comboBoxCom->currentText();


    serialPort.setPortName(port);
    serialPort.setBaudRate(QSerialPort::Baud9600);

    if (!serialPort.open(QIODevice::ReadWrite)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось подключится к порту");
        return;
    }
    else{
        connection = true;
        ui->buttonConnect->setText("Отключиться");
    }
    ui->historyText->appendPlainText("Success connection");

    comWrite("$getangle$");
    comWrite("$getroll$");
}


void MainWindow::ReadInPort(){//Чтение данных из порта

    QByteArray data;
    data.append(serialPort.readAll());
    qDebug() << "data:" << ((QString)(data)).toLatin1();

}






void MainWindow::comWrite(QString dataForSend){
    if(connection == false)
        return;

    serialPort.write(dataForSend.toLatin1());
    qDebug()<< dataForSend.toLatin1();
    serialPort.waitForBytesWritten();
    ui->historyText->appendPlainText("Was writed: " + QString(dataForSend.toLatin1()));
}



void MainWindow::updateScreen(){
   if (connection == false)
       return;
   //qDebug() << "timer";
   if (comFlag == 0)
       PDL();
   else
       voltage();




}

void MainWindow::PDL(){
    dataForSend = "$pdl$";
    serialPort.write(dataForSend.toLatin1().data());
//    serialPort.waitForReadyRead(100);
//    ui->historyText->appendPlainText(serialPort.readLine());
    //qDebug() << serialPort.readAll();
    comFlag = 1;
}

void MainWindow::setPDLText(QString text){
    ui->labelPDL->setText(QString::number(text.count("1") * 10) + "%");
}

void MainWindow::voltage(){
    dataForSend = "$volt$";
    serialPort.write(dataForSend.toLatin1().data());
//    serialPort.waitForReadyRead(100);
//    ui->historyText->appendPlainText(serialPort.readLine());
    comFlag = 0;
}
void MainWindow::setVoltageText(QString text){
    ui->labelVolt->setText(text);
}

void MainWindow::readData()
{

      QByteArray data = serialPort.readAll();
      qDebug() << data;

      if (data == ","){
          flag = 1;
          return;
      }
      else if (data == "$" && flag == 0){
          command.clear();
          value.clear();
          return;
      }
      else if (data == "$" && flag == 1){
          if (command == "pdl")
              setPDLText(value);

          if (command == "volt")
              setVoltageText(value);

          if (command == "roll")
              readRoll(value);

          if (command == "angle")
              readAngle(value);


          flag = 0;
          return;
      }
      else if (flag == 0){
          command+=data;
          return;
      }

      else if (flag == 1){
          value+=data;
          return;
      }

}

void MainWindow::openServoSettings(){
    qDebug()<<"gg";
    Servosetting *ss = new Servosetting();
    ss->show();

}

void MainWindow::readRoll(QString text){
     ui->rollText->setText(text);

}
void MainWindow::readAngle(QString text){
    ui->angleText->setText(text);
}

void MainWindow::setRoll(){
    char command[] = "$setroll";
    strcat(command, ui->rollText->toPlainText().toLatin1().data());
    comWrite(command);
}

void MainWindow::setAngle(){
    char command[] = "$setangle";
    strcat(command, ui->angleText->toPlainText().toLatin1().data());
    comWrite(command);
}
