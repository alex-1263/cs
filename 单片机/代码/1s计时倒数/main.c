#include <reg51.h>

// �����������ʱ�����
int i = 30, n = 60, k = 0;
unsigned char code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void delay(unsigned int t);

// �������ʾ����
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

// ��ʱ��0�жϷ�����
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
    TMOD = 0x01; // ��ʱ��0������16λ�Զ���װģʽ
    TH0 = (8192 - 5000) / 32;
    TL0 = (8192 - 5000) / 32;
    EA = 1; // �����ж�
    ET0 = 1; // ����ʱ��0�ж�
    TR0 = 1; // ������ʱ��0
    for(t=20;l=100,t>0;t--){
	 while(l--)
	 display(t);
	}
}

// ��ʱ����
void delay(unsigned int t) {
    unsigned int i, j;
    for (i = 0; i < t; i++) {
        for (j = 0; j < 125; j++);
    }
}
