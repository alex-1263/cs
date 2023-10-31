#include<reg52.h>
#include<intrins.h>
#define LCD_DATA P2

sbit Data=P1^6;   //∂®“ÂŒ¬ ™∂»¥´∏–∆˜
sbit RS = P1^0;
sbit RW = P1^1;
sbit E = P1^2;

unsigned char line1[16]={" Hum  Tem       "};
unsigned char line2[16]={"   %     C      "};

unsigned char tab[]={'0','1','2','3','4','5','6','7','8','9'};
		
void delay(unsigned char xms)
{
    unsigned char x,y;
    for(x=xms;x>0;x--)
        for(y=110;y>0;y--);
}
void DHT11_delay_ms(unsigned int n)//—”≥Ÿ
{
   unsigned int i,j;
   for(i=n;i>0;i--)
      for(j=110;j>0;j--);
}
void Delay_DHT11_40us()		//@12.000MHz
{
	unsigned char i;

	_nop_();    //÷‹∆⁄1/12ŒªuS£¨¿˚”√nop÷ª–Ë“™0.15uS°£∂Ã‘›——” ±
	i = 12;
	while (--i);
}
void Delay_DHT11_30us()		//@12.000MHz
{
	unsigned char i;

	_nop_();
	i = 12;
	while (--i);
}

void wr_com(unsigned char comm)	
{
   E=0;
   RS=0;
   RW=0;
	 LCD_DATA=comm;
	 delay(5);
   E=1;   
   E=0;
}
void wr_data(unsigned char dat)
{
   E=0;
   RW=0;
   RS=1; 
   LCD_DATA=dat;
	 delay(5);
	 E=1;   
   E=0;
}
unsigned char rd_bf(void)
{
   unsigned char bflag;
   E=0;
   RS=0;
   RW=1;
   bflag=LCD_DATA&0x80;
	 E=1;   
   E=0;
   return(bflag);
}
void Init_1602() 
{
   wr_com(0x38);
   delay(5);
   wr_com(0x01);
   delay(5);
   wr_com(0x06);
   delay(5);
   wr_com(0x38);
   delay(5);
   wr_com(0x0c);
	 delay(5);
}
void Display_1602()
{
   unsigned char i;
   wr_com(0x80+0x05); //µ⁄“ª––œ‘ æ
   delay(5);   
	 for(i=0;i<16;i++)
	 {
			wr_data(line1[i]); 
			delay(5);
		  while(rd_bf());    
	 }
	 wr_com(0xc0+0x05); //µ⁄∂˛––œ‘ æ 
	 delay(5); 
	 for(i=0;i<16;i++)
	 {
			wr_data(line2[i]);
			delay(5);	
	 }
}

void DHT11_start()
{
   Data=1;   
   Data=0;
   DHT11_delay_ms(25);   //¿≠∏ﬂ∫Û—”≥Ÿ
   Data=1;
   Delay_DHT11_30us();    
}
unsigned char DHT11_rec_byte()      //Ω” ‹“ª∏ˆ◊÷Ω⁄
{
   unsigned char i,dat=0;
  for(i=0;i<8;i++)    
   {         
      while(Data==0);  
			Delay_DHT11_40us();
			dat=_crol_(dat,1);		 
      if(Data==1)
			{
				dat|=1;
				while(Data==1);
			}         
       
    }  
    return dat;
}
void DHT11_receive() //Ω” ’Œ¬ ™∂» ˝æ›    
{
    unsigned char R_H,R_L,T_H,T_L,RH,RL,TH,TL,revise;
    DHT11_start();
    if(Data==0)       
    {
        while(Data==0);   //µ»¥˝¿≠∏ﬂ     
        while(Data==1);		
        R_H=DHT11_rec_byte();    //Ω” ‹Œ¬∂»∏ﬂ∞ÀŒª  
        R_L=DHT11_rec_byte();    //Ω” ’Œ¬∂»µÕ∞ÀŒª  
        T_H=DHT11_rec_byte();    //Ω” ’Œ¬∂»∏ﬂ∞ÀŒª  
        T_L=DHT11_rec_byte();    //Ω” ’Œ¬∂»µÕ∞ÀŒª
        revise=DHT11_rec_byte(); //Ω” ’–£’˝Œª

        Delay_DHT11_40us();    //Ω· ¯

        if((R_H+R_L+T_H+T_L)==revise)      //–£’˝
        {
            RH=R_H;
            RL=R_L;
            TH=T_H;
            TL=T_L;
        }// ˝æ›¥¶¿Ì∑Ω±„œ‘ æ
				line2[1]=tab[(RH/10)];
				line2[2]=tab[(RH%10)];
				line2[6]=tab[(TH/10)];
				line2[7]=tab[(TH%10)];
				line2[8]=0xDF;
    }
}

void main()   
{   
	Init_1602();
	Display_1602();
  DHT11_delay_ms(1000);
	while(1)   
	{   
		DHT11_receive();
		Display_1602();
	}	
}   