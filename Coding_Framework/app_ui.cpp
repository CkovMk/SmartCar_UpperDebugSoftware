#include "app_ui.h"

//using namespace std;

#if defined(_OPENCV_DBG_) && _OPENCV_DBG_
#include "coding_framework.h"
extern Coding_Framework* cfw;
#endif

void appui_disp_t::disp_update(void)
{
#if defined(_OPENCV_DBG_) && _OPENCV_DBG_
	//opencv update code

#else
	//mcu update code
#error "app_ui: Adapt LCD update function HERE! "
#endif

}

/*----------generic color definitions----------*/

//line gray
const gnc_rgb_t menu_l_gray(200, 200, 200);

//status bar blue
const gnc_rgb_t menu_sf_white(225, 225, 225);
const gnc_rgb_t menu_sb_blue(0, 180, 240);

//unslected black & white
const gnc_rgb_t menu_rf_black(0, 0, 0);
const gnc_rgb_t menu_rb_white(225, 225, 225);

//selected white & orange
const gnc_rgb_t menu_rf_white(255, 255, 255);
const gnc_rgb_t menu_rb_orange(240, 200, 0);
















/*---------- appui_disp_t ----------*/

void appui_disp_t::dispPutchar(dispSize_t r, dispSize_t c, gnc_rgb_t f_color, gnc_rgb_t b_color, const char ch)
{
	assert(0 <= r && r <= 240 - 16);
	assert(0 <= c && c <= 240 - 8);
	assert(gnc_asciiBegin <= ch && ch < gnc_asciiEndin);

	for (uint8_t cell : gnc_getFont0816(newSongType, ch))
	{
		for (uint8_t i = 0; i < 8; i++)
		{
			if (bitRd(cell, i))
			{
				dispBuf.pix[r][c + i] = f_color;
			}
			else
			{
				dispBuf.pix[r][c + i] = b_color;
			}
		}
		++r;
	}
}

void appui_disp_t::dispPrint(dispSize_t r, dispSize_t c, gnc_rgb_t f_color, gnc_rgb_t b_color, const char* str)
{
	for (const char* p = str; (*p) != '\0'; ++p)
	{
		if ((*p) == '\n')
		{
			r += 16;
			c = 0;
			continue;
		}
		if (gnc_asciiBegin <= (*p) && (*p) < gnc_asciiEndin)
		{
			dispPutchar(r, c, f_color, b_color, *p);
		}
		//Attention: if you send an unprintable char, no printing will be done. the char will remain as what it was.
		c += 8;
		if (c > 240 - 8)
		{
			c = 0;
			r += 16;
			if (r > 240 - 16)
			{
				break;
			}
		}
	}
}

void appui_disp_t::dispPrintf(dispSize_t r, dispSize_t c, gnc_rgb_t f_color, gnc_rgb_t b_color, const char* _fmt, ...)
{
	va_list args;
	va_start(args, _fmt);
	static char strBuf[64];
	vsprintf(strBuf, _fmt, args);
	dispPrint(r, c, f_color, b_color, strBuf);
}

void appui_disp_t::rowPrint(dispSize_t row, dispSize_t c, gnc_rgb_t f_color, gnc_rgb_t b_color, const char* str)
{
	dispSize_t r = row << 4;
	for (const char* p = str; (*p) != '\0'; ++p)
	{
		if (gnc_asciiBegin <= (*p) && (*p) < gnc_asciiEndin)
		{
			dispPutchar(r, c, f_color, b_color, *p);
		}
		//Attention: if you send an unprintable char, no printing will be done. the char will remain as what it was.
		c += 8;
		if (c > 240 - 8)
		{
			break;
		}
	}
}

void appui_disp_t::rowPrintf(dispSize_t row, dispSize_t c, gnc_rgb_t f_color, gnc_rgb_t b_color, const char* _fmt, ...)
{
	va_list args;
	va_start(args, _fmt);
	static char strBuf[64];
	vsprintf(strBuf, _fmt, args);
	strBuf[30] = '\0';
	rowPrint(row, c, f_color, b_color, strBuf);
}



void appui_disp_t::dispPutchar(dispSize_t r, dispSize_t c, gnc_rgb_t f_color, const char ch)
{
	assert(0 <= r && r <= 240 - 16);
	assert(0 <= c && c <= 240 - 8);
	assert(gnc_asciiBegin <= ch && ch < gnc_asciiEndin);

	for (uint8_t cell : gnc_getFont0816(newSongType, ch))
	{
		for (uint8_t i = 0; i < 8; i++)
		{
			if (bitRd(cell, i))
			{
				dispBuf.pix[r][c + i] = f_color;
			}
			else
			{
				//dispBuf.pix[r][c + i] = b_color;
			}
		}
		++r;
	}
}

