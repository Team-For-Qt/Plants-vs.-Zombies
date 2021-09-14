#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMovie>
#include <QPainter>
#include "plant_groundattack.h"
#include "plant.h"

class Zombie : public QGraphicsItem
{
public:
    int bv;//血量
    int ht;//伤害
    int condition;//状态
    /*
     * ‘0’代表死亡
     * ‘1’代表行走
     * ‘2’代表伤害植物
     * ‘3’代表冰冻
     */
    qreal speed;
    int flag;//判断第几次死亡
    int nnn2;//判断第几次
    Zombie();
    enum { Type = UserType + 1};
    void setMovie(QString path);
    void setHead(QString path);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    int type() const override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;

protected:
    QMovie *movie;
    QMovie *head;

};

#endif // ZOMBIE_H
