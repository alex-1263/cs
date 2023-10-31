#include <reg52.h>
unsigned char seg7code[]={
	   0xc0, 0xf9, 0xa4, 0xb0, 
	   0x99, 0x92, 0x82, 0xf8, 
	   0x80, 0x90, 0x88, 0x83,
	   0xc6, 0xa1, 0x86, 0x8e};
void delay(int x)
{
 char i;
 while(x--)
 {
 for(i=120;i>0;i--);
}
}
void display(unsigned char num)
{
  P1=~0x01; 
 P3=seg7code[num];

} 
void keyscan()
{
 unsigned char temp,key;//diyihang??
 P2=0xfe;
 temp=P2;	
 temp=temp&0xf0;
 if(temp!=0xf0)
 {
  delay(10);
  temp=P2;
  temp=temp&0xf0;
  if(temp!=0xf0)
  {
   temp=P2;
   switch(temp)
   {
    case 0xee:
     key=0;
     break;
    case 0xde:
     key=1;
     break;
    case 0xbe:
     key=2;
     break;
    case 0x7e:
     key=3;
     break;
   }
   while(temp!=0xf0)
   {
    temp=P2;
    temp=temp&0xf0;
   }
   display(key);
  }
 }
  //di2hang??
 P2=0xfd;
 temp=P2;
 temp=temp&0xf0;
 if(temp!=0xf0)
 {
  delay(10);
  temp=P2;
  temp=temp&0xf0;
  if(temp!=0xf0)
  {
   temp=P2;
   switch(temp)
   {
    case 0xed:
     key=4;
     break;
    case 0xdd:
     key=5;
     break;
    case 0xbd:
     key=6;
     break;
    case 0x7d:
     key=7;
     break;
   }
   while(temp!=0xf0)
   {
    temp=P2;
    temp=temp&0xf0;
   }
   display(key);
  }
 }
//di3hang??
 P2=0xfb;
 temp=P2;
 temp=temp&0xf0;
 if(temp!=0xf0)
 {
  delay(10);
  temp=P2;
  temp=temp&0xf0;
  if(temp!=0xf0)
  {
   temp=P2;
   switch(temp)
   {
    case 0xeb:
     key=8;
     break;
    case 0xdb:
     key=9;
     break;
    case 0xbb:
     key=10;
     break;
    case 0x7b:
     key=11;
     break;
   }
   while(temp!=0xf0)
   {
    temp=P2;
    temp=temp&0xf0;
   }
   display(key);
  }
 }
//di4hang??
 P2=0xf7;
 temp=P2;
 temp=temp&0xf0;
 if(temp!=0xf0)
 {
  delay(10);
  temp=P2;
  temp=temp&0xf0;
  if(temp!=0xf0)
  {
   temp=P2;
   switch(temp)
   {
    case 0xe7:
     key=12;
     break;
    case 0xd7:
     key=13;
     break;
    case 0xb7:
     key=14;
     break;
    case 0x77:
     key=15;
     break;
   }
   						   while(temp!=0xf0)
   {
    temp=P2;
    temp=temp&0xf0;
   }
   display(key);
  }
 }
}
void main()
{
 P3=0;
 while(1)
 {
  keyscan();
 }
}