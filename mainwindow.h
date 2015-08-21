#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gamewindow.h"

#include <QMainWindow>
#include <QInputDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QRect>
#include <QDesktopWidget>

#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonLoad_clicked();
    void on_pushButtonNew_clicked();
    void mkDirektorie();
    void moveToCenter();


protected:
    void closeEvent(QCloseEvent* event);

private:
    Ui::MainWindow *ui;
    GameWindow* form1;


};

#endif // MAINWINDOW_H

