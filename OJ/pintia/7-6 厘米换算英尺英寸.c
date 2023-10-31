int main()
{
	int lm=0,inch=0,foot=0;
	scanf("%d",&lm);
	inch=lm/2.54;
	foot=inch/12;
	inch=inch%12;
	printf("%d %d",foot,inch);
	return 0;
} 