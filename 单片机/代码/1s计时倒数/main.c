#include <reg51.h>

// 定义计数器和时间变量
int i = 30, n = 60, k = 0;
unsigned char code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void delay(unsigned int t);

// 数码管显示函数
void display(unsigned char n) {

    P2=table[n%10];
	P3=~0x02;
	delay(5);
	P3=0;
	P2=table[n/10];
	P3=~0x01;
	delay(5);
	P3=0;
}

// 定时器0中断服务函数
void t0Intr(void) interrupt 1 {
    TH0 = (8192 - 5000) / 32;
    TL0 = (8192 - 5000) / 32;
    k++;
    if (k == 200 && n > 0) {
        n--;
        k = 0;
        if (i == 0) {
            i = 30;
        }
    }
}

void main() {
	int t=0,c=20,l=100;
    TMOD = 0x01; // 定时器0工作在16位自动重装模式
    TH0 = (8192 - 5000) / 32;
    TL0 = (8192 - 5000) / 32;
    EA = 1; // 允许中断
    ET0 = 1; // 允许定时器0中断
    TR0 = 1; // 启动定时器0
    for(t=20;l=100,t>0;t--){
	 while(l--)
	 display(t);
	}
}

// 延时函数
void delay(unsigned int t) {
    unsigned int i, j;
    for (i = 0; i < t; i++) {
        for (j = 0; j < 125; j++);
    }
}
