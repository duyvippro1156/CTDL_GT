#include<stdio.h>
#include<conio.h>
int Gthua(int n)
{
	int i,gt;
	gt=1; 
	for (i=1; i<=n; i++)
		gt=gt*i;
	return gt;
}
int main()
{
	int x;
	printf("Nhap x: "); 
	scanf("%d",&x);
	printf("%d! la %d",x,Gthua(x));
	getch();
}
