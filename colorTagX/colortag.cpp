#include "colortag.h"

colorTag::colorTag(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	time.start(); //开始计时，以ms为单位
	connect(barwindow, SIGNAL(changeMessage(XGradient, QString, int)), this, SLOT(barChange(XGradient, QString, int)));//barwindow传到主窗口的色标信息
	connect(ui.graphicView, SIGNAL(colorMessage(QColor, QPoint)), this, SLOT(colorRefresh(QColor, QPoint)));//graphicView传到主窗口的坐标和颜色信息
	connect(ui.bar, SIGNAL(colorMessage(QColor, float)), this, SLOT(colorRefresh(QColor, float)));//bar传到主窗口的颜色信息

	readSet();//打开时读取色标信息
	currentTag = min(tagSets.count() - 1, 7);//初始化为标准色标
	ui.bar->linearGrad = tagSets[currentTag].second;//更新色标预览栏
	ui.barCombo->setCurrentIndex(currentTag);//更新色标列表

	QImage author1 = QImage("author1.png");//作者头像
	QImage author2 = QImage("author2.png");//作者头像
	QImage author3 = QImage("author3.png");//作者头像
	ui.authorIcon1->setPixmap(QPixmap::fromImage(author1).scaled(ui.authorIcon1->size()));//作者头像
	ui.authorIcon_2->setPixmap(QPixmap::fromImage(author2).scaled(ui.authorIcon_2->size()));//作者头像
	ui.authorIcon_3->setPixmap(QPixmap::fromImage(author3).scaled(ui.authorIcon_3->size()));//作者头像
}

colorTag::~colorTag()
{

}

//将QLinearGradient中色标信息转化为QPixmap，用于图像显示。
QIcon colorTag::QLinearGradient2QIcon(XGradient &tag, double dou)
{
	int w = 1000 * dou, h = 100 * dou;
	QPixmap pixmap(w, h);//图像大小
	QPainter painter(&pixmap);
	painter.fillRect(0, 0, w, h, Qt::GlobalColor::white);
	tag.paintTo(&painter, w, h);

	QIcon icon(pixmap);
	return icon;
}

//读取文件数据，用二维数组储存，并计算出数据最大值和最小值
void colorTag::getInputData()
{
	QFile file(inFilePath);//输入地址
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//只读形式打开文件
		QMessageBox::warning(this, "Warning", "can't open", QMessageBox::Yes);//打不开就报警
	QTextStream in(&file);//数据流

	//metadata.expand_init();

	int i = 0;
	int value;
	while (!in.atEnd()) {//读取到文件末尾
		QString line = in.readLine();//读取一行
		QByteArray &lineBytes = line.toLatin1();//转换为QByteArray数据
		const char *bytesBegin = lineBytes.cbegin();//转换为字符串数据

		int j = 0;
		int pos1 = 0, pos2;
		while (true) {//读取一行中
			pos2 = lineBytes.indexOf('\t', pos1);//按制表符读取
			if (pos2 < 0) break;

			value = atof(&bytesBegin[pos1]);//QByteArray数据转换为double

			if (i == 0) metadata.expand_width_to(j);
			metadata(i, j) = value;//存入数组

			maxValue = maxValue < value ? value : maxValue;//计算最大值
			minValue = value < minValue ? value : minValue;//计算最小值
			j++;
			pos1 = pos2 + 1;
		}
		if (i == 0) width = j;//图像宽
		i++;

		if (i > 1) metadata.expand_height_to(i + 1);
	}
	height = i;//图像高

	data.alloc(width, height);

	file.close();//关闭文件
}

//用拉依达法则去除异常值
void colorTag::pauta()
{
	double sum = 0;//合
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			sum += metadata(i, j);
		}
	}

	double average = sum / height / width;//期望

	double variance = 0;//方差
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			variance += pow((average - metadata(i, j)), 2);
		}
	}
	variance = variance / (height * width - 1);

	double std_dev = sqrt(variance);//标准差

	belifeMaxValue = average + belifeLev * std_dev;//置信数据最大值
	belifeMinValue = average - belifeLev * std_dev;//置信数据最大值

	QString temp;
	ui.belifeMaxLine->setText(temp.setNum(belifeMaxValue));//显示最大数值
	ui.belifeMinLine->setText(temp.setNum(belifeMinValue));//显示最小数值
}


//选择输入文件路径事件
void colorTag::inPath()
{
	QString filePath = QFileDialog::getOpenFileName(//得到文件路径
		this,
		"Open Image",
		QDir::currentPath(),
		"Txt(*.txt);; All files(*.*)");

	if (filePath != "") {//路径存在
		ui.inPathLine->setText(filePath);//显示文件路径
		inFilePath = filePath;//跟新路径
		nameChange = 1;//标记输入地址改变过
		refresh();//刷新
	}
}

