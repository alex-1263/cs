#include<reg51.h>
#include<intrins.h>
int b[8]={0x00,0x66,0x99,0x81,0x81,0x42,0x24,0x18};
void delay(unsigned char i) //��ʱ����
{	
    unsigned char j,k;	
    for(j=i;j>0;j--)		
        for(k=110;k>0;k--);	
}    
void main()//������	
{     
unsigned char i,j,k,temp;//��������	
while(1)	
    { 		
    for(j=0;j<8;j++) //ѭ������		
        {			
        for(k=0;k<100;k++)//���ƹ����ٶȣ�����ԽС������Խ��
            {	
            temp=0x01;	    		
            for (i = 0; i < 8; i++)				
                {					
P2 =temp;					 
 P3 =~b[(i+j)%8];//����ʵ�ֵĹؼ�����%8������8������	
temp=_crol_(temp,1);//���ƶ�����	    		            
                     delay(2);	  			
                 } 							    
            }
        }
}
}
