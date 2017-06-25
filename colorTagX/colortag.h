#ifndef COLORTAG_H
#define COLORTAG_H

//�Զ��Ű棺Ctrl + K��Ctrl + F
//ע�ͣ���CTRL + K��Ȼ��CTRL + C
//ȡ��ע�ͣ���CTRL + K��Ȼ��CTRL + U

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

//��������
class colorTag : public QMainWindow
{
	Q_OBJECT

public:
	colorTag(QWidget *parent = 0);
	~colorTag();

private:
	Ui::colorTagClass ui;
	barWindow *barwindow = new barWindow;

	QString inFilePath;//�����ļ�·��
	bool nameChange = true;//�����ַ�Ƿ�ı��
	QImage image1;//����ͼ��
	int width = 0;//ͼ���
	int height = 0;//ͼ���
	AmazeBuffer metadata;//��������
	double belifeLev = 3;//����ˮƽ
	bool belifeChange = true;//����ˮƽ�Ƿ�ı��
	int maxValue = -INFINITY;//�������ֵ
	int minValue = INFINITY;//������Сֵ
	int belifeMaxValue = -INFINITY;//�����������ֵ
	int belifeMinValue = INFINITY;//�����������ֵ
	AmazeBuffer data;//������������
	QVector<XSebiaoXiangmu> tagSets; // ɫ���ȫ
	int currentTag = 0;//��ǰɫ����
	int segmrnt = 100;//ɫ��ֶ���
	QColor map[1000];//ɫ�����ɢ��ֵ
	bool mapChange = true;//ɫ���Ƿ�ı��
	QImage image2;//���ͼ��
	QString outFilePath;//����ļ�·��
	QTime time;//���м�ʱ

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
