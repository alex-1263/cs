#include <reg51.h>
unsigned char code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void show(unsigned char n);
void delay();
void main()
{
unsigned char i;
int j;
while(1)
{
for(i=20;j=100,i>0;i--)
{
while(j--)
show(i);
}
}
}
void show(unsigned char n)
{
P1=table[n%10];
P2=~0x02;
delay();
P2=0;
P1=table[n/10];
P2=~0x01;
delay();
P2=0;
}
void delay()
{
int i=300;
while(i--);
}
