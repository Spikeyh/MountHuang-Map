#ifndef DIJKSTRA_H
#define DIJKSTRA_H


#include <QMainWindow>
#include <QToolButton>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QComboBox>
#include <QTextEdit>
#include <QVector>
#include <QDialog>
#include <QPixmap>
#include <QGridLayout>
#include <QLineEdit>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QPointF>

QT_BEGIN_NAMESPACE
namespace Ui { class Dijkstra; }
QT_END_NAMESPACE

class Dijkstra : public QMainWindow
{
    Q_OBJECT

public:
    Dijkstra(QWidget *parent = nullptr);
    ~Dijkstra();


    void createToolBar ();
    void createAction();
    void initScene();
    QVector<int> getShortestPath() const {
            return shortestPath;
        }
    QPointF getPointForIndex(int index) const;




public slots:

    void FindPath();
    void Clear();

private:
    Ui::Dijkstra *ui;
    QVector<int> shortestPath;

    QLabel *startLabel;
    QLabel *endLabel;
    QComboBox *startComboBox;
    QComboBox *endComboBox;
    QComboBox *reviseComboBox;

    QAction *findPathAction;
    QAction *clearAction;


    QGraphicsScene *scene;
    QGraphicsView *view;




    int startX, startY, endX, endY;
    QVector<int> nextPath;

    /*
     * 图的实现，和最短路径算法声明
     */
    struct ArcCell{    //弧信息
        int adj;       //对无权图有1，0表示是否相邻，对带权图，则为权值类型
    //    string info; //该弧的相关信息
    };


    //内部类
    static const int MAX_VERTEX_NUM = 50;
    static const int INF = 999999;

    struct MGraph{
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

    DijkstraFindPath *dj;

    class PathDisplayWindow : public QDialog
    {


    public:
        explicit PathDisplayWindow(QWidget *parent = nullptr);
        void setPathText(const QString &text);

    private:
        QLabel *pathLabel;
        QVBoxLayout *mainLayout;
    };



private:
    QPoint nandamen;      //南大门
    QPoint yungusi;      //云谷寺
    QPoint ciguangge ;//慈光阁
    QPoint yingkesong;     //迎客松
    QPoint guangmingding;   //光明顶
    QPoint mengbishenghua;    //梦笔生花
    QPoint yupingzhan;
    QPoint baieling;

    QLabel *label;
};
#endif // DIJKSTRA_H