void appui_disp_t::dispPrint(dispSize_t r, dispSize_t c, gnc_rgb_t f_color, const char* str)
{
	for (const char* p = str; (*p) != '\0'; ++p)
	{
		if ((*p) == '\n')
		{
			r += 16;
			c = 0;
			continue;
		}
		if (gnc_asciiBegin <= (*p) && (*p) < gnc_asciiEndin)
		{
			dispPutchar(r, c, f_color, *p);
		}
		//Attention: if you send an unprintable char, no printing will be done. the char will remain as what it was.
		c += 8;
		if (c > 240 - 8)
		{
			c = 0;
			r += 16;
			if (r > 240 - 16)
			{
				break;
			}
		}
	}
}

void appui_disp_t::dispPrintf(dispSize_t r, dispSize_t c, gnc_rgb_t f_color, const char* _fmt, ...)
{
	va_list args;
	va_start(args, _fmt);
	static char strBuf[64];
	vsprintf(strBuf, _fmt, args);
	dispPrint(r, c, f_color, strBuf);
}

void appui_disp_t::rowPrint(dispSize_t row, dispSize_t c, gnc_rgb_t f_color,  const char* str)
{
	dispSize_t r = row << 4;
	for (const char* p = str; (*p) != '\0'; ++p)
	{
		if (gnc_asciiBegin <= (*p) && (*p) < gnc_asciiEndin)
		{
			dispPutchar(r, c, f_color,  *p);
		}
		//Attention: if you send an unprintable char, no printing will be done. the char will remain as what it was.
		c += 8;
		if (c > 240 - 8)
		{
			break;
		}
	}
}

void appui_disp_t::rowPrintf(dispSize_t row, dispSize_t c, gnc_rgb_t f_color, const char* _fmt, ...)
{
	va_list args;
	va_start(args, _fmt);
	static char strBuf[64];
	vsprintf(strBuf, _fmt, args);
	strBuf[30] = '\0';
	rowPrint(row, c, f_color, strBuf);
}

void appui_disp_t::dispFillRectangle(dispSize_t r1, dispSize_t r2, dispSize_t c1, dispSize_t c2, gnc_rgb_t b_color)
{
	//assert(r1 <= r2);
	//assert(c1 <= c2);
	for (int i = r1; i <= r2; ++i)
	{
		for (int j = c1; j <= c2; ++j)
		{
			setPixel(i, j, b_color);
		}
	}
}

void appui_disp_t::dispDrawRectangle(dispSize_t r1, dispSize_t r2, dispSize_t c1, dispSize_t c2, dispSize_t thick, gnc_rgb_t b_color)
{
	for (int i = r1; i <= r2; ++i)
	{
		for (int t = 0; t < thick; ++t)
		{
			setPixel(i, c1 + t, b_color);
			setPixel(i, c2 - t, b_color);
		}
	}
	for (int j = c1; j <= c2; ++j)
	{
		for (int t = 0; t < thick; ++t)
		{
			setPixel(r1 + t, j, b_color);
			setPixel(r2 - t, j, b_color);
		}
	}
}













/*---------- appui_menu_t::dispSlot_t ----------*/


void appui_menu_t::dispSlot_t::slotNamePrintf(gnc_rgb_t f_color, gnc_rgb_t b_color, char* _fmt, ...)
{
	va_list args;
	va_start(args, _fmt);
	static char strBuf[64];
	int32_t len = vsprintf(strBuf, _fmt, args);
	for (len; len < 30; ++len)
	{
		strBuf[len] = ' ';
	}
	strBuf[30] = '\0';
	appui_disp_t::getInstance().rowPrint((slotNum << 1) + 1, 0, f_color, b_color, strBuf);
}

void appui_menu_t::dispSlot_t::slotDataPrintf(gnc_rgb_t f_color, gnc_rgb_t b_color, char* _fmt, ...)
{
	va_list args;
	va_start(args, _fmt);
	static char strBuf[64];
	int32_t len = vsprintf(strBuf, _fmt, args);
	for (len; len < 30; ++len)
	{
		strBuf[len] = ' ';
	}
	strBuf[30] = '\0';
	appui_disp_t::getInstance().rowPrint((slotNum << 1) + 2, 0, f_color, b_color, strBuf);
}

void appui_menu_t::dispSlot_t::erase(void)
{
	appui_disp_t::getInstance();
}

appui_menu_t::menuList_t::menuList_t(std::string _nameStr, menuList_t * _prev)
{
	nameStr = _nameStr;
	prev = _prev;
	insert(new menuItem_menuType_t(prev, std::string("<<back"), 0));
}












/*---------- appui_menu_t ----------*/

