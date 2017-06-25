#pragma once
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>

//图像显示控件，能实现图片的放缩和读取鼠标处颜色信息
class GraphicView : public QGraphicsView {
	Q_OBJECT

public:
	GraphicView(QWidget * parent = Q_NULLPTR);
	~GraphicView();

	void showImage(QImage &img);
	void fitImage();

signals:
	void colorMessage(QColor, QPoint);

public:
	QGraphicsScene *scene;//QGraphicsView信息
	QGraphicsPixmapItem *item;//像素信息
	QImage img;//图像信息

protected:
	void mouseMoveEvent(QMouseEvent *ev);
	void mouseDoubleClickEvent(QMouseEvent *ev);
	void wheelEvent(QWheelEvent *ev);
};
