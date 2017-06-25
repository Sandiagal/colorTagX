/********************************************************************************
** Form generated from reading UI file 'colortag.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORTAG_H
#define UI_COLORTAG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "GraphicView.h"
#include "barsimple.h"

QT_BEGIN_NAMESPACE

class Ui_colorTagClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    GraphicView *graphicView;
    barSimple *bar;
    QGridLayout *gridLayout_3;
    QLabel *GLabel;
    QLabel *YLabel;
    QLineEdit *YLine;
    QLineEdit *XLine;
    QLabel *RLabel;
    QLineEdit *GLine;
    QLineEdit *RLine;
    QLabel *XLabel;
    QLabel *metaLabel;
    QLineEdit *metaLine;
    QLabel *BLabel;
    QLineEdit *BLine;
    QLabel *HLabel;
    QLabel *SLabel;
    QLabel *VLabel;
    QLineEdit *HLine;
    QLineEdit *SLine;
    QLineEdit *VLine;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QLabel *inPathLable;
    QHBoxLayout *horizontalLayout;
    QLineEdit *inPathLine;
    QPushButton *inPathButton;
    QHBoxLayout *horizontalLayout_5;
    QLabel *barLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *barButton;
    QComboBox *barCombo;
    QFrame *line;
    QGridLayout *gridLayout_2;
    QLabel *maxLabel;
    QLabel *minLabel;
    QLineEdit *minLine;
    QLineEdit *maxLine;
    QLineEdit *belifeMinLine;
    QLabel *belifeMaxLabel;
    QLabel *belifeMinLabel;
    QLineEdit *belifeMaxLine;
    QLabel *belifeLabel;
    QSlider *belifeSlider;
    QLabel *segmentLabel;
    QSlider *segmentSlider;
    QFrame *line_2;
    QLabel *outPathLable;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *outPathLine;
    QPushButton *outPathButton;
    QPushButton *outButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *authorIcon1;
    QFrame *line_3;
    QLabel *authorIcon_2;
    QLabel *label;
    QLabel *authorIcon_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *colorTagClass)
    {
        if (colorTagClass->objectName().isEmpty())
            colorTagClass->setObjectName(QStringLiteral("colorTagClass"));
        colorTagClass->resize(977, 772);
        QIcon icon;
        icon.addFile(QStringLiteral("icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        colorTagClass->setWindowIcon(icon);
        centralWidget = new QWidget(colorTagClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicView = new GraphicView(centralWidget);
        graphicView->setObjectName(QStringLiteral("graphicView"));
        graphicView->setMinimumSize(QSize(500, 500));

        verticalLayout->addWidget(graphicView);

        bar = new barSimple(centralWidget);
        bar->setObjectName(QStringLiteral("bar"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bar->sizePolicy().hasHeightForWidth());
        bar->setSizePolicy(sizePolicy);
        bar->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(bar);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        GLabel = new QLabel(centralWidget);
        GLabel->setObjectName(QStringLiteral("GLabel"));

        gridLayout_3->addWidget(GLabel, 2, 1, 1, 1);

        YLabel = new QLabel(centralWidget);
        YLabel->setObjectName(QStringLiteral("YLabel"));

        gridLayout_3->addWidget(YLabel, 2, 0, 1, 1);

        YLine = new QLineEdit(centralWidget);
        YLine->setObjectName(QStringLiteral("YLine"));
        YLine->setReadOnly(true);

        gridLayout_3->addWidget(YLine, 3, 0, 1, 1);

        XLine = new QLineEdit(centralWidget);
        XLine->setObjectName(QStringLiteral("XLine"));
        XLine->setReadOnly(true);

        gridLayout_3->addWidget(XLine, 1, 0, 1, 1);

        RLabel = new QLabel(centralWidget);
        RLabel->setObjectName(QStringLiteral("RLabel"));

        gridLayout_3->addWidget(RLabel, 0, 1, 1, 1);

        GLine = new QLineEdit(centralWidget);
        GLine->setObjectName(QStringLiteral("GLine"));
        GLine->setReadOnly(true);

        gridLayout_3->addWidget(GLine, 3, 1, 1, 1);

        RLine = new QLineEdit(centralWidget);
        RLine->setObjectName(QStringLiteral("RLine"));
        RLine->setReadOnly(true);

        gridLayout_3->addWidget(RLine, 1, 1, 1, 1);

        XLabel = new QLabel(centralWidget);
        XLabel->setObjectName(QStringLiteral("XLabel"));

        gridLayout_3->addWidget(XLabel, 0, 0, 1, 1);

        metaLabel = new QLabel(centralWidget);
        metaLabel->setObjectName(QStringLiteral("metaLabel"));

        gridLayout_3->addWidget(metaLabel, 4, 0, 1, 1);

        metaLine = new QLineEdit(centralWidget);
        metaLine->setObjectName(QStringLiteral("metaLine"));
        metaLine->setReadOnly(true);

        gridLayout_3->addWidget(metaLine, 5, 0, 1, 1);

        BLabel = new QLabel(centralWidget);
        BLabel->setObjectName(QStringLiteral("BLabel"));

        gridLayout_3->addWidget(BLabel, 4, 1, 1, 1);

        BLine = new QLineEdit(centralWidget);
        BLine->setObjectName(QStringLiteral("BLine"));
        BLine->setReadOnly(true);

        gridLayout_3->addWidget(BLine, 5, 1, 1, 1);

        HLabel = new QLabel(centralWidget);
        HLabel->setObjectName(QStringLiteral("HLabel"));

        gridLayout_3->addWidget(HLabel, 0, 2, 1, 1);

        SLabel = new QLabel(centralWidget);
        SLabel->setObjectName(QStringLiteral("SLabel"));

        gridLayout_3->addWidget(SLabel, 2, 2, 1, 1);

        VLabel = new QLabel(centralWidget);
        VLabel->setObjectName(QStringLiteral("VLabel"));

        gridLayout_3->addWidget(VLabel, 4, 2, 1, 1);

        HLine = new QLineEdit(centralWidget);
        HLine->setObjectName(QStringLiteral("HLine"));
        HLine->setReadOnly(true);

        gridLayout_3->addWidget(HLine, 1, 2, 1, 1);

        SLine = new QLineEdit(centralWidget);
        SLine->setObjectName(QStringLiteral("SLine"));
        SLine->setReadOnly(true);

        gridLayout_3->addWidget(SLine, 3, 2, 1, 1);

        VLine = new QLineEdit(centralWidget);
        VLine->setObjectName(QStringLiteral("VLine"));
        VLine->setReadOnly(true);

        gridLayout_3->addWidget(VLine, 5, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        colorTagClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(colorTagClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 977, 26));
        colorTagClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(colorTagClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        colorTagClass->setStatusBar(statusBar);
        dockWidget = new QDockWidget(colorTagClass);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        inPathLable = new QLabel(dockWidgetContents);
        inPathLable->setObjectName(QStringLiteral("inPathLable"));

        verticalLayout_3->addWidget(inPathLable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        inPathLine = new QLineEdit(dockWidgetContents);
        inPathLine->setObjectName(QStringLiteral("inPathLine"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(inPathLine->sizePolicy().hasHeightForWidth());
        inPathLine->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(inPathLine);

        inPathButton = new QPushButton(dockWidgetContents);
        inPathButton->setObjectName(QStringLiteral("inPathButton"));

        horizontalLayout->addWidget(inPathButton);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        barLabel = new QLabel(dockWidgetContents);
        barLabel->setObjectName(QStringLiteral("barLabel"));
        barLabel->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_5->addWidget(barLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        barButton = new QPushButton(dockWidgetContents);
        barButton->setObjectName(QStringLiteral("barButton"));

        horizontalLayout_5->addWidget(barButton);


        verticalLayout_3->addLayout(horizontalLayout_5);

        barCombo = new QComboBox(dockWidgetContents);
        barCombo->setObjectName(QStringLiteral("barCombo"));
        barCombo->setIconSize(QSize(20, 20));

        verticalLayout_3->addWidget(barCombo);

        line = new QFrame(dockWidgetContents);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(1);
        line->setMidLineWidth(0);
        line->setFrameShape(QFrame::HLine);

        verticalLayout_3->addWidget(line);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        maxLabel = new QLabel(dockWidgetContents);
        maxLabel->setObjectName(QStringLiteral("maxLabel"));

        gridLayout_2->addWidget(maxLabel, 0, 1, 1, 1);

        minLabel = new QLabel(dockWidgetContents);
        minLabel->setObjectName(QStringLiteral("minLabel"));

        gridLayout_2->addWidget(minLabel, 0, 0, 1, 1);

        minLine = new QLineEdit(dockWidgetContents);
        minLine->setObjectName(QStringLiteral("minLine"));
        minLine->setReadOnly(true);

        gridLayout_2->addWidget(minLine, 1, 0, 1, 1);

        maxLine = new QLineEdit(dockWidgetContents);
        maxLine->setObjectName(QStringLiteral("maxLine"));
        maxLine->setReadOnly(true);

        gridLayout_2->addWidget(maxLine, 1, 1, 1, 1);

        belifeMinLine = new QLineEdit(dockWidgetContents);
        belifeMinLine->setObjectName(QStringLiteral("belifeMinLine"));

        gridLayout_2->addWidget(belifeMinLine, 3, 0, 1, 1);

        belifeMaxLabel = new QLabel(dockWidgetContents);
        belifeMaxLabel->setObjectName(QStringLiteral("belifeMaxLabel"));

        gridLayout_2->addWidget(belifeMaxLabel, 2, 1, 1, 1);

        belifeMinLabel = new QLabel(dockWidgetContents);
        belifeMinLabel->setObjectName(QStringLiteral("belifeMinLabel"));

        gridLayout_2->addWidget(belifeMinLabel, 2, 0, 1, 1);

        belifeMaxLine = new QLineEdit(dockWidgetContents);
        belifeMaxLine->setObjectName(QStringLiteral("belifeMaxLine"));

        gridLayout_2->addWidget(belifeMaxLine, 3, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        belifeLabel = new QLabel(dockWidgetContents);
        belifeLabel->setObjectName(QStringLiteral("belifeLabel"));

        verticalLayout_3->addWidget(belifeLabel);

        belifeSlider = new QSlider(dockWidgetContents);
        belifeSlider->setObjectName(QStringLiteral("belifeSlider"));
        belifeSlider->setMinimum(100);
        belifeSlider->setMaximum(500);
        belifeSlider->setSingleStep(10);
        belifeSlider->setPageStep(10);
        belifeSlider->setValue(300);
        belifeSlider->setSliderPosition(300);
        belifeSlider->setTracking(true);
        belifeSlider->setOrientation(Qt::Horizontal);
        belifeSlider->setTickPosition(QSlider::TicksBothSides);
        belifeSlider->setTickInterval(50);

        verticalLayout_3->addWidget(belifeSlider);

        segmentLabel = new QLabel(dockWidgetContents);
        segmentLabel->setObjectName(QStringLiteral("segmentLabel"));

        verticalLayout_3->addWidget(segmentLabel);

        segmentSlider = new QSlider(dockWidgetContents);
        segmentSlider->setObjectName(QStringLiteral("segmentSlider"));
        segmentSlider->setMinimum(1);
        segmentSlider->setMaximum(256);
        segmentSlider->setSingleStep(10);
        segmentSlider->setValue(50);
        segmentSlider->setSliderPosition(50);
        segmentSlider->setOrientation(Qt::Horizontal);
        segmentSlider->setTickPosition(QSlider::TicksBothSides);
        segmentSlider->setTickInterval(20);

        verticalLayout_3->addWidget(segmentSlider);

        line_2 = new QFrame(dockWidgetContents);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(1);
        line_2->setMidLineWidth(0);
        line_2->setFrameShape(QFrame::HLine);

        verticalLayout_3->addWidget(line_2);

        outPathLable = new QLabel(dockWidgetContents);
        outPathLable->setObjectName(QStringLiteral("outPathLable"));

        verticalLayout_3->addWidget(outPathLable);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        outPathLine = new QLineEdit(dockWidgetContents);
        outPathLine->setObjectName(QStringLiteral("outPathLine"));

        horizontalLayout_2->addWidget(outPathLine);

        outPathButton = new QPushButton(dockWidgetContents);
        outPathButton->setObjectName(QStringLiteral("outPathButton"));

        horizontalLayout_2->addWidget(outPathButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        outButton = new QPushButton(dockWidgetContents);
        outButton->setObjectName(QStringLiteral("outButton"));

        verticalLayout_3->addWidget(outButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        authorIcon1 = new QLabel(dockWidgetContents);
        authorIcon1->setObjectName(QStringLiteral("authorIcon1"));
        authorIcon1->setMinimumSize(QSize(75, 75));

        horizontalLayout_3->addWidget(authorIcon1);

        line_3 = new QFrame(dockWidgetContents);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_3);

        authorIcon_2 = new QLabel(dockWidgetContents);
        authorIcon_2->setObjectName(QStringLiteral("authorIcon_2"));
        authorIcon_2->setMinimumSize(QSize(75, 75));

        horizontalLayout_3->addWidget(authorIcon_2);

        label = new QLabel(dockWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        authorIcon_3 = new QLabel(dockWidgetContents);
        authorIcon_3->setObjectName(QStringLiteral("authorIcon_3"));
        authorIcon_3->setMinimumSize(QSize(75, 75));

        horizontalLayout_3->addWidget(authorIcon_3);

        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        dockWidget->setWidget(dockWidgetContents);
        colorTagClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        retranslateUi(colorTagClass);
        QObject::connect(inPathButton, SIGNAL(clicked()), colorTagClass, SLOT(inPath()));
        QObject::connect(outPathButton, SIGNAL(clicked()), colorTagClass, SLOT(outPath()));
        QObject::connect(barButton, SIGNAL(clicked()), colorTagClass, SLOT(barChoose()));
        QObject::connect(outButton, SIGNAL(clicked()), colorTagClass, SLOT(out()));
        QObject::connect(barCombo, SIGNAL(currentIndexChanged(QString)), colorTagClass, SLOT(changeTag()));
        QObject::connect(segmentSlider, SIGNAL(actionTriggered(int)), colorTagClass, SLOT(segmentChange()));
        QObject::connect(belifeSlider, SIGNAL(actionTriggered(int)), colorTagClass, SLOT(beliefChange()));
        QObject::connect(belifeMinLine, SIGNAL(textChanged(QString)), colorTagClass, SLOT(beliefMinChange()));
        QObject::connect(belifeMaxLine, SIGNAL(textChanged(QString)), colorTagClass, SLOT(beliefMaxChange()));

        QMetaObject::connectSlotsByName(colorTagClass);
    } // setupUi

    void retranslateUi(QMainWindow *colorTagClass)
    {
        colorTagClass->setWindowTitle(QApplication::translate("colorTagClass", "\350\211\262\346\240\207\346\217\222\344\273\266", Q_NULLPTR));
        GLabel->setText(QApplication::translate("colorTagClass", "G:", Q_NULLPTR));
        YLabel->setText(QApplication::translate("colorTagClass", "Y:", Q_NULLPTR));
        RLabel->setText(QApplication::translate("colorTagClass", "R:", Q_NULLPTR));
        XLabel->setText(QApplication::translate("colorTagClass", "X:", Q_NULLPTR));
        metaLabel->setText(QApplication::translate("colorTagClass", "\345\216\237\345\247\213\346\225\260\346\215\256\357\274\232", Q_NULLPTR));
        BLabel->setText(QApplication::translate("colorTagClass", "B\357\274\232", Q_NULLPTR));
        HLabel->setText(QApplication::translate("colorTagClass", "H\357\274\232", Q_NULLPTR));
        SLabel->setText(QApplication::translate("colorTagClass", "S:", Q_NULLPTR));
        VLabel->setText(QApplication::translate("colorTagClass", "V:", Q_NULLPTR));
        inPathLable->setText(QApplication::translate("colorTagClass", "\350\276\223\345\205\245\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", Q_NULLPTR));
        inPathButton->setText(QApplication::translate("colorTagClass", "\351\200\211\346\213\251\350\267\257\345\276\204", Q_NULLPTR));
        barLabel->setText(QApplication::translate("colorTagClass", "\345\275\223\345\211\215\350\211\262\346\240\207\351\242\204\350\247\210\357\274\232", Q_NULLPTR));
        barButton->setText(QApplication::translate("colorTagClass", "\347\274\226\350\276\221\346\240\267\345\274\217", Q_NULLPTR));
        maxLabel->setText(QApplication::translate("colorTagClass", "\346\234\200\345\244\247\345\200\274\357\274\232", Q_NULLPTR));
        minLabel->setText(QApplication::translate("colorTagClass", "\346\234\200\345\260\217\345\200\274\357\274\232", Q_NULLPTR));
        belifeMaxLabel->setText(QApplication::translate("colorTagClass", "\347\275\256\344\277\241\346\234\200\345\244\247\345\200\274\357\274\232", Q_NULLPTR));
        belifeMinLabel->setText(QApplication::translate("colorTagClass", "\347\275\256\344\277\241\346\234\200\345\260\217\345\200\274\357\274\232", Q_NULLPTR));
        belifeLabel->setText(QApplication::translate("colorTagClass", "\346\225\260\346\215\256\347\275\256\344\277\241\346\260\264\345\271\263\357\274\232\357\274\210\346\213\211\344\276\235\350\276\276\346\263\225\345\210\231\357\274\211", Q_NULLPTR));
        segmentLabel->setText(QApplication::translate("colorTagClass", "\350\211\262\351\230\266\346\225\260\357\274\232", Q_NULLPTR));
        outPathLable->setText(QApplication::translate("colorTagClass", "\350\276\223\345\207\272\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", Q_NULLPTR));
        outPathButton->setText(QApplication::translate("colorTagClass", "\351\200\211\346\213\251\350\267\257\345\276\204", Q_NULLPTR));
        outButton->setText(QApplication::translate("colorTagClass", "\350\276\223\345\207\272", Q_NULLPTR));
        authorIcon1->setText(QString());
        authorIcon_2->setText(QString());
        label->setText(QApplication::translate("colorTagClass", "Sandiagle", Q_NULLPTR));
        authorIcon_3->setText(QString());
        label_2->setText(QApplication::translate("colorTagClass", "Argh", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class colorTagClass: public Ui_colorTagClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORTAG_H
