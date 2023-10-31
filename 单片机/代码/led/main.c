#include<reg51.h>
void delay(void)
{
	unsigned int i;
	for(i=0;i<20000;i++);
}

int main(void)
{
 	unsigned char led,a,b;
	led =0xfe;
	while(1)
	{
	 	P0=led;
		a=led>>7;
		b=led<<1;
		led=b|a;
		delay();
	}
}