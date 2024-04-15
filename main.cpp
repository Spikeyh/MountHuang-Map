#include "MountHuang.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MountHuang w;
    //w.setFixedSize(880, 1000); // 设置窗口大小为固定值
    w.setWindowTitle("黄山风景区导览");
    w.show();
    return a.exec();
}
