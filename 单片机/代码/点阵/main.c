#include<reg51.h>
#include<intrins.h>
int b[8]={0x00,0x66,0x99,0x81,0x81,0x42,0x24,0x18};
void delay(unsigned char i) //延时函数
{	
    unsigned char j,k;	
    for(j=i;j>0;j--)		
        for(k=110;k>0;k--);	
}    
void main()//主函数	
{     
unsigned char i,j,k,temp;//变量定义	
while(1)	
    { 		
    for(j=0;j<8;j++) //循环次数		
        {			
        for(k=0;k<100;k++)//控制滚动速度，数字越小，滚动越快
            {	
            temp=0x01;	    		
            for (i = 0; i < 8; i++)				
                {					
P2 =temp;					 
 P3 =~b[(i+j)%8];//滚动实现的关键，（%8）除以8求余数	
temp=_crol_(temp,1);//左移动函数	    		            
                     delay(2);	  			
                 } 							    
            }
        }
}
}
