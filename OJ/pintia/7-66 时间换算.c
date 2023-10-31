#include<stdio.h>
int main()
{
	int hh=0,mm=0,ss=0,n=0;
	scanf("%d:%d:%d",&hh,&mm,&ss);
	scanf("%d",&n);
	ss+=n;
	if(ss>59)
	{
		ss-=60;
		mm+=1;
		if(mm>59)
		{
			mm-=60;
			hh+=1;
			if(hh>23)
			hh=0;
		}
	}
	printf("%02d:%02d:%02d",hh,mm,ss);
	return 0;
}
