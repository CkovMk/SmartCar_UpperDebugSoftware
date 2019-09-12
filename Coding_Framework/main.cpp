#include "coding_framework.h"
#include <QtWidgets/QApplication>

//OpenCV
#if defined(_OPENCV_DBG_) && _OPENCV_DBG_
#include <opencv2/opencv.hpp>
#endif

////CPP MultiThread
//#include <atomic>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <future>

#include "app_ui.h"






//global varibes & forward declarations
Coding_Framework* cfw = NULL;

char str1[50] = "Hello,World!";
char str2[50];

int size = 0;


int main(int argc, char *argv[])
{
	size = sizeof(void*);
	appui_dataIO_t::getInstance().fill();
	appui_dataIO_t::getInstance().save(20, 4, str1);
	appui_dataIO_t::getInstance().read(20, 4, str2);

#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
	QApplication a(argc, argv);
	//Coding_Framework w;
	//cfw = &w;
	Coding_Framework::getInstance().show();
	return a.exec();
}



//Qt with OpenCV:
//https://blog.csdn.net/guanzhen3657/article/details/81812566