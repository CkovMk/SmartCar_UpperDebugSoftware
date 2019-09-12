/*
 * Beta-Cat Controll @ HSIC
 * @name	app_ui.h
 * Application Layer User Interface.
 *
*/
#pragma once
#ifndef _APP_VIEWER_H_
#define _APP_VIEWER_H_

#include "inc_std.h"
#include "inc_stl.h"
#include "inc_gnc.h"

#include "app_var.h"

#if defined(_OPENCV_DBG_) && _OPENCV_DBG_
#include <opencv2/opencv.hpp>
#include <fstream>
#else




#endif

//display HAL

class appui_disp_t
{
public:
	static appui_disp_t& getInstance(void)
	{
		static appui_disp_t inst;
		return inst;
	}
	typedef uint32_t dispSize_t;

	gnc_rgbLcdBuf_t dispBuf;// = *(new gnc_rgbLcdBuf_t);

	

	void disp_update(void);
	//set one pixel on dispBuf
	void setPixel(dispSize_t r, dispSize_t c, gnc_rgb_t color) { dispBuf.pix[r][c] = color; }
	//print one char on dispBuf, (r,c) is Top_Left_Corner.
	void dispPutchar(dispSize_t r, dispSize_t c, gnc_rgb_t f_color, gnc_rgb_t b_color, const char ch);
	//write string on dispBuf, '\n' & auto linefeed Enabled. (r,c) is Top_Left_Corner.
	void dispPrint(dispSize_t r, dispSize_t c, gnc_rgb_t f_color, gnc_rgb_t b_color, const char* str);
	//write formatted string on dispBuf, '\n' & auto linefeed Enabled. (r,c) is Top_Left_Corner.
	void dispPrintf(dispSize_t r, dispSize_t c, gnc_rgb_t f_color, gnc_rgb_t b_color, const char* _fmt, ...);
	//write string on dispBuf, '\n' & auto linefeed Disabled. row should in range of 0~15.
	void rowPrint(dispSize_t row, dispSize_t c, gnc_rgb_t f_color, gnc_rgb_t b_color, const char* str);
	//write formatted string on dispBuf, '\n' & auto linefeed Disabled. row should in range of 0~15.
	void rowPrintf(dispSize_t row, dispSize_t c, gnc_rgb_t f_color, gnc_rgb_t b_color, const char* _fmt, ...);

	//print one char on dispBuf, (r,c) is Top_Left_Corner. OverLay.
	void dispPutchar(dispSize_t r, dispSize_t c, gnc_rgb_t f_color, const char ch);
	//write string on dispBuf, '\n' & auto linefeed Enabled. (r,c) is Top_Left_Corner. OverLay.
	void dispPrint(dispSize_t r, dispSize_t c, gnc_rgb_t f_color, const char* str);
	//write formatted string on dispBuf, '\n' & auto linefeed Enabled. (r,c) is Top_Left_Corner. OverLay.
	void dispPrintf(dispSize_t r, dispSize_t c, gnc_rgb_t f_color, const char* _fmt, ...);
	//write string on dispBuf, '\n' & auto linefeed Disabled. row should in range of 0~15. OverLay.
	void rowPrint(dispSize_t row, dispSize_t c, gnc_rgb_t f_color, const char* str);
	//write formatted string on dispBuf, '\n' & auto linefeed Disabled. row should in range of 0~15. OverLay.
	void rowPrintf(dispSize_t row, dispSize_t c, gnc_rgb_t f_color, const char* _fmt, ...);

	void dispFillRectangle(dispSize_t r1, dispSize_t r2, dispSize_t c1, dispSize_t c2, gnc_rgb_t b_color);
	void dispDrawRectangle(dispSize_t r1, dispSize_t r2, dispSize_t c1, dispSize_t c2, dispSize_t thick, gnc_rgb_t b_color);




private:
	appui_disp_t(void) {}
	appui_disp_t(const appui_disp_t&);
	appui_disp_t& operator = (const appui_disp_t&);

};


