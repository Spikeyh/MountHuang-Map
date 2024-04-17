#include "dijkstra.h"
#include <QPushButton>
#include <QDebug>
#include <qdebug.h>
#include <QToolBar>
#include <QtAlgorithms>
#include <iostream>
#include <windows.h>
#include <QTimer>
Dijkstra::Dijkstra(QWidget *parent)
    : QMainWindow(parent)

{
    setWindowTitle ("黄山导航");
       dj = new Dijkstra::DijkstraFindPath();
       dj->CreateGraph ();

       scene = new QGraphicsScene;
       initScene();

       view = new QGraphicsView;
       view->setScene (scene);
       view->setMinimumSize (720, 600);
       view->show ();
       setCentralWidget (view);

       createAction ();
       createToolBar ();           //实现一个工具栏

       Sleep(2000);
}
Dijkstra::~Dijkstra()
{
    delete dj;
}
Dijkstra::PathDisplayWindow::PathDisplayWindow(QWidget *parent) : QDialog(parent)
{
    pathLabel = new QLabel(this);
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(pathLabel);
}

void Dijkstra::PathDisplayWindow::setPathText(const QString &text)
{
    pathLabel->setText(text);
}

void Dijkstra::initScene() {
    // 加载地图图片
       QGraphicsPixmapItem *item = scene->addPixmap(QPixmap("F:\\qt\\黄山.jpg"));
       item->setPos(0, 50);

       // 绘制最短路径曲线
       QPainterPath path;
       for (int i = 0; i < shortestPath.size(); ++i) {
           QPointF point = getPointForIndex(shortestPath[i]);
           if (i == 0) {
               path.moveTo(point);
           } else {
               path.lineTo(point);
           }
       }
       scene->addPath(path, QPen(Qt::red, 2));

}


Dijkstra::DijkstraFindPath::DijkstraFindPath()
{
    mgraph.vexnum = 40;                        //初始化点数目
       for (int i = 0; i < mgraph.vexnum; i++) //初始化点编号
           mgraph.vexs.push_back (i);
       mgraph.arcnum = 98;                     //暂定
       for (int i = 0; i < mgraph.vexnum; i++) {
           for (int j = 0; j < mgraph.vexnum; j++) {
               if (i == j)
                   mgraph.arcs[i][j].adj = 0;
               else
                   mgraph.arcs[i][j].adj = INF;
   //            mgraph.arcs[i][j].info = "";
           }
       }
}

void Dijkstra::DijkstraFindPath::CreateGraph ()
{
        mgraph.arcs[0][1].adj = mgraph.arcs[1][0].adj = 374;    //南大门0-云谷寺1
        mgraph.arcs[0][2].adj = mgraph.arcs[2][0].adj = 306;   //南大门0-慈光阁2
        mgraph.arcs[1][2].adj = mgraph.arcs[2][1].adj = 642;    //云谷寺1-慈光阁2
        mgraph.arcs[2][3].adj = mgraph.arcs[3][2].adj = 252;    //慈光阁2-迎客松3
        mgraph.arcs[3][4].adj = mgraph.arcs[4][3].adj = 244;    //迎客松3-光明顶4
        mgraph.arcs[4][5].adj = mgraph.arcs[5][4].adj = 208;  //光明顶4-梦笔生花5
        mgraph.arcs[1][5].adj = mgraph.arcs[5][1].adj = 370;  //梦笔生花5-云谷寺1
        mgraph.arcs[2][6].adj = mgraph.arcs[6][2].adj = 378;  //慈光阁2-玉屏站6
        mgraph.arcs[3][6].adj = mgraph.arcs[6][3].adj = 182;  //玉屏站6-迎客松3
        mgraph.arcs[1][7].adj = mgraph.arcs[7][1].adj = 106;  //云谷寺1-白鹅岭7
        mgraph.arcs[5][7].adj = mgraph.arcs[7][5].adj = 188;  //白鹅岭7-梦笔生花5



}

void Dijkstra::DijkstraFindPath::dijkstra (int startPos)
{
    for (int i = 0; i < mgraph.vexnum; i++) d[i] = INF;
    for (int i = 0; i < mgraph.vexnum; i++) used[i] = false;
    for (int i = 0; i < mgraph.vexnum; i++) prev[i] = -1;
    d[startPos] = 0;

    while (true) {
        int v = -1;
        for (int u = 0; u < mgraph.vexnum; u++) {
            if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }

        if (v == -1) break;
        used[v] = true;

        for (int u = 0; u < mgraph.vexnum; u++) {
            if (d[u] > d[v] + mgraph.arcs[v][u].adj) {
                d[u] = d[v] + mgraph.arcs[v][u].adj;
                prev[u] = v;
            }
        }
    }
}

