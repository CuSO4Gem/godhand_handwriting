#ifndef ABOULT_H
#define ABOULT_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class aboult;
}

class aboult : public QDialog
{
	Q_OBJECT

public:
    explicit aboult(QWidget *parent = 0);
	~aboult();
private:
    Ui::aboult *ui;
};
	
#endif // ABOULT_H