class appui_dataIO_t
{
public:

#if defined(_OPENCV_DBG_) && _OPENCV_DBG_
	const char fileName[64] = "uiData.mdat";
	FILE* ifp;
	FILE* ofp;
#else
#error "unfilled code !"
#endif

	static appui_dataIO_t& getInstance(void)
	{
		static appui_dataIO_t inst;
		return inst;
	}

	void fill(void)
	{
#if defined(_OPENCV_DBG_) && _OPENCV_DBG_
		fseek(ofp, 0, SEEK_SET);
		//oFile.seekp(0, std::ios::beg);
		for (int i = 0; i < 196608; i++)
		{
			//oFile.write(0, 1);
			uint8_t d = 0;
			fwrite(&d, 1, 1, ofp);
		}
#else
#error "unfilled code !"
#endif
		
	}

	bool read(uint32_t _addr, uint32_t _cnt, void* _buf)
	{
#if defined(_OPENCV_DBG_) && _OPENCV_DBG_
		fseek(ifp, addr(_addr), SEEK_SET);
		fread(_buf, 1, _cnt, ifp);
		//iFile.read((char*)_buf, _cnt);
#else
#error "unfilled code !"
#endif
		return true;
	}
	bool save(uint32_t _addr, uint32_t _cnt, void* _buf)
	{
#if defined(_OPENCV_DBG_) && _OPENCV_DBG_
		fseek(ofp, addr(_addr), SEEK_SET);
		fwrite(_buf, 1, _cnt, ofp);
#else
#error "unfilled code !"
#endif
		return true;
	}

private:
	appui_dataIO_t(void)
	{
#if defined(_OPENCV_DBG_) && _OPENCV_DBG_
		ofp = fopen(fileName, "wb");
		ifp = fopen(fileName, "rb");
#else
#error "unfilled code !"
#endif
	}


	uint32_t addr(uint32_t _addr)
	{
#if defined(_OPENCV_DBG_) && _OPENCV_DBG_
		return _addr;
#else
#error "unfilled code !"
#endif
	}



};



//menu
class appui_menu_t
{
public:

	static const uint32_t name_strSize = 24;

	class dispSlot_t
	{
	public:
		appui_disp_t::dispSize_t slotNum;
		dispSlot_t(appui_disp_t::dispSize_t _slot) : slotNum(_slot){}
		void slotNamePrintf(gnc_rgb_t f_color, gnc_rgb_t b_color, char* _fmt, ...);
		void slotDataPrintf(gnc_rgb_t f_color, gnc_rgb_t b_color, char* _fmt, ...);
		void erase(void);
	};

	struct menuItemIdex_t
	{
		static const uint8_t globalHead = 0xaf, regionHead = 0xa0;

		uint8_t head;
		uint8_t type;
		char nameStr[name_strSize];
		uint8_t strSum[2];	// DO NOT CARE at present.
		//uint8_t data[4];

		bool operator== (const menuItemIdex_t& a)const
		{
			if (memcmp(this, &a, sizeof(menuItemIdex_t)) == 0) { return true; }
			return false; 
		}
		bool operator >(const menuItemIdex_t& a)const
		{
			if (memcmp(this, &a, sizeof(menuItemIdex_t)) > 0) { return true; }
			return false; 
		}
		bool operator <(const menuItemIdex_t& a)const
		{
			if (memcmp(this, &a, sizeof(menuItemIdex_t)) < 0) { return true; }
			return false; 
		}
		
	};

	struct menuItemSaver_t
	{
		menuItemIdex_t index;
		uint32_t data;

		bool operator== (const menuItemSaver_t& a)const
		{
			if (memcmp(this, &a, sizeof(menuItemSaver_t)) == 0) { return true; }
			return false;
		}
	};




	class menuItemIfce_t;

	//UI Menu menuList
	class menuList_t
	{
	public:
		static const uint32_t slotPerScreen = 8;
		//static const uint32_t name_strSize = 24;
		std::vector<menuItemIfce_t*> menu;
		uint32_t disp_p, slct_p;
		std::string nameStr;
		menuList_t* prev;

		menuList_t(std::string _nameStr, menuList_t* _prev);
		~menuList_t(void);
		void insert(appui_menu_t::menuItemIfce_t* item);
		void printDisp(void);
		void keyOp(appVar_keyBTOp_t* _op);

	};

