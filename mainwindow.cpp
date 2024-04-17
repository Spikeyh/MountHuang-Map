#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <qdebug.h>
#include <QToolBar>
#include <QtAlgorithms>
#include <iostream>
#include <windows.h>
#include <QTimer>
#include "dijkstra.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ui->setupUi(this);

    setMinimumHeight(720);
    setMinimumWidth(600);
    //resize(600,720);

    // 创建一个QWidget作为中心部件
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // 创建按钮
    QPushButton* button_ciguangge = new QPushButton("", this);
    button_ciguangge->setGeometry(QRect(QPoint(135, 530), QSize(20, 20)));
    button_ciguangge->setStyleSheet("border-image: url(image/buttonbackground.jpg);border-radius: 10px;");
    connect(button_ciguangge, &QPushButton::clicked, this, &MainWindow::onCiguanggeButtonClicked);

    QPushButton* button_miaobishenghua = new QPushButton("", this);
    button_miaobishenghua->setGeometry(QRect(QPoint(409, 317), QSize(20, 20)));
    button_miaobishenghua->setStyleSheet("border-image: url(image/buttonbackground.jpg);border-radius: 10px;");
    connect(button_miaobishenghua, &QPushButton::clicked, this, &MainWindow::onMiaobishenghuaButtonClicked);

    QPushButton* button_yungusi = new QPushButton("", this);
    button_yungusi->setGeometry(QRect(QPoint(454, 504), QSize(50, 50)));
    button_yungusi->setStyleSheet("border-image: url(image/buttonbackground.jpg);border-radius: 25px;");
    connect(button_yungusi, &QPushButton::clicked, this, &MainWindow::onYungusiButtonClicked);

    QPushButton* button_yingkesong = new QPushButton("", this);
    button_yingkesong->setGeometry(QRect(QPoint(162, 428), QSize(20, 20)));
    button_yingkesong->setStyleSheet("border-image: url(image/buttonbackground.jpg);border-radius: 10px;");
    connect(button_yingkesong, &QPushButton::clicked, this, &MainWindow::onYingkesongButtonClicked);

    QPushButton* button_guangmingding = new QPushButton("", this);
    button_guangmingding->setGeometry(QRect(QPoint(243, 316), QSize(20, 20)));
    button_guangmingding->setStyleSheet("border-image: url(image/buttonbackground.jpg);border-radius: 10px;");
    connect(button_guangmingding, &QPushButton::clicked, this, &MainWindow::onGuangmingdingButtonClicked);

    QPushButton* button_nandamen = new QPushButton("", this);
    button_nandamen->setGeometry(QRect(QPoint(372, 579), QSize(20, 20)));
    button_nandamen->setStyleSheet("border-image: url(image/buttonbackground.jpg);border-radius: 10px;");
    connect(button_nandamen, &QPushButton::clicked, this, &MainWindow::onNandamenButtonClicked);

    QPushButton* button_yupingzhan = new QPushButton("", this);
    button_yupingzhan->setGeometry(QRect(QPoint(107, 397), QSize(20, 20)));
    button_yupingzhan->setStyleSheet("border-image: url(image/buttonbackground.jpg);border-radius: 10px;");
    connect(button_yupingzhan, &QPushButton::clicked, this, &MainWindow::onyupingzhanButtonClicked);

    QPushButton* button_baieling = new QPushButton("", this);
    button_baieling->setGeometry(QRect(QPoint(457, 389), QSize(20, 20)));
    button_baieling->setStyleSheet("border-image: url(image/buttonbackground.jpg);border-radius: 10px;");
    connect(button_baieling, &QPushButton::clicked, this, &MainWindow::onbaielingButtonClicked);

    QMenuBar* menuBar = new QMenuBar(this);
    setMenuBar(menuBar);



    QMenu* menu_spotSearch = menuBar->addMenu("景点查找");
    QAction* action_spotSearch = new QAction("打开景点查找", this);
    connect(action_spotSearch, &QAction::triggered, this, &MainWindow::onSpotSearchActionTriggered);
    menu_spotSearch->addAction(action_spotSearch);

    QMenu* menu_shortestPath = menuBar->addMenu("最短路径规划");
    QAction* action_shortestPath = new QAction("打开最短路径规划", this);
    connect(action_shortestPath, &QAction::triggered, this, &MainWindow::onShortestPathActionTriggered);
    menu_shortestPath->addAction(action_shortestPath);

    // 使用样式表设置菜单的背景图片
    /*QString styleSheet = QString("QMenuBar { background-color: transparent; }");
    menuBar->setStyleSheet(styleSheet);
    QString menuExpandedStyleSheet = "QMenu { background-color: transparent; }";
    menu_scenicUI->setStyleSheet(menuExpandedStyleSheet);
    menu_spotSearch->setStyleSheet(menuExpandedStyleSheet);
    menu_shortestPath->setStyleSheet(menuExpandedStyleSheet);*/

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCiguanggeButtonClicked()
{
    qDebug() << "慈光阁按钮 clicked!";
}

void MainWindow::onMiaobishenghuaButtonClicked()
{
    qDebug() << "梦笔生花按钮 clicked!";
}

void MainWindow::onYungusiButtonClicked()
{
    qDebug() << "云谷寺按钮 clicked!";
}

void MainWindow::onYingkesongButtonClicked()
{
    qDebug() << "迎客松按钮 clicked!";
}

void MainWindow::onGuangmingdingButtonClicked()
{
    qDebug() << "光明顶按钮 clicked!";
}

void MainWindow::onNandamenButtonClicked()
{
    qDebug() << "南大门按钮 clicked!";
}
void MainWindow::onyupingzhanButtonClicked()
{
    qDebug() << "玉屏站按钮 clicked!";
}
void MainWindow::onbaielingButtonClicked()
{
    qDebug() << "白鹅岭按钮 clicked!";
}

void MainWindow::onScenicUIActionTriggered()
{
    qDebug() << "打开景区UI";
    // 在这里添加打开景区UI的代码
}

void MainWindow::onSpotSearchActionTriggered()
{
    qDebug() << "打开景点查找";
    // 在这里添加打开景点查找的代码
}
void MainWindow::onShortestPathActionTriggered(){
    Dijkstra *dijkstra = new Dijkstra(this);
        dijkstra->show();
}















