#include "MountHuang.h"
#include <QPushButton>
#include <QDebug>
#include <QResizeEvent>


MountHuang::MountHuang(QWidget* parent)
    : QMainWindow(parent)
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
    connect(button_ciguangge, &QPushButton::clicked, this, &MountHuang::onCiguanggeButtonClicked);

    QPushButton* button_miaobishenghua = new QPushButton("", this);
    button_miaobishenghua->setGeometry(QRect(QPoint(409, 317), QSize(20, 20)));
    button_miaobishenghua->setStyleSheet("border-image: url(image/buttonbackground.jpg);border-radius: 10px;");
    connect(button_miaobishenghua, &QPushButton::clicked, this, &MountHuang::onMengbishenghuaButtonClicked);

    QPushButton* button_yungusi = new QPushButton("", this);
    button_yungusi->setGeometry(QRect(QPoint(454, 504), QSize(50, 50)));
    button_yungusi->setStyleSheet("border-image: url(image/buttonbackground.jpg);border-radius: 25px;");
    connect(button_yungusi, &QPushButton::clicked, this, &MountHuang::onYungusiButtonClicked);

    QPushButton* button_yingkesong = new QPushButton("", this);
    button_yingkesong->setGeometry(QRect(QPoint(162, 428), QSize(20, 20)));
    button_yingkesong->setStyleSheet("border-image: url(image/buttonbackground.jpg);border-radius: 10px;");
    connect(button_yingkesong, &QPushButton::clicked, this, &MountHuang::onYingkesongButtonClicked);

    QPushButton* button_guangmingding = new QPushButton("", this);
    button_guangmingding->setGeometry(QRect(QPoint(243, 316), QSize(20, 20)));
    button_guangmingding->setStyleSheet("border-image: url(image/buttonbackground.jpg);border-radius: 10px;");
    connect(button_guangmingding, &QPushButton::clicked, this, &MountHuang::onGuangmingdingButtonClicked);

    QPushButton* button_nandamen = new QPushButton("", this);
    button_nandamen->setGeometry(QRect(QPoint(372, 579), QSize(20, 20)));
    button_nandamen->setStyleSheet("border-image: url(image/buttonbackground.jpg);border-radius: 10px;");
    connect(button_nandamen, &QPushButton::clicked, this, &MountHuang::onNandamenButtonClicked);

    QPushButton* button_yupingzhan = new QPushButton("", this);
    button_yupingzhan->setGeometry(QRect(QPoint(107, 397), QSize(20, 20)));
    button_yupingzhan->setStyleSheet("border-image: url(image/buttonbackground.jpg);border-radius: 10px;");
    connect(button_yupingzhan, &QPushButton::clicked, this, &MountHuang::onyupingzhanButtonClicked);

    QPushButton* button_baieling = new QPushButton("", this);
    button_baieling->setGeometry(QRect(QPoint(457, 389), QSize(20, 20)));
    button_baieling->setStyleSheet("border-image: url(image/buttonbackground.jpg);border-radius: 10px;");
    connect(button_baieling, &QPushButton::clicked, this, &MountHuang::onbaielingButtonClicked);

    QMenuBar* menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    // 创建菜单
    QMenu* menu_scenicUI = menuBar->addMenu("景区介绍");
    QAction* action_scenicUI = new QAction("打开景区介绍", this);
    connect(action_scenicUI, &QAction::triggered, this, &MountHuang::onInformationActionTriggered);
    menu_scenicUI->addAction(action_scenicUI);

    QMenu* menu_spotSearch = menuBar->addMenu("景点查找");
    QAction* action_spotSearch = new QAction("打开景点查找", this);
    connect(action_spotSearch, &QAction::triggered, this, &MountHuang::onSpotSearchActionTriggered);
    menu_spotSearch->addAction(action_spotSearch);

    QMenu* menu_shortestPath = menuBar->addMenu("最短路径规划");
    QAction* action_shortestPath = new QAction("打开最短路径规划", this);
    connect(action_shortestPath, &QAction::triggered, this, &MountHuang::onShortestPathActionTriggered);
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

MountHuang::~MountHuang()
{}

