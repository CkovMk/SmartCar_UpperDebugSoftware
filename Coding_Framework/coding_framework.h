#pragma once

#include <QtWidgets/QMainWindow>
#include <QThread>
#include "ui_coding_framework.h"

#include "inc_std.h"
#include "inc_stl.h"
#include "inc_gnc.h"

#include "app_ui.h"
#include "app_var.h"

#if defined(_OPENCV_DBG_) && _OPENCV_DBG_
#include <opencv2/opencv.hpp>
#include <windows.h>
#endif

#define CONTROLL_MENU_USE_SCREEN_BUTTONS 1


void menuDispUpdateHandler(void);

class Coding_Framework : public QMainWindow
{
	Q_OBJECT

public:
	Coding_Framework(QWidget *parent = Q_NULLPTR);

	static Coding_Framework& getInstance(void)
	{
		static Coding_Framework inst;
		return inst;
	}

	appui_disp_t& uiDisp = appui_disp_t::getInstance();
	appui_menu_t& uiMenu = appui_menu_t::getInstance();
	appVar_t& var = appVar_t::getInstance();

	//external used display update functions
	cv::Mat menuDispMat;
	QLabel* menuDispLabel = new QLabel();
	cv::Mat imageDispMat;
	QLabel* imageDispLabel = new QLabel();
	cv::Mat imageIptDispMat;
	QLabel* imageIptDispLabel = new QLabel();
	void func_updateMenuDisp(gnc_rgbLcdBuf_t* _buf);
	void func_updateImageDisp(gnc_rgbCamImg_t* _buf);
	void func_updateImageIptDisp(gnc_rgbIptImg_t* _buf);

	std::thread menuDispUpdate;


public slots:

#if defined(CONTROLL_MENU_USE_SCREEN_BUTTONS) && (CONTROLL_MENU_USE_SCREEN_BUTTONS == 1)
	void on_KEY_UP_clicked(void);
	void on_KEY_DN_clicked(void);
	void on_KEY_LF_clicked(void);
	void on_KEY_RT_clicked(void);
	void on_KEY_OK_clicked(void);

	void on_KEY_LUP_clicked(void);
	void on_KEY_LDN_clicked(void);
	void on_KEY_LLF_clicked(void);
	void on_KEY_LRT_clicked(void);
	void on_KEY_LOK_clicked(void);
#endif
	void on_MainTab_currentChanged(int tab);


protected:
	virtual void keyPressEvent(QKeyEvent* ev);
	virtual void keyReleaseEvent(QKeyEvent* ev);
	
private:
	// Default Code
	Ui::Coding_FrameworkClass ui;

	
	
};


class key_status_t
{
public:
	uint32_t keyCnt;

};
