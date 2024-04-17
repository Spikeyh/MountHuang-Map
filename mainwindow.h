#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();





private slots:
    void onCiguanggeButtonClicked();
    void onMiaobishenghuaButtonClicked();
    void onYungusiButtonClicked();
    void onYingkesongButtonClicked();
    void onGuangmingdingButtonClicked();
    void onNandamenButtonClicked();
    void onScenicUIActionTriggered();
    void onSpotSearchActionTriggered();
    void onShortestPathActionTriggered();
    void onyupingzhanButtonClicked();
    void onbaielingButtonClicked();



private:
    Ui::MainWindow *ui;




private:
    QPixmap nandamen;      //南大门
    QPixmap yungusi;      //云谷寺
    QPixmap ciguangge;  //慈光阁
    QPixmap yingkesong;     //迎客松
    QPixmap guangmingding;   //光明顶
    QPixmap mengbishenghua;    //梦笔生花
    QString strPath;      //文件路径
    QLabel *label;
};



#endif // MAINWINDOW_H