void MountHuang::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);

    //for (QPushButton* button : buttonList) {
    //    // 获取按钮的原始位置和大小
    //    QRect oldGeometry = button->geometry();

    //    QSize newSize = event->size();
    //    // 计算按钮的新位置和大小
    //    int newButtonX = (oldGeometry.x() / 600.0) * newSize.width();  // 假设原窗口宽度为600
    //    int newButtonY = (oldGeometry.y() / 720.0) * newSize.height(); // 假设原窗口高度为720
    //    int newButtonWidth = (oldGeometry.width() / 600.0) * newSize.width();  // 假设原窗口宽度为600
    //    int newButtonHeight = (oldGeometry.height() / 720.0) * newSize.height(); // 假设原窗口高度为720

    //    // 设置按钮的新位置和大小
    //    button->setGeometry(QRect(QPoint(newButtonX, newButtonY), QSize(newButtonWidth, newButtonHeight)));
    //}

    QPixmap pixmap = QPixmap("image/map2.jpg").scaled(this->size());
    QPalette palette;

    // 将QPixmap设置为背景
    palette.setBrush(QPalette::Window, QBrush(pixmap));

    // 应用QPalette到QWidget
   this->setPalette(palette);   
}

void MountHuang::onInformationActionTriggered()
{
    InfoWindow* infoWindow = new InfoWindow(this);
    infoWindow->show();
}
InfoWindow::InfoWindow(QWidget* parent) : QMainWindow(parent)
{
    setFixedSize(600,720);
    setWindowTitle("Basic Information");

    QWidget* centralWidget = new QWidget(this);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(10);

    //QVBoxLayout* imageAndTextLayout = new QVBoxLayout();
    QLabel* imageLabel = new QLabel(this);
    QPixmap image=QPixmap("image/MountHuang.jpg").scaled(this->size()); // 替换为您的图片路径=
    imageLabel->setPixmap(image);
    //imageLabel->setScaledContents(true); // 保持图片比例
    mainLayout->addWidget(imageLabel);

    QLabel* descriptionLabel = new QLabel(u8"    黄山，位于中国安徽省南部，是中国著名的风景名胜区和世界自然与文化双重遗产地。黄山以其奇松、怪石、云海、温泉、冬雪“五绝”闻名于世，被誉为“中国山水之冠”。", centralWidget);
    descriptionLabel->setFont(QFont("Arial", 12)); // 设置文字字体和大小
    descriptionLabel->setWordWrap(true); // 开启自动换行
    //descriptionLabel->setStyleSheet("QLabel { padding-left: 10px; }");// 设置首行缩进，这里假设我们想要缩进10像素
    mainLayout->addWidget(descriptionLabel);

    QPushButton* myButton = new QPushButton(u8"语音介绍", centralWidget);
    myButton->setStyleSheet("QPushButton {"
        "border: 2px solid black;"     // 按钮边框
        "font-size: 14px;"            // 按钮字体大小
        "padding: 5px;"                // 按钮内边距
        "border-radius: 10px;"        // 按钮边框圆角
        "color: black;"               // 按钮文本颜色
        "}"
        "QPushButton:pressed {"
        "background-color: darkorange;" // 按钮按下时的背景颜色
        "}");
    mainLayout->addWidget(myButton); // 将按钮添加到imageAndTextLayout
    //buttonLayout->addWidget(myButton);

    // 将按钮布局添加到主布局
    mainLayout->addLayout(mainLayout);

    // 设置中心部件的布局
    centralWidget->setLayout(mainLayout);

    // 设置中心部件
    setCentralWidget(centralWidget);
}
InfoWindow::~InfoWindow() {};

