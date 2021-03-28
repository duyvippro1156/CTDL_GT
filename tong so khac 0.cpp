#include <stdio.h>
#include <conio.h>
int main()
{
	int tg,so;
	tg=0;
	do 
	{
		printf("Nhap so: ");
		scanf("%d",&so);
		if (so>0)
			tg=tg+so;
	}
	while (so!=0);
	printf("Tong %d",tg);
	getch();
		
}
