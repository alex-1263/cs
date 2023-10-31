#include<reg51.h>
#include "LCD1602.h"
#include<intrins.h>
#include<stdio.h>
#include<usart.h>
#define  uchar  unsigned  char
//定义变量
sbit Data=P1^7;
sbit  RS=P2^0;
sbit  RW=P2^1;
sbit  E=P2^2;
unsigned char g_dht11_temperature=0;
unsigned char g_dht11_humidity=0;
unsigned char g_lcd1602_display1[16]="Temp:  C";
unsigned char g_lcd1602_display2[16]="Humi:    %";


void DHT11_delay_us(unsigned char n)//us级别延时
{
            while(--n);
}
void DHT11_delay_ms(unsigned int z)//ms级别延时
{
 unsigned int i,j;
for(i=z;i>0;i--)
for(j=110;j>0;j--);
}

  //检查忙函数
void  fbusy()
{
P2=0Xff;RS=0;RW=1;
E=0; E=1;
while (P2&0x80){E=0;E=1;}      //忙,等待
}

 //写命令函数
void  wc51r(uchar  j)
{
fbusy();
E=0;RS=0;RW=0;
E=1;P2=j;E=0;
}
//写数据函数
void  wc51ddr(uchar  j)
{
fbusy();
E=0;RS=1;RW=0;
E=1;P2=j;E=0;
}

void  lcd1602wstr(uchar hang,uchar lie,uchar length,uchar *str)
{
uchar i;
wc51r(0x80+0x40*hang+lie);
for (i=0;i<length;i++)
{wc51ddr(*str);str++;}
}

void  LCDinit()
{
wc51r(0x38);       //使用8位数据,显示两行,使用5×7的字型
wc51r(0x0c);      //显示器开,光标关,字符不闪烁
wc51r(0x06);      //字符不动,光标自动右移一格
wc51r(0x01);      //清屏
}


void DHT11_start(void)
{
   Data=1;
   DHT11_delay_us(2);
   Data=0;
   DHT11_delay_ms(20);   //延时18ms以上
   Data=1;
   DHT11_delay_us(30);
}

unsigned char DHT11_rec_byte()  //接收一个字节
{
   unsigned char i,dat=0;
  for(i=0;i<8;i++)   //从高到低依次接收8位数据
   {          
      while(!Data);   //等待50us低电平过去
      DHT11_delay_us(40);  //延时40us，如果还为高则数据为1，否则为0   
      dat<<=1;   //移位使正确接收8位数据，数据为0时直接移位
      if(Data==1)   //数据为1时，使dat加1来接收数据1
         dat+=1;
      while(Data);  //等待数据线拉低    
    }  
    return dat;
}

void DHT11_receive(void)      //接收40位的数据
{
     unsigned char R_H,R_L,T_H,T_L,revise;
    DHT11_start();
     if(Data==0)
    {
        while(Data==0);   //等待拉高     
        DHT11_delay_us(80);  //把总线拉高80us，
        R_H=DHT11_rec_byte();    //接收湿度高八位  
        R_L=DHT11_rec_byte();    //接收湿度低八位  
        T_H=DHT11_rec_byte();    //接收温度高八位  
        T_L=DHT11_rec_byte();    //接收温度低八位
        revise=DHT11_rec_byte(); //接收校正位
        DHT11_delay_us(50);    //拉低总线50us，随后总线由上拉电阻进入空闲状态
        g_dht11_temperature=T_H;
        g_dht11_humidity=R_H;
     }
}

void LCD1602_Display(void)//lcd显示
{
unsigned char i;
wc51r(0x80);
for(i=0;i<16;i++)
{
  wc51ddr(g_lcd1602_display1[i]);
}
wc51r(0x80+0x40);
for(i=0;i<16;i++)
{
   wc51ddr(g_lcd1602_display2[i]);
}
}




void main(void)
{

LCDinit();

while(1)
{ 
DHT11_receive();
g_lcd1602_display1[6]=g_dht11_temperature/10+'0';
g_lcd1602_display1[7]=g_dht11_temperature%10+'0';
g_lcd1602_display2[6]=g_dht11_humidity/10+'0';
g_lcd1602_display2[7]=g_dht11_humidity%10+'0';
LCD1602_Display();
DHT11_delay_ms(10);
}
}
