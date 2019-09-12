/*
 * Beta-Cat Controll @ HSIC
 * @name	app_ctrlfw.h
 * Application Layer Controll Framework. This part implements a "Status Machine".
 *
*/
#ifndef _APP_FW_H_
#define _APP_FW_H_

#include "inc_std.h"
#include "inc_stl.h"
#include "inc_gnc.h"


using namespace std;


class appfw_ctrlIfce_t
{
public:
	virtual void taskInit(void) = 0;
	virtual void shiftIn(void) = 0;
	virtual void jumpOut(void) = 0;
};


class appfw_tcModeGenric : public appfw_ctrlIfce_t
{
public:
	static appfw_tcModeGenric& getInstance(void)
	{
		static appfw_tcModeGenric inst;
		return inst;
	}

	virtual void taskInit(void) override {}
	virtual void shiftIn(void) override {}
	virtual void jumpOut(void) override {}

private:
	//whatever you write......
	void angCtrl(void) {}
	void spdCtrl(void) {}
	void dirCtrl(void) {}

private:
	appfw_tcModeGenric(void){}
	appfw_tcModeGenric(const appfw_tcModeGenric&);
	appfw_tcModeGenric& operator = (const appfw_tcModeGenric&);
};


#endif // ! _APP_CTRLFW_H_