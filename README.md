<h1 align="center">C51单片机笔记</h1>

### 【Time】: 2018-06-15

### 延时函数与读取一个按键的函数

```c
#include <reg51.h>
sbit P10 = P1^0;

/*-----------------------------------------------------
*@Name: delay
*@Function: 实现软件延时,延时itime秒
*@Time: 2018-06-15
------------------------------------------------------*/
void delay(int itime)
{
    int i,j;
    for(i = 0; i < itime; i++)
    {
        j = 1000;   //1ms
        while(j-- < 0);
    }
}
/*----------------------------------------------------
*@Name: readKey
*@Function: 读取P10口的状态，为1时返回1.
*@Time: 2018-06-15
----------------------------------------------------*/
int readKey()
{
    if(P10 == 0)
    {
        delay(20);
        if(0 == P10)
        {
            while(0 == P10);
            return 1;
        }
    }
    return 0;
}
```

### 添加串口通信程序uart.c
@【Time】: 2018-06-26  
@【address】:[uart.c](https://github.com/54fire/C51/blob/master/uart.c)
