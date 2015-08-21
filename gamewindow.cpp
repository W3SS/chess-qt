#include "gamewindow.h"
#include "ui_gamewindow.h"



GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    generateBoard();
}

GameWindow::~GameWindow()
{
    delete ui;
}



void GameWindow::generateBoard() //Рисуем игральную доску
{

    scene = new QGraphicsScene(); //Новая графическая сцена
    scene->setSceneRect(0, 0, 800, 800);
    ui->graphicsView->setScene(scene);

    bool isWhite = true;  //Рисуем саму доску
    for(int y = 0; y < 800; y += 100)
    {
        for(int x = 0; x < 800; x += 100)
        {
            QBrush brush;
            if(isWhite) brush = QBrush(Qt::white);
            else brush = QBrush(Qt::gray);
            scene->addRect(x, y, 100, 100, QPen(Qt::black), brush);

            if(isWhite) isWhite = false;
            else isWhite = true;
        }
        if(isWhite) isWhite = false;
        else isWhite = true;
    }


  //расставляем фигуры , пока так


    int posX = 0;
    int posY = 0;




    // Раставляем фигуры
    QGraphicsPixmapItem *figure = 0;
    figure = scene->addPixmap(QPixmap("://images/black_rook.png"));
    figure->setPos(posX, posY);
    if(figure) blackFigures.append(figure);

    posX += 100;
    figure = scene->addPixmap(QPixmap("://images/black_horse.png"));
    figure->setPos(posX, posY);
    if(figure) blackFigures.append(figure);

    posX += 100;
    figure = scene->addPixmap(QPixmap("://images/black_bishop.png"));
    figure->setPos(posX, posY);
    if(figure) blackFigures.append(figure);

    posX += 100;
    figure = scene->addPixmap(QPixmap("://images/black_queen.png"));
    figure->setPos(posX, posY);
    if(figure) blackFigures.append(figure);

    posX += 100;
    figure = scene->addPixmap(QPixmap("://images/black_king.png"));
    figure->setPos(posX, posY);
    if(figure) blackFigures.append(figure);

    posX += 100;
    figure = scene->addPixmap(QPixmap("://images/black_bishop.png"));
    figure->setPos(posX, posY);
    if(figure) blackFigures.append(figure);

    posX += 100;
    figure = scene->addPixmap(QPixmap("://images/black_horse.png"));
    figure->setPos(posX, posY);
    if(figure) blackFigures.append(figure);

    posX += 100;
    figure = scene->addPixmap(QPixmap("://images/black_rook.png"));
    figure->setPos(posX, posY);
    if(figure) blackFigures.append(figure);

    posX = 0;
    posY = 700;

    figure = scene->addPixmap(QPixmap("://images/white_rook.png"));
    figure->setPos(posX, posY);
    if(figure) whiteFigures.append(figure);

    posX += 100;
    figure = scene->addPixmap(QPixmap("://images/white_horse.png"));
    figure->setPos(posX, posY);
    if(figure) whiteFigures.append(figure);

    posX += 100;
    figure = scene->addPixmap(QPixmap("://images/white_bishop.png"));
    figure->setPos(posX, posY);
    if(figure) whiteFigures.append(figure);

    posX += 100;
    figure = scene->addPixmap(QPixmap("://images/white_queen.png"));
    figure->setPos(posX, posY);
    if(figure) whiteFigures.append(figure);

    posX += 100;
    figure = scene->addPixmap(QPixmap("://images/white_king.png"));
    figure->setPos(posX, posY);
    if(figure) whiteFigures.append(figure);

    posX += 100;
    figure = scene->addPixmap(QPixmap("://images/white_bishop.png"));
    figure->setPos(posX, posY);
    if(figure) whiteFigures.append(figure);

    posX += 100;
    figure = scene->addPixmap(QPixmap("://images/white_horse.png"));
    figure->setPos(posX, posY);
    if(figure) whiteFigures.append(figure);

    posX += 100;
    figure = scene->addPixmap(QPixmap("://images/white_rook.png"));
    figure->setPos(posX, posY);
    if(figure) whiteFigures.append(figure);

    posY = 100;
    for(posX = 0; posX < 800; posX += 100)
    {
        figure = scene->addPixmap(QPixmap("://images/black_pawn.png"));
        figure->setPos(posX, posY);
        if(figure) blackFigures.append(figure);
    }

    posY = 600;
    for(posX = 0; posX < 800; posX += 100)
    {
        figure = scene->addPixmap(QPixmap("://images/white_pawn.png"));
        figure->setPos(posX, posY);
        if(figure) whiteFigures.append(figure);
    }



}


void GameWindow::mousePressEvent(QMouseEvent *event) //обрабатываем событе нажатия кнопки мыши
{
    // Проверяем альтернативные ходы
    // AlternateTurn(this,++count);

    //сохраняем историю игры в файл после каждого хода
    //saveGame();м

}



