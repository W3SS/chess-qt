#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>

#include "QGraphicsView"
#include "QGraphicsScene"
#include "QGraphicsPixmapItem"
#include "QVector"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT


    QGraphicsScene *scene;

    QVector<QGraphicsPixmapItem*> whiteFigures;
    QVector<QGraphicsPixmapItem*> blackFigures;

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

    void mousePressEvent(QMouseEvent *event);

private:
    Ui::GameWindow *ui;

private:
   void generateBoard();



};

#endif // GAMEWINDOW_H
