#include <reg51.h>

typedef unsigned char u8;
typedef unsigned int  u16;
u8 g_r_sbuf;

void init_uart()
{
    SCON = 0x50;
    TMOD = 0x20;
    TH1  = 0xfd;
    TL1  = 0xfd;
    EA   = 1;
    ES   = 1;
    TR   = 1;
}

void send_data(u8 data)
{
    SBUF = data;
    while(TI == 0);
    TI = 0;
}

void uart_interrupt() interrupt 4
{
    while(RI)
    {
        RI = 0;
        g_r_sbuf = SBUF;
    }
}
