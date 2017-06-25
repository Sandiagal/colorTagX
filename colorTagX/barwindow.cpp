#include "barwindow.h"

barWindow::barWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.bar, SIGNAL(colorMessage(QColor, int, int)), this, SLOT(refresh(QColor, int, int)));//窗口传递信息信号与槽函数的连接
}

barWindow::~barWindow()
{

}

//设置当前色标信息
void barWindow::setLinearGrad(QString str, XGradient linearGrad,int index)
{
	ui.bar->linearGrad = linearGrad;//色标
	ui.bar->currentStops = linearGrad.stops(); //关键点
	ui.bar->currentStopIndex = 0;//当前关键点
	ui.nowLine->setText(str);//显示色标名称
	ui.comboBox->setCurrentIndex(linearGrad.getInterpolationMode() ? 1 : 0);//差值方式


	ui.RLine->clear();//重置信息
	ui.GLine->clear();
	ui.BLine->clear();
	ui.HLine->clear();
	ui.SLine->clear();
	ui.VLine->clear();
	ui.alphaLine->clear();
	ui.IndexNumLine->clear();
	ui.IndexLine->clear();

	if (index < 11) {//保护原始色标
		ui.OKButton->setEnabled(false);
		ui.deleteButton->setEnabled(false);
		ui.warning->show();
	}
	else {
		ui.OKButton->setEnabled(true);
		ui.deleteButton->setEnabled(true);
		ui.warning->hide();
	}
}

//鼠标在bar上时，返回指针处的信息
void barWindow::refresh(QColor color, int count, int index)
{
	QString temp;
	ui.RLine->setText(temp.setNum(color.red()));//R
	ui.GLine->setText(temp.setNum(color.green()));//G
	ui.BLine->setText(temp.setNum(color.blue()));//B
	ui.HLine->setText(temp.setNum(color.hue()));//H
	ui.SLine->setText(temp.setNum(color.saturation()));//S
	ui.VLine->setText(temp.setNum(color.value()));//V
	ui.alphaLine->setText(temp.setNum(color.alpha()));//透明度
	ui.IndexNumLine->setText(temp.setNum(count));//当前关键点
	ui.IndexLine->setText(temp.setNum(index > 0 ? index : 0));//关键点总数
}

//修改色标事件
void barWindow::OK()
{
	emit changeMessage(ui.bar->linearGrad, ui.nowLine->text(), 0);//传出当前色标和控制符
	this->close();//关闭窗口
}

//添加色标事件
void barWindow::Add()
{
	emit changeMessage(ui.bar->linearGrad, ui.nowLine->text(), 1);//传出当前色标和控制符
	this->close();//关闭窗口
}

//删除色标事件
void barWindow::Delete()
{
	emit changeMessage(ui.bar->linearGrad, ui.nowLine->text(), 2);//传出当前色标和控制符
	this->close();//关闭窗口
}

//关闭窗口事件
void barWindow::Cancel()
{
	this->close();
}

//色标翻转事件
void barWindow::Reversal()
{
	ui.bar->Reversal();
}

//选择差值空间
void barWindow::InterpolationChange()
{
	ui.bar->InterpolationChange(ui.comboBox->currentIndex());
}
