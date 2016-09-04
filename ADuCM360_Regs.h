/*****

This header file includes some registers of ADuCM360 related to GPIO_Ex1_Blink.
Some registers mean the followings :
		1. Watchdog timer MMRs.
		2. Clocking MMRs.
		3. GPIO MMRs.

2013, 10, 12, Developed by Lim Jong Su(Fermi Lim)

*****/

#include <stdint.h>

#if FermiEmulation_Mode

// Watchdog Timer Memory Mapped Registers(MMRs) : Base Address : 0x4000_2580
//											Address Offset		Description								Access Type		Default(Reset Value)
extern uint16_t T3LD,	*pT3LD;			//		0x0000,			Load value.									RW,			0x1000
extern uint16_t T3VAL,	*pT3VAL;		//		0x0004,			Current count value, read only.				R			0x1000
extern uint16_t T3CON,	*pT3CON;		//		0x0008,			Control Register.							RW			0x00E9
extern uint16_t T3CLRI, *pT3CLRI;		//		0x000C			Clear Register.								W			N/A
extern uint16_t T3STA,	*pT3STA;		//		0x0018			Status Register.							R			0x0000

// Clocking Memory Mapped Registers(MMRs) : Base Address : 0x4000_2000
//											Address Offset		Description								Access Type		Default(Reset Value)
extern uint16_t CLKCON0,	*pCLKCON0;	//		0x0000,			System Clocks Control Reg. #0.				RW,			0x0004
extern uint16_t CLKCON1,	*pCLKCON1;  //		0x0004,			System Clocks Control Reg. #1.				RW,			0x0000
extern uint16_t CLKDIS,		*pCLKDIS;	//		0x002C,			System clock to peripherals enable/disable.	RW			0x01FF
extern uint16_t XOSCCON,	*pXOSCCON;	//		0x0410			Crystal oscillator control register.		RW			0x0000
extern uint16_t CLKSYSDIV,	*pCLKSYSDIV;//		0x0444			System clock divide-by-2 control register.	RW			0x0001

// GPIO Memory Mapped Registers(MMRs) : Base Address : 0x4000_6000
//											Address Offset		Description								Access Type		Default(Reset Value)
extern uint16_t GP0CON,	*pGP0CON;		//		0x0000,			GPIO Port 0 configuration.					RW,			0x0000
extern uint8_t GP0OEN,	*pGP0OEN;		//		0x0004,			GPIO Port 0 output enable.					RW,			0x00
extern uint8_t GP0PUL,	*pGP0PUL;		//		0x0008,			GPIO Port 0 output pull-up enable.			RW			0xFF
extern uint8_t GP0OCE,	*pGP0OCE;		//		0x000C			GPIO Port 0 open-circuit enable.			RW			0x00
extern uint8_t GP0IN,	*pGP0IN;		//		0x0014			GPIO Port 0 data input.						R			N/A
extern uint8_t GP0OUT,	*pGP0OUT;		//		0x0018			GPIO Port 0 data output.					RW			0x00
extern uint8_t GP0SET,	*pGP0SET;		//		0x001C			GPIO Port 0 data out set.					W			0x00
extern uint8_t GP0CLR,	*pGP0CLR;		//		0x0020			GPIO Port 0 data out clear.					W			0x00
extern uint8_t GP0TGL,	*pGP0TGL;		//		0x0024			GPIO Port 0 data out toggle.				W			0x00

extern uint16_t GP1CON,	*pGP1CON;		//		0x0030,			GPIO Port 1 configuration.					RW,			0x0000
extern uint8_t GP1OEN,	*pGP1OEN;		//		0x0034,			GPIO Port 1 output enable.					RW,			0x00
extern uint8_t GP1PUL,	*pGP1PUL;		//		0x0038,			GPIO Port 1 output pull-up enable.			RW			0xFF
extern uint8_t GP1OCE,	*pGP1OCE;		//		0x003C			GPIO Port 1 open-circuit enable.			RW			0x00
extern uint8_t GP1IN,	*pGP1IN;		//		0x0044			GPIO Port 1 data input.						R			N/A
extern uint8_t GP1OUT,	*pGP1OUT;		//		0x0048			GPIO Port 1 data output.					RW			0x00
extern uint8_t GP1SET,	*pGP1SET;		//		0x004C			GPIO Port 1 data out set.					W			0x00
extern uint8_t GP1CLR,	*pGP1CLR;		//		0x0050			GPIO Port 1 data out clear.					W			0x00
extern uint8_t GP1TGL,	*pGP1TGL;		//		0x0054			GPIO Port 1 data out toggle.				W			0x00

