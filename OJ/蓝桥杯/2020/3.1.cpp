#include<iostream>
using namespace std;
int main()
{
	int sum=0;
	for(int i=1;i<40;i++)
	{
		for(int j=1;j<=i;j++)
		{
			sum++;
			if(i==39&&j==20)
			break;
		}
	}
	cout<<sum;
	return 0;
}
