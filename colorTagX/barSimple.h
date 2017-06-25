#ifndef ICEBANGBANG_H
#define ICEBANGBANG_H

#include <QWidget>
#include "xgradient.h"

//���������ڵ�ɫ����ʾ�ؼ���������ɫ������������괦��ɫ��Ϣ
class barSimple : public QWidget
{
	Q_OBJECT

public:
	explicit barSimple(QWidget *parent = 0);
	~barSimple();
	XGradient linearGrad;
	int segment;

signals:
	void colorMessage(QColor, float);//�ÿؼ����������ڵ���ɫ��Ϣ

private:

protected:
	void paintEvent(QPaintEvent * e);
	void mouseMoveEvent(QMouseEvent *e);

};

#endif // ICEBANGBANG_H
