#include "BarAdvance.h"
#include <QColorDialog>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <random>

BarAdvance::BarAdvance(QWidget *parent) :
	QWidget(parent)
{
	setMouseTracking(true);//ʵʱ��׽�����Ϣ
}

BarAdvance::~BarAdvance()
{
}

//ѡ���ֵ�ռ�
void BarAdvance::InterpolationChange(int index)
{
	if (index == 0)
		linearGrad.setInterpolationMode(false);//RGB���ֵ
	else
		linearGrad.setInterpolationMode(true);//HSV���ֵ
	this->repaint();//ˢ��
}

//ɫ�귭ת
void BarAdvance::Reversal()
{
	currentStops = linearGrad.stops();
	for (int i = 0; i < currentStops.count(); i++)//ɨ�����йؼ���
	{
		currentStops[i].first = 1 - currentStops[i].first;//λ�÷�ת
	}
	linearGrad.setStops(currentStops);
	this->repaint();//ˢ��
}

//����ɫ��ͼ��
void BarAdvance::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	QRect dirtyRect = e->rect();
	dirtyRect.setHeight(dirtyRect.height() - 20);//�ϲ��ֵĳ�ɫ��
	int w = dirtyRect.width();//ɫ����
	int h = dirtyRect.height();//ɫ����
	linearGrad.paintTo(&painter, w, h);//����

	const int ww = 5;//�ؼ�����
	auto ps = linearGrad.stops();
	auto p = ps.begin();

	QBrush brush(Qt::black);

	painter.setPen(QColor(0, 0, 0, 255));//�ؼ���Ŀ����ɫ

	QGradientStop *last = nullptr; //ǰһ���ؼ���
	for (; p != ps.end(); p++) {//�����Ҽ����ؼ���
		int x = w * p->first - ww;
		auto rect1 = QRect(x, dirtyRect.height(), ww * 2, 20);//���ƹؼ���

		if (last) {// ǰ���йؼ���
			painter.drawLine(
				last->first * w, (255 - last->second.alpha()) / 255.0 * h,
				p->first * w, (255 - p->second.alpha()) / 255.0 * h
			);
		}
		last = p;

		brush.setColor(p->second);
		painter.setBrush(brush);
		painter.drawRect(rect1);//���ƹؼ���
	}
}

//��갴��ʱ���¹ؼ���
void BarAdvance::mousePressEvent(QMouseEvent *e)
{
	float widgetWidth = this->width();//�ؼ���
	int mouseX = e->x();//�������

	const int boxSize = 10;
	currentStopIndex = 0;
	currentStops = linearGrad.stops();

	auto point = currentStops.begin();
	for (; point != currentStops.end(); point++) {//�����Ҽ����ؼ���
		int x = widgetWidth * point->first;
		if ((mouseX >= x - boxSize) && (mouseX <= x + boxSize)) {//�㵽�ִ��, ����Ҫ����µĵ㡣�˳��¼�
			return;
		}
		currentStopIndex++;
	}

	QGradientStop new_point;
	new_point.first = mouseX / widgetWidth;//�¹ؼ�������
	new_point.second = linearGrad.getColorAt(mouseX / widgetWidth);//�¹ؼ�����ɫ

	currentStops.append(new_point);//���ӹؼ���
}

//����ƶ���¼������꣬��������ɫ��Ϣ
void BarAdvance::mouseMoveEvent(QMouseEvent *e)
{
	float widgetWidth = this->width();
	float widgetHeight = this->height();
	int mouseX = e->x(), mouseY = e->y();
	float pointPos = mouseX / widgetWidth;//���λ��

	if (pointPos < 0) pointPos = 0;//Խ�紦��
	if (pointPos > 1) pointPos = 1;//Խ�紦��

	Qt::MouseButtons btns = e->buttons();
	if (btns.testFlag(Qt::LeftButton)) {
		if ((e->modifiers() & Qt::Modifier::SHIFT) == 0) currentStops[currentStopIndex].first = pointPos;//�����ƶ��ؼ������λ��
		else currentStops[currentStopIndex].second.setAlpha(255 - 255 * mouseY / widgetHeight);//����SHIFTֻ�������ƶ��ؼ������͸����
		linearGrad.setStops(currentStops);//�������λ����Ϣ

		this->repaint();//ˢ��
	}
	emit colorMessage(linearGrad.getColorAt(pointPos), currentStops.count(), currentStopIndex);//������괦��ɫ��Ϣ
}

//����Ҽ�ȥ���ؼ���
void BarAdvance::mouseReleaseEvent(QMouseEvent *e)
{
	if (e->button() == Qt::RightButton) {
		currentStops.removeAt(currentStopIndex);//�Ҽ��Ƴ�ָ���ؼ���
		linearGrad.setStops(currentStops);
		this->repaint();//ˢ��
	}
}

//������˫�������¹ؼ���
void BarAdvance::mouseDoubleClickEvent(QMouseEvent *e)
{
	QColor color;
	color = QColorDialog::getColor(currentStops[currentStopIndex].second, this);//���õ�ɫ��
	if (color.isValid()) {
		currentStops[currentStopIndex].second = color;
		linearGrad.setStops(currentStops);//����ɫ��ؼ���
		this->repaint();//ˢ��
	}
}
