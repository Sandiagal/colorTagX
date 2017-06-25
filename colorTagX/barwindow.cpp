#include "barwindow.h"

barWindow::barWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.bar, SIGNAL(colorMessage(QColor, int, int)), this, SLOT(refresh(QColor, int, int)));//���ڴ�����Ϣ�ź���ۺ���������
}

barWindow::~barWindow()
{

}

//���õ�ǰɫ����Ϣ
void barWindow::setLinearGrad(QString str, XGradient linearGrad,int index)
{
	ui.bar->linearGrad = linearGrad;//ɫ��
	ui.bar->currentStops = linearGrad.stops(); //�ؼ���
	ui.bar->currentStopIndex = 0;//��ǰ�ؼ���
	ui.nowLine->setText(str);//��ʾɫ������
	ui.comboBox->setCurrentIndex(linearGrad.getInterpolationMode() ? 1 : 0);//��ֵ��ʽ


	ui.RLine->clear();//������Ϣ
	ui.GLine->clear();
	ui.BLine->clear();
	ui.HLine->clear();
	ui.SLine->clear();
	ui.VLine->clear();
	ui.alphaLine->clear();
	ui.IndexNumLine->clear();
	ui.IndexLine->clear();

	if (index < 11) {//����ԭʼɫ��
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

//�����bar��ʱ������ָ�봦����Ϣ
void barWindow::refresh(QColor color, int count, int index)
{
	QString temp;
	ui.RLine->setText(temp.setNum(color.red()));//R
	ui.GLine->setText(temp.setNum(color.green()));//G
	ui.BLine->setText(temp.setNum(color.blue()));//B
	ui.HLine->setText(temp.setNum(color.hue()));//H
	ui.SLine->setText(temp.setNum(color.saturation()));//S
	ui.VLine->setText(temp.setNum(color.value()));//V
	ui.alphaLine->setText(temp.setNum(color.alpha()));//͸����
	ui.IndexNumLine->setText(temp.setNum(count));//��ǰ�ؼ���
	ui.IndexLine->setText(temp.setNum(index > 0 ? index : 0));//�ؼ�������
}

//�޸�ɫ���¼�
void barWindow::OK()
{
	emit changeMessage(ui.bar->linearGrad, ui.nowLine->text(), 0);//������ǰɫ��Ϳ��Ʒ�
	this->close();//�رմ���
}

//���ɫ���¼�
void barWindow::Add()
{
	emit changeMessage(ui.bar->linearGrad, ui.nowLine->text(), 1);//������ǰɫ��Ϳ��Ʒ�
	this->close();//�رմ���
}

//ɾ��ɫ���¼�
void barWindow::Delete()
{
	emit changeMessage(ui.bar->linearGrad, ui.nowLine->text(), 2);//������ǰɫ��Ϳ��Ʒ�
	this->close();//�رմ���
}

//�رմ����¼�
void barWindow::Cancel()
{
	this->close();
}

//ɫ�귭ת�¼�
void barWindow::Reversal()
{
	ui.bar->Reversal();
}

//ѡ���ֵ�ռ�
void barWindow::InterpolationChange()
{
	ui.bar->InterpolationChange(ui.comboBox->currentIndex());
}