QVector<int> Dijkstra::DijkstraFindPath::get_Path (int endPos)
{
    QVector<int> path;

    for ( ; endPos != -1; endPos = prev[endPos]) {
//        std::cout << "EndPos: " << endPos << ", ";
        path.push_back (endPos);
    }

    std::reverse(path.begin (), path.end ());

    return path;
}


void Dijkstra::createAction ()
{
    findPathAction = new QAction(QIcon("F:\\qt\\Search.png"),tr("搜索路径"), this);
    findPathAction->setShortcut (tr("Ctrl+F"));
    findPathAction->setStatusTip (tr("搜索路径"));
    connect (findPathAction, SIGNAL(triggered(bool)), this, SLOT(FindPath()));
}

void Dijkstra::createToolBar ()
{
    QToolBar *toolBar = addToolBar ("Tool");
    startLabel = new QLabel(tr("起点: "));
    startComboBox = new QComboBox;
    startComboBox->addItem (tr("南大门"));  //0
    startComboBox->addItem (tr("云谷寺"));  //1
    startComboBox->addItem (tr("慈光阁"));  //2
    startComboBox->addItem (tr("迎客松"));  //3
    startComboBox->addItem (tr("光明顶"));  //4
    startComboBox->addItem (tr("梦笔生花"));  //5

    startComboBox->addItem (tr("玉屏站")); //6
    startComboBox->addItem (tr("白鹅岭"));  //7


    endLabel = new QLabel(tr("终点: "));

    endComboBox = new QComboBox;
    endComboBox->addItem (tr("南大门"));
    endComboBox->addItem (tr("云谷寺"));
    endComboBox->addItem (tr("慈光阁"));
    endComboBox->addItem (tr("迎客松"));
    endComboBox->addItem (tr("光明顶"));
    endComboBox->addItem (tr("梦笔生花"));
    endComboBox->addItem (tr("玉屏站"));
    endComboBox->addItem (tr("白鹅岭"));




    toolBar->addWidget (startLabel);
    toolBar->addWidget (startComboBox);
    toolBar->addSeparator ();
    toolBar->addWidget (endLabel);
    toolBar->addWidget (endComboBox);
    toolBar->addSeparator ();
    toolBar->addAction(findPathAction);
    toolBar->addSeparator ();


}


QString getSpotName(int spotIndex) {
    QString spotName;
    switch (spotIndex) {
    case 0:
        spotName = "南大门"; break;
    case 1:
        spotName = "云谷寺"; break;
    case 2:
        spotName = "慈光阁"; break;
    case 3:
        spotName = "迎客松"; break;
    case 4:
        spotName = "光明顶"; break;
    case 5:
        spotName = "梦笔生花"; break;
    case 6:
        spotName = "玉屏站"; break;
    case 7:
        spotName = "白鹅岭"; break;
    default:
        spotName = "未知景点"; break;
    }
    return spotName;
}

void Dijkstra::FindPath()
{
    // 执行 Dijkstra 算法找到最短路径
        dj->dijkstra(startComboBox->currentIndex());

        // 获取最短路径的景点索引
        shortestPath = dj->get_Path(endComboBox->currentIndex());


        Clear();

        //文字输出
        QString pathText = "最短路径为：\n";
            for (int i = 0; i < shortestPath.size(); i++) {
                pathText += getSpotName(shortestPath[i]) + "\n";
            }

            // 创建并显示路径信息窗口
            PathDisplayWindow *pathWindow = new PathDisplayWindow(this);
            pathWindow->setWindowTitle("最短路径信息");
            pathWindow->setPathText(pathText);
            pathWindow->show();

}


void Dijkstra::Clear ()
{
    QList<QGraphicsItem*> listItem = scene->items();
       while (!listItem.empty()) {
           scene->removeItem(listItem.at(0));
           delete listItem.at(0);
           listItem.removeAt(0);
       }
       initScene();
}
QPointF Dijkstra::getPointForIndex(int index)const{
    QPoint nandamen(744, 1158);       // 南大门
    QPoint yungusi(908, 1008);        // 云谷寺
    QPoint ciguangge(270, 1060);      // 慈光阁
    QPoint yingkesong(324, 856);      // 迎客松
    QPoint guangmingding(486, 632);   // 光明顶
    QPoint mengbishenghua(818, 634);  // 梦笔生花
    QPoint yupingzhan(214, 794);      // 玉屏站
    QPoint baieling(914, 778);        // 白鹅岭
    switch (index) {
           case 0:
               return nandamen;
           case 1:
               return yungusi;
           case 2:
               return ciguangge;
           case 3:
               return yingkesong;
           case 4:
               return guangmingding;
           case 5:
               return mengbishenghua;
           case 6:
               return yupingzhan;
    case 7:
        return baieling;
           default:
               return QPointF(0, 0); // 如果索引无效，返回原点作为默认值

}
}
