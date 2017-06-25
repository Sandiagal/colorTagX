#include "xgradient.h"
#include <qalgorithms.h>
#include <QPainter>

static bool stopPos(QGradientStop p1, QGradientStop p2)
{
	return p1.first < p2.first;
}

XGradient::XGradient(QObject *parent)
	: QObject(parent)
	, m_hsv(false)
	, m_stops()
{
	
}

XGradient::~XGradient()
{

}

QGradientStops XGradient::stops()
{
	return m_stops;
}

//设置关键点
void XGradient::setStops(QGradientStops & stops)
{
	m_stops = stops;
	qSort(m_stops.begin(), m_stops.end(), stopPos);
}

//得到差值方式
void XGradient::setInterpolationMode(bool hsv)
{
	m_hsv = hsv;
}

//得到指定点的颜色
QColor XGradient::getColorAt(qreal pos)
{
	auto &ss = m_stops;
	if (ss.length() == 0) return QColor(0, 0, 0);//没有关键点返回白色
	if (ss.length() == 1) return ss[0].second;//只有一个关键点的返回颜色
	if (pos <= 0.0) return ss[0].second;//点击范围超过左边界，返回第一个关键点颜色
	if (pos >= 1.0) return ss[ss.length() - 1].second;//点击范围超过右边界，返回最后一个关键点颜色

	for (int i = 0; i < ss.length(); i++) {
		if (ss[i].first < pos) continue;

		if (i == 0) return ss[0].second;

		auto &l = ss[i - 1], &r = ss[i];//当前点左右关键点
		auto lp = l.first, rp = r.first;//当前点左右关键点的位置
		auto lc = l.second, rc = r.second;//当前点左右关键点的颜色

#define inter(A, B) (B - A) * (pos - lp) / (rp - lp) + A//定义插值运算符

		QColor rtn;
		if (m_hsv) {//HSV差值模式
			rtn.setHsv(
				inter(lc.hue(), rc.hue()),//H
				inter(lc.saturation(), rc.saturation()),//S
				inter(lc.value(), rc.value()),//V
				inter(lc.alpha(), rc.alpha())//透明度
				);
		} else {//RGB差值模式
			rtn.setRgb(
				inter(lc.red(), rc.red()),//R
				inter(lc.green(), rc.green()),//G
				inter(lc.blue(), rc.blue()),//B
				inter(lc.alpha(), rc.alpha())//透明度
				);
		}
		return rtn;
	}

	return ss[ss.length() - 1].second;
}

//绘制色标条
void XGradient::paintTo(QPainter * painter, int w, int h)
{
	for (int x = 0; x < w; x++) {
		QLine line(x, 0, x, h);
		painter->setPen(getColorAt((double)x / w));
		painter->drawLine(line);
	}
}
