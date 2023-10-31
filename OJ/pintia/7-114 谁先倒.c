#include<stdio.h>
int main()
{
	int jj=0,yj=0,n=0,a[100][4],jy=0,yy=0,jh=0,yh=0;
	scanf("%d %d",&jj,&yj);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	for(int i=0;i<n;i++)
	{
		if(a[i][0]+a[i][2]==a[i][1])
		jy=0;
		else
		jy=1;
		if(a[i][0]+a[i][2]==a[i][3])
		yy=0;
		else
		yy=1;
		if(jy!=yy)
		{
			if(jy>yy)
			{
				yj--;
				yh++;
			}
			else
			{
				jj--;
				jh++;
			}
		}	
		if(yj==-1)
		{
			printf("B\n%d",jh);
			break;
		}
		if(jj==-1)
		{
			printf("A\n%d",yh);
			break;
		}	
	}
}
