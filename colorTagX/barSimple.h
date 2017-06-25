#ifndef ICEBANGBANG_H
#define ICEBANGBANG_H

#include <QWidget>
#include "xgradient.h"

//用于主窗口的色标显示控件，能设置色阶数，传递鼠标处颜色信息
class barSimple : public QWidget
{
	Q_OBJECT

public:
	explicit barSimple(QWidget *parent = 0);
	~barSimple();
	XGradient linearGrad;
	int segment;

signals:
	void colorMessage(QColor, float);//该控件传到主窗口的颜色信息

private:

protected:
	void paintEvent(QPaintEvent * e);
	void mouseMoveEvent(QMouseEvent *e);

};

#endif // ICEBANGBANG_H
