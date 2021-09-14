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
#include "plant_cherrybomb.h"
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
#include "sunner.h"
#include "energy.h"
#include "zombie_block.h"
#include "plant_peasnow.h"
#include<qgraphicsitem.h>
#include <QSound>
#include "zombie_bucket.h"
#include "box.h"
#include "zombie_jump.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qsrand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));
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
//    Zombie *b =new Zombie_Bucket;
//    b->setPos(1220, 215);
//    Zombie *a =new Zombie_Basic;
//    a->setPos(1220,315);
//    Zombie *c = new Zombie_Jump;
//    c->setPos(1220,415);
//    scene->addItem(b);
//    scene->addItem(a);
//    scene->addItem(c);

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
    Plant *l9 = new Sunner;
    l9->setPos(675,415);
    scene->addItem(l9);


//    Plant *sss = new Plant_PeaSnow;
//    sss->setPos(575,215);
//    scene->addItem(sss);
//    scene->addItem(t);
//    scene->addItem(p);


//    for(int i=0;i<9;i++){
//        for(int j=0;j<5;j++){
//            Plant *p = new Plant_shield;
//            p->setPos(570+i*82,215+j*100);
//            scene->addItem(p);
//        }
//    }



//    static int cnt = 0;
//    cnt=0;
//    int tp = 1;
//    int road = 1;
//    Zombie *b;

//    if(tp==0)
//    {
//        b =new Zombie_Basic;
//        b->setPos(1220, 215+100*road);
//        scene->addItem(b);
//    }
//    else if(tp==1)
//    {
//        b =new Zombie_Block;
//        b->setPos(1220, 215+100*road);
//        scene->addItem(b);
//    }
//    else if(tp==2)
//    {
//        b =new Zombie_Bucket;
//        b->setPos(1220, 215+100*road);
//        scene->addItem(b);
//    }
//    else if(tp==3)
//    {
//        b =new Zombie_Jump;
//        b->setPos(1220, 215+100*road);
//        scene->addItem(b);
//    }





//添加除草机

    view = new QGraphicsView(scene, this);    for(int i=0;i<5;i++)
    {
        Whacker *wha = new Whacker;
        wha->setPos(500,235+i*100);
        scene->addItem(wha);
    }
    view->resize(1052, 651);
    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(QPixmap(":/image/images/Background0.jpg"));
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, this, &MainWindow::AddZombie);
    timer->start(33);
    view->show();


}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::AddZombie()
//{
//    static int low = 4;
//    static int high = 8;
//    static int maxtime = 20 * 1000 / 33;
//    static int time = maxtime / 2;
//    static int counter = 0;
//    if (++counter >= time)
//    {
//        if (++low > high)
//        {
//            maxtime /= 1.3;
//            high *= 2;
//        }
//        counter = 0;
//        time = qrand() % (2 * maxtime / 3) + maxtime / 3;
//        int type = qrand() % 100;
//        int i = qrand() % 5;
//        Zombie *zombie;
//        if (type < 40)
//            zombie = new Zombie_Basic;
//        else if (type < 70)
//            zombie = new Zombie_Block;
//        else if (type < 80)
//            zombie = new Zombie_Bucket;
//        else if (type < 90)
//            zombie = new Zombie_Jump;
//        else
//            zombie = new Zombie_Basic;
//        zombie->setPos(1028, 130 + 98 * i);
//        scene->addItem(zombie);
//    }
//}

void MainWindow::AddZombie(){
    static int cnt = 0;
    static int time = 300;
    if(cnt++>time)
    {
        cnt=0;
        int tp = qrand()%5;
        int road = qrand()%5;
        Zombie *b;

        if(tp==0)
        {
            b =new Zombie_Basic;
            b->setPos(1220, 215+100*road);
            scene->addItem(b);
            return ;
        }
        else if(tp==1)
        {
            Zombie *bc =new Zombie_Jump;
            bc->setPos(1220, 215+100*road);
            scene->addItem(bc);
            return ;
        }
        else if(tp==2)
        {
            b =new Zombie_Bucket;
            b->setPos(1220, 215+100*road);
            scene->addItem(b);
            return;
        }
        else if(tp==3)
        {
            b =new Zombie_Jump;
            b->setPos(1220, 215+100*road);
            scene->addItem(b);
            return;
        }
    }
}