appui_menu_t::menuList_t::~menuList_t(void)
{
	for (auto x : menu)
	{
		delete[] x;
	}
}

void appui_menu_t::menuList_t::insert(appui_menu_t::menuItemIfce_t * item)
{
	item->list_id = menu.size();
	item->myList = this;
	menu.push_back(item);
}

void appui_menu_t::menuList_t::printDisp(void)
{
	static appui_disp_t& _disp = appui_disp_t::getInstance();
	_disp.rowPrintf(0, 0, menu_sf_white, menu_sb_blue, "M: %s%30s", nameStr.c_str(), "");
	for (int i = 0; i < 7; i++)
	{
		if (disp_p + i < menu.size())
		{
			menu[disp_p + i]->printSlot(dispSlot_t(i));
		}
		else
		{
			_disp.dispFillRectangle((2 * i + 1) * 16, (2 * i + 3) * 16 - 1, 0, 239, menu_rb_white);
		}
	}
}

void appui_menu_t::menuList_t::keyOp(appVar_keyBTOp_t * _op)
{
	switch (*_op)
	{
	case appVar_keyBTOp_t::lok:
		//return
		appui_menu_t::getInstance().currList = prev;
		break;
		//case appVar_keyBTOp_t::sok:
		//	//return
		//	appui_menu_t::getInstance().currItem = menu[slct_p];
		//	break;
	case appVar_keyBTOp_t::sup:
	case appVar_keyBTOp_t::lup:
		//menu up
		if (slct_p > 0)
		{
			--slct_p;
		}
		while (disp_p > slct_p)
		{
			--disp_p;
		}
		break;
	case appVar_keyBTOp_t::sdn:
	case appVar_keyBTOp_t::ldn:
		//menu dn
		if (slct_p < menu.size() - 1)
		{
			++slct_p;
		}
		while (slct_p >= 6 && disp_p < slct_p - 6)
		{
			++disp_p;
		}
		break;
	default:
		//direct op
		menu[slct_p]->directKeyOp(_op);
		break;
	}
}











/*----------appui_menu_t::menuItemIfce_t----------*/

uint32_t appui_menu_t::menuItemIfce_t::itemCnt = 0;



//warinng: NOOOO NEED to check type manually when save data.
bool appui_menu_t::menuItemIfce_t::getIndex(menuItemIdex_t* _data)
{
	memset(_data, 0, sizeof(menuItemIdex_t));
	if (pptFlag & data_ROFlag || type == menuType || type == procType) { return false; }
	if (pptFlag & data_global) { _data->head = menuItemIdex_t::globalHead; }
	else if (pptFlag & data_region) { _data->head = menuItemIdex_t::regionHead | appui_menu_t::getInstance().currRegionNum; }
	else { return false; }
	
	_data->type = type;
	strcpy(_data->nameStr, nameStr.c_str());
	nameStr[name_strSize - 1] = '\0';
	return true;
}
/*
//Warning: NEED to check type manually when read data.
bool appui_menu_t::menuItemIfce_t::cmpIndex(menuItemIdex_t* _data)
{
	menuItemIdex_t myIndex;
	getIndex(&myIndex);
	if (myIndex == *_data) { return true; }
	return false;
}
*/






/*----------appui_menu_t::menuItem_menuType_t----------*/
//UI Menu menuItem menuEntry_type

appui_menu_t::menuItem_menuType_t::menuItem_menuType_t(menuList_t * _data, std::string _nameStr, uint32_t _pptFlag)
{
	unique_id = itemCnt++;

	type = type_t::menuType;
	data = _data;
	nameStr = _nameStr;
	pptFlag = _pptFlag;
	slotFunc = NULL;
}

appui_menu_t::menuItem_menuType_t::~menuItem_menuType_t(void)
{
	--itemCnt;
}

void appui_menu_t::menuItem_menuType_t::printSlot(appui_menu_t::dispSlot_t _slot)
{
	if (myList->slct_p == list_id)
	{
		_slot.slotNamePrintf(menu_rf_black, menu_rb_orange, "%2.2d|%s", list_id, nameStr.c_str());
		_slot.slotDataPrintf(menu_rf_black, menu_rb_orange, " m|");
	}
	else
	{
		_slot.slotNamePrintf(menu_rf_black, menu_rb_white, "%2.2d|%s", list_id, nameStr.c_str());
		_slot.slotDataPrintf(menu_rf_black, menu_rb_white, " m|");
	}
}

void appui_menu_t::menuItem_menuType_t::directKeyOp(appVar_keyBTOp_t * _op)
{
	switch (*_op)
	{
	case appVar_keyBTOp_t::sok:
	case appVar_keyBTOp_t::llf:
	case appVar_keyBTOp_t::lrt:
		appui_menu_t::getInstance().currList = data;
		//break;	//this is intensively blocked.
	default:
		appui_menu_t::getInstance().currItem = NULL;
		break;
	}
}


