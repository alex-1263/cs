#include<reg51.h>
#include "LCD1602.h"
#include<intrins.h>
#include<stdio.h>
#include<usart.h>
#define  uchar  unsigned  char
//�������
sbit Data=P1^7;
sbit  RS=P2^0;
sbit  RW=P2^1;
sbit  E=P2^2;
unsigned char g_dht11_temperature=0;
unsigned char g_dht11_humidity=0;
unsigned char g_lcd1602_display1[16]="Temp:  C";
unsigned char g_lcd1602_display2[16]="Humi:    %";


void DHT11_delay_us(unsigned char n)//us������ʱ
{
            while(--n);
}
void DHT11_delay_ms(unsigned int z)//ms������ʱ
{
 unsigned int i,j;
for(i=z;i>0;i--)
for(j=110;j>0;j--);
}

  //���æ����
void  fbusy()
{
P2=0Xff;RS=0;RW=1;
E=0; E=1;
while (P2&0x80){E=0;E=1;}      //æ,�ȴ�
}

 //д�����
void  wc51r(uchar  j)
{
fbusy();
E=0;RS=0;RW=0;
E=1;P2=j;E=0;
}
//д���ݺ���
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
wc51r(0x38);       //ʹ��8λ����,��ʾ����,ʹ��5��7������
wc51r(0x0c);      //��ʾ����,����,�ַ�����˸
wc51r(0x06);      //�ַ�����,����Զ�����һ��
wc51r(0x01);      //����
}


void DHT11_start(void)
{
   Data=1;
   DHT11_delay_us(2);
   Data=0;
   DHT11_delay_ms(20);   //��ʱ18ms����
   Data=1;
   DHT11_delay_us(30);
}

unsigned char DHT11_rec_byte()  //����һ���ֽ�
{
   unsigned char i,dat=0;
  for(i=0;i<8;i++)   //�Ӹߵ������ν���8λ����
   {          
      while(!Data);   //�ȴ�50us�͵�ƽ��ȥ
      DHT11_delay_us(40);  //��ʱ40us�������Ϊ��������Ϊ1������Ϊ0   
      dat<<=1;   //��λʹ��ȷ����8λ���ݣ�����Ϊ0ʱֱ����λ
      if(Data==1)   //����Ϊ1ʱ��ʹdat��1����������1
         dat+=1;
      while(Data);  //�ȴ�����������    
    }  
    return dat;
}

void DHT11_receive(void)      //����40λ������
{
     unsigned char R_H,R_L,T_H,T_L,revise;
    DHT11_start();
     if(Data==0)
    {
        while(Data==0);   //�ȴ�����     
        DHT11_delay_us(80);  //����������80us��
        R_H=DHT11_rec_byte();    //����ʪ�ȸ߰�λ  
        R_L=DHT11_rec_byte();    //����ʪ�ȵͰ�λ  
        T_H=DHT11_rec_byte();    //�����¶ȸ߰�λ  
        T_L=DHT11_rec_byte();    //�����¶ȵͰ�λ
        revise=DHT11_rec_byte(); //����У��λ
        DHT11_delay_us(50);    //��������50us�������������������������״̬
        g_dht11_temperature=T_H;
        g_dht11_humidity=R_H;
     }
}

void LCD1602_Display(void)//lcd��ʾ
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
