#ifndef SERVOSETTING_H
#define SERVOSETTING_H

#include <QWidget>
#include "mainwindow.h"



namespace Ui {
class Servosetting;
}

class Servosetting : public QWidget
{
    Q_OBJECT

public:
    explicit Servosetting(QWidget *parent = nullptr);
    ~Servosetting();

    void readRoll();
public slots:
    void setRoll();
private:
    Ui::Servosetting *ui;
    MainWindow *m;
};

#endif // SERVOSETTING_H