void MountHuang::onCiguanggeButtonClicked()
{
    Ciguangge* ciguangge = new Ciguangge(this);
    ciguangge->show();
}
Ciguangge::Ciguangge(QWidget* parent) : QMainWindow(parent)
{
    setFixedSize(600, 720);
    setWindowTitle(u8"慈光阁");

    QWidget* centralWidget = new QWidget(this);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(10);

    //QVBoxLayout* imageAndTextLayout = new QVBoxLayout();
    QLabel* imageLabel = new QLabel(this);
    QPixmap image = QPixmap(u8"image/Ciguangge.jpg").scaled(this->size()); // 替换为您的图片路径=
    imageLabel->setPixmap(image);
    //imageLabel->setScaledContents(true); // 保持图片比例
    mainLayout->addWidget(imageLabel);

    QLabel* descriptionLabel = new QLabel(u8"    慈光阁古称朱砂庵，原为法海寺，是黄山风景区前山登山或索道的起点。也是门票售票点。", centralWidget);
    descriptionLabel->setFont(QFont("Arial", 12)); // 设置文字字体和大小
    descriptionLabel->setWordWrap(true); // 开启自动换行
    //descriptionLabel->setStyleSheet("QLabel { padding-left: 10px; }");// 设置首行缩进，这里假设我们想要缩进10像素
    mainLayout->addWidget(descriptionLabel);

    QPushButton* myButton = new QPushButton(u8"语音介绍", centralWidget);
    myButton->setStyleSheet("QPushButton {"
        "border: 2px solid black;"     // 按钮边框
        "font-size: 14px;"            // 按钮字体大小
        "padding: 5px;"                // 按钮内边距
        "border-radius: 10px;"        // 按钮边框圆角
        "color: black;"               // 按钮文本颜色
        "}"
        "QPushButton:pressed {"
        "background-color: darkorange;" // 按钮按下时的背景颜色
        "}");
    mainLayout->addWidget(myButton);
    mainLayout->addLayout(mainLayout);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}
Ciguangge::~Ciguangge() {};

void MountHuang::onMengbishenghuaButtonClicked()
{
    Mengbishenghua* mengbishenghua = new Mengbishenghua(this);
    mengbishenghua->show();
}
Mengbishenghua::Mengbishenghua(QWidget* parent) : QMainWindow(parent)
{
    setFixedSize(600, 720);
    setWindowTitle(u8"梦笔生花");

    QWidget* centralWidget = new QWidget(this);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(10);

    //QVBoxLayout* imageAndTextLayout = new QVBoxLayout();
    QLabel* imageLabel = new QLabel(this);
    QPixmap image = QPixmap(u8"image/Mengbishenghua.jpg").scaled(this->size()); // 替换为您的图片路径=
    imageLabel->setPixmap(image);
    //imageLabel->setScaledContents(true); // 保持图片比例
    mainLayout->addWidget(imageLabel);

    QLabel* descriptionLabel = new QLabel(u8"    传说李白深感长老待人诚恳，意欲草书诗作相赠，以作答谢之礼。长老大喜，小和尚们忙着研墨的研墨，铺纸的铺纸。李白趁着酒兴，奋笔疾书。长老及小和尚们分站两旁，目睹那遒劲的大字，赞叹不已。李白写毕，还有三分酒意，便将毛笔顺手一掷，那毛笔翻翻摇摇，从空中落下插入土中。他这才告辞长老而去。长老送走李白，回过头来，不禁大吃一惊，刚才李白掷下的毛笔已化成一座笔峰，笔尖化成了一棵松树，矗立在散花坞中。这就是如今见到的“梦笔生花。", centralWidget);
    descriptionLabel->setFont(QFont("Arial", 12)); // 设置文字字体和大小
    descriptionLabel->setWordWrap(true); // 开启自动换行
    //descriptionLabel->setStyleSheet("QLabel { padding-left: 10px; }");// 设置首行缩进，这里假设我们想要缩进10像素
    mainLayout->addWidget(descriptionLabel);

    QPushButton* myButton = new QPushButton(u8"语音介绍", centralWidget);
    myButton->setStyleSheet("QPushButton {"
        "border: 2px solid black;"     // 按钮边框
        "font-size: 14px;"            // 按钮字体大小
        "padding: 5px;"                // 按钮内边距
        "border-radius: 10px;"        // 按钮边框圆角
        "color: black;"               // 按钮文本颜色
        "}"
        "QPushButton:pressed {"
        "background-color: darkorange;" // 按钮按下时的背景颜色
        "}");
    mainLayout->addWidget(myButton);
    mainLayout->addLayout(mainLayout);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}
Mengbishenghua::~Mengbishenghua() {};

