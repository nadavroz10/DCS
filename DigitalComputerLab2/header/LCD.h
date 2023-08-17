#ifndef _LCD_H_
#define _LCD_H_

// #define CHECKBUSY	1  // using this define, only if we want to read from LCD
#ifdef __MSP430FG4619__
#include "bsp_msp430x4xx.h"
#else
#include "bsp_msp430x2xx.h"
#endif

#ifdef CHECKBUSY
	#define	LCD_WAIT lcd_check_busy()
#else
	#define LCD_WAIT DelayMs(5)
#endif

/*----------------------------------------------------------
  CONFIG: change values according to your port pin selection
------------------------------------------------------------*/
#define LCD_EN(a)	(!a ? (LcdCtrl&=~0X20) : (LcdCtrl|=0X20)) // P2.5 is lcd enable pin
#define LCD_EN_DIR(a)	(!a ? (LcdCtrlDir&=~0X20) : (LcdCtrlDir|=0X20)) // P2.5 pin direction

#define LCD_RS(a)	(!a ? (LcdCtrl&=~0X40) : (LcdCtrl|=0X40)) // P2.6 is lcd RS pin
#define LCD_RS_DIR(a)	(!a ? (LcdCtrlDir&=~0X40) : (LcdCtrlDir|=0X40)) // P2.6 pin direction
  
#define LCD_RW(a)	(!a ? (LcdCtrl&=~0X80) : (LcdCtrl|=0X80)) // P2.7 is lcd RW pin
#define LCD_RW_DIR(a)	(!a ? (LcdCtrlDir&=~0X80) : (LcdCtrlDir|=0X80)) // P2.7 pin direction

#define LCD_DATA_OFFSET 0x04 //data pin selection offset for 4 bit mode, variable range is 0-4, default 0 - Px.0-3, no offset
   

/*---------------------------------------------------------
  END CONFIG
-----------------------------------------------------------*/
#define FOURBIT_MODE	0x0
#define EIGHTBIT_MODE	0x1
#define LCD_MODE        FOURBIT_MODE
   
#define OUTPUT_PIN      1	
#define INPUT_PIN       0	
#define OUTPUT_DATA     (LCD_MODE ? 0xFF : (0x0F << LCD_DATA_OFFSET))
#define INPUT_DATA      0x00	

#define LCD_STROBE_READ(value)	LCD_EN(1), \
				asm("nop"), asm("nop"), \
				value=LCD_DATA_READ, \
				LCD_EN(0) 

#define	lcd_cursor(x)		lcd_cmd(((x)&0x7F)|0x80)
#define lcd_clear()		lcd_cmd(0x01)
#define lcd_putchar(x)		lcd_data(x)
#define lcd_goto(x)		lcd_cmd(0x80+(x))
#define lcd_cursor_right()	lcd_cmd(0x14)
#define lcd_cursor_left()	lcd_cmd(0x10)
#define lcd_display_shift()	lcd_cmd(0x1C)
#define lcd_home()		lcd_cmd(0x02)
#define cursor_off              lcd_cmd(0x0C)
#define cursor_on               lcd_cmd(0x0F) 
#define lcd_function_set        lcd_cmd(0x3C) // 8bit,two lines,5x10 dots 
#define lcd_new_line            lcd_cmd(0xC0)                                  

extern void lcd_cmd(unsigned char);
extern void lcd_data(unsigned char);
extern void lcd_init();
extern void lcd_strobe();
extern void DelayMs(unsigned int);
extern void DelayUs(unsigned int);
/*
 *	Delay functions for HI-TECH C on the PIC18
 *
 *	Functions available:
 *		DelayUs(x)	Delay specified number of microseconds
 *		DelayMs(x)	Delay specified number of milliseconds
*/

#endif




