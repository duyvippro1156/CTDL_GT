#include<stdio.h>
#include<conio.h>
float TONG(int n)
{
	int i,a;
	float S;
	a=1;
	S=0;
	for (i=1; i<=n; i++)
	{
		a=a*i;
		S=S+1.0/a;
	}
	return (S);
}
int main()
{
	int x;
	printf("Nhap x: ");
	scanf("%d",&x);
	printf("%f",TONG (x));
	getch();
}
