#include <stdio.h>
#include <conio.h>
int main()
{
	int n,i;
	printf("Nhap n: ");
	scanf("%d",&n);
	for (i=1; i<=n; i++)
		if (n%i==0)
			printf("uoc la %d",i);
	getch();
}