void MountHuang::onYungusiButtonClicked()
{
    Yungusi* yungusi = new Yungusi(this);
    yungusi->show();
}
Yungusi::Yungusi(QWidget* parent) : QMainWindow(parent)
{
    setFixedSize(600, 720);
    setWindowTitle(u8"云谷寺");

    QWidget* centralWidget = new QWidget(this);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(10);

    //QVBoxLayout* imageAndTextLayout = new QVBoxLayout();
    QLabel* imageLabel = new QLabel(this);
    QPixmap image = QPixmap(u8"image/Yungusi.jpg").scaled(this->size()); // 替换为您的图片路径=
    imageLabel->setPixmap(image);
    //imageLabel->setScaledContents(true); // 保持图片比例
    mainLayout->addWidget(imageLabel);

    QLabel* descriptionLabel = new QLabel(u8"    云谷寺位于黄山钵盂峰下，罗汉峰和香炉峰之间，海拔890米。今寺已不存，旧址上盖有宾馆，自东路登山者在此小憩，可远眺变幻风云奇景，品尝黄山毛峰名茶。在此建登山索道。并建有“云谷山庄”宾馆。是黄山的后山登山处。", centralWidget);
    descriptionLabel->setFont(QFont("Arial", 12)); // 设置文字字体和大小
    descriptionLabel->setWordWrap(true); // 开启自动换行
    //descriptionLabel->setStyleSheet("QLabel { padding-left: 10px; }");// 设置首行缩进，这里假设我们想要缩进10像素
    mainLayout->addWidget(descriptionLabel);

    QPushButton* myButton = new QPushButton(u8"语音介绍", centralWidget);
    myButton->setStyleSheet("QPushButton {"
        "border: 2px solid black;"     // 按钮边框
        "font-size: 14px;"            // 按钮字体大小
        "padding: 5px;"                // 按钮内边距
        "border-radius: 10px;"        // 按钮边框圆角
        "color: black;"               // 按钮文本颜色
        "}"
        "QPushButton:pressed {"
        "background-color: darkorange;" // 按钮按下时的背景颜色
        "}");
    mainLayout->addWidget(myButton);
    mainLayout->addLayout(mainLayout);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}
Yungusi::~Yungusi() {};

void MountHuang::onYingkesongButtonClicked()
{
    Yingkesong* yingkesong = new Yingkesong(this);
    yingkesong->show();
}
Yingkesong::Yingkesong(QWidget* parent) : QMainWindow(parent)
{
    setFixedSize(600, 720);
    setWindowTitle(u8"迎客松");

    QWidget* centralWidget = new QWidget(this);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(10);

    //QVBoxLayout* imageAndTextLayout = new QVBoxLayout();
    QLabel* imageLabel = new QLabel(this);
    QPixmap image = QPixmap(u8"image/Yingkesong.jpg").scaled(this->size()); // 替换为您的图片路径=
    imageLabel->setPixmap(image);
    //imageLabel->setScaledContents(true); // 保持图片比例
    mainLayout->addWidget(imageLabel);

    QLabel* descriptionLabel = new QLabel(u8"    迎客松在黄山玉屏楼右侧、文殊洞之上，倚青狮石破石而生，高10.2米，胸径0.64米，地径75厘米，枝下高2.5米，树龄至少已有1300年，是黄山“五绝”之一。其一侧枝桠伸出，如人伸出一只臂膀欢迎远道而来的客人，另一只手优雅地斜插在裤兜里，雍容大度，姿态优美。", centralWidget);
    descriptionLabel->setFont(QFont("Arial", 12)); // 设置文字字体和大小
    descriptionLabel->setWordWrap(true); // 开启自动换行
    //descriptionLabel->setStyleSheet("QLabel { padding-left: 10px; }");// 设置首行缩进，这里假设我们想要缩进10像素
    mainLayout->addWidget(descriptionLabel);

    QPushButton* myButton = new QPushButton(u8"语音介绍", centralWidget);
    myButton->setStyleSheet("QPushButton {"
        "border: 2px solid black;"     // 按钮边框
        "font-size: 14px;"            // 按钮字体大小
        "padding: 5px;"                // 按钮内边距
        "border-radius: 10px;"        // 按钮边框圆角
        "color: black;"               // 按钮文本颜色
        "}"
        "QPushButton:pressed {"
        "background-color: darkorange;" // 按钮按下时的背景颜色
        "}");
    mainLayout->addWidget(myButton);
    mainLayout->addLayout(mainLayout);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}