void appui_menu_t::menuItem_menuType_t::printDisp(void)
{
	//appui_disp_t::getInstance().dispFillRectangle(19, 220, 19, 220, menu_sf_white);
	//appui_disp_t::getInstance().dispDrawRectangle(19, 220, 19, 220, 2, menu_sb_blue);
}


void appui_menu_t::menuItem_menuType_t::keyOp(appVar_keyBTOp_t * _op)
{
	switch (*_op)
	{
	case appVar_keyBTOp_t::sok:
		//case appVar_keyBTOp_t::lok:
		appui_menu_t::getInstance().currList = data;
		//break;	//this is intensively blocked.
	default:
		appui_menu_t::getInstance().currItem = NULL;
		break;
	}
}







/*----------appui_menu_t::menuItem_variType_t----------*/
//UI Menu menuItem integer_varible

const int32_t appui_menu_t::menuItem_variType_t::lut[4] = { 1,10,100,1000 };

appui_menu_t::menuItem_variType_t::menuItem_variType_t(int32_t * _data, std::string _nameStr, uint32_t _pptFlag)
{
	unique_id = itemCnt++;

	type = variType;
	data = _data;
	nameStr = _nameStr;
	pptFlag = _pptFlag;
	slotFunc = NULL;
	
	cur = 0;
	bData = *data;
}

appui_menu_t::menuItem_variType_t::~menuItem_variType_t(void)
{
	--itemCnt;
}

//used when in menuList
void appui_menu_t::menuItem_variType_t::printSlot(appui_menu_t::dispSlot_t _slot)
{
	if (myList->slct_p == list_id)
	{
		_slot.slotNamePrintf(menu_rf_black, menu_rb_orange, "%2.2d|%s", list_id, nameStr.c_str());
		_slot.slotDataPrintf(menu_rf_black, menu_rb_orange, " i|%15s %d", "", *data);
	}
	else
	{
		_slot.slotNamePrintf(menu_rf_black, menu_rb_white, "%2.2d|%s", list_id, nameStr.c_str());
		_slot.slotDataPrintf(menu_rf_black, menu_rb_white, " i|%15s %d", "", *data);
	}
}

void appui_menu_t::menuItem_variType_t::directKeyOp(appVar_keyBTOp_t * _op)
{
	switch (*_op)
	{
	case appVar_keyBTOp_t::sok:
		getContent(v, e, *data);
		appui_menu_t::getInstance().currItem = this;
		break;
	case appVar_keyBTOp_t::slf:
	case appVar_keyBTOp_t::llf:
	{
		getContent(v, e, *data);
		setContent(*data, v + 100, e);
		break;
	}
	case appVar_keyBTOp_t::srt:
	case appVar_keyBTOp_t::lrt:
	{
		getContent(v, e, *data);
		setContent(*data, v - 100, e);
		break;
	}
	default:
		//appui_menu_t::getInstance().currItem = NULL;
		break;
	}
}

//used when in menuItem
void appui_menu_t::menuItem_variType_t::printDisp(void)
{
	appui_disp_t::getInstance().dispFillRectangle(19, 220, 19, 220, menu_sf_white);
	appui_disp_t::getInstance().dispDrawRectangle(19, 220, 19, 220, 2, menu_sb_blue);
	appui_disp_t::getInstance().dispFillRectangle(20, 20 + 16, 21, 218, menu_sb_blue);
	appui_disp_t::getInstance().dispPrintf(20, 20, menu_sf_white, menu_sb_blue,">%s", nameStr.c_str());
	appui_disp_t::getInstance().dispPrintf(20 + 2 * 16, 36, menu_rf_black, menu_sf_white, "Cur: %d", *data);
	setContent(bData, v, e);
	appui_disp_t::getInstance().dispPrintf(20 + 4 * 16, 36, menu_rf_black, menu_sf_white, "Adj: %d", bData);
	char strBuf[16];
	sprintf(strBuf, "%+4.4de%+1.1d   ", v, e);
	appui_disp_t::getInstance().dispPrint(20 + 6 * 16, 36+4*8, menu_rf_black, menu_sf_white, strBuf);
	if (cur < 0)
	{
		appui_disp_t::getInstance().dispPutchar(20 + 6 * 16, 36 + 11 * 8, menu_rf_black, menu_rb_orange, strBuf[7]);
	}
	else
	{
		appui_disp_t::getInstance().dispPutchar(20 + 6 * 16, 36 + 8 * 8 - cur * 8 , menu_rf_black, menu_rb_orange, strBuf[4-cur]);
	}

}

