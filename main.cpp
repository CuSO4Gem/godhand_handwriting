#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QDebug>
#include <QDir>
#include <QIcon>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator *translator = new QTranslator;
    QLocale location;
    if(location.language()==QLocale::Language::Chinese)
        translator->load("./godhand_zh_CN.qm");
    else
        translator->load("./godhand_zh_EN.qm");
    qApp->installTranslator(translator);
    MainWindow w;
//    w.setWindowIcon(QIcon(":/icon/mainIcon.png"));
    w.setWindowFlags(w.windowFlags()&Qt::WindowMinMaxButtonsHint|Qt::WindowMaximizeButtonHint|Qt::WindowCloseButtonHint);
    w.show();
    return a.exec();
}
