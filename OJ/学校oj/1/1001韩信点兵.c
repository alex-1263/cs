#include<stdio.h>
int main() {
    int a,b,c;
    int i;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF) 
	{
        a%=3;
        b%=5;
        c%=7;
		for(i=10; i<=100; i++) {
            if(i%3==a&&i%5==b&&i%7==c)
            break;
        }
        if(i<=100)
        printf("%d\n",i);
        else
        printf("No answer\n");
    }
    return 0;
}