void appui_menu_t::menuItem_variType_t::keyOp(appVar_keyBTOp_t * _op)
{
	switch (*_op)
	{
	case appVar_keyBTOp_t::sok:
		setContent(*data, v, e);
	case appVar_keyBTOp_t::lok:
		appui_menu_t::getInstance().currItem = NULL;
		break;
	case appVar_keyBTOp_t::llf:
		cur = 3;
	case appVar_keyBTOp_t::lrt:
		cur = -1;
		break;
	case appVar_keyBTOp_t::slf:
		if (cur < 3)
		{
			++cur;
		}
		break;
	case appVar_keyBTOp_t::srt:
		if (cur > -1)
		{
			--cur;
		}
		break;
	case appVar_keyBTOp_t::sup:
	case appVar_keyBTOp_t::lup:
	case appVar_keyBTOp_t::rup:
		if (cur == -1) { ++e; }
		else
		{
			v += lut[cur];
		}
		break;
	case appVar_keyBTOp_t::sdn:
	case appVar_keyBTOp_t::ldn:
	case appVar_keyBTOp_t::rdn:
		if (cur == -1) { --e; }
		else
		{
			v -= lut[cur];
		}
		break;
	default:
		//appui_menu_t::getInstance().currItem = NULL;
		break;
	}
	//v & e ranging
	while (v > 9999 || v < -9999 || e < 0)
	{
		v *= 0.1f;
		e++;
		if (cur > 0) { --cur; }
	}
	while (((v > 0 && v < 100) || (v < 0 && v > -100)) && e > 0)
	{
		v *= 10;
		e--;
		if (cur < 3) { ++cur; }
	}
}

//data process

void appui_menu_t::menuItem_variType_t::getContent(int32_t & v, int32_t & e, int32_t data)
{
	v = data;
	e = 0;
	while (-10 < e && e < 10)
	{
		if (v > 9999)
		{
			v *= 0.1;
			e++;
			continue;
		}
		if (v < -9999)
		{
			v *= 0.1;
			e++;
			continue;
		}
		break;
	}
}
void appui_menu_t::menuItem_variType_t::setContent(int32_t & data, int32_t v, int32_t e)
{
	//int32_t v = v, e = e;
	while (1)
	{
		if (e > 0)
		{
			v *= 10;
			e--;
			continue;
		}
		if (e < 0)
		{
			v *= 0.1;
			e++;
			continue;
		}
		break;
	}
	data = v;
}










/*----------appui_menu_t::menuItem_variType_t----------*/
//UI Menu menuItem integer_varible

const int32_t appui_menu_t::menuItem_varfType_t::lut[4] = { 1,10,100,1000 };

appui_menu_t::menuItem_varfType_t::menuItem_varfType_t(float* _data, std::string _nameStr, uint32_t _pptFlag)
{
	unique_id = itemCnt++;

	type = type_t::variType;
	data = _data;
	nameStr = _nameStr;
	pptFlag = _pptFlag;
	slotFunc = NULL;

	cur = 0;
	bData = *data;
}

appui_menu_t::menuItem_varfType_t::~menuItem_varfType_t(void)
{
	--itemCnt;
}

//used when in menuList
void appui_menu_t::menuItem_varfType_t::printSlot(appui_menu_t::dispSlot_t _slot)
{
	if (myList->slct_p == list_id)
	{
		_slot.slotNamePrintf(menu_rf_black, menu_rb_orange, "%2.2d|%s", list_id, nameStr.c_str());
		_slot.slotDataPrintf(menu_rf_black, menu_rb_orange, " i|%15s %.2f", "", *data);
	}
	else
	{
		_slot.slotNamePrintf(menu_rf_black, menu_rb_white, "%2.2d|%s", list_id, nameStr.c_str());
		_slot.slotDataPrintf(menu_rf_black, menu_rb_white, " i|%15s %.2f", "", *data);
	}
}

void appui_menu_t::menuItem_varfType_t::directKeyOp(appVar_keyBTOp_t* _op)
{
	switch (*_op)
	{
	case appVar_keyBTOp_t::sok:
		getContent(v, e, *data);
		appui_menu_t::getInstance().currItem = this;
		break;
	case appVar_keyBTOp_t::slf:
	case appVar_keyBTOp_t::llf:
	{
		getContent(v, e, *data);
		setContent(*data, v + 100, e);
		break;
	}
	case appVar_keyBTOp_t::srt:
	case appVar_keyBTOp_t::lrt:
	{
		getContent(v, e, *data);
		setContent(*data, v - 100, e);
		break;
	}
	default:
		//appui_menu_t::getInstance().currItem = NULL;
		break;
	}
}

