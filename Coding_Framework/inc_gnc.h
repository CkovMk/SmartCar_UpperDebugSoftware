/*
 * Beta-Cat Controll @ HSIC
 * @name	inc_gnc.h
 * Generic include file. Include ALL global varibles, golbal definitions HERE.
 * Warning: This file should be platform-independent.
*/
#pragma once
#ifndef _INC_GNC_H_
#define _INC_GNC_H_
/*
----------Global Definitions----------
*/
#define INC_USING_FREERTOS		0U

#if defined(_OPENCV_DBG_) && _OPENCV_DBG_
//TODO: Fix this.
#define kStatus_Success 0
#define kStatus_Fail 1

typedef int status_t;

#endif

/*
----------Global Varible Type Definitions----------
*/
typedef		float		gflt_t;
typedef		int32_t		gint_t;

//color processing

#define GNC_SQRT3 1.73205f
#define GNC_1DSQRT3 0.57735f
#define GNC_SQRT2 1.41421f
#define GNC_1DSQRT2 0.707107f

#define GNC_MIN(x,y) (x<y?x:y)
#define GNC_MAX(x,y) (x<y?y:x)

#define GNC_PI (3.1415926f)
#define GNC_PId2 (GNC_PI/2.0f) //PI/2
#define GNC_PId3 (GNC_PI/3.0f) //PI/3
#define GNC_2PI (GNC_PI*2.0f) //2PI

#define GNC_DEG2RAD(x) (x/180.0f*gnc_PI)
#define GNC_RAD2DEG(x) (x/GNC_PI*180.0f)


#define GNC_G 9.80f


class gnc_rgb_t
{
public:
	uint8_t r;
	uint8_t g;
	uint8_t b;
	gnc_rgb_t() { r = g = b = 0; }
	gnc_rgb_t(uint8_t _r, uint8_t _g, uint8_t _b) :r(_r), g(_g), b(_b) {}
	//operator gnc_hsi_t(void);
};

class gnc_hsv_t
{
public:
	uint8_t h;
	uint8_t s;
	uint8_t v;
	gnc_hsv_t() { h = s = v = 0; }
	gnc_hsv_t(uint8_t _h, uint8_t _s, uint8_t _v) :h(_h), s(_s), v(_v) {}
	//operator gnc_rgb_t(void);
};

static inline gnc_hsv_t gnc_rgb2hsv(gnc_rgb_t rgb)
{
	gnc_hsv_t ret;
	float fr = ((float)rgb.r);
	float fg = ((float)rgb.g);
	float fb = ((float)rgb.b);
	float max , min;
	if (fr > fg)
	{
		max = fr;
		min = fg;
	}
	else
	{
		max = fg;
		min = fr;
	}
	if (fb > max)
	{
		max = fb;
	}
	else if (fb < min)
	{
		min = fb;
	}

	if (max == min)
	{
		ret.h = 0;
	}
	else if (max == fr)
	{
		if (fg < fb)
		{
			ret.h = ((fg - fb) / (max - min)) / 6.0f * 255.0f;
		}
		else
		{
			ret.h = ((fg - fb) / (max - min) + 6.0f) / 6.0f * 255.0f;
		}
	}
	else if (max == fg)
	{
		ret.h = ((fb - fr) / (max - min) + 2.0f) / 6.0f * 255.0f;
	}
	else if (max == fb)
	{
		ret.h = ((fr - fg) / (max - min) + 4.0f) / 6.0f * 255.0f;
	}

	if (max < 0.0001f)
	{
		ret.s = 0;
	}
	else
	{
		ret.s = (1.0f - min / max) * 255.0f;
	}

	ret.v = max;

	return ret;
}

