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
 /*
    gameload *gl = new gameload; //загружаем окно игрового поля
    gl->setParent(this);
    gl->show();
*/

    //имена файлов сохранееных игр считываем (dir) с папки где они хранятся в масив
    // и элементы масива подставляем в items
    QStringList items;
    char str[7] = "Hello!";

    items << tr(str) << tr("Game-2") << tr("Game-3") << tr("Game-4");

    bool bOk;
    QString item = QInputDialog::getItem(this, tr("Load a saved game:"), tr("Game:"), items, 0, false, &bOk);

    if (bOk){
        slotOpen();
    }
    if (!bOk) {
// Была нажата кнопка Cancel

    }

}


void MainWindow::on_pushButtonNew_clicked()
{
     GameWindow *gm = new GameWindow; //загружаем окно игрового поля
     gm->setParent(this);
//     gm->setGeometry(200,200,100,100);

     gm->show();
}

void MainWindow::slotOpen()
{
    QString FileName=QFileDialog::getOpenFileName(this,"Open file...", QDir::homePath(), "Textfiles(*.svg);;Allfiles(*.*)");
    //Вызвать системный диалог открытия файла в домашней папке пользователя
}