Yingkesong::~Yingkesong() {};

void MountHuang::onGuangmingdingButtonClicked()
{
    Guangmingding* guangmingding = new Guangmingding(this);
    guangmingding->show();
}
Guangmingding::Guangmingding(QWidget* parent) : QMainWindow(parent)
{
    setFixedSize(600, 720);
    setWindowTitle(u8"光明顶");

    QWidget* centralWidget = new QWidget(this);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(10);

    //QVBoxLayout* imageAndTextLayout = new QVBoxLayout();
    QLabel* imageLabel = new QLabel(this);
    QPixmap image = QPixmap(u8"image/Guangmingding.jpeg").scaled(this->size()); // 替换为您的图片路径=
    imageLabel->setPixmap(image);
    //imageLabel->setScaledContents(true); // 保持图片比例
    mainLayout->addWidget(imageLabel);

    QLabel* descriptionLabel = new QLabel(u8"    光明顶是黄山的主峰之一。位于黄山中部，海拔1860米，为黄山第二高峰。顶上平坦而高旷，可观东海奇景、西海群峰，炼丹、天都、莲花、玉屏、鳌鱼诸峰尽收眼底。", centralWidget);
    descriptionLabel->setFont(QFont("Arial", 12)); // 设置文字字体和大小
    descriptionLabel->setWordWrap(true); // 开启自动换行
    //descriptionLabel->setStyleSheet("QLabel { padding-left: 10px; }");// 设置首行缩进，这里假设我们想要缩进10像素
    mainLayout->addWidget(descriptionLabel);

    QPushButton* myButton = new QPushButton(u8"语音介绍", centralWidget);
    myButton->setStyleSheet("QPushButton {"
        "border: 2px solid black;"     // 按钮边框
        "font-size: 14px;"            // 按钮字体大小
        "padding: 5px;"                // 按钮内边距
        "border-radius: 10px;"        // 按钮边框圆角
        "color: black;"               // 按钮文本颜色
        "}"
        "QPushButton:pressed {"
        "background-color: darkorange;" // 按钮按下时的背景颜色
        "}");
    mainLayout->addWidget(myButton);
    mainLayout->addLayout(mainLayout);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}
Guangmingding::~Guangmingding() {};

void MountHuang::onNandamenButtonClicked()
{
    Nandamen* nandamen = new Nandamen(this);
    nandamen->show();
}
Nandamen::Nandamen(QWidget* parent) : QMainWindow(parent)
{
    setFixedSize(600, 720);
    setWindowTitle(u8"南大门");

    QWidget* centralWidget = new QWidget(this);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(10);

    //QVBoxLayout* imageAndTextLayout = new QVBoxLayout();
    QLabel* imageLabel = new QLabel(this);
    QPixmap image = QPixmap(u8"image/Nandamen.jpg").scaled(this->size()); // 替换为您的图片路径=
    imageLabel->setPixmap(image);
    //imageLabel->setScaledContents(true); // 保持图片比例
    mainLayout->addWidget(imageLabel);

    QLabel* descriptionLabel = new QLabel(u8"    黄山风景区方圆160.6平方公里群峰林立、壁立千仞、历史上自然形成4个进出景区的通道，其中南向进山道路溯逍遥而上、被称之为黄山南大门。", centralWidget);
    descriptionLabel->setFont(QFont("Arial", 12)); // 设置文字字体和大小
    descriptionLabel->setWordWrap(true); // 开启自动换行
    //descriptionLabel->setStyleSheet("QLabel { padding-left: 10px; }");// 设置首行缩进，这里假设我们想要缩进10像素
    mainLayout->addWidget(descriptionLabel);

    QPushButton* myButton = new QPushButton(u8"语音介绍", centralWidget);
    myButton->setStyleSheet("QPushButton {"
        "border: 2px solid black;"     // 按钮边框
        "font-size: 14px;"            // 按钮字体大小
        "padding: 5px;"                // 按钮内边距
        "border-radius: 10px;"        // 按钮边框圆角
        "color: black;"               // 按钮文本颜色
        "}"
        "QPushButton:pressed {"
        "background-color: darkorange;" // 按钮按下时的背景颜色
        "}");
    mainLayout->addWidget(myButton);
    mainLayout->addLayout(mainLayout);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}
