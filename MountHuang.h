#pragma once

#include <QtWidgets/QMainWindow>
#include <QMenuBar>
#include<QMessageBox>
#include <QMenu>
#include <QApplication>
#include <QVBoxLayout>
#include<QLabel>
#include<QLineEdit>
#include<QTextBrowser>
#include<QPalette>
#include<QPushButton>
#include "ui_MountHuang.h"
#include<QMap>


#include <QDebug>
#include <qdebug.h>
#include <QToolBar>
#include <QtAlgorithms>
#include <iostream>
#include <windows.h>
#include <QLineEdit>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QComboBox>
#include <QTextEdit>
#include <QVector>
#include <QDialog>
#include <QToolButton>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QGraphicsView>

//QT_BEGIN_NAMESPACE
//namespace Ui { class MountHuang; }
//QT_END_NAMESPACE

class InfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InfoWindow(QWidget* parent = nullptr);

    ~InfoWindow();

private:

};

class Guangmingding :public QMainWindow
{
    Q_OBJECT

public:
    explicit Guangmingding(QWidget* parent = nullptr);

    ~Guangmingding();
};
class Yingkesong :public QMainWindow
{
    Q_OBJECT

public:
    explicit Yingkesong(QWidget* parent = nullptr);

    ~Yingkesong();
};
class Ciguangge :public QMainWindow
{
    Q_OBJECT

public:
    explicit Ciguangge(QWidget* parent = nullptr);

    ~Ciguangge();
};
class Mengbishenghua :public QMainWindow
{
    Q_OBJECT

public:
    explicit Mengbishenghua(QWidget* parent = nullptr);

    ~Mengbishenghua();
};
class Nandamen :public QMainWindow
{
    Q_OBJECT

public:
    explicit Nandamen(QWidget* parent = nullptr);

    ~Nandamen();
};
class Yungusi :public QMainWindow
{
    Q_OBJECT

public:
    explicit Yungusi(QWidget* parent = nullptr);

    ~Yungusi();
};
class Yupingzhan :public QMainWindow
{
    Q_OBJECT

public:
    explicit Yupingzhan(QWidget* parent = nullptr);

    ~Yupingzhan();
};
class Baieling :public QMainWindow
{
    Q_OBJECT

public:
    explicit Baieling(QWidget* parent = nullptr);

    ~Baieling();
};

class search_box : public QMainWindow
{
    Q_OBJECT
public:
    explicit search_box(QWidget* parent = 0);
    void search();


private:
    QLineEdit* search_edit1, * search_edit2;
    QAction* search_action;
    QPushButton* search_btn;
    QTextBrowser* text;
    QMap<QString, QWidget*> keywordMap;

signals:

public slots:

};
//
//class Shortest :public QMainWindow {
//    Q_OBJECT
//public:
//    Shortest(QWidget* parent = nullptr);
//    ~Shortest();
//
//    //最短路径
//    void createToolBar();
//    void createAction();
//    void initScene();
//
//public slots:
//    void FindPath();
//    void Clear();
//
//
//private:
//    //Shortest
//    QLabel* startLabel;
//    QLabel* endLabel;
//    QComboBox* startComboBox;
//    QComboBox* endComboBox;
//    QComboBox* reviseComboBox;
//
//    QAction* findPathAction;
//    QAction* clearAction;
//
//
//    QGraphicsScene* scene;
//    QGraphicsView* view;
//
//
//    int startX, startY, endX, endY;
//    QVector<int> nextPath;
//
//    /*
//     * 图的实现，和最短路径算法声明
//     */
//    struct ArcCell {    //弧信息
//        int adj;       //对无权图有1，0表示是否相邻，对带权图，则为权值类型
//        //    string info; //该弧的相关信息
//    };
//
//
//    //内部类
//    static const int MAX_VERTEX_NUM = 50;
//    static const int INF = 999999;
//
//    struct MGraph {
//        QVector<int> vexs;                                    //顶点集合
//        //临接矩阵
//        ArcCell arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//        int vexnum;                                           //顶点数
//        int arcnum;                                           //边数
//        //    int kind;                                             //图的类型
//    };
//
//    class DijkstraFindPath
//    {
//    public:
//        DijkstraFindPath();
//        MGraph mgraph;
//        void CreateGraph();
//
//        int prev[MAX_VERTEX_NUM];  //最短路上的前驱顶点
//        int d[MAX_VERTEX_NUM];     //表示边e = (u,v)的权值(不存在时为INF,不过d[i][i]=0)
//        bool used[MAX_VERTEX_NUM]; //已经使用过的图
//        void dijkstra(int startPos);      //求从起点startPos出发到各个顶点的最短距离
//        QVector<int> get_Path(int endPos);//到顶点endPos的最短路
//    };
//
//    DijkstraFindPath* dj;
//
//    class PathDisplayWindow : public QDialog
//    {
//
//
//    public:
//        explicit PathDisplayWindow(QWidget* parent = nullptr);
//        void setPathText(const QString& text);
//
//    private:
//        QLabel* pathLabel;
//        QVBoxLayout* mainLayout;
//    };
//    //Ui::MountHuang* ui;
//
//private:
//    QPixmap nandamen;      //南大门
//    QPixmap yungusi;      //云谷寺
//    QPixmap ciguangge;  //慈光阁
//    QPixmap yingkesong;     //迎客松
//    QPixmap guangmingding;   //光明顶
//    QPixmap mengbishenghua;    //梦笔生花
//    QString strPath;      //文件路径
//    QLabel* label;
//};

