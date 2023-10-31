#include<stdio.h>
int main()
{
	char a[164]={"S1,S2,S3,S4,S5,S6,S7,S8,S9,S10S11S12S13H1,H2,H3,H4,H5,H6,H7,H8,H9,H10H11H12H13C1,C2,C3,C4,C5,C6,C7,C8,C9,C10C11C12C13D1,D2,D3,D4,D5,D6,D7,D8,D9,D10D11D12D13J1,J2,\0"};
	char b[164]={"S1,S2,S3,S4,S5,S6,S7,S8,S9,S10S11S12S13H1,H2,H3,H4,H5,H6,H7,H8,H9,H10H11H12H13C1,C2,C3,C4,C5,C6,C7,C8,C9,C10C11C12C13D1,D2,D3,D4,D5,D6,D7,D8,D9,D10D11D12D13J1,J2,\0"};
	int  c[54],x=0;
	char d=0;
	scanf("%d",&x);
	for(int i=0;i<54;i++)
	{
		scanf("%d",&c[i]);
	}
	for(int j=0;j<x;j++)
	{
		if(j%2==0)
		{
			for(int i=0;i<54;i++)
			{
				d=a[i*3];
				b[(c[i]-1)*3]=d;
				d=a[i*3+1];
				b[(c[i]-1)*3+1]=d;
				d=a[i*3+2];
				b[(c[i]-1)*3+2]=d;
			}
		}
		else
		{
			for(int i=0;i<54;i++)
			{
				d=b[i*3];
				a[(c[i]-1)*3]=d;
				d=b[i*3+1];
				a[(c[i]-1)*3+1]=d;
				d=b[i*3+2];
				a[(c[i]-1)*3+2]=d;
			}
		}
	}
	if(x%2==0)
	{
			for(int i=0;i<162;i++)
		{
			if(a[i]>='A'&&a[i]<='Z')
			{
				if(a[i-1]>='0'&&a[i-1]<='9')
				printf(" ");
			}
			if(a[i]!=',')
			printf("%c",a[i]);
			else if(i!=161)
			printf(" ");
		}
	}
	if(x%2!=0)
	{
			for(int i=0;i<162;i++)
		{
			if(b[i]>='A'&&b[i]<='Z')
			{
				if(b[i-1]>='0'&&b[i-1]<='9')
				printf(" ");
			}
			if(b[i]!=',')
			printf("%c",b[i]);
			else if(i!=161)
			printf(" ");
		}
	}
	return 0;
}
//1 a b  2 b a 
//36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