Nandamen::~Nandamen() {};

void MountHuang::onyupingzhanButtonClicked()
{
    Yupingzhan* yupingzhan = new Yupingzhan(this);
    yupingzhan->show();
}
Yupingzhan::Yupingzhan(QWidget* parent) : QMainWindow(parent)
{
    setFixedSize(600, 720);
    setWindowTitle(u8"玉屏站");

    QWidget* centralWidget = new QWidget(this);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(10);

    //QVBoxLayout* imageAndTextLayout = new QVBoxLayout();
    QLabel* imageLabel = new QLabel(this);
    QPixmap image = QPixmap(u8"image/Yupingzhan.jpg").scaled(this->size()); // 替换为您的图片路径=
    imageLabel->setPixmap(image);
    //imageLabel->setScaledContents(true); // 保持图片比例
    mainLayout->addWidget(imageLabel);

    QLabel* descriptionLabel = new QLabel(u8"    黄山玉屏峰位于安徽省黄山，玉屏峰介于天都、莲花峰间，为36小峰之一，海拔1716米。峰壁如玉雕屏障，故名“玉屏峰”。玉屏站在迎客松旁，为下山坐索道之处。", centralWidget);
    descriptionLabel->setFont(QFont("Arial", 12)); // 设置文字字体和大小
    descriptionLabel->setWordWrap(true); // 开启自动换行
    //descriptionLabel->setStyleSheet("QLabel { padding-left: 10px; }");// 设置首行缩进，这里假设我们想要缩进10像素
    mainLayout->addWidget(descriptionLabel);

    QPushButton* myButton = new QPushButton(u8"语音介绍", centralWidget);
    myButton->setStyleSheet("QPushButton {"
        "border: 2px solid black;"     // 按钮边框
        "font-size: 14px;"            // 按钮字体大小
        "padding: 5px;"                // 按钮内边距
        "border-radius: 10px;"        // 按钮边框圆角
        "color: black;"               // 按钮文本颜色
        "}"
        "QPushButton:pressed {"
        "background-color: darkorange;" // 按钮按下时的背景颜色
        "}");
    mainLayout->addWidget(myButton);
    mainLayout->addLayout(mainLayout);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}
Yupingzhan::~Yupingzhan() {};

void MountHuang::onbaielingButtonClicked()
{
    Baieling* baieling = new Baieling(this);
    baieling->show();
}
Baieling::Baieling(QWidget* parent) : QMainWindow(parent)
{
    setFixedSize(600, 720);
    setWindowTitle(u8"白鹅岭");

    QWidget* centralWidget = new QWidget(this);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(10);

    //QVBoxLayout* imageAndTextLayout = new QVBoxLayout();
    QLabel* imageLabel = new QLabel(this);
    QPixmap image = QPixmap(u8"image/Baieling.jpg").scaled(this->size()); // 替换为您的图片路径=
    imageLabel->setPixmap(image);
    //imageLabel->setScaledContents(true); // 保持图片比例
    mainLayout->addWidget(imageLabel);

    QLabel* descriptionLabel = new QLabel(u8"    白鹅岭位于白鹅峰与贡阳山之间，是东海与北海的分水岭， 云谷索道的上站在白鹅岭东500米，是观东海云海的最佳处。", centralWidget);
    descriptionLabel->setFont(QFont("Arial", 12)); // 设置文字字体和大小
    descriptionLabel->setWordWrap(true); // 开启自动换行
    //descriptionLabel->setStyleSheet("QLabel { padding-left: 10px; }");// 设置首行缩进，这里假设我们想要缩进10像素
    mainLayout->addWidget(descriptionLabel);

    QPushButton* myButton = new QPushButton(u8"语音介绍", centralWidget);
    myButton->setStyleSheet("QPushButton {"
        "border: 2px solid black;"     // 按钮边框
        "font-size: 14px;"            // 按钮字体大小
        "padding: 5px;"                // 按钮内边距
        "border-radius: 10px;"        // 按钮边框圆角
        "color: black;"               // 按钮文本颜色
        "}"
        "QPushButton:pressed {"
        "background-color: darkorange;" // 按钮按下时的背景颜色
        "}");
    mainLayout->addWidget(myButton);
    mainLayout->addLayout(mainLayout);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}
