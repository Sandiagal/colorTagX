#ifndef BARWINDOW_H
#define BARWINDOW_H

#include <QtWidgets/QMainWindow>
#include "BarAdvance.h"
#include "ui_barwindow.h"
#include "xgradient.h"

//ɫ��༭������
class barWindow : public QMainWindow
{
	Q_OBJECT

public:
	barWindow(QWidget *parent = 0);
	~barWindow();
	void setLinearGrad(QString,XGradient,int);
	void setName(QString);

signals:
	void changeMessage(XGradient, QString, int);//�ô��ڴ��������ڵ�ɫ����Ϣ

private:
	Ui::barWindowClass ui;

	private slots:
	void refresh(QColor, int, int);
	void OK();
	void Add();
	void Delete();
	void Cancel();
	void Reversal();
	void InterpolationChange();
};

#endif // BARWINDOW_H