class Dijkstra : public QMainWindow
{
    Q_OBJECT

public:
    Dijkstra(QWidget* parent = nullptr);
    ~Dijkstra();


    void createToolBar();
    void createAction();
    /*void initScene();*/




public slots:

    void FindPath();
    /*void Clear();*/

private:

    QLabel* startLabel;
    QLabel* endLabel;
    QComboBox* startComboBox;
    QComboBox* endComboBox;
    QComboBox* reviseComboBox;

    QAction* findPathAction;
    QAction* clearAction;


    QGraphicsScene* scene;
    QGraphicsView* view;




    int startX, startY, endX, endY;
    QVector<int> nextPath;

    /*
     * 图的实现，和最短路径算法声明
     */
    struct ArcCell {    //弧信息
        int adj;       //对无权图有1，0表示是否相邻，对带权图，则为权值类型
        //    string info; //该弧的相关信息
    };


    //内部类
    static const int MAX_VERTEX_NUM = 50;
    static const int INF = 999999;

    struct MGraph {
        QVector<int> vexs;                                    //顶点集合
        //临接矩阵
        ArcCell arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
        int vexnum;                                           //顶点数
        int arcnum;                                           //边数
        //    int kind;                                             //图的类型
    };

    class DijkstraFindPath
    {
    public:
        DijkstraFindPath();
        MGraph mgraph;
        void CreateGraph();

        int prev[MAX_VERTEX_NUM];  //最短路上的前驱顶点
        int d[MAX_VERTEX_NUM];     //表示边e = (u,v)的权值(不存在时为INF,不过d[i][i]=0)
        bool used[MAX_VERTEX_NUM]; //已经使用过的图
        void dijkstra(int startPos);      //求从起点startPos出发到各个顶点的最短距离
        QVector<int> get_Path(int endPos);//到顶点endPos的最短路
    };

    DijkstraFindPath* dj;

    class PathDisplayWindow : public QDialog
    {


    public:
        explicit PathDisplayWindow(QWidget* parent = nullptr);
        void setPathText(const QString& text);

    private:
        QLabel* pathLabel;
        QVBoxLayout* mainLayout;
    };



private:
    QPixmap nandamen;      //南大门
    QPixmap yungusi;      //云谷寺
    QPixmap ciguangge;  //慈光阁
    QPixmap yingkesong;     //迎客松
    QPixmap guangmingding;   //光明顶
    QPixmap mengbishenghua;    //梦笔生花
    QString strPath;      //文件路径
    QLabel* label;
};

class MountHuang : public QMainWindow
{
    Q_OBJECT

public:
    MountHuang(QWidget* parent = nullptr);
    ~MountHuang();


private slots:
    //简介
    void onInformationActionTriggered();

    void onCiguanggeButtonClicked();
    void onMengbishenghuaButtonClicked();
    void onYungusiButtonClicked();
    void onYingkesongButtonClicked();
    void onGuangmingdingButtonClicked();
    void onNandamenButtonClicked();
    void onScenicUIActionTriggered();
    void onyupingzhanButtonClicked();
    void onbaielingButtonClicked();

    void onSpotSearchActionTriggered();
    void onShortestPathActionTriggered();

  

    void resizeEvent(QResizeEvent* event)override;


private:
    QWidget* backgroundWidget;
    QList<QPushButton*> buttonList;
    QAction* informationAction;
    InfoWindow* infoWindow;


};