	//UI Menu menuItem interface
	class menuItemIfce_t
	{
	public:
		enum type_t : uint8_t
		{
			nullType,
			variType,
			varfType,
			procType,
			menuType,
		};
		enum message_t : uint32_t
		{
			selected,
			deselected,
			dataUpdate,
		};
		enum propety_t : uint32_t
		{
			//data config
			data_global = 1 << 0,	//data save in global area
			data_region = 1 << 1,	//data save in regional area
			data_getPos = data_global | data_region,
			data_ROFlag = 1 << 2,	//data read only
			data_prioRW = 1 << 3,	//data rw prior than other item
			data_getCfg = data_global | data_region | data_ROFlag | data_prioRW,

			//error mask
		};
		typedef void (*slotFunction_t)(menuItemIfce_t* _this, message_t _msg);
		//static const uint32_t name_strSize = 24;
		static uint32_t itemCnt;


		type_t type;
		menuList_t* myList;
		uint32_t pptFlag;	//property flag
		uint32_t list_id, unique_id;
		std::string nameStr;
		slotFunction_t slotFunc;
		/*
		 * Configure by Constructor Default:
		 *     type,unique_id,slotFunc
		 * Configure by Constructor Parameter:
		 *     pptFlag,nameStr,(*data)
		 * Configure by menuList insert() Default:
		 *     myList,list_id,
		 *
		 */

		virtual void installSlotFunction(slotFunction_t _func) final { slotFunc = _func; }
		virtual void uninstallSlotFunction(void) final { slotFunc = NULL; }
		virtual void slotCall(message_t _msg) final
		{
			if (slotFunc != NULL) { (*slotFunc)(this, _msg); }
		}
		//used when reading or saving data
		virtual uint32_t getData(void) = 0;
		virtual void setData(uint32_t _data) = 0;
		virtual bool getIndex(menuItemIdex_t* _data) final;
		//virtual bool cmpIndex(menuItemIdex_t* _data) final;
		//used when in menuList
		virtual void printSlot(appui_menu_t::dispSlot_t _slot) = 0;
		virtual void directKeyOp(appVar_keyBTOp_t * _op) = 0;
		//used when in menuItem
		virtual void printDisp(void) = 0;
		virtual void keyOp(appVar_keyBTOp_t * _op) = 0;
	};
	//End of UI Menu menuItem interface

	//UI Menu menuItem menuEntry_type
	class menuItem_menuType_t : public menuItemIfce_t
	{
	public:
		menuList_t* data;
		menuItem_menuType_t(menuList_t* _data, std::string _nameStr, uint32_t _pptFlag);
		~menuItem_menuType_t(void);
		//used when reading or saving data
		void setData(uint32_t _data) final{}
		uint32_t getData(void) final { return  0;/* (uint32_t)data;*/ }
		//used when in menuList
		void printSlot(appui_menu_t::dispSlot_t _slot) final;
		void directKeyOp(appVar_keyBTOp_t* _op) final;
		//used when in menuItem
		void printDisp(void) final;
		void keyOp(appVar_keyBTOp_t* _op) final;
	};
	
	//UI Menu menuItem integer_varible
	class menuItem_variType_t : public menuItemIfce_t
	{
	public:
		int32_t* data;
		int32_t bData;
		menuItem_variType_t(int32_t* _data, std::string _nameStr, uint32_t _pptFlag);
		~menuItem_variType_t(void);
		//used when reading or saving data
		void setData(uint32_t _data) final { (*data) = _data; }
		uint32_t getData(void) final { return *((uint32_t*)data); }
		//used when in menuList
		void printSlot(appui_menu_t::dispSlot_t _slot) final;
		void directKeyOp(appVar_keyBTOp_t* _op) final;
		//used when in menuItem
		void printDisp(void) final;
		void keyOp(appVar_keyBTOp_t* _op) final;
	private:
		static const int32_t lut[4];
		int32_t v, e;
		int32_t cur;	//cursor pos
		void getContent(int32_t& v, int32_t& e, int32_t data);
		void setContent(int32_t& data, int32_t v, int32_t e);
		
	};

