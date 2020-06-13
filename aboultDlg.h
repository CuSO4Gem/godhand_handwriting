#ifndef ABOULTDLG_H
#define ABOULTDLG_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class aboultDlg;
}

class aboultDlg : public QDialog
{
	Q_OBJECT

public:
    explicit aboultDlg(QWidget *parent = 0);
    ~aboultDlg();
private:
    Ui::aboultDlg *ui;
};
	
#endif // ABOULTDLG_H
