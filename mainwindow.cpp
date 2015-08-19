#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewindow.h"
//#include "gameload.h"
#include <QInputDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButtonLoad_clicked() //выбор сохранненой игры из списка
{
    QString FileName=QFileDialog::getOpenFileName(this,"Open file...", QDir::homePath(), "Textfiles(*.svg);;Allfiles(*.*)");
    //Вызвать системный диалог открытия файла пока в домашней папке пользователя потом в папке игры "save"
}


void MainWindow::on_pushButtonNew_clicked()
{
     GameWindow *gm = new GameWindow; //загружаем окно игрового поля
     gm->setParent(this);
//     gm->setGeometry(200,200,100,100);

     gm->show();
}

