#include <stdio.h>
#include <conio.h>
int main()
{
	int so,dv,tg;
	printf("Nhap so: ");
	scanf("%d",&so);
	tg=0;
	while (so!=0)
	{
		dv=so%10;
		tg=tg+dv;
		so=so/10;
	}
	printf("tong cac chu so nguyen la %d",tg);
	getch();
}
