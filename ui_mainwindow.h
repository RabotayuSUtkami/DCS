/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *servoSettings;
    QWidget *centralwidget;
    QLabel *label;
    QLabel *labelPDL;
    QLabel *labelVolt;
    QLabel *label_4;
    QPlainTextEdit *historyText;
    QComboBox *comboBoxCom;
    QLabel *label_2;
    QPushButton *buttonConnect;
    QPushButton *buttonSearch;
    QRadioButton *radioButtonKeyboard;
    QRadioButton *radioButtonJoystick;
    QTextEdit *rollText;
    QPushButton *rollButton;
    QTextEdit *angleText;
    QPushButton *angleButton;
    QLabel *label_3;
    QLabel *label_5;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 444);
        servoSettings = new QAction(MainWindow);
        servoSettings->setObjectName(QString::fromUtf8("servoSettings"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 320, 61, 16));
        labelPDL = new QLabel(centralwidget);
        labelPDL->setObjectName(QString::fromUtf8("labelPDL"));
        labelPDL->setGeometry(QRect(100, 320, 51, 16));
        labelVolt = new QLabel(centralwidget);
        labelVolt->setObjectName(QString::fromUtf8("labelVolt"));
        labelVolt->setGeometry(QRect(100, 340, 61, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 340, 71, 16));
        historyText = new QPlainTextEdit(centralwidget);
        historyText->setObjectName(QString::fromUtf8("historyText"));
        historyText->setGeometry(QRect(490, 190, 281, 181));
        comboBoxCom = new QComboBox(centralwidget);
        comboBoxCom->setObjectName(QString::fromUtf8("comboBoxCom"));
        comboBoxCom->setGeometry(QRect(80, 70, 81, 22));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 61, 16));
        buttonConnect = new QPushButton(centralwidget);
        buttonConnect->setObjectName(QString::fromUtf8("buttonConnect"));
        buttonConnect->setGeometry(QRect(170, 70, 101, 23));
        buttonSearch = new QPushButton(centralwidget);
        buttonSearch->setObjectName(QString::fromUtf8("buttonSearch"));
        buttonSearch->setGeometry(QRect(170, 40, 101, 23));
        radioButtonKeyboard = new QRadioButton(centralwidget);
        radioButtonKeyboard->setObjectName(QString::fromUtf8("radioButtonKeyboard"));
        radioButtonKeyboard->setGeometry(QRect(30, 250, 101, 17));
        radioButtonJoystick = new QRadioButton(centralwidget);
        radioButtonJoystick->setObjectName(QString::fromUtf8("radioButtonJoystick"));
        radioButtonJoystick->setGeometry(QRect(30, 270, 101, 17));
        rollText = new QTextEdit(centralwidget);
        rollText->setObjectName(QString::fromUtf8("rollText"));
        rollText->setGeometry(QRect(20, 130, 131, 31));
        rollButton = new QPushButton(centralwidget);
        rollButton->setObjectName(QString::fromUtf8("rollButton"));
        rollButton->setGeometry(QRect(150, 130, 121, 31));
        angleText = new QTextEdit(centralwidget);
        angleText->setObjectName(QString::fromUtf8("angleText"));
        angleText->setGeometry(QRect(20, 190, 131, 31));
        angleButton = new QPushButton(centralwidget);
        angleButton->setObjectName(QString::fromUtf8("angleButton"));
        angleButton->setGeometry(QRect(150, 190, 121, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 110, 131, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 170, 121, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(servoSettings);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        servoSettings->setText(QCoreApplication::translate("MainWindow", "\320\241\320\265\321\200\320\262\320\276", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\241\320\262\321\217\320\267\321\214", nullptr));
        labelPDL->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelVolt->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\220\320\275\321\202\320\265\320\275\320\260", nullptr));
        buttonConnect->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        buttonSearch->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276\321\200\321\202\320\276\320\262", nullptr));
        radioButtonKeyboard->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\320\260\320\262\320\270\320\260\321\202\321\203\321\200\320\260", nullptr));
        radioButtonJoystick->setText(QCoreApplication::translate("MainWindow", "\320\224\320\266\320\276\320\271\321\201\321\202\320\270\320\272", nullptr));
        rollButton->setText(QCoreApplication::translate("MainWindow", "\320\277\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        angleButton->setText(QCoreApplication::translate("MainWindow", "\320\277\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\235\321\203\320\273\320\265\320\262\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 (roll)", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260 (angle)", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
