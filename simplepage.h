#ifndef SIMPLEPAGE_H
#define SIMPLEPAGE_H

#include <QObject>
#include <QImage>
#include <QPoint>
#include <QString>
#include <QSize>


class Simplepage
{
public:
    explicit Simplepage  (const QSize imgSize,
                    const int topMargin, const int bottemMargin, const int leftMargin, const int rightMargin,
                    const int columnSpacing, const int lineSpacing, const int fontX,const int fontY);
    ~Simplepage();
	int getTotalLine();//How many ine in total
	int totalColumn();//How many column this line
    int totalColumn(int col);//How many column at line XXX
	int currentLine();//Current line number
	int currentColumn();//Current column number
	QPoint atPixel();//Return QPoint according to column number and line number
	bool isFull();
	bool nextPoint();//goto nextPosition
	void firstPoint();//move to Line 1 and column 1
	bool netLine();//move to nextLin
	void firstColumn();//move to first column of this line
	bool gotoPoint(int ln,int col);//goto line ... and column ...
	
private:
    QPoint *pageStructe;//total line and column
    QPoint *currentLocation;//current line and column
    QPoint *pageStepPix;
    QPoint *point1;//first point;
};
#endif // SIMPLEPAGE_H
