/*
 * Beta-Cat Controll @ HSIC
 * @name	app_var.h
 * Application Layer Varibles Management. Controller should ONLY access data HERE.
 *
*/

#ifndef _APP_VAR_H_
#define _APP_VAR_H_

#include "inc_std.h"
#include "inc_stl.h"
#include "inc_gnc.h"

/**************** Data Implements ****************/

enum class appVar_keyBTOp_t : int32_t
{
	nop,
	//bt
	sok, slf, srt, sup, sdn, sfa, sfb, sfc,		//SHRT
	lok, llf, lrt, lup, ldn, lfa, lfb, lfc,		//LONG
	rok, rlf, rrt, rup, rdn, rfa, rfb, rfc,		//REPT


};


enum class appVar_keySWOp_t : int32_t
{
	nop,
	//sw
	ri1, ri2, ri3, ri4, ri5, ri6, ri7, ri8,
	fl1, fl2, fl3, fl4, fl5, fl6, fl7, fl8,
};

struct appVar_keyData_t
{
	appVar_keyBTOp_t BTOp;
	appVar_keySWOp_t SWOp;
	uint8_t swStatus;
};

struct appVar_imuData_t
{
	float Ax, Ay, Az;
	float Gx, Gy, Gz;

	//Add more ahrs Data HERE!
	//maybe semaphore here.
};

//mag data
struct appVar_magData_t
{

};
//camera data
struct appVar_camData_t
{

};


/**************** Data Collection ****************/



/**************** Flag Implements ****************/

enum class appVar_uiModeFlag_t
{
	idleMode,
	menuMode,
	imgeMode,
	dlogMode,
};

enum class appVar_runModeFlag_t
{
	tcMode, urMode,
};
//exception: loop
enum class appVar_loopFlag_t
{

};

//exception flag collection
struct appVar_excpFlag
{
	int32_t loopFlag;	//loop
	int32_t snapFlag;	//snap road
	int32_t rampFlag;	//ramp
	int32_t lineFlag;	//start line

};


/**************** Flag Collection ****************/





class appVar_t
{
public:

	static appVar_t& getInstance(void)
	{
		static appVar_t var;
		return var;
	}

private:
	appVar_t(void)
	{

	}
	appVar_t(const appVar_t&);
	appVar_t& operator = (const appVar_t&);
};

#endif // ! _APP_VAR_H_