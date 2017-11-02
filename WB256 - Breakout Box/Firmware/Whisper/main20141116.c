/*
 * File:   main20141116.c
 * Author: Brian Barbarits
 *
 * Created on November 16, 2014, 5:21 PM
 */


#include <p32xxxx.h>
#include <plib.h>


#pragma config  PMDL1WAY = OFF      //Peripheral Module Disable
#pragma config  IOL1WAY = OFF       //Peripheral Pin Select
#pragma config  FUSBIDIO = OFF      //USB USBID Selection
#pragma config  FVBUSONIO = OFF     //USB Vbuson Selection
#pragma config  FPLLIDIV = DIV_2    //PLL Input Divider
#pragma config  FPLLMUL = MUL_24    //PLL Multiplier
#pragma config  UPLLIDIV = DIV_4    //USB PLL Input Divider
#pragma config  UPLLEN = OFF        //USB PLL Enable
#pragma config  FPLLODIV = DIV_256  //System PLL Output Clock Divider
#pragma config  FNOSC = PRI         //Oscillator //PRI primary//PRIPLL pri w/osc
#pragma config  FSOSCEN = OFF       //Secondary Oscillator Enable
#pragma config  IESO = OFF          //Internal/External Switch over
#pragma config  POSCMOD = EC        //Primary Oscillator
#pragma config  OSCIOFNC = OFF      //CLK0 enable
#pragma config  FPBDIV = DIV_1      //Peripheral Clock divisor
#pragma config  FCKSM = CSDCMD      //Clock Switching and Monitor Selection
#pragma config  WDTPS = PS1         //Watchdog Timer Postscaler
#pragma config  WINDIS = OFF        //Watchdog Timer Window Enable
#pragma config  FWDTEN = OFF        //Watchdog Timer Enable
#pragma config  FWDTWINSZ = WINSZ_50//Watchdog Timer Window Size
#pragma config  JTAGEN = OFF        //JTAG Enable
#pragma config  ICESEL = ICS_PGx1   //ICE/ICD Comm - ICS_PGx3 = PGEC3/PGED3
#pragma config  PWP = OFF           //Program Flash Write Protect
#pragma config  BWP = OFF           //Boot Flash Write Protect
#pragma config  CP = OFF            //Code Protect

//Input/Output Line Setup
//RB10 - P0.0_UC - from SpikeGL (NI card) which starts the multiplexer system
//RB11 - TRIGGER - clock sent to the NI card to make an acquisition
//RPC4 - RESET - used to reset the Intan chip to ch0
//RPC5 - STEP - used to advance the Intan chip to the next channel

void main(void)
{
    //I/O Setup  ///////////////////////////////////////////////////////////////
    TRISBbits.TRISB10 = 1;     //Configure RB10 digital input
    TRISBbits.TRISB11 = 0;     //Configure RB11 digital output
    LATB = 0x00;            //Clear latches on PortB
    ANSELB = 0x00;          //Configure B I/O for digital

    TRISC = 0x00;           //Configure RPC5 & RCP4 as digital output
    LATC = 0x00;            //Clear latches on PortC
    ANSELC = 0x00;          //Configure C I/O for digital
    ////////////////////////////////////////////////////////////////////////////

    //Initiailize  /////////////////////////////////////////////////////////////
    PORTBbits.RB11 = 0;         //RB11 = TRIGGER = 0
    PORTCbits.RC5 = 0;     	//RC4 = STEP = 0
    PORTCbits.RC4 = 1;		//RC5 = RESET = 1
    ////////////////////////////////////////////////////////////////////////////
    while(1)
    {
        intloop:
        if(PORTBbits.RB10 == 0)
        {
            PORTBbits.RB11 = 0;     //RB11 = TRIGGER = 0
            PORTCbits.RC5 = 0;      //RC4 = STEP = 0
            PORTCbits.RC4 = 1;      //RC5 = RESET = 1
            goto intloop;
        }

        else
        {
//FIX 1 - correct delay --> //Delay10KTCYx(255) @ 48Mhz clk = 213 ms for each delay last time
            delay_n_x_m_clk_cyc(1000,1000);      //Delay10KTCYx(255) @ 48Mhz clk = 213 ms
            PORTCbits.RC4 = 0;          //RC5 = RESET = 0
            delay_n_x_m_clk_cyc(1000,1000);      //Delay10KTCYx(255) @ 48Mhz clk = 213 ms
//FIX 1 - correct delay --> //Delay10KTCYx(255) @ 48Mhz clk = 213 ms for each delay last time
        }

        while(1)
	{
        //ch0  /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 0;		//RC4 = RESET = 0
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch1  /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch2  /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch3  /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch4  /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch5  /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch6  /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch7  /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch8  /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch9  /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch10 /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch11  ////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch12  ////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch13  /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch14  ////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch15  ////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch16  /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch17  ////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch18 /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch19 /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch20 /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch21  ////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch22 /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch23 /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch24 /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch25  ////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch26 /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch27  /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch28 /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch29  /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch30  /////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();Nop();Nop();
        ////////////////////////////////////////////////////////////////////////

        //ch31  ////////////////////////////////////////////////////////////////
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();
            PORTCbits.RC5 = 0;     	//RC5 = STEP = 0
            Nop();
            PORTBbits.RB11 = 0;	    	//RB11 = TRIGGER = 0
            if(PORTBbits.RB10 == 0)     //RB10 - P0.0_UC
            {
                goto intloop;
            }
            PORTBbits.RB11 = 1;	    	//RB11 = TRIGGER = 1
            Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
            Nop();Nop();Nop();Nop();Nop();Nop();
            PORTCbits.RC4 = 1;		//RC4 = RESET = 1
            Nop();Nop();
            PORTCbits.RC5 = 1;     	//RC5 = STEP = 1
            Nop();Nop();                //While loop return is x2 Nop()

        ////////////////////////////////////////////////////////////////////////

        }

    }
}

void delay_n_x_m_clk_cyc(unsigned int n, unsigned int m)
{
    int i = 0;
    int j = 0;
    for (i=0;i < m;i++)
    {
        for(j=0;j < n;j++)
        {
            Nop();
        }
    }

}






