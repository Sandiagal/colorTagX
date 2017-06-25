#ifndef COLORTAG_H
#define COLORTAG_H

//自动排版：Ctrl + K，Ctrl + F
//注释：先CTRL + K，然后CTRL + C
//取消注释：先CTRL + K，然后CTRL + U

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QPainter>
#include <QImageWriter>
#include <QIcon>
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <QTime>
using namespace std;
#include "ui_colortag.h"
#include "barwindow.h"
#include "xgradient.h"
#include "AmazeBuffer.h"

typedef QPair<QString, XGradient> XSebiaoXiangmu;

//主窗口类
class colorTag : public QMainWindow
{
	Q_OBJECT

public:
	colorTag(QWidget *parent = 0);
	~colorTag();

private:
	Ui::colorTagClass ui;
	barWindow *barwindow = new barWindow;

	QString inFilePath;//输入文件路径
	bool nameChange = true;//输入地址是否改变过
	QImage image1;//输入图像
	int width = 0;//图像宽
	int height = 0;//图像高
	AmazeBuffer metadata;//数据数组
	double belifeLev = 3;//置信水平
	bool belifeChange = true;//置信水平是否改变过
	int maxValue = -INFINITY;//数据最大值
	int minValue = INFINITY;//数据最小值
	int belifeMaxValue = -INFINITY;//置信数据最大值
	int belifeMinValue = INFINITY;//置信数据最大值
	AmazeBuffer data;//置信数据数组
	QVector<XSebiaoXiangmu> tagSets; // 色标大全
	int currentTag = 0;//当前色标编号
	int segmrnt = 100;//色标分段数
	QColor map[1000];//色标的离散数值
	bool mapChange = true;//色标是否改变过
	QImage image2;//输出图像
	QString outFilePath;//输出文件路径
	QTime time;//运行计时

	void refresh();
	void getColor(XGradient &);
	void getInputData();
	void pauta();
	void readSet();
	QIcon QLinearGradient2QIcon(XGradient &,double);

	private slots:
	void inPath();
	void barChoose();
	void outPath();
	void out();
	void changeTag();
	void barChange(XGradient, QString, int);
	void beliefChange();
	void segmentChange();
	void colorRefresh(QColor, QPoint);
	void colorRefresh(QColor, float);
	void beliefMinChange();
	void beliefMaxChange();

protected:
	void closeEvent(QCloseEvent *e);
};

#endif // COLORTAG_H