	//UI Menu menuItem floatpoint_varible
	class menuItem_varfType_t : public menuItemIfce_t
	{
	public:
		float* data;
		float bData;
		menuItem_varfType_t(float* _data, std::string _nameStr, uint32_t _pptFlag);
		~menuItem_varfType_t(void);
		//used when reading or saving data
		void setData(uint32_t _data) final { (*data) = *((float*)(&_data)); }
		uint32_t getData(void) final { return *((uint32_t*)data); }
		//used when in menuList
		void printSlot(appui_menu_t::dispSlot_t _slot) final;
		void directKeyOp(appVar_keyBTOp_t* _op) final;
		//used when in menuItem
		void printDisp(void) final;
		void keyOp(appVar_keyBTOp_t* _op) final;
	private:
		static const int32_t lut[4];
		int32_t v, e;
		int32_t cur;	//cursor pos
		void getContent(int32_t& v, int32_t& e, float data);
		void setContent(float& data, int32_t v, int32_t e);

	};


	//UI Menu menuItem process_type
	class menuItem_procType_t : public menuItemIfce_t
	{
	public:
		enum cmdFlag_t
		{
			menu_dircKeyOp_avail = 1 << 0,
			menu_itemKeyOp_avail = 1 << 1,
			menu_dispRequest = 1 << 2,

			proc_exitProcess = 1 << 15,
		};
		typedef void (*procHandler_t)(appVar_keyBTOp_t* _op,uint32_t& _flag, int32_t& _retv);

		int32_t retv;
		uint32_t flag;
		procHandler_t data;
		menuItem_procType_t(procHandler_t _data, std::string _nameStr, uint32_t _pptFlag);
		~menuItem_procType_t(void);

		//used when reading or saving data
		void setData(uint32_t _data) final{}
		uint32_t getData(void) final { return 0; }
		//used when in menuList
		void printSlot(appui_menu_t::dispSlot_t _slot) final;
		void directKeyOp(appVar_keyBTOp_t* _op) final;
		//used when in menuItem
		void printDisp(void) final;
		void keyOp(appVar_keyBTOp_t* _op) final;
	};
	

	
	//static definitions
	menuList_t* currList;
	menuItemIfce_t* currItem;
	const uint8_t saveRegionCnt = 5;
	int32_t currRegionNum;

	const uint32_t globalAddrOffset = 0;
	const uint32_t regionAddrOffset[5] = {32768,65536,98304,131072,163840};
	
	//general definitions
	menuList_t rootMenu = menuList_t(std::string("#RootMenu#"), &rootMenu);

	static appui_menu_t& getInstance(void)
	{
		static appui_menu_t inst;
		inst.currRegionNum = 0;
		return inst;
	}


	menuList_t menuTest = menuList_t(std::string("#MenuTest#"), &rootMenu);

	void printDisp(void);
	void keyOp(appVar_keyBTOp_t* _op);

	void dataSave(void);
	void dataRead(void);

	private:
	appui_menu_t(void);
	~appui_menu_t(void){}
};

//image
class appui_imge_t
{
	static appui_imge_t& getInstance(void)
	{
		static appui_imge_t inst;
		return inst;
	}

private:
	appui_imge_t(void);
};

//datalog
class appui_dlog_t
{
public:

	const uint32_t maxLogNum = 4096;
	std::deque<std::string> log;

	static appui_dlog_t& getInstance(void)
	{
		static appui_dlog_t inst;
		return inst;
	}

	void printDisp(void)
	{
		static appui_disp_t& inst = appui_disp_t::getInstance();

	}

private:
	appui_dlog_t(void);

};


class appui_t
{
public:
	static appui_t& getInstance(void)
	{
		static appui_t inst;
		return inst;
	}

	

	appui_menu_t& uimenu = appui_menu_t::getInstance();



	//appui global function
	void printDisp(void);
	


private:
	appui_t(void) {}
	appui_t(const appui_t&);
	appui_t& operator = (const appui_t&);

	
};





















#endif // ! _APP_VIEWER_H_