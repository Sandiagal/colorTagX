#include "barSimple.h"

#include <QColorDialog>
#include <QPaintEvent>
#include <QPainter>

barSimple::barSimple(QWidget *parent) :
	QWidget(parent),
	linearGrad(),
	segment(0)
{
	setMouseTracking(true);//实时捕捉鼠标信息
}

barSimple::~barSimple()
{
}

//绘制色标条
void barSimple::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	QRect dirtyRect = e->rect();
	int w = dirtyRect.width();
	int h = dirtyRect.height();
	if (segment > 0) { //如果需要对色标分段
		QImage tmp(segment, 1, QImage::Format_ARGB32); //新建一个宽度=分段数，高度=1的图片
		QPainter painter2(&tmp);
		painter2.fillRect(0, 0, segment, 1, Qt::GlobalColor::white); // 用白色填充此图
		linearGrad.paintTo(&painter2, segment, 1); //画渐变色
		painter.drawImage(dirtyRect, tmp); //将小图拉大画到控件上
	}
	else {
		linearGrad.paintTo(&painter, w, h);
	}
}

//鼠标移动记录鼠标坐标，并更新颜色信息
void barSimple::mouseMoveEvent(QMouseEvent *e)
{
	float widgetWidth = this->width();
	int mouseX = e->x();
	float pointPos = mouseX / widgetWidth;//鼠标位置

	if (pointPos < 0) pointPos = 0;//越界处理
	if (pointPos > 1) pointPos = 1;//越界处理

	emit colorMessage(linearGrad.getColorAt(pointPos), pointPos);//传出鼠标处颜色信息
}