#ifndef BARADVANCE_H
#define BARADVANCE_H

#include <QWidget>
#include "xgradient.h"

//����ɫ��༭���ڵ�ɫ����ʾ�ؼ������޸�ɫ��ؼ��㣬������괦��ɫ��Ϣ
class BarAdvance : public QWidget
{
	Q_OBJECT

public:
	explicit BarAdvance(QWidget *parent = 0);
	~BarAdvance();
	XGradient linearGrad;//ɫ��
	QGradientStops currentStops;//�ؼ���Ⱥ
	int currentStopIndex = 0;//��ǰ�ؼ���
	void InterpolationChange(int);
	void Reversal();

signals:
	void colorMessage(QColor, int, int);//�ô��ڴ��������ڵ���ɫ��Ϣ

private:

protected:
	void paintEvent(QPaintEvent * e);
	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseDoubleClickEvent(QMouseEvent *e);
};

#endif // ICEBANGBANG_H
