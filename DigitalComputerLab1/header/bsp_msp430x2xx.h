#ifndef _bsp_H_
#define _bsp_H_

#include  <msp430g2553.h>          // MSP430x2xx

#define   debounceVal      250
#define   LEDs_SHOW_RATE  500 //  0x80000  // 62_5ms
#define TPwm 20



// LEDs abstraction
#define LEDsArrPort        P1OUT   //Evalution Kit
#define LEDsArrPortDir     P1DIR
#define LEDsArrPortSel     P1SEL

// Switches abstraction
#define SWsArrPort         P2IN
#define SWsArrPortDir      P2DIR
#define SWsArrPortSel      P2SEL
#define SWmask             0x0F

// PushButtons abstraction
#define PBsArrPort     P2IN
#define PwmOutPort      P2OUT
#define PBsArrIntPend      P2IFG
#define PBsArrIntEn    P2IE
#define PBsArrIntEdgeSel   P2IES
#define PBsArrPortSel      P2SEL
#define PBsArrPortDir      P2DIR
#define PB0                0x01
#define PB1                0x02
#define PB2                0x04
#define PB3                0x08



#define delay_0 3
#define delay_1 16
extern void GPIOconfig(void);
extern void TIMERconfig(void);
extern void ADCconfig(void);

#endif