//使用重绘色标图像的方式得到色标的离散数值
void colorTag::getColor(XGradient &gradient)
{
	for (int i = 0; i <= segmrnt; i++) {
		map[i] = gradient.getColorAt((double)i / segmrnt);//得到色标的离散数值
	}
}

//使用重绘色标图像的方式得到色标的离散数值
void colorTag::changeTag()
{
	currentTag = ui.barCombo->currentIndex();
	mapChange = true;
	if (time.elapsed() > 2000)	refresh();//防止初始化时运行//刷新
}


//配置信息发生改变时，刷新统计和图像信息
void colorTag::refresh() {

	bool needFit = false;//需要重置图像尺寸
	QString temp;

	if (!inFilePath.isEmpty()) {//输入文件路径存在
		if (nameChange) {
			getInputData();//读取图像信息

			image2 = QImage(width, height, QImage::Format_ARGB32); //创建空图片

			ui.maxLine->setText(temp.setNum(maxValue));//显示最大数值
			ui.minLine->setText(temp.setNum(minValue));//显示最小数值

			nameChange = false;//重置控制信息
			mapChange = true;
			belifeChange = true;
			needFit = true;

			pauta();
		}

		if (belifeChange) {
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					data(i, j) = metadata(i, j) < belifeMinValue ? belifeMinValue : metadata(i, j);//修正数据
					data(i, j) = belifeMaxValue < metadata(i, j) ? belifeMaxValue : metadata(i, j);//修正数据
				}
			}

			belifeChange = false;//重置控制信息
		}
	}

	if (mapChange) {
		getColor(tagSets[currentTag].second);//更新色标离散值

		mapChange = false;//重置控制信息
	}

	ui.bar->linearGrad = tagSets[currentTag].second;//更新色标的显示
	ui.bar->repaint();//刷新

	QColor color;
	int value;
	if ((belifeMaxValue - belifeMinValue) > 0) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				value = data(i, j);
				int mapIdx = (value - belifeMinValue)*segmrnt / (belifeMaxValue - belifeMinValue) - 1;
				if (mapIdx < 0) mapIdx = 0;//防止越界
				if (mapIdx >= segmrnt) mapIdx = segmrnt - 1; //防止越界
				color = map[mapIdx];//得到每个像素的颜色 
				image2.setPixel(j, i, color.rgba());//将颜色放置在每个像素上
			}
		}
	}

	ui.graphicView->showImage(image2);//更新图像
	if (needFit) ui.graphicView->fitImage();//重置图像尺寸
}

//编辑色标事件
void colorTag::barChoose()
{
	barwindow->setLinearGrad(tagSets[currentTag].first, tagSets[currentTag].second, currentTag);//传入色标信息
	barwindow->show();//显示编辑窗口
}

//置信度改变事件
void colorTag::beliefChange()
{
	belifeLev = double(ui.belifeSlider->value()) / 100;//得到置信度值
	pauta();
	belifeChange = true;//置信水平改变过
	refresh();//刷新
}

//色阶改变事件
void colorTag::segmentChange()
{
	segmrnt = ui.segmentSlider->value();////得到色阶数
	mapChange = true;//色标改变过
	ui.bar->segment = segmrnt;
	ui.bar->repaint();
	refresh();//刷新
}

//得到鼠标处图像中的坐标和颜色
void colorTag::colorRefresh(QColor color, QPoint qp)
{
	QString temp;
	ui.RLine->setText(temp.setNum(color.red()));//R
	ui.GLine->setText(temp.setNum(color.green()));//G
	ui.BLine->setText(temp.setNum(color.blue()));//B
	ui.HLine->setText(temp.setNum(color.hue()));//R
	ui.SLine->setText(temp.setNum(color.saturation()));//G
	ui.VLine->setText(temp.setNum(color.value()));//B
	ui.XLine->setText(temp.setNum(qp.x()));//X
	ui.YLine->setText(temp.setNum(qp.y()));//Y
	ui.metaLine->setText(temp.setNum(data(qp.y(), qp.x())));//元数据
}

//得到鼠标处图像中的坐标和颜色
void colorTag::colorRefresh(QColor color, float idx)
{
	QString temp;
	ui.RLine->setText(temp.setNum(color.red()));//R
	ui.GLine->setText(temp.setNum(color.green()));//G
	ui.BLine->setText(temp.setNum(color.blue()));//B
	ui.HLine->setText(temp.setNum(color.hue()));//R
	ui.SLine->setText(temp.setNum(color.saturation()));//G
	ui.VLine->setText(temp.setNum(color.value()));//B
	ui.metaLine->setText(temp.setNum((int)((belifeMaxValue - belifeMinValue)*idx + belifeMinValue + 0.5)));//元数据
}

void colorTag::beliefMinChange()
{
	belifeMinValue = ui.belifeMinLine->text().toInt();
	belifeChange = true;
	refresh();//刷新
}


void colorTag::beliefMaxChange()
{
	belifeMaxValue = ui.belifeMaxLine->text().toInt();
	belifeChange = true;
	refresh();//刷新
}

