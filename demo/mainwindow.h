#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QSound>
#include "sun_num.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void AddZombie();



private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene ;
    QGraphicsView *view;
    QTimer *timer;
    QSound *sound;
};

#endif // MAINWINDOW_H
