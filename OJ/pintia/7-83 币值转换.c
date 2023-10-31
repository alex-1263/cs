#include<stdio.h>
 #include<math.h>
 int main()
 {
     int i=-1,x,y,z,m,n,h,l,a;
     char c='a';
     scanf("%d",&x);
     y=x;
     if(x==0)
    {
    	printf("a");
    }
	do
	{
 		x=x/10;
		i++;
	}
   	while(x!=0);
	do
	{
		if(i>=4)
		{
		  h=y/10000;
		  l=i-4;
    }
     if(i<4)
	 {
	
          h=y;
	      l=i;
	 }
	a=pow(10,l);
	m=pow(10,i);
	z=y/m;
	if(z==0&&z!=n&&h%a!=0)
	{
		printf("a");
	}
	if(z!=0)
	{
	    printf("%c",c+z);
	if(i==8){
		printf("Y");
	}
	if(i==7||i==3)
		printf("Q");
	if(i==6||i==2)
	{
		printf("B");
	}
	if(i==5||i==1)
	{
		printf("S");
	}
	if(i==4)
	{
		printf("W");
	}
    }
	if(i==4&&z==0)
	{
		printf("W");
	}
    	if(n==0&&i==3&&z==0)
    	{
		printf("a");
    	}
		y=y%m;
   		i--;
  		n=z;
   	}
   	while(y!=0);
	return 0;
 }
/*
	个 十 百 千 万 十万 百万 千万 亿
	1  2  3   4  5  6   7     8   9 
*/
