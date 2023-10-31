#include<iostream>
#include<cstdio>

int main(){
    int a=-2,x=0,i=0,j=0;
    for(i=0;i<5;i++,a++){
        if(a<0)
        x=-a;
        else
        x=a;
        for(j=0;j<x;j++){
            printf(" ");
        }
        x=5-(x*2);
        for(j=0;j<x;j++){
            printf("*");
        }
        printf("\n");
    }
}
