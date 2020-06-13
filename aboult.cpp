#include "ui_aboult.h"
#include "aboult.h"
#include <QDialog>

aboult::aboult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboult)
{

}

aboult::~aboult()
{
    delete ui;
}