//used when in menuItem
void appui_menu_t::menuItem_varfType_t::printDisp(void)
{
	appui_disp_t::getInstance().dispFillRectangle(19, 220, 19, 220, menu_sf_white);
	appui_disp_t::getInstance().dispDrawRectangle(19, 220, 19, 220, 2, menu_sb_blue);
	appui_disp_t::getInstance().dispFillRectangle(20, 20 + 16, 21, 218, menu_sb_blue);
	appui_disp_t::getInstance().dispPrintf(20, 20, menu_sf_white, menu_sb_blue, ">%s", nameStr.c_str());
	appui_disp_t::getInstance().dispPrintf(20 + 2 * 16, 36, menu_rf_black, menu_sf_white, "Cur: %.4f", *data);
	setContent(bData, v, e);
	appui_disp_t::getInstance().dispPrintf(20 + 4 * 16, 36, menu_rf_black, menu_sf_white, "Adj: %.4f", bData);
	char strBuf[16];
	sprintf(strBuf, "%+4.4de%+1.1d   ", v, e);
	appui_disp_t::getInstance().dispPrint(20 + 6 * 16, 36 + 4 * 8, menu_rf_black, menu_sf_white, strBuf);
	if (cur < 0)
	{
		appui_disp_t::getInstance().dispPutchar(20 + 6 * 16, 36 + 11 * 8, menu_rf_black, menu_rb_orange, strBuf[7]);
	}
	else
	{
		appui_disp_t::getInstance().dispPutchar(20 + 6 * 16, 36 + 8 * 8 - cur * 8, menu_rf_black, menu_rb_orange, strBuf[4 - cur]);
	}

}

void appui_menu_t::menuItem_varfType_t::keyOp(appVar_keyBTOp_t* _op)
{
	switch (*_op)
	{
	case appVar_keyBTOp_t::sok:
		setContent(*data, v, e);
	case appVar_keyBTOp_t::lok:
		appui_menu_t::getInstance().currItem = NULL;
		break;
	case appVar_keyBTOp_t::llf:
		cur = 3;
	case appVar_keyBTOp_t::lrt:
		cur = -1;
		break;
	case appVar_keyBTOp_t::slf:
		if (cur < 3)
		{
			++cur;
		}
		break;
	case appVar_keyBTOp_t::srt:
		if (cur > -1)
		{
			--cur;
		}
		break;
	case appVar_keyBTOp_t::sup:
	case appVar_keyBTOp_t::lup:
	case appVar_keyBTOp_t::rup:
		if (cur == -1) { ++e; }
		else
		{
			v += lut[cur];
		}
		break;
	case appVar_keyBTOp_t::sdn:
	case appVar_keyBTOp_t::ldn:
	case appVar_keyBTOp_t::rdn:
		if (cur == -1) { --e; }
		else
		{
			v -= lut[cur];
		}
		break;
	default:
		//appui_menu_t::getInstance().currItem = NULL;
		break;
	}
	//v & e ranging
	while (v > 9999 || v < -9999)
	{
		v /= 10;
		e++;
	}
	while ((v > 0 && v < 1000) || (v < 0 && v > -1000))
	{
		v *= 10;
		e--;
	}
}

//data process

void appui_menu_t::menuItem_varfType_t::getContent(int32_t& v, int32_t& e, float data)
{
	e = 0;
	while (-10 < e && e < 10)
	{
		if (data > 0.0 && data < 999.0)
		{
			data *= 10.0;
			e--;
			continue;
		}
		if (data > 9999.0)
		{
			data /= 10.0;
			e++;
			continue;
		}
		if (data < 0.0 && data > -999.0)
		{
			data *= 10.0;
			e--;
			continue;
		}
		if (data < -9999.0)
		{
			data /= 10.0;
			e++;
			continue;
		}
		break;
	}
	v = (int32_t)data;
}
void appui_menu_t::menuItem_varfType_t::setContent(float& data, int32_t v, int32_t e)
{
	while (1)
	{
		if (e > 0)
		{
			v *= 10.0;
			e--;
			continue;
		}
		if (e < 0)
		{
			v /= 10.0;
			e++;
			continue;
		}
		break;
	}
	data = v;
}



/*----------appui_menu_t::menuItem_procType_t----------*/
//UI Menu menuItem process_type
appui_menu_t::menuItem_procType_t::menuItem_procType_t(procHandler_t _data, std::string _nameStr, uint32_t _pptFlag)
{
	unique_id = itemCnt++;

	type = type_t::variType;
	data = _data;
	nameStr = _nameStr;
	pptFlag = _pptFlag;
	slotFunc = NULL;

	flag = 0;
	retv = 0;
}

appui_menu_t::menuItem_procType_t::~menuItem_procType_t(void)
{
	--itemCnt;
}

//used when in menuList