static inline gnc_rgb_t gnc_hsv2rgb(gnc_hsv_t hsv)
{
	gnc_rgb_t ret;
	
	uint8_t hi = ((float)hsv.h) * 60.0f / 255.0f;
	hi = hi % 6;

	float f = (((float)hsv.h) * 60.0f / 255.0f) - hi;

	float fv = ((float)hsv.v);
	float fs = ((float)hsv.s) / 255.0f;

	float p = fv * (1.0f - fs);
	float q = fv * (1.0f - f * fs);
	float r = fv * (1.0f - (1.0f - f) * fs);

	switch (hi)
	{
	case 0:
		ret = gnc_rgb_t(fv, r, p); break;
	case 1:
		ret = gnc_rgb_t(q, fv, p); break;
	case 2:
		ret = gnc_rgb_t(p, fv, r); break;
	case 3:
		ret = gnc_rgb_t(p, q, fv); break;
	case 4:
		ret = gnc_rgb_t(r, p, fv); break;
	case 5:
		ret = gnc_rgb_t(fv, p, q); break;
	}
	
	return ret;
}

//inline gnc_rgb_t::operator gnc_hsi_t(void)
//{
//	return gnc_rgb2hsi(*this);
//}

//inline gnc_hsi_t::operator gnc_rgb_t(void)
//{
//	return gnc_hsi2rgb(*this);
//}





//original camera image size
#define GNC_CAM_IMG_R 400u
#define GNC_CAM_IMG_C 640u

struct gnc_rgbCamImg_t
{
	gnc_rgb_t pix[GNC_CAM_IMG_R][GNC_CAM_IMG_C];
};

struct gnc_hsvCamImg_t
{
	gnc_hsv_t pix[GNC_CAM_IMG_R][GNC_CAM_IMG_C];
};

//ipt image size, used for final digesting
#define GNC_IPT_IMG_R 200u
#define GNC_IPT_IMG_C 160u

struct gnc_rgbIptImg_t
{
	gnc_rgb_t pix[GNC_IPT_IMG_R][GNC_IPT_IMG_C];
};
struct gnc_hsvIptImg_t
{
	gnc_hsv_t pix[GNC_IPT_IMG_R][GNC_IPT_IMG_C];
};



#define GNC_LCD_R 240u
#define GNC_LCD_C 240u


struct gnc_rgbLcdBuf_t
{
	gnc_rgb_t pix[GNC_LCD_R][GNC_LCD_C];
};

/*
----------Global Varible Definitions----------
*/










// begin is the first , endin is the one after the last.
static const uint8_t gnc_asciiBegin = 32;
static const uint8_t gnc_asciiEndin = 127;
static const uint8_t gnc_asciiCnt = 95;

/*
 * this font is in Totally Hscan Mode.
 * each (uint8_t) represents ONE H line.
 * Total 16 (uint8_t)s stores ALL 16 H lines.
 * When it comes to Chinese, each single cell is an (uint16_t).
 */

