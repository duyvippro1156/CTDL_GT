#include <stdio.h>
#include <conio.h>
int main()
{
	int i,n,S;
	printf("Nhap n: ");
	scanf("%d",&n);
	S=0;
	for (i=n; i>=1; i--)
		{
			if (i%2==1) 
				S=S+i;
			else
				S=S-i;
		}
	printf("S = %d",S);
	getch();
}
