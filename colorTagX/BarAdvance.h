#ifndef BARADVANCE_H
#define BARADVANCE_H

#include <QWidget>
#include "xgradient.h"

//用于色标编辑窗口的色标显示控件，能修改色标关键点，传递鼠标处颜色信息
class BarAdvance : public QWidget
{
	Q_OBJECT

public:
	explicit BarAdvance(QWidget *parent = 0);
	~BarAdvance();
	XGradient linearGrad;//色标
	QGradientStops currentStops;//关键点群
	int currentStopIndex = 0;//当前关键点
	void InterpolationChange(int);
	void Reversal();

signals:
	void colorMessage(QColor, int, int);//该窗口传到主窗口的颜色信息

private:

protected:
	void paintEvent(QPaintEvent * e);
	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseDoubleClickEvent(QMouseEvent *e);
};

#endif // ICEBANGBANG_H
