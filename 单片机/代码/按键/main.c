#include <reg51.h>

unsigned char code ledchar[] = 
{
    0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90 
};

sbit s1 = P3^0;
sbit s2 = P3^1;
sbit button = P1^0;

void delay(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 456; j++);
}

void main()
{
    int count = 0;
    while (1) {
        if (button == 0) {  // check if button is pressed
            count++;
            while (button == 0);  // wait for button release
        }
        
        // display count on LED
        s1 = 1;
        s2 = 0;
        P2 = ledchar[count / 10];
        delay(30);
        s1 = 0; 
        s2 = 1;
        P2 = ledchar[count % 10];
        delay(30);
    }
}	