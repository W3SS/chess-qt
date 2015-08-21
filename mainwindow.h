#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