void appui_menu_t::menuItem_procType_t::printSlot(appui_menu_t::dispSlot_t _slot)
{
	if (myList->slct_p == list_id)
	{
		_slot.slotNamePrintf(menu_rf_black, menu_rb_orange, "%2.2d|%s", list_id, nameStr.c_str());
		_slot.slotDataPrintf(menu_rf_black, menu_rb_orange, " p|%15s%d", "", retv);
	}
	else
	{
		_slot.slotNamePrintf(menu_rf_black, menu_rb_white, "%2.2d|%s", list_id, nameStr.c_str());
		_slot.slotDataPrintf(menu_rf_black, menu_rb_white, " p|%15s%d", "", retv);
	}
}

void appui_menu_t::menuItem_procType_t::directKeyOp(appVar_keyBTOp_t* _op)
{
	switch (*_op)
	{
	case appVar_keyBTOp_t::sok:
		appui_menu_t::getInstance().currItem = this;
		break;
	case appVar_keyBTOp_t::slf:
	case appVar_keyBTOp_t::srt:
		flag = menu_dircKeyOp_avail;
		(*data)(_op, flag, retv);
		break;
	default:
		
		break;
	}
	
}

//used when in menuItem

void appui_menu_t::menuItem_procType_t::printDisp(void)
{
	appui_disp_t::getInstance().dispFillRectangle(19, 220, 19, 220, menu_sf_white);
	appui_disp_t::getInstance().dispDrawRectangle(19, 220, 19, 220, 2, menu_sb_blue);

	flag = menu_dispRequest;
	(*data)(NULL, flag, retv);
	if (flag & proc_exitProcess)
	{
		appui_menu_t::getInstance().currItem = NULL;
	}
}

void appui_menu_t::menuItem_procType_t::keyOp(appVar_keyBTOp_t* _op)
{
	switch (*_op)
	{
	case appVar_keyBTOp_t::lok:
		appui_menu_t::getInstance().currItem = NULL;
		break;
	case appVar_keyBTOp_t::sok:
	case appVar_keyBTOp_t::sup:
	case appVar_keyBTOp_t::sdn:
	case appVar_keyBTOp_t::slf:
	case appVar_keyBTOp_t::srt:
		flag = menu_itemKeyOp_avail;
		(*data)(_op, flag, retv);
		break;
	default:
		break;
	}
}




















/*----------appui_menu_t----------*/

int32_t test_i = 23450;
float test_f = 3114.3f;

void test_p(appVar_keyBTOp_t* _op, uint32_t& _flag, int32_t& _retv)
{
	if (_flag & appui_menu_t::menuItem_procType_t::menu_dircKeyOp_avail)
	{
		_retv = 1000 + (int32_t)(*_op);
	}
	if (_flag & appui_menu_t::menuItem_procType_t::menu_itemKeyOp_avail)
	{
		_retv = 3000 + (int32_t)(*_op);
	}
	if (_flag & appui_menu_t::menuItem_procType_t::menu_dispRequest)
	{
		appui_disp_t::getInstance().dispPrint(50, 50, menu_rf_black, "test_p run.");
	}
}

appui_menu_t::appui_menu_t(void)
{
	currList = &rootMenu;
	currItem = NULL;
	
	rootMenu.insert(new menuItem_variType_t((int32_t*)(&(this->currRegionNum)), std::string("@currRegionNum"), menuItemIfce_t::data_global | menuItemIfce_t::data_prioRW));

	rootMenu.insert(new menuItem_menuType_t(&menuTest, "MenuTest", 0));
	{
		menuTest.insert(new menuItem_variType_t(&test_i, "test_i", menuItemIfce_t::data_region));
		menuTest.insert(new menuItem_varfType_t(&test_f, "test_f", menuItemIfce_t::data_region));
		menuTest.insert(new menuItem_procType_t(test_p, "test_p", 0));
	}

}

void appui_menu_t::printDisp(void)
{
	if (currItem == NULL)
	{
		currList->printDisp();
	}
	else
	{
		currItem->printDisp();
	}
}

void appui_menu_t::keyOp(appVar_keyBTOp_t * _op)
{
	if (currItem == NULL)
	{
		currList->keyOp(_op);
	}
	else
	{
		currItem->keyOp(_op);
	}
}



