#include "ui_aboultDlg.h"
#include "aboultDlg.h"
#include <QDialog>

aboultDlg::aboultDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboultDlg)
{
    setFixedSize(400,210);
    ui->setupUi(this);
}

aboultDlg::~aboultDlg()
{
    delete ui;
}
