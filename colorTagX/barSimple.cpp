#include "barSimple.h"

#include <QColorDialog>
#include <QPaintEvent>
#include <QPainter>

barSimple::barSimple(QWidget *parent) :
	QWidget(parent),
	linearGrad(),
	segment(0)
{
	setMouseTracking(true);//ʵʱ��׽�����Ϣ
}

barSimple::~barSimple()
{
}

//����ɫ����
void barSimple::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	QRect dirtyRect = e->rect();
	int w = dirtyRect.width();
	int h = dirtyRect.height();
	if (segment > 0) { //�����Ҫ��ɫ��ֶ�
		QImage tmp(segment, 1, QImage::Format_ARGB32); //�½�һ�����=�ֶ������߶�=1��ͼƬ
		QPainter painter2(&tmp);
		painter2.fillRect(0, 0, segment, 1, Qt::GlobalColor::white); // �ð�ɫ����ͼ
		linearGrad.paintTo(&painter2, segment, 1); //������ɫ
		painter.drawImage(dirtyRect, tmp); //��Сͼ���󻭵��ؼ���
	}
	else {
		linearGrad.paintTo(&painter, w, h);
	}
}

//����ƶ���¼������꣬��������ɫ��Ϣ
void barSimple::mouseMoveEvent(QMouseEvent *e)
{
	float widgetWidth = this->width();
	int mouseX = e->x();
	float pointPos = mouseX / widgetWidth;//���λ��

	if (pointPos < 0) pointPos = 0;//Խ�紦��
	if (pointPos > 1) pointPos = 1;//Խ�紦��

	emit colorMessage(linearGrad.getColorAt(pointPos), pointPos);//������괦��ɫ��Ϣ
}