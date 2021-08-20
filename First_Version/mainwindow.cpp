#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zombie_basic.h"
#include "zombie.h"
#include<qgraphicsitem.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer= new QTimer;
    scene = new QGraphicsScene(this);
    scene->setSceneRect(150, 0, 900, 600);
    Zombie *b =new Zombie_Basic;
    b->setPos(1000, 200);
    scene->addItem(b);
    view = new QGraphicsView(scene, this);
    view->resize(902, 602);
    view->setBackgroundBrush(QPixmap(":/image/images/Background.jpg"));
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    timer->start(33);
    view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addZombie(){

}
