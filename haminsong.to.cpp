#include <stdio.h>
#include <conio.h>
int KT(int n)
{
	int i,d;
	d=0;
	for (i=1; i<=n; i++)
		if (n%i==0)
			d=d+1;
	if (d==2)
		return 1;
	else 
		return 0;
}
int main()
{
	int i,x;
	for (i=1; i<=1000; i++)
	{
		x=i;
		if (KT(x)==1)
			printf("%d\n",i);
	}
	getch();
}
