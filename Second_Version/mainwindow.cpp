#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zombie_basic.h"
#include "zombie.h"
#include "plant.h"
#include "plant_pea.h"
#include "weapon.h"
#include "weapon_pea.h"
#include "messy.h"
#include "whacker.h"
#include<qgraphicsitem.h>
#include <QSound>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    sound = new QSound(":/image/images/Grazy Dave.wav",this);
    sound->play();
    sound->setLoops(QSound::Infinite);
    ui->setupUi(this);
    timer= new QTimer;
    scene = new QGraphicsScene(this);
    scene->setSceneRect(360, 120, 900, 600);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    Zombie *b =new Zombie_Basic;
    b->setPos(1220, 215);
    Plant *p = new Plant_Pea;
    p->setPos(575,215);
    Plant *t = new Plant_Pea;
    t->setPos(775,215);
    scene->addItem(t);
//    Weapon *w = new Weapon_Pea;
//    w->setPos(300,200);
//    scene->addItem(w);
    scene->addItem(p);
    scene->addItem(b);
    for(int i=0;i<5;i++){
        Whacker *wha = new Whacker;
        wha->setPos(500,235+i*100);
        scene->addItem(wha);
    }
    view = new QGraphicsView(scene, this);
    view->resize(1052, 651);
    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(QPixmap(":/image/images/Background0.jpg"));
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
