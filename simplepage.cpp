#include "simplepage.h"

Simplepage::Simplepage(const QSize imgSize,
                 const int topMargin, const int bottemMargin, const int leftMargin, const int rightMargin,
                 const int columnSpacing, const int lineSpacing, const int fontX,const int fontY)
{
    //set attribute
    Simplepage::point1 = new QPoint;
    Simplepage::point1->setX(leftMargin);
    Simplepage::point1->setY(topMargin);
    //set step
    Simplepage::pageStepPix = new QPoint(fontX+columnSpacing,fontY+lineSpacing);
    //pageStructe .x() = total column  .y() = total line
    Simplepage::pageStructe = new QPoint((imgSize.width()-leftMargin-rightMargin)/Simplepage::pageStepPix->x(),
                                         (imgSize.height()-topMargin-bottemMargin)/Simplepage::pageStepPix->y());
    Simplepage::currentLocation = new QPoint(1,1);
}

Simplepage::~Simplepage()
{
    delete pageStructe;
    delete currentLocation;
    delete pageStepPix;
    delete point1;
}

int Simplepage::getTotalLine()
{
    return pageStructe->y();
}

int Simplepage::totalColumn()
{
    return pageStructe->x();
}

int Simplepage::totalColumn(int col)
{
    return pageStructe->x();
}

int Simplepage::currentLine()
{
    return currentLocation->y();
}

int Simplepage::currentColumn()
{
    return currentLocation->x();
}

QPoint Simplepage::atPixel()
{
    QPoint currentPixel((point1->x()+pageStepPix->x()*(currentLocation->x()-1)),(point1->y()+pageStepPix->y()*(currentLocation->y()-1)));
    return currentPixel;
}

bool Simplepage::isFull()
{
    if(currentLocation->x()==pageStructe->x() && currentLocation->y()==pageStructe->y()){
        return true;
    }
    else {
        return false;
    }
}

bool Simplepage::nextPoint()
{
    if(isFull()){
        return false;
    }
    else if(currentLocation->x()==pageStructe->x()){
        currentLocation->setX(1);
        currentLocation->setY(currentLocation->y()+1);
    }
    else {
        currentLocation->setX(currentLocation->x()+1);
    }
    return true;
}

void Simplepage::firstPoint()
{
    currentLocation->setX(0);
    currentLocation->setY(0);
}

bool Simplepage::netLine()
{
    if(currentLocation->y()==pageStructe->y()){
        return false;
    }
    else{
        currentLocation->setY(currentLocation->y()+1);
        return true;
    }
}

void Simplepage::firstColumn()
{
    currentLocation->setX(1);
}

bool Simplepage::gotoPoint(int ln, int col)
{
    if(col>currentLocation->x()||ln>currentLocation->y()
       ||col<0||ln<0){
        return false;
    }
    else{
        currentLocation->setX(col);
        currentLocation->setY(ln);
        return true;
    }
}