Baieling::~Baieling() {};

void MountHuang::onScenicUIActionTriggered()
{
}

void MountHuang::onSpotSearchActionTriggered() {
    search_box* search = new search_box(this);
    search->show();
}

//槽函数，用于执行搜索匹配的逻辑
void search_box::search() {
    // 获取用户输入的内容
    QString userInput = search_edit2->text();

    bool found = false;

    // Iterate through the map to find matching keywords
    for (auto it = keywordMap.begin(); it != keywordMap.end(); ++it) {
        if (userInput.contains(it.key())) {
            it.value()->show(); // Show the corresponding destination
            found = true;
        }
    }
    // If no match found, display a message box
    if (!found) {
        // 创建消息框对象并设置标题和内容
        QMessageBox msgBox;
        msgBox.setWindowTitle("提示");
        msgBox.setText("未找到任何信息");
        // 设置消息框的图标
        msgBox.setIcon(QMessageBox::Information);

        // 向消息框添加按钮
        msgBox.setStandardButtons(QMessageBox::Ok);
        // 设置默认按钮
        msgBox.setDefaultButton(QMessageBox::Ok);
        // 弹出消息框并等待用户响应
        int ret = msgBox.exec();
        // 根据用户响应进行处理
        if (ret == QMessageBox::Ok) {
            // 用户点击了确定按钮，可以继续其他操作
        }
    }
}
search_box::search_box(QWidget* parent) : QMainWindow(parent)
{
    this->setWindowIcon(QIcon("image/search.png"));
    this->resize(500, 200);
    this->setWindowTitle("搜索功能");

    keywordMap.insert("南大门", new Nandamen(this));//修改为Nandamen，测试用的
    keywordMap.insert("云谷寺", new Yungusi(this));
    keywordMap.insert("慈光阁", new Ciguangge(this));
    keywordMap.insert("迎客松", new Yingkesong(this));
    keywordMap.insert("光明顶", new Guangmingding(this));
    keywordMap.insert("梦笔生花", new Mengbishenghua(this));

     //QAction
    search_action = new QAction;
    search_action->setToolTip("搜索");//设置鼠标悬浮的提示
    search_action->setIcon(QIcon("image/search.png"));//加载显示图片

    // 创建一个 QWidget 作为 central widget
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // 创建一个布局管理器，将搜索框放置在其中并设置居中对齐
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    layout->setAlignment(Qt::AlignCenter);

    // 编辑框
    search_edit2 = new QLineEdit(centralWidget);
    search_edit2->setFixedWidth(400); // 设置编辑框宽度
    search_edit2->setFixedHeight(50);
    search_edit2->setPlaceholderText("请输入您要搜索的内容");

    // 添加编辑框到布局管理器
    layout->addWidget(search_edit2);

    //TrailingPosition:将action放置在右边
    search_edit2->addAction(search_action, QLineEdit::TrailingPosition);

    //鼠标点击触发
    connect(search_action, &QAction::triggered, this, &search_box::search);
    // 连接编辑框的 returnPressed() 信号到槽函数，以便通过回车键触发搜索
    connect(search_edit2, &QLineEdit::returnPressed, this, &search_box::search);
}



void MountHuang::onShortestPathActionTriggered() {
    Dijkstra* dijkstra = new Dijkstra(this);
    dijkstra->show();
}

//Shortest
//
//Shortest::Shortest(QWidget* parent) :QMainWindow(parent) {
//    setWindowTitle("黄山导航");
//    setMinimumSize(600,720);
//
//}

Dijkstra::Dijkstra(QWidget* parent) : QMainWindow(parent)
{
    setMinimumSize(600, 720);
    setWindowTitle("黄山导航");
    dj = new Dijkstra::DijkstraFindPath();
    dj->CreateGraph();

    scene = new QGraphicsScene;
    initScene();


    view = new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(600,720);
    view->show();
    setCentralWidget(view);

    createAction();
    createToolBar();           //实现一个工具栏

    Sleep(2000);
}

