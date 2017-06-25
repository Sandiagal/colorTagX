#ifndef XGRADIENT_H
#define XGRADIENT_H

#include <QObject>
#include <QPair>
#include <QVector>
#include <QColor>
#include <QLinearGradient>

//重写的色标控件
class XGradient : public QObject
{
	Q_OBJECT

public:
	XGradient(QObject *parent = NULL);
	~XGradient();

	QGradientStops stops();
	void setStops(QGradientStops &stops);
	
	inline bool getInterpolationMode() { return m_hsv; }
	void setInterpolationMode(bool hsv);

	QColor getColorAt(qreal pos);

	void paintTo(QPainter *painter, int w, int h);

	inline void setFinalStop(int a, int b) {}

	//构造运算符
	inline operator QLinearGradient () const {
		QLinearGradient rtn;
		rtn.setStops(this->m_stops);
		rtn.setFinalStop(1000, 0);
		rtn.setStart(0, 0);
		return rtn;
	}

	//赋值运算符
	inline XGradient& operator=(const XGradient &lg) {
		m_stops = lg.m_stops;
		m_hsv = lg.m_hsv;
		return *this;
	}

	//赋值运算符
	inline XGradient& operator=(const QLinearGradient &lg) {
		setStops(lg.stops());
		return *this;
	}

	//赋值运算符
	inline XGradient(const XGradient &lg) {
		this->operator=(lg);
	}

private:
	bool m_hsv;
	QGradientStops m_stops;
};

#endif // XGRADIENT_H
