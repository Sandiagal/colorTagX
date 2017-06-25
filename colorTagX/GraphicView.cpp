#include "GraphicView.h"
#include <QWheelEvent>

GraphicView::GraphicView(QWidget * parent) : QGraphicsView(parent) {
	item = nullptr;
	scene = new QGraphicsScene(this);
	setScene(scene);

	setMouseTracking(true);//实时捕捉鼠标信息
}

GraphicView::~GraphicView() {

}

//显示图像
void GraphicView::showImage(QImage &img)
{
	if (item) {//删除原始信息
		scene->removeItem(item);
		delete item;
	}
	this->img = img;
	item = scene->addPixmap(QPixmap::fromImage(this->img));//显示图像
	
	QPointF pos(-img.width() / 2, -img.height() / 2);//图像至中
	item->setPos(pos);
}

//变化图像尺寸，使其充满控件
void GraphicView::fitImage()
{
	float sx = this->width() / (float)img.width();//宽度变化比例
	float sy = this->height()/ (float)img.height();//高度变化比例
	float s = sx > sy ? sy : sx;

	resetTransform();//重置图像尺寸

	QTransform t;
	t.scale(s, s);//尺寸变换
	setTransform(t);
}

//得到鼠标处图像信息
void GraphicView::mouseMoveEvent(QMouseEvent * ev)
{
	QPoint pos = ev->pos();//窗口坐标
	QPointF pos2 = mapToScene(pos) - QPointF(-img.width() / 2, -img.height() / 2);//控件内坐标
	QPoint pos3(pos2.x(), pos2.y());

	if (pos3.x() < 0 || pos3.y() < 0 || pos3.x() >= img.width() || pos3.y() >= img.height()) return;//超出控件边界就跳出

	QColor color = img.pixelColor(pos3);//读取当前位置信息
	emit colorMessage(color, pos3);//传出信息
}

//双击重置图像尺寸
void GraphicView::mouseDoubleClickEvent(QMouseEvent * ev)
{
	resetTransform();//重置图像尺寸
}

//用鼠标滚轮缩放图像大小
void GraphicView::wheelEvent(QWheelEvent * ev)
{
	int delta = ev->delta();
	ev->setAccepted(true);

	QTransform t;
	if (delta < 0) t.scale(0.9, 0.9);//下滚缩小
	if (delta > 0) t.scale(1.1, 1.1);//上滚放大
    //setTransformationAnchor(ViewportAnchor::AnchorUnderMouse);//以鼠标处为变换中心
	setTransform(t, true);//变换尺寸
}
