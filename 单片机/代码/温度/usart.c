#include "usart.h"
 
 
 
/****************************
*函数名：USART_Init
*函数功能：串口初始化 波特率9600
*输入：无
*输出：无
********************************/
void USART_Init(void)//使用定时器1作为串口波特率发生器
{
	TH1 = 0xfd;	 //晶振11.0592mhz 波特率设为9600
	TL1 = 0xfd;
	TMOD |= 0x20;	 //定时器1方式2
	SCON = 0x50;	 //设置为工作方式1，串口接收使能
	ES = 1;			 //串口中断使能
	TR1 = 1;		 //定时器1使能
	TI = 1;			 //发送中断标记位，必须设置
	EA = 1;	  	//开总中断
}
/*****************************
*函数名：UsartRecive
*函数功能：通信中断服务函数
*输入：无
*输出：无
**********************************/
//void UsartRecive(void)interrupt 4
//{
//	unsigned char recelveData;
//	recelveData=SBUF;
//	RI=0;//RI接收中断标志位，清零
//	SBUF=recelveData;
//	while(!TI);//发送中断标志位
//	TI=0;
//}
/*********************************************************************************
*函数名：Delay_ms
*函数功能：延时
*输入：xms
*输出：无
***************************/
void Delay_ms(unsigned int xms)
{
	unsigned int x, y;
	for (x = 0;x < xms; x++)
	{
		for (y = 0; y < 112; y++);
	}
}