static const uint8_t gnc_font0816_newSongType[gnc_asciiCnt][16] =
{
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*" ",0*/
{0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,0x08,0x08,0x00,0x00},/*"!",1*/
{0x00,0x48,0x24,0x24,0x12,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*""",2*/
{0x00,0x00,0x00,0x48,0x48,0x48,0x7E,0x24,0x24,0x24,0x7E,0x24,0x24,0x24,0x00,0x00},/*"#",3*/
{0x00,0x00,0x10,0x3C,0x52,0x52,0x12,0x1C,0x30,0x50,0x50,0x52,0x52,0x3C,0x10,0x10},/*"$",4*/
{0x00,0x00,0x00,0x22,0x25,0x15,0x15,0x0D,0x2A,0x58,0x54,0x54,0x52,0x22,0x00,0x00},/*"%",5*/
{0x00,0x00,0x00,0x0C,0x12,0x12,0x12,0x0A,0x76,0x25,0x29,0x19,0x91,0x6E,0x00,0x00},/*"&",6*/
{0x00,0x06,0x04,0x04,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"'",7*/
{0x00,0x40,0x20,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x10,0x10,0x20,0x40,0x00},/*"(",8*/
{0x00,0x02,0x04,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x08,0x08,0x04,0x02,0x00},/*")",9*/
{0x00,0x00,0x00,0x00,0x08,0x08,0x6B,0x1C,0x1C,0x6B,0x08,0x08,0x00,0x00,0x00,0x00},/*"*",10*/
{0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x10,0xFE,0x10,0x10,0x10,0x00,0x00,0x00,0x00},/*"+",11*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x04,0x04,0x02},/*",",12*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"-",13*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x06,0x00,0x00},/*".",14*/
{0x00,0x00,0x40,0x20,0x20,0x20,0x10,0x10,0x08,0x08,0x08,0x04,0x04,0x02,0x02,0x00},/*"/",15*/
{0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00},/*"0",16*/
{0x00,0x00,0x00,0x10,0x1C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00},/*"1",17*/
{0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x40,0x20,0x10,0x08,0x04,0x42,0x7E,0x00,0x00},/*"2",18*/
{0x00,0x00,0x00,0x3C,0x42,0x42,0x40,0x20,0x18,0x20,0x40,0x42,0x42,0x3C,0x00,0x00},/*"3",19*/
{0x00,0x00,0x00,0x20,0x30,0x30,0x28,0x24,0x24,0x22,0xFE,0x20,0x20,0xF8,0x00,0x00},/*"4",20*/
{0x00,0x00,0x00,0x7E,0x02,0x02,0x02,0x1E,0x22,0x40,0x40,0x42,0x22,0x1C,0x00,0x00},/*"5",21*/
{0x00,0x00,0x00,0x18,0x24,0x02,0x02,0x3A,0x46,0x42,0x42,0x42,0x44,0x38,0x00,0x00},/*"6",22*/
{0x00,0x00,0x00,0x7E,0x42,0x20,0x20,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x00,0x00},/*"7",23*/
{0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x24,0x18,0x24,0x42,0x42,0x42,0x3C,0x00,0x00},/*"8",24*/
{0x00,0x00,0x00,0x1C,0x22,0x42,0x42,0x42,0x62,0x5C,0x40,0x40,0x24,0x18,0x00,0x00},/*"9",25*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00},/*":",26*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x08},/*";",27*/
{0x00,0x00,0x00,0x40,0x20,0x10,0x08,0x04,0x02,0x04,0x08,0x10,0x20,0x40,0x00,0x00},/*"<",28*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00,0x00,0x00,0x00,0x00},/*"=",29*/
{0x00,0x00,0x00,0x02,0x04,0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x04,0x02,0x00,0x00},/*">",30*/
{0x00,0x00,0x00,0x3C,0x42,0x42,0x46,0x20,0x10,0x10,0x10,0x00,0x18,0x18,0x00,0x00},/*"?",31*/
{0x00,0x00,0x00,0x1C,0x22,0x5A,0x55,0x55,0x55,0x55,0x55,0x3A,0x42,0x3C,0x00,0x00},/*"@",32*/
{0x00,0x00,0x00,0x08,0x08,0x18,0x14,0x14,0x24,0x3C,0x22,0x42,0x42,0xE7,0x00,0x00},/*"A",33*/
{0x00,0x00,0x00,0x1F,0x22,0x22,0x22,0x1E,0x22,0x42,0x42,0x42,0x22,0x1F,0x00,0x00},/*"B",34*/
{0x00,0x00,0x00,0x7C,0x42,0x42,0x01,0x01,0x01,0x01,0x01,0x42,0x22,0x1C,0x00,0x00},/*"C",35*/
{0x00,0x00,0x00,0x1F,0x22,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x22,0x1F,0x00,0x00},/*"D",36*/
{0x00,0x00,0x00,0x3F,0x42,0x12,0x12,0x1E,0x12,0x12,0x02,0x42,0x42,0x3F,0x00,0x00},/*"E",37*/
{0x00,0x00,0x00,0x3F,0x42,0x12,0x12,0x1E,0x12,0x12,0x02,0x02,0x02,0x07,0x00,0x00},/*"F",38*/
{0x00,0x00,0x00,0x3C,0x22,0x22,0x01,0x01,0x01,0x71,0x21,0x22,0x22,0x1C,0x00,0x00},/*"G",39*/
{0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x7E,0x42,0x42,0x42,0x42,0xE7,0x00,0x00},/*"H",40*/
{0x00,0x00,0x00,0x3E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00},/*"I",41*/
{0x00,0x00,0x00,0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x11,0x0F},/*"J",42*/
{0x00,0x00,0x00,0x77,0x22,0x12,0x0A,0x0E,0x0A,0x12,0x12,0x22,0x22,0x77,0x00,0x00},/*"K",43*/
{0x00,0x00,0x00,0x07,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x42,0x7F,0x00,0x00},/*"L",44*/
{0x00,0x00,0x00,0x77,0x36,0x36,0x36,0x36,0x36,0x2A,0x2A,0x2A,0x2A,0x6B,0x00,0x00},/*"M",45*/
{0x00,0x00,0x00,0xE3,0x46,0x46,0x4A,0x4A,0x52,0x52,0x52,0x62,0x62,0x47,0x00,0x00},/*"N",46*/
{0x00,0x00,0x00,0x1C,0x22,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x22,0x1C,0x00,0x00},/*"O",47*/
{0x00,0x00,0x00,0x3F,0x42,0x42,0x42,0x42,0x3E,0x02,0x02,0x02,0x02,0x07,0x00,0x00},/*"P",48*/
{0x00,0x00,0x00,0x1C,0x22,0x41,0x41,0x41,0x41,0x41,0x41,0x4D,0x32,0x1C,0x60,0x00},/*"Q",49*/
{0x00,0x00,0x00,0x3F,0x42,0x42,0x42,0x3E,0x12,0x12,0x22,0x22,0x42,0xC7,0x00,0x00},/*"R",50*/
{0x00,0x00,0x00,0x7C,0x42,0x42,0x02,0x04,0x18,0x20,0x40,0x42,0x42,0x3E,0x00,0x00},/*"S",51*/
{0x00,0x00,0x00,0x7F,0x49,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x1C,0x00,0x00},/*"T",52*/
{0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00},/*"U",53*/
{0x00,0x00,0x00,0xE7,0x42,0x42,0x22,0x24,0x24,0x14,0x14,0x18,0x08,0x08,0x00,0x00},/*"V",54*/
{0x00,0x00,0x00,0x6B,0x2A,0x2A,0x2A,0x2A,0x2A,0x36,0x14,0x14,0x14,0x14,0x00,0x00},/*"W",55*/
{0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x18,0x18,0x18,0x24,0x24,0x42,0xE7,0x00,0x00},/*"X",56*/
{0x00,0x00,0x00,0x77,0x22,0x22,0x14,0x14,0x08,0x08,0x08,0x08,0x08,0x1C,0x00,0x00},/*"Y",57*/
{0x00,0x00,0x00,0x7E,0x21,0x20,0x10,0x10,0x08,0x04,0x04,0x42,0x42,0x3F,0x00,0x00},/*"Z",58*/
{0x00,0x78,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x78,0x00},/*"[",59*/
{0x00,0x00,0x02,0x04,0x04,0x04,0x08,0x08,0x08,0x10,0x10,0x20,0x20,0x20,0x40,0x40},/*"\",60*/
{0x00,0x1E,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1E,0x00},/*"]",61*/
{0x00,0x18,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"^",62*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF},/*"_",63*/
{0x00,0x06,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"`",64*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x22,0x30,0x2C,0x22,0x32,0x6C,0x00,0x00},/*"a",65*/
{0x00,0x00,0x00,0x00,0x03,0x02,0x02,0x1A,0x26,0x42,0x42,0x42,0x26,0x1A,0x00,0x00},/*"b",66*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x44,0x02,0x02,0x02,0x44,0x38,0x00,0x00},/*"c",67*/
{0x00,0x00,0x00,0x00,0x60,0x40,0x40,0x7C,0x42,0x42,0x42,0x42,0x62,0xDC,0x00,0x00},/*"d",68*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x42,0x7E,0x02,0x42,0x3C,0x00,0x00},/*"e",69*/
{0x00,0x00,0x00,0x00,0x30,0x48,0x08,0x3E,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00},/*"f",70*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x22,0x22,0x1C,0x02,0x3C,0x42,0x42,0x3C},/*"g",71*/
{0x00,0x00,0x00,0x00,0x03,0x02,0x02,0x3A,0x46,0x42,0x42,0x42,0x42,0xE7,0x00,0x00},/*"h",72*/
{0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x0E,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00},/*"i",73*/
{0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x38,0x20,0x20,0x20,0x20,0x20,0x20,0x22,0x1E},/*"j",74*/
{0x00,0x00,0x00,0x00,0x03,0x02,0x02,0x72,0x12,0x0A,0x0E,0x12,0x22,0x77,0x00,0x00},/*"k",75*/
{0x00,0x00,0x00,0x08,0x0E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00},/*"l",76*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x92,0x92,0x92,0x92,0x92,0xB7,0x00,0x00},/*"m",77*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3B,0x46,0x42,0x42,0x42,0x42,0xE7,0x00,0x00},/*"n",78*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00},/*"o",79*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1B,0x26,0x42,0x42,0x42,0x26,0x1A,0x02,0x07},/*"p",80*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x58,0x64,0x42,0x42,0x42,0x64,0x58,0x40,0xE0},/*"q",81*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x4C,0x04,0x04,0x04,0x04,0x1F,0x00,0x00},/*"r",82*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x42,0x02,0x3C,0x40,0x42,0x3E,0x00,0x00},/*"s",83*/
{0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x3E,0x08,0x08,0x08,0x08,0x48,0x30,0x00,0x00},/*"t",84*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0x42,0x42,0x42,0x42,0x62,0xDC,0x00,0x00},/*"u",85*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x22,0x22,0x14,0x14,0x08,0x08,0x00,0x00},/*"i",86*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xDB,0x91,0x52,0x5A,0x2A,0x24,0x24,0x00,0x00},/*"w",87*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6E,0x24,0x18,0x18,0x18,0x24,0x76,0x00,0x00},/*"x",88*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x18,0x18,0x08,0x08,0x06},/*"y",89*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x22,0x10,0x08,0x08,0x44,0x7E,0x00,0x00},/*"z",90*/
{0x00,0xC0,0x20,0x20,0x20,0x20,0x20,0x20,0x10,0x20,0x20,0x20,0x20,0x20,0xC0,0x00},/*"{",91*/
{0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10},/*"|",92*/
{0x00,0x03,0x04,0x04,0x04,0x04,0x04,0x04,0x08,0x04,0x04,0x04,0x04,0x04,0x03,0x00},/*"}",93*/
{0x04,0x5A,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"~",94*/
};/* (8 X 16 , ������ )*/


#define gnc_getFont0816(type,ch) (gnc_font0816_##type##[((uint8_t)ch) - gnc_asciiBegin])



/*
----------Bit Operation Definitions----------
*/
#define  bitRd(value, bit)   (((value) >> (bit)) & 0x01) 
#define  bitWr(value, bit, bitvalue)   (bitvalue ? bitSet(value, bit) : bitClear(value, bit)) 
#define  bitSet(value, bit)   ((value) |= (1UL << (bit))) 
#define  bitClr(value, bit)   ((value) &= ~(1UL << (bit))) 
#define  bit(b)   (1 << (b)) 











/*
----------Global Function Linker Definitions----------
*/
//#define uart_putbuff UART_WriteBlocking

#define sprintf sprintf_s




#endif // ! _INC_GNC_H_