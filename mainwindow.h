#pragma once

#include <QMainWindow>
#include <QShortcut>
#include <QtSerialPort/QSerialPort>

#include <QGamepad>
#include <QTimer>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QSerialPort serialPort;
    QString dataForSend;
    QString port;
    bool connection = false;


    void comWrite(QString dataForSend);
    void PDL();
    void voltage();


public slots:
//    void keyUp();
//    void keyDown();
//    void keyRight();
//    void keyLeft();


    void comConnect();

    void comSearch();
    void updateScreen();

    void ReadInPort();
   // void joystick();


    void onAxisLeftXChanged(double value);
    void onAxisLeftYChanged(double value);
    //void onButtonAChanged(bool pressed);
    void openServoSettings();

    void setRoll();
    void setAngle();
private:
    Ui::MainWindow *ui;    
    QShortcut *up;
    QShortcut *down;
    QShortcut *left;
    QShortcut *right;

    QGamepad *gamepad;

    QTimer *tmr;

    bool flag;
    bool comFlag;
    QString command;
    QString value;


private slots:
     void readData();
     void setVoltageText(QString);
     void setPDLText(QString);
     void readRoll(QString);
     void readAngle(QString);



protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);


};

