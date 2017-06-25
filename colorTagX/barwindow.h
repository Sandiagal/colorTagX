#ifndef BARWINDOW_H
#define BARWINDOW_H

#include <QtWidgets/QMainWindow>
#include "BarAdvance.h"
#include "ui_barwindow.h"
#include "xgradient.h"

//色标编辑窗口类
class barWindow : public QMainWindow
{
	Q_OBJECT

public:
	barWindow(QWidget *parent = 0);
	~barWindow();
	void setLinearGrad(QString,XGradient,int);
	void setName(QString);

signals:
	void changeMessage(XGradient, QString, int);//该窗口传到主窗口的色标信息

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