extern uint16_t GP2CON,	*pGP2CON;		//		0x0060,			GPIO Port 2 configuration.					RW,			0x0000
extern uint8_t GP2OEN,	*pGP2OEN;		//		0x0064,			GPIO Port 2 output enable.					RW,			0x00
extern uint8_t GP2PUL,	*pGP2PUL;		//		0x0068,			GPIO Port 2 output pull-up enable.			RW			0xFF
extern uint8_t GP2OCE,	*pGP2OCE;		//		0x006C			GPIO Port 2 open-circuit enable.			RW			0x00
extern uint8_t GP2IN,	*pGP2IN;		//		0x0074			GPIO Port 2 data input.						R			N/A
extern uint8_t GP2OUT,	*pGP2OUT;		//		0x0078			GPIO Port 2 data output.					RW			0x00
extern uint8_t GP2SET,	*pGP2SET;		//		0x007C			GPIO Port 2 data out set.					W			0x00
extern uint8_t GP2CLR,	*pGP2CLR;		//		0x0080			GPIO Port 2 data out clear.					W			0x00
extern uint8_t GP2TGL,	*pGP2TGL;		//		0x0084			GPIO Port 2 data out toggle.				W			0x00

// UART Memory Mapped Registers(MMRs) : Base Address : 0x4000_5000
//																			Address Offset		Description														Access Type		Default(Reset Value)
  
extern uint8_t COMTX_RX, *pCOMTX_RX; //    0x0000        Transmit/Receive Holding register          W/R			0x0000	
extern uint8_t COMIEN, *pCOMIEN;     //    0x0004        Interrupt Enable register                  RW          0x0000
extern uint8_t COMIIR, *pCOMIIR;     //    0x0008        Interrupt Identification register          R           0x0000
extern uint8_t COMLCR, *pCOMLCR;     //    0x000C        Line Control register                      RW          0x0000
extern uint8_t COMMCR, *pCOMMCR;     //    0x0010        Module Control register                    RW          0x0000
extern uint8_t COMLSR, *pCOMLSR;     //    0x0014        Line Status register                       R           0x0000
extern uint8_t COMMSR, *pCOMMSR;     //    0x0018        Modem Status register                      R           0x0000
extern uint16_t COMFBR, *pCOMFBR;    //    0x0024        Fractional baud rate divider register.     RW          0x0000
extern uint16_t COMDIV, *pCOMDIV;    //    0x0028        Baud rate Divisor register                 RW          0x0000
extern uint8_t  COMCON, *pCOMCON;    //    0x0030        UART control register                      RW          0x0000
  
void ADuCM360_GPIORegsInit(void);
#else

// Watchdog Timer Memory Mapped Registers(MMRs) : Base Address : 0x4000_2580
extern volatile uint16_t *pT3LD;			
extern volatile uint16_t *pT3VAL;		
extern volatile uint16_t *pT3CON;		
extern volatile uint16_t *pT3CLRI;	
extern volatile uint16_t *pT3STA;		

// Clocking Memory Mapped Registers(MMRs) : Base Address : 0x4000_2000
extern volatile uint16_t *pCLKCON0;	
extern volatile uint16_t *pCLKCON1; 
extern volatile uint16_t *pCLKDIS;	
extern volatile uint16_t *pXOSCCON;	
extern volatile uint16_t *pCLKSYSDIV;

// GPIO Memory Mapped Registers(MMRs) : Base Address : 0x4000_6000
extern volatile uint16_t *pGP0CON;	
extern volatile uint8_t *pGP0OEN;		
extern volatile uint8_t *pGP0PUL;		
extern volatile uint8_t *pGP0OCE;		
extern volatile uint8_t *pGP0IN;		
extern volatile uint8_t *pGP0OUT;		
extern volatile uint8_t *pGP0SET;		
extern volatile uint8_t *pGP0CLR;		
extern volatile uint8_t *pGP0TGL;		

extern volatile uint16_t *pGP1CON;	
extern volatile uint8_t *pGP1OEN;		
extern volatile uint8_t *pGP1PUL;		
extern volatile uint8_t *pGP1OCE;		
extern volatile uint8_t *pGP1IN;		
extern volatile uint8_t *pGP1OUT;		
extern volatile uint8_t *pGP1SET;		
extern volatile uint8_t *pGP1CLR;		
extern volatile uint8_t *pGP1TGL;		

extern volatile uint16_t *pGP2CON;	
extern volatile uint8_t *pGP2OEN;		
extern volatile uint8_t *pGP2PUL;		
extern volatile uint8_t *pGP2OCE;		
extern volatile uint8_t *pGP2IN;		
extern volatile uint8_t *pGP2OUT;		
extern volatile uint8_t *pGP2SET;		
extern volatile uint8_t *pGP2CLR;		
extern volatile uint8_t *pGP2TGL;		

// UART Memory Mapped Registers(MMRs) : Base Address : 0x4000_5000
extern volatile uint8_t COMTX_RX, *pCOMTX_RX;
extern volatile uint8_t COMIEN, *pCOMIEN;
extern volatile uint8_t COMIIR, *pCOMIIR;
extern volatile uint8_t COMLCR, *pCOMLCR;
extern volatile uint8_t COMMCR, *pCOMMCR;
extern volatile uint8_t COMLSR, *pCOMLSR;
extern volatile uint8_t COMMSR, *pCOMMSR;
extern volatile uint16_t COMFBR, *pCOMFBR;
extern volatile uint16_t COMDIV, *pCOMDIV;
extern volatile uint8_t  COMCON, *pCOMCON;

#endif
