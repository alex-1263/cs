#include<stdio.h>
int main()
{
	int n=0,y=0,r=0,run=0,x=0;
	while(scanf("%d/%d/%d",&n,&y,&r)!=EOF)
	{
		run=0;
		if(n%4==0&&n%100!=0)
		run=1;
		if(n%400==0)
		run=1;
		switch(y)
		{
		case 1:x=0;break;
		case 2:x=31;break;
		case 3:x=59;break;
		case 4:x=90;break;
		case 5:x=120;break;
		case 6:x=151;break;
		case 7:x=181;break;
		case 8:x=212;break;
		case 9:x=243;break;
		case 10:x=273;break;
		case 11:x=304;break;
		case 12:x=334;break;
		}
		x+=r;
		if(run==1)
		{
			if(y>2)
			{
				x++;
			}
		}
		printf("%d\n",x);
	}
	return 0;
}

