/********************************************************************************
** Form generated from reading UI file 'MountHuang.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOUNTHUANG_H
#define UI_MOUNTHUANG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MountHuang
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MountHuang)
    {
        if (MountHuang->objectName().isEmpty())
            MountHuang->setObjectName("MountHuang");
        MountHuang->resize(600, 400);
        centralWidget = new QWidget(MountHuang);
        centralWidget->setObjectName("centralWidget");
        MountHuang->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MountHuang);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 25));
        MountHuang->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MountHuang);
        mainToolBar->setObjectName("mainToolBar");
        MountHuang->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MountHuang);
        statusBar->setObjectName("statusBar");
        MountHuang->setStatusBar(statusBar);

        retranslateUi(MountHuang);

        QMetaObject::connectSlotsByName(MountHuang);
    } // setupUi

    void retranslateUi(QMainWindow *MountHuang)
    {
        MountHuang->setWindowTitle(QCoreApplication::translate("MountHuang", "MountHuang", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MountHuang: public Ui_MountHuang {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOUNTHUANG_H
