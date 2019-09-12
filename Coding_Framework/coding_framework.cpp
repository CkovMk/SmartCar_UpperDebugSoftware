#include "coding_framework.h"

gnc_rgbCamImg_t a;
gnc_rgbIptImg_t b;
gnc_rgbLcdBuf_t c;


Coding_Framework::Coding_Framework(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	appui_disp_t& uiDisp = appui_disp_t::getInstance();
	int test = 2000;
	//uiDisp.dispPrintf(10, 10, gnc_rgb_t(0, 100, 200), gnc_rgb_t(200, 200, 0), "Hello,uiDisp!\n  Good Night %d", test);
	uiMenu.printDisp();
	//uiDisp.disp_update();
	func_updateMenuDisp(&uiDisp.dispBuf);


	for (int i = 20; i < 100; i++)
	{
		for (int j = 40; j < 100; j++)
		{
			a.pix[i][j] = b.pix[i][j] = c.pix[i][j] = gnc_rgb_t(0, 200, 200);
		}
	}
	//c.pix[10][10] = gnc_makeRGB(200, 150, 100);

	//func_updateImageDisp(&a);
	//func_updateImageIptDisp(&b);
	//func_updateMenuDisp(&c);

	//appui_disp_t.getInstance()

	//char strBuf[1024];
	//sprintf(strBuf,"%d, %d", ui.menuDisp->width(), ui.menuDisp->height());
	//OutputDebugStringA((LPCSTR)strBuf);
}

void Coding_Framework::func_updateMenuDisp(gnc_rgbLcdBuf_t* _buf)
{
	menuDispMat = cv::Mat(GNC_LCD_R, GNC_LCD_C, CV_8UC3, (void*)_buf, (size_t)0);
	//cv::resize(menuDispMat, menuDispMat, cv::Size(ui.menuDisp->height(), ui.menuDisp->width()));
	static QImage img = QImage((const unsigned char*)(menuDispMat.data), menuDispMat.cols, menuDispMat.rows, QImage::Format_RGB888);

	menuDispLabel->setPixmap(QPixmap::fromImage(img));
	menuDispLabel->resize(QSize(ui.menuDisp->width(), ui.menuDisp->height()));
	ui.menuDisp->setWidget(menuDispLabel);
}

void Coding_Framework::func_updateImageDisp(gnc_rgbCamImg_t* _buf)
{
	imageDispMat = cv::Mat(GNC_CAM_IMG_R, GNC_CAM_IMG_C, CV_8UC3, (void*)_buf, (size_t)0);
	//cv::resize(menuDispMat, menuDispMat, cv::Size(ui.imageDisp->height(), ui.imageDisp->width()));
	static QImage img = QImage((const unsigned char*)(imageDispMat.data), imageDispMat.cols, imageDispMat.rows, QImage::Format_RGB888);

	imageDispLabel->setPixmap(QPixmap::fromImage(img));
	imageDispLabel->resize(QSize(ui.imageDisp->width(), ui.imageDisp->height()));
	ui.imageDisp->setWidget(imageDispLabel);
}

void Coding_Framework::func_updateImageIptDisp(gnc_rgbIptImg_t* _buf)
{
	imageIptDispMat = cv::Mat(GNC_IPT_IMG_R, GNC_IPT_IMG_C, CV_8UC3, (void*)_buf, (size_t)0);
	//cv::resize(menuDispMat, menuDispMat, cv::Size(ui.imageIptDisp->height(), ui.imageIptDisp->width()));
	static QImage img = QImage((const unsigned char*)(imageIptDispMat.data), imageIptDispMat.cols, imageIptDispMat.rows, QImage::Format_RGB888);

	imageIptDispLabel->setPixmap(QPixmap::fromImage(img));
	imageIptDispLabel->resize(QSize(ui.imageIptDisp->width(), ui.imageIptDisp->height()));
	ui.imageIptDisp->setWidget(imageIptDispLabel);
}

void Coding_Framework::on_KEY_UP_clicked(void)
{
	var.data.key.BTOp = appVar_keyBTOp_t::sup;
	uiMenu.keyOp(&var.data.key.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}
void Coding_Framework::on_KEY_DN_clicked(void)
{
	var.data.key.BTOp = appVar_keyBTOp_t::sdn;
	uiMenu.keyOp(&var.data.key.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}
void Coding_Framework::on_KEY_LF_clicked(void)
{
	var.data.key.BTOp = appVar_keyBTOp_t::slf;
	uiMenu.keyOp(&var.data.key.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}
void Coding_Framework::on_KEY_RT_clicked(void)
{
	var.data.key.BTOp = appVar_keyBTOp_t::srt;
	uiMenu.keyOp(&var.data.key.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}
void Coding_Framework::on_KEY_OK_clicked(void)
{
	var.data.key.BTOp = appVar_keyBTOp_t::sok;
	uiMenu.keyOp(&var.data.key.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}

void Coding_Framework::on_KEY_LUP_clicked(void)
{
	var.data.key.BTOp = appVar_keyBTOp_t::lup;
	uiMenu.keyOp(&var.data.key.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}
void Coding_Framework::on_KEY_LDN_clicked(void)
{
	var.data.key.BTOp = appVar_keyBTOp_t::ldn;
	uiMenu.keyOp(&var.data.key.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}
void Coding_Framework::on_KEY_LLF_clicked(void)
{
	var.data.key.BTOp = appVar_keyBTOp_t::llf;
	uiMenu.keyOp(&var.data.key.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}
void Coding_Framework::on_KEY_LRT_clicked(void)
{
	var.data.key.BTOp = appVar_keyBTOp_t::lrt;
	uiMenu.keyOp(&var.data.key.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}
void Coding_Framework::on_KEY_LOK_clicked(void)
{
	var.data.key.BTOp = appVar_keyBTOp_t::lok;
	uiMenu.keyOp(&var.data.key.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}



