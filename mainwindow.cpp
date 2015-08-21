#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    moveToCenter();
    mkDirektorie();
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButtonLoad_clicked() //выбор файла сохранненой игры
{
     QString FileName=QFileDialog::getOpenFileName(this,"Open file...", QDir::currentPath(), "Savefiles(*.sg)");
    //Вызвать системный диалог открытия файла пока в домашней папке пользователя потом в папке игры "save"

    if (FileName.isEmpty()){ //Если пользователь не выбрал ни одного файла
        return;              //выйти из метода
    }

    QFile File(FileName);    //Устанавливаем имя открытого файла
    if (File.open(QIODevice::ReadOnly | QIODevice::Text)){   //Если текстовый файл открыт только для чтения...
       //задать имя файла
       //читаем последнюю строку истории и загружаем в масив доски
       //ui-> масив
        QMessageBox::information(0, "Information", "Operation Complete");
        File.close(); //закрываем открытый файл
                      //запускаем игру
    }
    else{  //Если при открытии файла возникла ошибка выводим диалоговое окно с сообщением,
            //содержащим имя файла, одну кнопку «Ок» и заголовок «Error»
        QMessageBox::warning(this,"Error", QString("Could not open file %1 for reading").arg(File.fileName()), QMessageBox::Ok);

    }

}


void MainWindow::on_pushButtonNew_clicked()
{

    GameWindow *gm = new GameWindow; //загружаем окно игрового поля
     gm->setParent(this);
     gm->show();

}

void MainWindow::mkDirektorie() //создание директории для файлов сохранения
{
    QDir::currentPath();

    if (QDir().exists("savegame")){ //если папка уже создана
       return;                      //выходим из метода
    }
    else{                           //ели папка отсутствует
      QDir().mkdir("savegame");    //создаем
    }
}

void MainWindow::closeEvent(QCloseEvent *event) //обрабатываем событие закрытия окна игры
{
    //спрашиваем - действительно ли нужно закрыть?
     event->accept();   //подтверждаем событие и закрываем приложение
}

void MainWindow::moveToCenter(){
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);
}


