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
#include "sun_num.h"
#include "plant_chomper.h"
#include "plant_shield.h"
#include "box_chomper.h"
#include "box_peashooter.h"
#include "plant_groundattack.h"
#include "box_grounattack.h"
#include "box_sunflower.h"
#include "box_snowpea.h"
#include "lawn.h"
#include "box_shield.h"
#include "box_cherrybomb.h"

#include "plant_peasnow.h"
#include<qgraphicsitem.h>
#include <QSound>

#include "box.h"

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


    //
    Sun_Num *po = new Sun_Num;
    po->setPos(400,100);
    scene->addItem(po);


    //

    Lawn *LL = new Lawn;
    LL->setPos(517,180);
    scene->addItem(LL);

//添加僵尸
    Zombie *b =new Zombie_Basic;
    b->setPos(1220, 215);


//添加卡片
    Box *x = new Box_Chomper;
    x->setPos(400,200);
    scene->addItem(x);

    Box *y = new Box_Peashooter;
    y->setPos(400,280);
    scene->addItem(y);

    Box *al = new Box_GrounAttack;
    al->setPos(400,360);
    scene->addItem(al);

    Box *ll = new Box_SunFlower;
    ll->setPos(400,440);
    scene->addItem(ll);

    Box *l2 = new Box_Shield;
    l2->setPos(400,520);
    scene->addItem(l2);


    Box *l3 = new Box_CherryBomb;
    l3->setPos(400,600);
    scene->addItem(l3);

    Box *l4 = new Box_SnowPea;
    l4->setPos(400,680);
    scene->addItem(l4);



//添加植物
//    Plant *pp = new Plant_GroundAttack;
//    pp->setPos(975,216);
//    scene->addItem(pp);

//    Plant *l1 = new Plant_Chomper;
//    l1->setPos(675,215);
//    scene->addItem(l1);

//    Plant *fuck = new Plant_shield;
//    fuck->setPos(900,215);
//    scene->addItem(fuck);

//    Plant *p = new Plant_Pea;
//    p->setPos(575,215);
//    Plant *t = new Plant_Pea;
//    t->setPos(775,215);



//    Plant *sss = new Plant_PeaSnow;
//    sss->setPos(575,215);
//    scene->addItem(sss);
//    scene->addItem(t);
//    scene->addItem(p);
    scene->addItem(b);


//    for(int i=0;i<9;i++){
//        for(int j=0;j<5;j++){
//            Plant *p = new Plant_shield;
//            p->setPos(570+i*82,215+j*100);
//            scene->addItem(p);
//        }
//    }




//添加除草机
    for(int i=0;i<5;i++){
        Whacker *wha = new Whacker;
        wha->setPos(500,235+i*100);
        scene->addItem(wha);
    }

    view = new QGraphicsView(scene, this);
    view->resize(1052, 651);
//    view->resize(900,600);
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
