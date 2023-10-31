#include <reg51.h>

unsigned char LED_pattern[8]={ 0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80 }; 
unsigned char LED_display[8]={ 0x00,0x66,0x99,0x81,0x81,0x42,0x24,0x18 }; 

void delay(void) {
    unsigned int i;
    for(i=0;i<10000;i++);
}

void main(void)
{ 
    unsigned int i;    
    while(1){         
        for(i=0;i<8;i++) {            
            P2=LED_pattern[i];            
            P3=~LED_display[i];           
            delay();         
        }     
    }
}
