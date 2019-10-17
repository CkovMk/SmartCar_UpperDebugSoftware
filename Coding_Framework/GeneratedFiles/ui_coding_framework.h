/********************************************************************************
** Form generated from reading UI file 'coding_framework.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODING_FRAMEWORK_H
#define UI_CODING_FRAMEWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Coding_FrameworkClass
{
public:
    QWidget *centralWidget;
    QTabWidget *MainTab;
    QWidget *serial;
    QComboBox *SerialPortSelect;
    QSpinBox *BaudRateSelect;
    QPlainTextEdit *plainTextEdit;
    QFrame *line;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QWidget *menu;
    QPushButton *KEY_UP;
    QPushButton *KEY_OK;
    QPushButton *KEY_DN;
    QPushButton *KEY_RT;
    QPushButton *KEY_LF;
    QCheckBox *menuOption0;
    QCheckBox *menuOption1;
    QCheckBox *menuOption2;
    QCheckBox *menuOption3;
    QCheckBox *menuOption4;
    QScrollArea *menuDisp;
    QWidget *scrollAreaWidgetContents_2;
    QPushButton *KEY_LUP;
    QPushButton *KEY_LDN;
    QPushButton *KEY_LLF;
    QPushButton *KEY_LOK;
    QPushButton *KEY_LRT;
    QWidget *image;
    QCheckBox *imageOption0;
    QCheckBox *imageOption4;
    QCheckBox *imageOption1;
    QCheckBox *imageOption2;
    QCheckBox *imageOption3;
    QLineEdit *imgDirInput1;
    QToolButton *imgDirSelect1;
    QPushButton *imagePrev;
    QPushButton *imageNext;
    QLabel *imageName;
    QPushButton *imageSerialOnOff;
    QPushButton *imageSerialRefresh;
    QScrollArea *imageDisp;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *imageIptDisp;
    QWidget *scrollAreaWidgetContents_3;
    QToolButton *imgDirSelect2;
    QLineEdit *imgDirInput2;
    QToolButton *imgDirSelect3;
    QLineEdit *imgDirInput3;
    QCheckBox *imageOption5;
    QLabel *imageNumber;

    void setupUi(QMainWindow *Coding_FrameworkClass)
    {
        if (Coding_FrameworkClass->objectName().isEmpty())
            Coding_FrameworkClass->setObjectName(QString::fromUtf8("Coding_FrameworkClass"));
        Coding_FrameworkClass->resize(800, 501);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Coding_FrameworkClass->sizePolicy().hasHeightForWidth());
        Coding_FrameworkClass->setSizePolicy(sizePolicy);
        Coding_FrameworkClass->setMinimumSize(QSize(800, 500));
        Coding_FrameworkClass->setMaximumSize(QSize(800, 501));
        centralWidget = new QWidget(Coding_FrameworkClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainTab = new QTabWidget(centralWidget);
        MainTab->setObjectName(QString::fromUtf8("MainTab"));
        MainTab->setGeometry(QRect(1, 1, 800, 500));
        sizePolicy.setHeightForWidth(MainTab->sizePolicy().hasHeightForWidth());
        MainTab->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(10);
        MainTab->setFont(font);
        MainTab->setAcceptDrops(false);
        MainTab->setTabPosition(QTabWidget::North);
        MainTab->setTabShape(QTabWidget::Rounded);
        serial = new QWidget();
        serial->setObjectName(QString::fromUtf8("serial"));
        SerialPortSelect = new QComboBox(serial);
        SerialPortSelect->setObjectName(QString::fromUtf8("SerialPortSelect"));
        SerialPortSelect->setGeometry(QRect(10, 20, 111, 25));
        BaudRateSelect = new QSpinBox(serial);
        BaudRateSelect->setObjectName(QString::fromUtf8("BaudRateSelect"));
        BaudRateSelect->setGeometry(QRect(10, 60, 121, 22));
        BaudRateSelect->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BaudRateSelect->setMinimum(1000);
        BaudRateSelect->setMaximum(5000000);
        BaudRateSelect->setSingleStep(100);
        BaudRateSelect->setStepType(QAbstractSpinBox::DefaultStepType);
        BaudRateSelect->setValue(115200);
        plainTextEdit = new QPlainTextEdit(serial);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(180, 300, 601, 141));
        line = new QFrame(serial);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(160, 10, 16, 451));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        textBrowser = new QTextBrowser(serial);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(180, 10, 601, 281));
        pushButton = new QPushButton(serial);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 20, 40, 25));
        MainTab->addTab(serial, QString());
        menu = new QWidget();
        menu->setObjectName(QString::fromUtf8("menu"));
        KEY_UP = new QPushButton(menu);
        KEY_UP->setObjectName(QString::fromUtf8("KEY_UP"));
        KEY_UP->setEnabled(true);
        KEY_UP->setGeometry(QRect(320, 110, 41, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        KEY_UP->setFont(font1);
        KEY_UP->setCursor(QCursor(Qt::CrossCursor));
        KEY_UP->setAutoFillBackground(false);
        KEY_UP->setCheckable(false);
        KEY_UP->setAutoRepeat(true);
        KEY_UP->setFlat(false);
        KEY_OK = new QPushButton(menu);
        KEY_OK->setObjectName(QString::fromUtf8("KEY_OK"));
        KEY_OK->setEnabled(true);
        KEY_OK->setGeometry(QRect(320, 160, 41, 41));
        KEY_OK->setFont(font1);
        KEY_OK->setCursor(QCursor(Qt::CrossCursor));
        KEY_OK->setAutoFillBackground(false);
        KEY_OK->setCheckable(false);
        KEY_OK->setAutoRepeat(true);
        KEY_OK->setFlat(false);
        KEY_DN = new QPushButton(menu);
        KEY_DN->setObjectName(QString::fromUtf8("KEY_DN"));
        KEY_DN->setEnabled(true);
        KEY_DN->setGeometry(QRect(320, 210, 41, 41));
        KEY_DN->setFont(font1);
        KEY_DN->setCursor(QCursor(Qt::CrossCursor));
        KEY_DN->setAutoFillBackground(false);
        KEY_DN->setCheckable(false);
        KEY_DN->setAutoRepeat(true);
        KEY_DN->setFlat(false);
        KEY_RT = new QPushButton(menu);
        KEY_RT->setObjectName(QString::fromUtf8("KEY_RT"));
        KEY_RT->setEnabled(true);
        KEY_RT->setGeometry(QRect(370, 160, 41, 41));
        KEY_RT->setFont(font1);
        KEY_RT->setCursor(QCursor(Qt::CrossCursor));
        KEY_RT->setAutoFillBackground(false);
        KEY_RT->setCheckable(false);
        KEY_RT->setAutoRepeat(true);
        KEY_RT->setFlat(false);
        KEY_LF = new QPushButton(menu);
        KEY_LF->setObjectName(QString::fromUtf8("KEY_LF"));
        KEY_LF->setEnabled(true);
        KEY_LF->setGeometry(QRect(270, 160, 41, 41));
        KEY_LF->setFont(font1);
        KEY_LF->setCursor(QCursor(Qt::CrossCursor));
        KEY_LF->setAutoFillBackground(false);
        KEY_LF->setCheckable(false);
        KEY_LF->setAutoRepeat(true);
        KEY_LF->setFlat(false);
        menuOption0 = new QCheckBox(menu);
        menuOption0->setObjectName(QString::fromUtf8("menuOption0"));
        menuOption0->setGeometry(QRect(20, 260, 220, 30));
        menuOption1 = new QCheckBox(menu);
        menuOption1->setObjectName(QString::fromUtf8("menuOption1"));
        menuOption1->setGeometry(QRect(20, 290, 220, 30));
        menuOption2 = new QCheckBox(menu);
        menuOption2->setObjectName(QString::fromUtf8("menuOption2"));
        menuOption2->setGeometry(QRect(20, 320, 220, 30));
        menuOption3 = new QCheckBox(menu);
        menuOption3->setObjectName(QString::fromUtf8("menuOption3"));
        menuOption3->setGeometry(QRect(20, 350, 220, 30));
        menuOption4 = new QCheckBox(menu);
        menuOption4->setObjectName(QString::fromUtf8("menuOption4"));
        menuOption4->setGeometry(QRect(20, 380, 220, 30));
        menuDisp = new QScrollArea(menu);
        menuDisp->setObjectName(QString::fromUtf8("menuDisp"));
        menuDisp->setGeometry(QRect(10, 10, 240, 240));
        sizePolicy.setHeightForWidth(menuDisp->sizePolicy().hasHeightForWidth());
        menuDisp->setSizePolicy(sizePolicy);
        menuDisp->setFrameShape(QFrame::StyledPanel);
        menuDisp->setFrameShadow(QFrame::Plain);
        menuDisp->setLineWidth(1);
        menuDisp->setMidLineWidth(0);
        menuDisp->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        menuDisp->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        menuDisp->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 238, 238));
        menuDisp->setWidget(scrollAreaWidgetContents_2);
        KEY_LUP = new QPushButton(menu);
        KEY_LUP->setObjectName(QString::fromUtf8("KEY_LUP"));
        KEY_LUP->setEnabled(true);
        KEY_LUP->setGeometry(QRect(500, 110, 41, 41));
        KEY_LUP->setFont(font1);
        KEY_LUP->setCursor(QCursor(Qt::CrossCursor));
        KEY_LUP->setAutoFillBackground(false);
        KEY_LUP->setCheckable(false);
        KEY_LUP->setAutoRepeat(true);
        KEY_LUP->setFlat(false);
        KEY_LDN = new QPushButton(menu);
        KEY_LDN->setObjectName(QString::fromUtf8("KEY_LDN"));
        KEY_LDN->setEnabled(true);
        KEY_LDN->setGeometry(QRect(500, 210, 41, 41));
        KEY_LDN->setFont(font1);
        KEY_LDN->setCursor(QCursor(Qt::CrossCursor));
        KEY_LDN->setAutoFillBackground(false);
        KEY_LDN->setCheckable(false);
        KEY_LDN->setAutoRepeat(true);
        KEY_LDN->setFlat(false);
        KEY_LLF = new QPushButton(menu);
        KEY_LLF->setObjectName(QString::fromUtf8("KEY_LLF"));
        KEY_LLF->setEnabled(true);
        KEY_LLF->setGeometry(QRect(450, 160, 41, 41));
        KEY_LLF->setFont(font1);
        KEY_LLF->setCursor(QCursor(Qt::CrossCursor));
        KEY_LLF->setAutoFillBackground(false);
        KEY_LLF->setCheckable(false);
        KEY_LLF->setAutoRepeat(true);
        KEY_LLF->setFlat(false);
        KEY_LOK = new QPushButton(menu);
        KEY_LOK->setObjectName(QString::fromUtf8("KEY_LOK"));
        KEY_LOK->setEnabled(true);
        KEY_LOK->setGeometry(QRect(500, 160, 41, 41));
        KEY_LOK->setFont(font1);
        KEY_LOK->setCursor(QCursor(Qt::CrossCursor));
        KEY_LOK->setAutoFillBackground(false);
        KEY_LOK->setCheckable(false);
        KEY_LOK->setAutoRepeat(true);
        KEY_LOK->setFlat(false);
        KEY_LRT = new QPushButton(menu);
        KEY_LRT->setObjectName(QString::fromUtf8("KEY_LRT"));
        KEY_LRT->setEnabled(true);
        KEY_LRT->setGeometry(QRect(550, 160, 41, 41));
        KEY_LRT->setFont(font1);
        KEY_LRT->setCursor(QCursor(Qt::CrossCursor));
        KEY_LRT->setAutoFillBackground(false);
        KEY_LRT->setCheckable(false);
        KEY_LRT->setAutoRepeat(true);
        KEY_LRT->setFlat(false);
        MainTab->addTab(menu, QString());
        image = new QWidget();
        image->setObjectName(QString::fromUtf8("image"));
        imageOption0 = new QCheckBox(image);
        imageOption0->setObjectName(QString::fromUtf8("imageOption0"));
        imageOption0->setGeometry(QRect(20, 220, 220, 30));
        imageOption4 = new QCheckBox(image);
        imageOption4->setObjectName(QString::fromUtf8("imageOption4"));
        imageOption4->setGeometry(QRect(40, 430, 100, 30));
        imageOption1 = new QCheckBox(image);
        imageOption1->setObjectName(QString::fromUtf8("imageOption1"));
        imageOption1->setGeometry(QRect(20, 250, 220, 30));
        imageOption2 = new QCheckBox(image);
        imageOption2->setObjectName(QString::fromUtf8("imageOption2"));
        imageOption2->setGeometry(QRect(20, 310, 220, 30));
        imageOption3 = new QCheckBox(image);
        imageOption3->setObjectName(QString::fromUtf8("imageOption3"));
        imageOption3->setGeometry(QRect(20, 370, 220, 30));
        imgDirInput1 = new QLineEdit(image);
        imgDirInput1->setObjectName(QString::fromUtf8("imgDirInput1"));
        imgDirInput1->setGeometry(QRect(40, 280, 400, 21));
        imgDirSelect1 = new QToolButton(image);
        imgDirSelect1->setObjectName(QString::fromUtf8("imgDirSelect1"));
        imgDirSelect1->setGeometry(QRect(450, 280, 30, 20));
        imagePrev = new QPushButton(image);
        imagePrev->setObjectName(QString::fromUtf8("imagePrev"));
        imagePrev->setGeometry(QRect(160, 255, 40, 20));
        imageNext = new QPushButton(image);
        imageNext->setObjectName(QString::fromUtf8("imageNext"));
        imageNext->setGeometry(QRect(220, 255, 40, 20));
        imageName = new QLabel(image);
        imageName->setObjectName(QString::fromUtf8("imageName"));
        imageName->setGeometry(QRect(280, 250, 191, 31));
        imageSerialOnOff = new QPushButton(image);
        imageSerialOnOff->setObjectName(QString::fromUtf8("imageSerialOnOff"));
        imageSerialOnOff->setGeometry(QRect(160, 225, 40, 20));
        imageSerialRefresh = new QPushButton(image);
        imageSerialRefresh->setObjectName(QString::fromUtf8("imageSerialRefresh"));
        imageSerialRefresh->setGeometry(QRect(220, 225, 40, 20));
        imageDisp = new QScrollArea(image);
        imageDisp->setObjectName(QString::fromUtf8("imageDisp"));
        imageDisp->setGeometry(QRect(10, 10, 320, 200));
        imageDisp->setFrameShadow(QFrame::Plain);
        imageDisp->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        imageDisp->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        imageDisp->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 318, 198));
        imageDisp->setWidget(scrollAreaWidgetContents);
        imageIptDisp = new QScrollArea(image);
        imageIptDisp->setObjectName(QString::fromUtf8("imageIptDisp"));
        imageIptDisp->setGeometry(QRect(340, 10, 160, 200));
        imageIptDisp->setFrameShadow(QFrame::Plain);
        imageIptDisp->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        imageIptDisp->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        imageIptDisp->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 158, 198));
        imageIptDisp->setWidget(scrollAreaWidgetContents_3);
        imgDirSelect2 = new QToolButton(image);
        imgDirSelect2->setObjectName(QString::fromUtf8("imgDirSelect2"));
        imgDirSelect2->setGeometry(QRect(450, 340, 30, 20));
        imgDirInput2 = new QLineEdit(image);
        imgDirInput2->setObjectName(QString::fromUtf8("imgDirInput2"));
        imgDirInput2->setGeometry(QRect(40, 340, 400, 21));
        imgDirSelect3 = new QToolButton(image);
        imgDirSelect3->setObjectName(QString::fromUtf8("imgDirSelect3"));
        imgDirSelect3->setGeometry(QRect(450, 400, 30, 20));
        imgDirInput3 = new QLineEdit(image);
        imgDirInput3->setObjectName(QString::fromUtf8("imgDirInput3"));
        imgDirInput3->setGeometry(QRect(40, 400, 400, 21));
        imageOption5 = new QCheckBox(image);
        imageOption5->setObjectName(QString::fromUtf8("imageOption5"));
        imageOption5->setGeometry(QRect(160, 430, 100, 30));
        imageNumber = new QLabel(image);
        imageNumber->setObjectName(QString::fromUtf8("imageNumber"));
        imageNumber->setGeometry(QRect(280, 220, 191, 31));
        MainTab->addTab(image, QString());
        Coding_FrameworkClass->setCentralWidget(centralWidget);
        QWidget::setTabOrder(BaudRateSelect, imageOption4);
        QWidget::setTabOrder(imageOption4, plainTextEdit);
        QWidget::setTabOrder(plainTextEdit, textBrowser);
        QWidget::setTabOrder(textBrowser, pushButton);
        QWidget::setTabOrder(pushButton, SerialPortSelect);
        QWidget::setTabOrder(SerialPortSelect, imageOption0);
        QWidget::setTabOrder(imageOption0, imgDirSelect1);
        QWidget::setTabOrder(imgDirSelect1, imageOption3);
        QWidget::setTabOrder(imageOption3, imageIptDisp);
        QWidget::setTabOrder(imageIptDisp, imageOption2);
        QWidget::setTabOrder(imageOption2, imageOption1);
        QWidget::setTabOrder(imageOption1, imagePrev);
        QWidget::setTabOrder(imagePrev, imageNext);
        QWidget::setTabOrder(imageNext, imageSerialOnOff);
        QWidget::setTabOrder(imageSerialOnOff, imageSerialRefresh);
        QWidget::setTabOrder(imageSerialRefresh, imgDirInput1);
        QWidget::setTabOrder(imgDirInput1, imageDisp);
        QWidget::setTabOrder(imageDisp, imgDirSelect2);
        QWidget::setTabOrder(imgDirSelect2, imgDirInput2);
        QWidget::setTabOrder(imgDirInput2, imgDirSelect3);
        QWidget::setTabOrder(imgDirSelect3, MainTab);
        QWidget::setTabOrder(MainTab, menuDisp);
        QWidget::setTabOrder(menuDisp, menuOption0);
        QWidget::setTabOrder(menuOption0, menuOption1);
        QWidget::setTabOrder(menuOption1, menuOption2);
        QWidget::setTabOrder(menuOption2, menuOption3);
        QWidget::setTabOrder(menuOption3, menuOption4);
        QWidget::setTabOrder(menuOption4, KEY_UP);
        QWidget::setTabOrder(KEY_UP, KEY_LF);
        QWidget::setTabOrder(KEY_LF, KEY_OK);
        QWidget::setTabOrder(KEY_OK, KEY_DN);
        QWidget::setTabOrder(KEY_DN, KEY_RT);
        QWidget::setTabOrder(KEY_RT, imgDirInput3);
        QWidget::setTabOrder(imgDirInput3, imageOption5);

        retranslateUi(Coding_FrameworkClass);

        MainTab->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Coding_FrameworkClass);
    } // setupUi

    void retranslateUi(QMainWindow *Coding_FrameworkClass)
    {
        Coding_FrameworkClass->setWindowTitle(QCoreApplication::translate("Coding_FrameworkClass", "Coding_Framework", nullptr));
        pushButton->setText(QCoreApplication::translate("Coding_FrameworkClass", "\350\277\236\346\216\245", nullptr));
        MainTab->setTabText(MainTab->indexOf(serial), QCoreApplication::translate("Coding_FrameworkClass", "\344\270\262\345\217\243", nullptr));
        KEY_UP->setText(QCoreApplication::translate("Coding_FrameworkClass", "SUP", nullptr));
        KEY_OK->setText(QCoreApplication::translate("Coding_FrameworkClass", "SOK", nullptr));
        KEY_DN->setText(QCoreApplication::translate("Coding_FrameworkClass", "SDN", nullptr));
        KEY_RT->setText(QCoreApplication::translate("Coding_FrameworkClass", "SRT", nullptr));
        KEY_LF->setText(QCoreApplication::translate("Coding_FrameworkClass", "SLF", nullptr));
        menuOption0->setText(QCoreApplication::translate("Coding_FrameworkClass", "\344\270\262\345\217\243\350\277\234\347\250\213\346\223\215\344\275\234\350\217\234\345\215\225", nullptr));
        menuOption1->setText(QCoreApplication::translate("Coding_FrameworkClass", "Option 1", nullptr));
        menuOption2->setText(QCoreApplication::translate("Coding_FrameworkClass", "Option 2", nullptr));
        menuOption3->setText(QCoreApplication::translate("Coding_FrameworkClass", "Option 3", nullptr));
        menuOption4->setText(QCoreApplication::translate("Coding_FrameworkClass", "Option 4", nullptr));
        KEY_LUP->setText(QCoreApplication::translate("Coding_FrameworkClass", "LUP", nullptr));
        KEY_LDN->setText(QCoreApplication::translate("Coding_FrameworkClass", "LDN", nullptr));
        KEY_LLF->setText(QCoreApplication::translate("Coding_FrameworkClass", "LLF", nullptr));
        KEY_LOK->setText(QCoreApplication::translate("Coding_FrameworkClass", "LOK", nullptr));
        KEY_LRT->setText(QCoreApplication::translate("Coding_FrameworkClass", "LRT", nullptr));
        MainTab->setTabText(MainTab->indexOf(menu), QCoreApplication::translate("Coding_FrameworkClass", "\350\217\234\345\215\225", nullptr));
        imageOption0->setText(QCoreApplication::translate("Coding_FrameworkClass", "\344\275\277\347\224\250\345\275\223\345\211\215\344\270\262\345\217\243\346\225\260\346\215\256", nullptr));
        imageOption4->setText(QCoreApplication::translate("Coding_FrameworkClass", "\344\277\235\345\255\230\345\216\237\345\247\213\345\233\276\345\203\217", nullptr));
        imageOption1->setText(QCoreApplication::translate("Coding_FrameworkClass", "\344\275\277\347\224\250\346\226\207\344\273\266\345\244\271\345\206\205\345\233\276\347\211\207", nullptr));
        imageOption2->setText(QCoreApplication::translate("Coding_FrameworkClass", "\344\275\277\347\224\250\344\277\235\345\255\230\347\232\204\344\270\262\345\217\243\346\225\260\346\215\256", nullptr));
        imageOption3->setText(QCoreApplication::translate("Coding_FrameworkClass", "\344\277\235\345\255\230\345\233\276\345\203\217\350\207\263\346\226\207\344\273\266\345\244\271", nullptr));
        imgDirSelect1->setText(QCoreApplication::translate("Coding_FrameworkClass", "...", nullptr));
        imagePrev->setText(QCoreApplication::translate("Coding_FrameworkClass", "<<", nullptr));
        imageNext->setText(QCoreApplication::translate("Coding_FrameworkClass", ">>", nullptr));
        imageName->setText(QCoreApplication::translate("Coding_FrameworkClass", "image name", nullptr));
        imageSerialOnOff->setText(QCoreApplication::translate("Coding_FrameworkClass", "\345\274\200\345\247\213", nullptr));
        imageSerialRefresh->setText(QCoreApplication::translate("Coding_FrameworkClass", "\345\210\267\346\226\260", nullptr));
        imgDirSelect2->setText(QCoreApplication::translate("Coding_FrameworkClass", "...", nullptr));
        imgDirSelect3->setText(QCoreApplication::translate("Coding_FrameworkClass", "...", nullptr));
        imageOption5->setText(QCoreApplication::translate("Coding_FrameworkClass", "\344\277\235\345\255\230\351\200\217\350\247\206\345\233\276\345\203\217", nullptr));
        imageNumber->setText(QCoreApplication::translate("Coding_FrameworkClass", "image number", nullptr));
        MainTab->setTabText(MainTab->indexOf(image), QCoreApplication::translate("Coding_FrameworkClass", "\345\233\276\345\203\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Coding_FrameworkClass: public Ui_Coding_FrameworkClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODING_FRAMEWORK_H
