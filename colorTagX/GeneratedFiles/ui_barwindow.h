/********************************************************************************
** Form generated from reading UI file 'barwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BARWINDOW_H
#define UI_BARWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "BarAdvance.h"

QT_BEGIN_NAMESPACE

class Ui_barWindowClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *nowLabel;
    QLineEdit *nowLine;
    BarAdvance *bar;
    QGridLayout *gridLayout;
    QLineEdit *SLine;
    QLabel *IndexLabel;
    QLabel *IndexNumLabel;
    QLabel *GLabel;
    QLabel *BLabel;
    QLabel *RLabel;
    QLabel *HLabel;
    QLabel *SLabel;
    QLabel *VLabel;
    QLineEdit *GLine;
    QLineEdit *RLine;
    QLineEdit *IndexLine;
    QLineEdit *HLine;
    QLineEdit *BLine;
    QLineEdit *VLine;
    QLabel *alphaLabel;
    QLineEdit *alphaLine;
    QLineEdit *IndexNumLine;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *reversalButton;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *warning;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *OKButton;
    QPushButton *AddButton;
    QPushButton *deleteButton;
    QPushButton *CancelButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *barWindowClass)
    {
        if (barWindowClass->objectName().isEmpty())
            barWindowClass->setObjectName(QStringLiteral("barWindowClass"));
        barWindowClass->resize(709, 458);
        QIcon icon;
        icon.addFile(QStringLiteral("icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        barWindowClass->setWindowIcon(icon);
        centralWidget = new QWidget(barWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(0, 0));
        centralWidget->setMaximumSize(QSize(999999, 999999));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        nowLabel = new QLabel(centralWidget);
        nowLabel->setObjectName(QStringLiteral("nowLabel"));

        horizontalLayout_3->addWidget(nowLabel);

        nowLine = new QLineEdit(centralWidget);
        nowLine->setObjectName(QStringLiteral("nowLine"));

        horizontalLayout_3->addWidget(nowLine);


        verticalLayout->addLayout(horizontalLayout_3);

        bar = new BarAdvance(centralWidget);
        bar->setObjectName(QStringLiteral("bar"));
        bar->setMinimumSize(QSize(0, 75));

        verticalLayout->addWidget(bar);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        SLine = new QLineEdit(centralWidget);
        SLine->setObjectName(QStringLiteral("SLine"));
        SLine->setReadOnly(true);

        gridLayout->addWidget(SLine, 3, 2, 1, 1);

        IndexLabel = new QLabel(centralWidget);
        IndexLabel->setObjectName(QStringLiteral("IndexLabel"));

        gridLayout->addWidget(IndexLabel, 0, 0, 1, 1);

        IndexNumLabel = new QLabel(centralWidget);
        IndexNumLabel->setObjectName(QStringLiteral("IndexNumLabel"));

        gridLayout->addWidget(IndexNumLabel, 2, 0, 1, 1);

        GLabel = new QLabel(centralWidget);
        GLabel->setObjectName(QStringLiteral("GLabel"));

        gridLayout->addWidget(GLabel, 2, 1, 1, 1);

        BLabel = new QLabel(centralWidget);
        BLabel->setObjectName(QStringLiteral("BLabel"));

        gridLayout->addWidget(BLabel, 4, 1, 1, 1);

        RLabel = new QLabel(centralWidget);
        RLabel->setObjectName(QStringLiteral("RLabel"));

        gridLayout->addWidget(RLabel, 0, 1, 1, 1);

        HLabel = new QLabel(centralWidget);
        HLabel->setObjectName(QStringLiteral("HLabel"));

        gridLayout->addWidget(HLabel, 0, 2, 1, 1);

        SLabel = new QLabel(centralWidget);
        SLabel->setObjectName(QStringLiteral("SLabel"));

        gridLayout->addWidget(SLabel, 2, 2, 1, 1);

        VLabel = new QLabel(centralWidget);
        VLabel->setObjectName(QStringLiteral("VLabel"));

        gridLayout->addWidget(VLabel, 4, 2, 1, 1);

        GLine = new QLineEdit(centralWidget);
        GLine->setObjectName(QStringLiteral("GLine"));
        GLine->setReadOnly(true);

        gridLayout->addWidget(GLine, 3, 1, 1, 1);

        RLine = new QLineEdit(centralWidget);
        RLine->setObjectName(QStringLiteral("RLine"));
        RLine->setReadOnly(true);

        gridLayout->addWidget(RLine, 1, 1, 1, 1);

        IndexLine = new QLineEdit(centralWidget);
        IndexLine->setObjectName(QStringLiteral("IndexLine"));
        IndexLine->setReadOnly(true);

        gridLayout->addWidget(IndexLine, 1, 0, 1, 1);

        HLine = new QLineEdit(centralWidget);
        HLine->setObjectName(QStringLiteral("HLine"));
        HLine->setReadOnly(true);

        gridLayout->addWidget(HLine, 1, 2, 1, 1);

        BLine = new QLineEdit(centralWidget);
        BLine->setObjectName(QStringLiteral("BLine"));
        BLine->setReadOnly(true);

        gridLayout->addWidget(BLine, 5, 1, 1, 1);

        VLine = new QLineEdit(centralWidget);
        VLine->setObjectName(QStringLiteral("VLine"));
        VLine->setReadOnly(true);

        gridLayout->addWidget(VLine, 5, 2, 1, 1);

        alphaLabel = new QLabel(centralWidget);
        alphaLabel->setObjectName(QStringLiteral("alphaLabel"));

        gridLayout->addWidget(alphaLabel, 4, 0, 1, 1);

        alphaLine = new QLineEdit(centralWidget);
        alphaLine->setObjectName(QStringLiteral("alphaLine"));
        alphaLine->setReadOnly(true);

        gridLayout->addWidget(alphaLine, 5, 0, 1, 1);

        IndexNumLine = new QLineEdit(centralWidget);
        IndexNumLine->setObjectName(QStringLiteral("IndexNumLine"));
        IndexNumLine->setReadOnly(true);

        gridLayout->addWidget(IndexNumLine, 3, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        reversalButton = new QPushButton(centralWidget);
        reversalButton->setObjectName(QStringLiteral("reversalButton"));

        horizontalLayout_2->addWidget(reversalButton);


        verticalLayout->addLayout(horizontalLayout_2);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::HLine);

        verticalLayout->addWidget(line);

        verticalSpacer = new QSpacerItem(20, 224, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        warning = new QLabel(centralWidget);
        warning->setObjectName(QStringLiteral("warning"));

        horizontalLayout_4->addWidget(warning);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        OKButton = new QPushButton(centralWidget);
        OKButton->setObjectName(QStringLiteral("OKButton"));

        horizontalLayout->addWidget(OKButton);

        AddButton = new QPushButton(centralWidget);
        AddButton->setObjectName(QStringLiteral("AddButton"));

        horizontalLayout->addWidget(AddButton);

        deleteButton = new QPushButton(centralWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout->addWidget(deleteButton);

        CancelButton = new QPushButton(centralWidget);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));

        horizontalLayout->addWidget(CancelButton);


        verticalLayout->addLayout(horizontalLayout);

        barWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(barWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 709, 26));
        barWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(barWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        barWindowClass->setStatusBar(statusBar);

        retranslateUi(barWindowClass);
        QObject::connect(OKButton, SIGNAL(clicked()), barWindowClass, SLOT(OK()));
        QObject::connect(CancelButton, SIGNAL(clicked()), barWindowClass, SLOT(Cancel()));
        QObject::connect(AddButton, SIGNAL(clicked()), barWindowClass, SLOT(Add()));
        QObject::connect(deleteButton, SIGNAL(clicked()), barWindowClass, SLOT(Delete()));
        QObject::connect(comboBox, SIGNAL(currentIndexChanged(QString)), barWindowClass, SLOT(InterpolationChange()));
        QObject::connect(reversalButton, SIGNAL(clicked()), barWindowClass, SLOT(Reversal()));

        QMetaObject::connectSlotsByName(barWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *barWindowClass)
    {
        barWindowClass->setWindowTitle(QApplication::translate("barWindowClass", "\350\211\262\346\240\207\347\274\226\350\276\221\347\252\227", Q_NULLPTR));
        nowLabel->setText(QApplication::translate("barWindowClass", "\346\240\267\345\274\217\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        nowLine->setText(QString());
        IndexLabel->setText(QApplication::translate("barWindowClass", "\345\275\223\345\211\215\345\205\263\351\224\256\347\202\271\345\272\217\345\217\267:", Q_NULLPTR));
        IndexNumLabel->setText(QApplication::translate("barWindowClass", "\345\205\263\351\224\256\347\202\271\346\200\273\346\225\260:", Q_NULLPTR));
        GLabel->setText(QApplication::translate("barWindowClass", "G:", Q_NULLPTR));
        BLabel->setText(QApplication::translate("barWindowClass", "B:", Q_NULLPTR));
        RLabel->setText(QApplication::translate("barWindowClass", "R:", Q_NULLPTR));
        HLabel->setText(QApplication::translate("barWindowClass", "H:", Q_NULLPTR));
        SLabel->setText(QApplication::translate("barWindowClass", "S:", Q_NULLPTR));
        VLabel->setText(QApplication::translate("barWindowClass", "V:", Q_NULLPTR));
        alphaLabel->setText(QApplication::translate("barWindowClass", "\351\200\217\346\230\216\345\272\246\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("barWindowClass", "\345\267\256\345\200\274\347\251\272\351\227\264\357\274\232", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("barWindowClass", "RGB", Q_NULLPTR)
         << QApplication::translate("barWindowClass", "HSV", Q_NULLPTR)
        );
        reversalButton->setText(QApplication::translate("barWindowClass", "\350\211\262\346\240\207\345\217\215\350\275\254", Q_NULLPTR));
        warning->setText(QApplication::translate("barWindowClass", "\346\263\250\346\204\217\357\274\232\351\242\204\347\275\256\350\211\262\346\240\207\347\246\201\346\255\242\344\277\256\346\224\271\357\274\201", Q_NULLPTR));
        OKButton->setText(QApplication::translate("barWindowClass", "\344\277\256\346\224\271", Q_NULLPTR));
        AddButton->setText(QApplication::translate("barWindowClass", "\346\267\273\345\212\240", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("barWindowClass", "\345\210\240\351\231\244", Q_NULLPTR));
        CancelButton->setText(QApplication::translate("barWindowClass", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class barWindowClass: public Ui_barWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BARWINDOW_H
