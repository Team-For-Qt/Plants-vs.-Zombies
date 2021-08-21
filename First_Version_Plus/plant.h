#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>


class Plant : public QGraphicsItem
{
public:
    Plant();
    QRectF boundingRect()  const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setMovie(QString path);
protected:
    QMovie *movie;
    int bv;//血量
    int ht;//伤害
    int time;
    int cnt;
};

#endif // PLANT_H
