#include "LCD1602.h"
 
/***************************************************************************
*函数名：Lcd1602_Delay1ms
*函数功能：延时函数，延时1ms
*输入：x
*输出：无
**********************************/
void Lcd1602_Delay1ms(uint x) {
	uchar i, j;
	for (i = x; i > 0; i--)
		for (j = 110; j > 0; j--);
}
/*************************************************************************************
*函数名：Lcd1602WriteCom
*函数功能：向LCD写入一个字节的命令
*输入：com
*输出：无
************************************/
#ifndef  LCD1602_4PINS//当没有定义这个LCD1602_PINS时
void LcdWriteCom(uchar com) {
	LCD1602_E = 0; //使能
	LCD1602_RS = 0; //选择发送命令
	LCD1602_RW = 0; //选择写入
 
	LCD1602_DATAPINS = com; //放入命令
	Lcd1602_Delay1ms(1);//保持时间,等待数据稳定
 
	LCD1602_E = 1; //写入时序
	Lcd1602_Delay1ms(5);//保持时间
	LCD1602_E = 0;
}
#else
 
void LcdWriteCom(uchar com) { //写入命令
	LCD1602_E = 0; //使能清零
	LCD1602_RS = 0; //选择发送命令
	LCD1602_RW = 0; //选择写入
 
	LCD1602_DATAPINS = com; //由于4位的接线是接到P1口的高四位，所以传输高四位不用改
	Lcd1602_Delay1ms(1);//保持时间
 
	Lcd1602_E = 1; //写入时序
	Lcd1602_Delay1ms(5);//保持时间
	LCD1602_E = 0;
 
	LCD1602_DATAPINS = com << 4; //发送低四位
	Lcd1602_Delay1ms(1);
 
	LCD1602_E = 1; //写入时序
	Lcd1602_Delay1ms(5);
	LCD1602_E = 0;
 
}
#endif
/***********************************************************************
*函数名：Lcd1602WriteData
*函数功能：向LCD写入一个字节的数据
*输入：dat
*输出：无
**************************/
#ifndef LCD1602_4PINS
 
void LcdWriteData(uchar dat) {
	LCD1602_E = 0; //使能清零
	LCD1602_RS = 1; //选择输入数据
	LCD1602_RW = 0; //选择写入
 
	LCD1602_DATAPINS = dat; //写入数据
	Lcd1602_Delay1ms(1);
 
	LCD1602_E = 1; //写入时序
	Lcd1602_Delay1ms(5);//保持时间，稳定数据
	LCD1602_E = 0;
}
#else
 
void LcdWriteData(uchar dat) {
	LCD1602_E = 0; //使能清零
	LCD1620_RS = 1; //选择输入数据
	LCD1602_RW = 0; //选择写入
 
	LCD1602_DATAPINS = dat; //由于4位的接线是接到P1口的高四位，所以传输高四位不用改
	Lcd1602_Delay1ms(1);
 
	LCD1602_E = 1; //写入时序
	Lcd1602_Delay1ms(5);//保持时间，稳定数据
	LCD1602_E = 0;
 
	LCD1602_DATAPINS = dat << 4; //写入低四位
	Lcd1602_Delay1ms(1);
 
	LCD1602_E = 1; //写入时序
	Lcd1602_Delay1ms(5);
	LCD1602_E = 0;
}
#endif
/*********************************************************************************
*函数名：LcdInit
*函数功能：初始化lcd屏
*输入函数：无
*输出函数：无
**************************/
#ifndef LCD1602_4PINS
 
void LcdInit() { //LCD初始化子程序
	LcdWriteCom(0x38);//开显示
	LcdWriteCom(0x0c);//开显示不开光标
	LcdWriteCom(0x06);//写一个指针加一
	LcdWriteCom(0x01);//清屏
	LcdWriteCom(0x80);//设置数据指针起点
}
#else
 
void LcdInit() {
	LcdWriteCom(0x32);//将八位总线转为四位总线
	LcdWriteCom(0x28);//在四位总线下的初始化
	LcdWriteCom(0x0c);//开显示不开光标
	LcdWriteCom(0x06);//写一个指针加一
	LcdWriteCom(0x01);//清屏
	LcdWriteCom(0x80);//设置数据指针起点
}

————————————