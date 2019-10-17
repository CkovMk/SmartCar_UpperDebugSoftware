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

	grabKeyboard();
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
	var.BTOp = appVar_keyBTOp_t::sup;
	uiMenu.keyOp(&var.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}
void Coding_Framework::on_KEY_DN_clicked(void)
{
	var.BTOp = appVar_keyBTOp_t::sdn;
	uiMenu.keyOp(&var.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}
void Coding_Framework::on_KEY_LF_clicked(void)
{
	var.BTOp = appVar_keyBTOp_t::slf;
	uiMenu.keyOp(&var.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}
void Coding_Framework::on_KEY_RT_clicked(void)
{
	var.BTOp = appVar_keyBTOp_t::srt;
	uiMenu.keyOp(&var.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}
void Coding_Framework::on_KEY_OK_clicked(void)
{
	var.BTOp = appVar_keyBTOp_t::sok;
	uiMenu.keyOp(&var.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}

void Coding_Framework::on_KEY_LUP_clicked(void)
{
	var.BTOp = appVar_keyBTOp_t::lup;
	uiMenu.keyOp(&var.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}
void Coding_Framework::on_KEY_LDN_clicked(void)
{
	var.BTOp = appVar_keyBTOp_t::ldn;
	uiMenu.keyOp(&var.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}
void Coding_Framework::on_KEY_LLF_clicked(void)
{
	var.BTOp = appVar_keyBTOp_t::llf;
	uiMenu.keyOp(&var.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}
void Coding_Framework::on_KEY_LRT_clicked(void)
{
	var.BTOp = appVar_keyBTOp_t::lrt;
	uiMenu.keyOp(&var.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}
void Coding_Framework::on_KEY_LOK_clicked(void)
{
	var.BTOp = appVar_keyBTOp_t::lok;
	uiMenu.keyOp(&var.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}

/*
Qt::Key_Left
Qt::Key_Up
Qt::Key_Right
Qt::Key_Down
Qt::Key_Space
*/

volatile uint32_t cnt_keyUp = 0, cnt_keyDn = 0, cnt_keyLf = 0, cnt_keyRt = 0, cnt_keyOk = 0;

void Coding_Framework::keyPressEvent(QKeyEvent* ev)
{
	switch (ev->key())
	{
	case Qt::Key_Up:
		if (ev->isAutoRepeat())
		{
			//long,send
			if (cnt_keyUp == 0)
			{
				var.BTOp = appVar_keyBTOp_t::lup;
			}
			else
			{
				var.BTOp = appVar_keyBTOp_t::rup;
			}
			++cnt_keyUp;
			break;
		}
		else
		{
			//shrt,do nothing
			cnt_keyUp = 0;
			return;
		}
	case Qt::Key_Down:
		if (ev->isAutoRepeat())
		{
			//long,send
			if (cnt_keyDn == 0)
			{
				var.BTOp = appVar_keyBTOp_t::ldn;
			}
			else
			{
				var.BTOp = appVar_keyBTOp_t::rdn;
			}
			++cnt_keyDn;
			break;
		}
		else
		{
			//shrt,do nothing
			cnt_keyDn = 0;
			return;
		}
	case Qt::Key_Left:
		if (ev->isAutoRepeat())
		{
			//long,send
			if (cnt_keyLf == 0)
			{
				var.BTOp = appVar_keyBTOp_t::llf;
			}
			else
			{
				var.BTOp = appVar_keyBTOp_t::rlf;
			}
			++cnt_keyLf;
			break;
		}
		else
		{
			//shrt,do nothing
			cnt_keyLf = 0;
			return;
		}
	case Qt::Key_Right:
		if (ev->isAutoRepeat())
		{
			//long,send
			if (cnt_keyRt == 0)
			{
				var.BTOp = appVar_keyBTOp_t::lrt;
			}
			else
			{
				var.BTOp = appVar_keyBTOp_t::rrt;
			}
			++cnt_keyRt;
			break;
		}
		else
		{
			//shrt,do nothing
			cnt_keyRt = 0;
			return;
		}
	case Qt::Key_Space:
		if (ev->isAutoRepeat())
		{
			//long,send
			if (cnt_keyOk == 0)
			{
				var.BTOp = appVar_keyBTOp_t::lok;
			}
			else
			{
				var.BTOp = appVar_keyBTOp_t::rok;
			}
			++cnt_keyOk;
			break;
		}
		else
		{
			//shrt,do nothing
			cnt_keyOk = 0;
			return;
		}
	default:
		QWidget::keyPressEvent(ev);
		return;
	}

	uiMenu.keyOp(&var.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);

	
}

void Coding_Framework::keyReleaseEvent(QKeyEvent* ev)
{
	switch (ev->key())
	{
	case Qt::Key_Up:
		if (!ev->isAutoRepeat() && cnt_keyUp == 0)
		{
			//shrt,send
			var.BTOp = appVar_keyBTOp_t::sup;
			break;
		}
		return;
	case Qt::Key_Down:
		if (!ev->isAutoRepeat() && cnt_keyDn == 0)
		{
			//shrt,send
			var.BTOp = appVar_keyBTOp_t::sdn;
			break;
		}
		return;
	case Qt::Key_Left:
		if (!ev->isAutoRepeat() && cnt_keyLf == 0)
		{
			//shrt,send
			var.BTOp = appVar_keyBTOp_t::slf;
			break;
		}
		return;
	case Qt::Key_Right:
		if (!ev->isAutoRepeat() && cnt_keyRt == 0)
		{
			//shrt,send
			var.BTOp = appVar_keyBTOp_t::srt;
			break;
		}
		return;
	case Qt::Key_Space:
		if (!ev->isAutoRepeat() && cnt_keyOk == 0)
		{
			//shrt,send
			var.BTOp = appVar_keyBTOp_t::sok;
			break;
		}
		return;

	default:
		QWidget::keyPressEvent(ev);
		return;
	}

	uiMenu.keyOp(&var.BTOp);
	uiMenu.printDisp();
	func_updateMenuDisp(&uiDisp.dispBuf);
}



