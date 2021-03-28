#include <stdio.h>
#include <conio.h>
int main()
{
	float i,n,S,gt,j;
	printf("Nhap n:");
	scanf("%f",&n);
	gt=1;
	for (i=1;i<=n;i=i+1)
		gt=gt*i;
	printf("Tong la %f",gt);
	getch();
}
