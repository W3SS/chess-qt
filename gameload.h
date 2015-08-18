#ifndef GAMELOAD_H
#define GAMELOAD_H

#include <QDialog>

namespace Ui {
class gameload;
}

class gameload : public QDialog
{
    Q_OBJECT

public:
    explicit gameload(QWidget *parent = 0);
    ~gameload();

private:
    Ui::gameload *ui;
};

#endif // GAMELOAD_H
