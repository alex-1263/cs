#include <reg52.h>

const unsigned char ledchar[] = {      
    0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90  
}; 

void delay(int ms){         
    int i,j;
    for(i=ms; i>0; i--)
        for(j=110; j>0; j--);
}

void main(){     
    int i;
    P2 = 0;      
    for(i = sizeof(ledchar) / sizeof(ledchar[0]) - 1;  i >= 0;  i--){
        P2 = ledchar[i];         
        delay(400);      
    } 
}