void appui_menu_t::dataSave(void)
{
	menuItemSaver_t dataBuf;
	std::deque<menuItemSaver_t> globalQue(0), regionQue(0);

	std::deque<menuList_t*> listQue(0);
	listQue.push_back(&rootMenu);	//push root menu in queue
	//uint32_t itemNumCnt = 0;
	char comBuf[1024] = "";

	//sprintf(comBuf, "\r\n>UI_MENU: Begin saving flash content...\r\n");
	//com_tx_str(comBuf);
	

	//start writing

	for (uint8_t list = 0; list < listQue.size(); list++)
	{
		for (auto it : listQue[list]->menu)
		{
			if (it->getIndex(&dataBuf.index) == true)
			{
				dataBuf.data = it->getData();
				if (dataBuf.index.head == dataBuf.index.globalHead) 
				{
					globalQue.push_back(dataBuf); 
				}
				else 
				{
					regionQue.push_back(dataBuf); 
				}
			}
			else if (it->type == menuItemIfce_t::menuType)
			{
				bool list_push = true;
				for (auto it2 : listQue)
				{
					//if ((uint32_t)(it2) == (*it).getData()) { list_push = false; break; }
				}
				//if (list_push) { listQue.push_back((menuList_t*)(*it).getData()); }
				break;
			}

		}
	}

	//generate EOF in the last sector.
	memset(&dataBuf, 0x0f, sizeof(menuItemSaver_t));
	globalQue.push_back(dataBuf);
	regionQue.push_back(dataBuf);

	uint32_t addr;
	addr = globalAddrOffset;
	for (auto it : globalQue)
	{
		appui_dataIO_t::getInstance().save(addr, sizeof(menuItemSaver_t), (void*)(&it));
		addr += sizeof(menuItemSaver_t);
	}

	addr = regionAddrOffset[currRegionNum];
	for (auto it : regionQue)
	{
		appui_dataIO_t::getInstance().save(addr, sizeof(menuItemSaver_t), (void*)(&it));
		addr += sizeof(menuItemSaver_t);
	}
	
	
}

void appui_menu_t::dataRead(void)
{
	menuItemSaver_t dataBuf,eofFlag;
	memset(&eofFlag, 0x0f, sizeof(menuItemSaver_t));
	menuItemIdex_t myIndex;	//index used for buffering when search.
	std::map<menuItemIdex_t, uint32_t> globalMap, regionMap;

	uint32_t addr;
	addr = globalAddrOffset;
	while (1)
	{
		appui_dataIO_t::getInstance().read(addr, sizeof(menuItemSaver_t), &dataBuf);
		addr += sizeof(menuItemSaver_t);
		if (dataBuf == eofFlag) { break; }
		else
		{
			globalMap[dataBuf.index] = dataBuf.data;
		}
	}


	std::deque<menuList_t*> listQue(0);
	listQue.push_back(&rootMenu);	//push root menu in queue
	//uint32_t itemNumCnt = 0;
	char comBuf[1024] = "";

	for (uint8_t list = 0; list < listQue.size(); list++)
	{
		for (auto it : listQue[list]->menu)
		{
			if (it->type == menuItemIfce_t::menuType)
			{
				bool list_push = true;
				for (auto it2 : listQue)
				{
					//if ((uint32_t)(it2) == (*it).getData()) { list_push = false; break; }
				}
				//if (list_push) { listQue.push_back((menuList_t*)(*it).getData()); }
				break;
			}
			else if(it->pptFlag & menuItemIfce_t::data_global)
			{
				it->getIndex(&myIndex);
				auto search = globalMap.find(myIndex);
				if (search == globalMap.end())//not found.
				{
					//++menuItemNotFound;
					//sprintf(strBuf, "menuItem \" %16.16s \" not found.\r\n", it->name);
					//com_tx_str(strBuf);
					continue;
				}	
				else
				{
					it->setData(search->second);
				}
			}
			//appui_dataIO_t::getInstance().save(itemNumCnt * sizeof(menuItemIdex_t), sizeof(menuItemIdex_t),(void*)(&dataBuf));
		}
	}

	globalMap.clear();	//save RAM.


	addr = regionAddrOffset[currRegionNum];
	while (1)
	{
		appui_dataIO_t::getInstance().read(addr, sizeof(menuItemSaver_t), &dataBuf);
		addr += sizeof(menuItemSaver_t);
		if (dataBuf == eofFlag) { break; }
		else
		{
			regionMap[dataBuf.index] = dataBuf.data;
		}
	}

	for (uint8_t list = 0; list < listQue.size(); list++)
	{
		for (auto it : listQue[list]->menu)
		{
			if (it->type == menuItemIfce_t::menuType)
			{
				
			}
			else if (it->pptFlag & menuItemIfce_t::data_global)
			{
				it->getIndex(&myIndex);
				auto search = regionMap.find(myIndex);
				if (search == regionMap.end())//not found.
				{
					//++menuItemNotFound;
					//sprintf(strBuf, "menuItem \" %16.16s \" not found.\r\n", it->name);
					//com_tx_str(strBuf);
					continue;
				}
				else
				{
					it->setData(search->second);
				}
			}
		}
	}

}

















/*----------appui_t----------*/




void appui_t::printDisp(void)
{
	//if(currItem)
}