Dijkstra::~Dijkstra()
{
    delete dj;
}

Dijkstra::PathDisplayWindow::PathDisplayWindow(QWidget* parent) : QDialog(parent)
{
    pathLabel = new QLabel(this);
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(pathLabel);
}

void Dijkstra::PathDisplayWindow::setPathText(const QString& text)
{
    pathLabel->setText(text);
}

void Dijkstra::initScene() {
    // 加载地图图片
    QGraphicsPixmapItem* item = scene->addPixmap(QPixmap("image/map2.jpg"));
    item->setPos(0, 50);

    // 绘制最短路径曲线
    QPainterPath path;
    for (int i = 0; i < shortestPath.size(); ++i) {
        QPointF point = getPointForIndex(shortestPath[i]);
        if (i == 0) {
            path.moveTo(point);
        }
        else {
            path.lineTo(point);
        }
    }
    scene->addPath(path, QPen(Qt::red, 2));

}

Dijkstra::DijkstraFindPath::DijkstraFindPath()
{
    mgraph.vexnum = 40;                        //初始化点数目
    for (int i = 0; i < mgraph.vexnum; i++) //初始化点编号
        mgraph.vexs.push_back(i);
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

void Dijkstra::DijkstraFindPath::CreateGraph()
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

void Dijkstra::DijkstraFindPath::dijkstra(int startPos)
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

QVector<int> Dijkstra::DijkstraFindPath::get_Path(int endPos)
{
    QVector<int> path;

    for (; endPos != -1; endPos = prev[endPos]) {
        //        std::cout << "EndPos: " << endPos << ", ";
        path.push_back(endPos);
    }

    std::reverse(path.begin(), path.end());

    return path;
}

void Dijkstra::createAction()
{
    findPathAction = new QAction(QIcon("F:\\qt\\Search.png"), tr("搜索路径"), this);
    findPathAction->setShortcut(tr("Ctrl+F"));
    findPathAction->setStatusTip(tr("搜索路径"));
    connect(findPathAction, SIGNAL(triggered(bool)), this, SLOT(FindPath()));
}

void Dijkstra::createToolBar()
{
    QToolBar* toolBar = addToolBar("Tool");
    startLabel = new QLabel(tr("起点: "));
    startComboBox = new QComboBox;
    startComboBox->addItem(tr("南大门"));  //0
    startComboBox->addItem(tr("云谷寺"));  //1
    startComboBox->addItem(tr("慈光阁"));  //2
    startComboBox->addItem(tr("迎客松"));  //3
    startComboBox->addItem(tr("光明顶"));  //4
    startComboBox->addItem(tr("梦笔生花"));  //5

    startComboBox->addItem(tr("玉屏站")); //6
    startComboBox->addItem(tr("白鹅岭"));  //7


    endLabel = new QLabel(tr("终点: "));

    endComboBox = new QComboBox;
    endComboBox->addItem(tr("南大门"));
    endComboBox->addItem(tr("云谷寺"));
    endComboBox->addItem(tr("慈光阁"));
    endComboBox->addItem(tr("迎客松"));
    endComboBox->addItem(tr("光明顶"));
    endComboBox->addItem(tr("梦笔生花"));
    endComboBox->addItem(tr("玉屏站"));
    endComboBox->addItem(tr("白鹅岭"));




    toolBar->addWidget(startLabel);
    toolBar->addWidget(startComboBox);
    toolBar->addSeparator();
    toolBar->addWidget(endLabel);
    toolBar->addWidget(endComboBox);
    toolBar->addSeparator();
    toolBar->addAction(findPathAction);
    toolBar->addSeparator();


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
    PathDisplayWindow* pathWindow = new PathDisplayWindow(this);
    pathWindow->setWindowTitle("最短路径信息");
    pathWindow->setPathText(pathText);
    pathWindow->show();

}

void Dijkstra::Clear()
{
    QList<QGraphicsItem*> listItem = scene->items();
    while (!listItem.empty()) {
        scene->removeItem(listItem.at(0));
        delete listItem.at(0);
        listItem.removeAt(0);
    }
    initScene();
}

QPointF Dijkstra::getPointForIndex(int index)const {
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
