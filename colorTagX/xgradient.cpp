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

//���ùؼ���
void XGradient::setStops(QGradientStops & stops)
{
	m_stops = stops;
	qSort(m_stops.begin(), m_stops.end(), stopPos);
}

//�õ���ֵ��ʽ
void XGradient::setInterpolationMode(bool hsv)
{
	m_hsv = hsv;
}

//�õ�ָ�������ɫ
QColor XGradient::getColorAt(qreal pos)
{
	auto &ss = m_stops;
	if (ss.length() == 0) return QColor(0, 0, 0);//û�йؼ��㷵�ذ�ɫ
	if (ss.length() == 1) return ss[0].second;//ֻ��һ���ؼ���ķ�����ɫ
	if (pos <= 0.0) return ss[0].second;//�����Χ������߽磬���ص�һ���ؼ�����ɫ
	if (pos >= 1.0) return ss[ss.length() - 1].second;//�����Χ�����ұ߽磬�������һ���ؼ�����ɫ

	for (int i = 0; i < ss.length(); i++) {
		if (ss[i].first < pos) continue;

		if (i == 0) return ss[0].second;

		auto &l = ss[i - 1], &r = ss[i];//��ǰ�����ҹؼ���
		auto lp = l.first, rp = r.first;//��ǰ�����ҹؼ����λ��
		auto lc = l.second, rc = r.second;//��ǰ�����ҹؼ������ɫ

#define inter(A, B) (B - A) * (pos - lp) / (rp - lp) + A//�����ֵ�����

		QColor rtn;
		if (m_hsv) {//HSV��ֵģʽ
			rtn.setHsv(
				inter(lc.hue(), rc.hue()),//H
				inter(lc.saturation(), rc.saturation()),//S
				inter(lc.value(), rc.value()),//V
				inter(lc.alpha(), rc.alpha())//͸����
				);
		} else {//RGB��ֵģʽ
			rtn.setRgb(
				inter(lc.red(), rc.red()),//R
				inter(lc.green(), rc.green()),//G
				inter(lc.blue(), rc.blue()),//B
				inter(lc.alpha(), rc.alpha())//͸����
				);
		}
		return rtn;
	}

	return ss[ss.length() - 1].second;
}

//����ɫ����
void XGradient::paintTo(QPainter * painter, int w, int h)
{
	for (int x = 0; x < w; x++) {
		QLine line(x, 0, x, h);
		painter->setPen(getColorAt((double)x / w));
		painter->drawLine(line);
	}
}
