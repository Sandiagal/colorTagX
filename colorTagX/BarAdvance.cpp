#include "BarAdvance.h"
#include <QColorDialog>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <random>

BarAdvance::BarAdvance(QWidget *parent) :
	QWidget(parent)
{
	setMouseTracking(true);//实时捕捉鼠标信息
}

BarAdvance::~BarAdvance()
{
}

//选择差值空间
void BarAdvance::InterpolationChange(int index)
{
	if (index == 0)
		linearGrad.setInterpolationMode(false);//RGB域差值
	else
		linearGrad.setInterpolationMode(true);//HSV域差值
	this->repaint();//刷新
}

//色标翻转
void BarAdvance::Reversal()
{
	currentStops = linearGrad.stops();
	for (int i = 0; i < currentStops.count(); i++)//扫描所有关键点
	{
		currentStops[i].first = 1 - currentStops[i].first;//位置反转
	}
	linearGrad.setStops(currentStops);
	this->repaint();//刷新
}

//绘制色标图形
void BarAdvance::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	QRect dirtyRect = e->rect();
	dirtyRect.setHeight(dirtyRect.height() - 20);//上部分的长色标
	int w = dirtyRect.width();//色条长
	int h = dirtyRect.height();//色条高
	linearGrad.paintTo(&painter, w, h);//绘制

	const int ww = 5;//关键点宽度
	auto ps = linearGrad.stops();
	auto p = ps.begin();

	QBrush brush(Qt::black);

	painter.setPen(QColor(0, 0, 0, 255));//关键点的框的颜色

	QGradientStop *last = nullptr; //前一个关键点
	for (; p != ps.end(); p++) {//从左到右检索关键点
		int x = w * p->first - ww;
		auto rect1 = QRect(x, dirtyRect.height(), ww * 2, 20);//绘制关键点

		if (last) {// 前面有关键点
			painter.drawLine(
				last->first * w, (255 - last->second.alpha()) / 255.0 * h,
				p->first * w, (255 - p->second.alpha()) / 255.0 * h
			);
		}
		last = p;

		brush.setColor(p->second);
		painter.setBrush(brush);
		painter.drawRect(rect1);//绘制关键点
	}
}

//鼠标按下时更新关键点
void BarAdvance::mousePressEvent(QMouseEvent *e)
{
	float widgetWidth = this->width();//控件长
	int mouseX = e->x();//鼠标坐标

	const int boxSize = 10;
	currentStopIndex = 0;
	currentStops = linearGrad.stops();

	auto point = currentStops.begin();
	for (; point != currentStops.end(); point++) {//从左到右检索关键点
		int x = widgetWidth * point->first;
		if ((mouseX >= x - boxSize) && (mouseX <= x + boxSize)) {//点到现存点, 不需要添加新的点。退出事件
			return;
		}
		currentStopIndex++;
	}

	QGradientStop new_point;
	new_point.first = mouseX / widgetWidth;//新关键点坐标
	new_point.second = linearGrad.getColorAt(mouseX / widgetWidth);//新关键点颜色

	currentStops.append(new_point);//增加关键点
}

//鼠标移动记录鼠标坐标，并更新颜色信息
void BarAdvance::mouseMoveEvent(QMouseEvent *e)
{
	float widgetWidth = this->width();
	float widgetHeight = this->height();
	int mouseX = e->x(), mouseY = e->y();
	float pointPos = mouseX / widgetWidth;//鼠标位置

	if (pointPos < 0) pointPos = 0;//越界处理
	if (pointPos > 1) pointPos = 1;//越界处理

	Qt::MouseButtons btns = e->buttons();
	if (btns.testFlag(Qt::LeftButton)) {
		if ((e->modifiers() & Qt::Modifier::SHIFT) == 0) currentStops[currentStopIndex].first = pointPos;//左右移动关键点调整位置
		else currentStops[currentStopIndex].second.setAlpha(255 - 255 * mouseY / widgetHeight);//按下SHIFT只能上下移动关键点调整透明度
		linearGrad.setStops(currentStops);//更新鼠标位置信息

		this->repaint();//刷新
	}
	emit colorMessage(linearGrad.getColorAt(pointPos), currentStops.count(), currentStopIndex);//传出鼠标处颜色信息
}

//鼠标右键去掉关键点
void BarAdvance::mouseReleaseEvent(QMouseEvent *e)
{
	if (e->button() == Qt::RightButton) {
		currentStops.removeAt(currentStopIndex);//右键移除指定关键点
		linearGrad.setStops(currentStops);
		this->repaint();//刷新
	}
}

//鼠标左键双击增加新关键点
void BarAdvance::mouseDoubleClickEvent(QMouseEvent *e)
{
	QColor color;
	color = QColorDialog::getColor(currentStops[currentStopIndex].second, this);//调用调色板
	if (color.isValid()) {
		currentStops[currentStopIndex].second = color;
		linearGrad.setStops(currentStops);//更新色标关键点
		this->repaint();//刷新
	}
}
