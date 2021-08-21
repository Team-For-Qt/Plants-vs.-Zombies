#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zombie_basic.h"
#include "zombie.h"
#include "plant.h"
#include "plant_pea.h"
#include "weapon.h"
#include "weapon_pea.h"
#include<qgraphicsitem.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer= new QTimer;
    scene = new QGraphicsScene(this);
    scene->setSceneRect(150, 0, 900, 600);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    Zombie *b =new Zombie_Basic;
    b->setPos(1000, 200);
    Plant *p=new Plant_Pea;
    p->setPos(300,200);
//    Weapon *w = new Weapon_Pea;
//    w->setPos(300,200);
//    scene->addItem(w);
    scene->addItem(p);
    scene->addItem(b);
    view = new QGraphicsView(scene, this);
    view->resize(902, 602);
    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(QPixmap(":/image/images/Background.jpg"));
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
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