//得到输出路径事件
void colorTag::outPath()
{
	QString file_path = QFileDialog::getExistingDirectory(this, "Choose path...", "./");
	if (file_path != "") {
		ui.outPathLine->setText(file_path + "/result.png");//更新文件路径
		outFilePath = file_path + "/result.png";//存入类中
	}
}

//保存图像事件
void colorTag::out()
{
	ui.graphicView->img.save(outFilePath);//保存在根目录下
	QMessageBox::information(this, "Save complete.", "Picture has been saved as: " + outFilePath + ".");//弹出对话框
}

//根据barwindow的控制符，采取不同的色标更新手段
void colorTag::barChange(XGradient linearGrad, QString str, int decision)
{
	if (decision == 0) {//修改
		tagSets[currentTag].first = str;
		tagSets[currentTag].second = linearGrad;
		ui.barCombo->removeItem(currentTag);//去掉旧色标
		ui.barCombo->insertItem(currentTag, QLinearGradient2QIcon(linearGrad, 1), str);//添加新色标
		ui.barCombo->setCurrentIndex(currentTag - 1);
	}

	if (decision == 1) {//添加
		for (auto & xiangmu : tagSets) {//在数组内扫描所有色标
			if (xiangmu.first == str) str = str + "_copy";//防止重名
		}
		tagSets.append(XSebiaoXiangmu(str, linearGrad));
		currentTag = tagSets.count() - 1;//新色标序号

		ui.barCombo->addItem(QLinearGradient2QIcon(linearGrad, 1), str);//添加新色标
		ui.barCombo->setCurrentIndex(currentTag);
	}

	if (decision == 2) {//删除
		tagSets.erase(&tagSets[currentTag]);//去掉旧色标
		ui.barCombo->removeItem(currentTag);
		if (currentTag == tagSets.count()) {
			currentTag = currentTag - 1;//更新当前色标序号
		}
	}

	mapChange = true;//色标改变过
	refresh();//刷新
}

//打开时读取色标信息
void colorTag::readSet()
{
	QFile file("save.txt");//存盘名称
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//只读形式打开文件
		QMessageBox::warning(this, "Warning", "can't open", QMessageBox::Yes);//打不开就报警
	QTextStream in(&file);//数据流

	int i = 0;
	int value;
	QGradientStop new_point;
	QGradientStops currentStops;
	QString currentName;
	bool currentHsv;

	while (!in.atEnd()) {
		QString line = in.readLine();
		if (line.length() != 0) {//该行不是空行
			QStringList strlist = line.split("\t");
			if (strlist.count() == 2) {//该行是 差值方式 + 名称
				currentHsv = (strlist[0] == "hsv");
				currentName = strlist[1];
				continue;
			}
			else {//该行是关键点
				new_point.first = strlist.at(0).toDouble();//读取关键点位置
				//读取关键点颜色
				new_point.second = QColor(
					strlist.at(1).toDouble(),
					strlist.at(2).toDouble(),
					strlist.at(3).toDouble(),
					strlist.at(4).toDouble()
					);
				currentStops.append(new_point);//添加关键点
			}
		}
		else {//该行是空行
			XGradient tmp;
			tmp.setInterpolationMode(currentHsv);
			tmp.setStops(currentStops);
			tagSets.append(XSebiaoXiangmu(currentName, tmp));//添加到色标组中
			currentStops.clear();
			i++;//一个色标读取完毕
		}
	}

	file.close();//关闭文件

	ui.barCombo->clear();
	for (auto & xiangmu : tagSets) {
		ui.barCombo->addItem(QLinearGradient2QIcon(xiangmu.second, 1), xiangmu.first);//重写色标选项卡信息
	}
	auto size = ui.barCombo->size();
	size.setWidth(size.width() / 3);
	ui.barCombo->setIconSize(size*1.5);//制定合适色标预览尺寸
}

//关闭时保存色标信息
void colorTag::closeEvent(QCloseEvent *e)
{
	QFile file("save.txt");//存盘名称
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))//只写形式打开文件
		QMessageBox::warning(this, "Warning", "can't open", QMessageBox::Yes);//打不开就报警
	QTextStream in(&file);//数据流

	for (auto & xiangmu : tagSets) {//在数组内扫描所有色标
		auto & linearGrad = xiangmu.second;
		QGradientStops currentStops = linearGrad.stops();//选择一个色标
		in << (linearGrad.getInterpolationMode() ? "hsv" : "rgb")
			<< '\t' << xiangmu.first
			<< endl;//当前色标名
		for (auto & stop : currentStops) {//在色标内扫描所有关键点
			in << stop.first << '\t'//输出关键点位置
												//输出关键点颜色
				<< stop.second.red() << '\t'
				<< stop.second.green() << '\t'
				<< stop.second.blue() << '\t'
				<< stop.second.alpha()
				<< endl;
		}
		in << endl;
	}

	file.close();//关闭文件
}

