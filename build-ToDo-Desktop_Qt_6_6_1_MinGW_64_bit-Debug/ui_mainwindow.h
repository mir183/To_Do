/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ok
{
public:
    QWidget *centralwidget;
    QLineEdit *txtTask;
    QPushButton *btnAdd;
    QListWidget *listWidget;
    QPushButton *btnRemove;
    QPushButton *btnRemoveAll;

    void setupUi(QMainWindow *ok)
    {
        if (ok->objectName().isEmpty())
            ok->setObjectName("ok");
        ok->resize(492, 681);
        centralwidget = new QWidget(ok);
        centralwidget->setObjectName("centralwidget");
        txtTask = new QLineEdit(centralwidget);
        txtTask->setObjectName("txtTask");
        txtTask->setGeometry(QRect(10, 20, 381, 24));
        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setGeometry(QRect(400, 20, 80, 24));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(10, 50, 471, 591));
        btnRemove = new QPushButton(centralwidget);
        btnRemove->setObjectName("btnRemove");
        btnRemove->setGeometry(QRect(280, 650, 80, 24));
        btnRemoveAll = new QPushButton(centralwidget);
        btnRemoveAll->setObjectName("btnRemoveAll");
        btnRemoveAll->setGeometry(QRect(400, 650, 80, 24));
        ok->setCentralWidget(centralwidget);

        retranslateUi(ok);

        QMetaObject::connectSlotsByName(ok);
    } // setupUi

    void retranslateUi(QMainWindow *ok)
    {
        ok->setWindowTitle(QCoreApplication::translate("ok", "MainWindow", nullptr));
        btnAdd->setText(QCoreApplication::translate("ok", "Add", nullptr));
        btnRemove->setText(QCoreApplication::translate("ok", "Remove", nullptr));
        btnRemoveAll->setText(QCoreApplication::translate("ok", "Remove All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ok: public Ui_ok {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
