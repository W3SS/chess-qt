#include "gameload.h"
#include "ui_gameload.h"

gameload::gameload(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameload)
{
    ui->setupUi(this);
}

gameload::~gameload()
{
    delete ui;
}
