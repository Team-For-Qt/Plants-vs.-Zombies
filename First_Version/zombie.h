#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <QGraphicsScene>
#include<QGraphicsItem>
#include<QMovie>
#include <QPainter>

class Zombie : public QGraphicsItem
{
public:
    Zombie();
    enum { Type = UserType + 2};//?
    void setMovie(QString path);
    void setHead(QString path);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    QMovie *movie;

};

#endif // ZOMBIE_H
