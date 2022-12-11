/********************************************************************************
** Form generated from reading UI file 'Saper.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAPER_H
#define UI_SAPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SaperClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SaperClass)
    {
        if (SaperClass->objectName().isEmpty())
            SaperClass->setObjectName(QString::fromUtf8("SaperClass"));
        SaperClass->resize(600, 400);
        menuBar = new QMenuBar(SaperClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        SaperClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SaperClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SaperClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SaperClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        SaperClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SaperClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SaperClass->setStatusBar(statusBar);

        retranslateUi(SaperClass);

        QMetaObject::connectSlotsByName(SaperClass);
    } // setupUi

    void retranslateUi(QMainWindow *SaperClass)
    {
        SaperClass->setWindowTitle(QCoreApplication::translate("SaperClass", "Saper", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaperClass: public Ui_SaperClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAPER_H
