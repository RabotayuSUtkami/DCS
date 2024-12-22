/********************************************************************************
** Form generated from reading UI file 'servosetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVOSETTING_H
#define UI_SERVOSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Servosetting
{
public:
    QTextEdit *textEdit;
    QPushButton *buttonAccept;
    QPushButton *buttonCancel;

    void setupUi(QWidget *Servosetting)
    {
        if (Servosetting->objectName().isEmpty())
            Servosetting->setObjectName(QString::fromUtf8("Servosetting"));
        Servosetting->resize(400, 300);
        textEdit = new QTextEdit(Servosetting);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(80, 70, 221, 31));
        buttonAccept = new QPushButton(Servosetting);
        buttonAccept->setObjectName(QString::fromUtf8("buttonAccept"));
        buttonAccept->setGeometry(QRect(110, 120, 141, 31));
        buttonCancel = new QPushButton(Servosetting);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        buttonCancel->setGeometry(QRect(110, 160, 141, 31));

        retranslateUi(Servosetting);

        QMetaObject::connectSlotsByName(Servosetting);
    } // setupUi

    void retranslateUi(QWidget *Servosetting)
    {
        Servosetting->setWindowTitle(QCoreApplication::translate("Servosetting", "Form", nullptr));
        buttonAccept->setText(QCoreApplication::translate("Servosetting", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        buttonCancel->setText(QCoreApplication::translate("Servosetting", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Servosetting: public Ui_Servosetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVOSETTING_H
