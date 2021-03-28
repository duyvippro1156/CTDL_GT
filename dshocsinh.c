#include <stdio.h>
#include <conio.h>
struct DSHS
{
	char ten[25], lop[10];
	float dtb;
};
void NHAP(DSHS hs[], int *n)
{
	int i;
	float tg;
	printf("Nhap bao nhieu hoc sinh");
	scanf("%d",n);
	for (i=1; i<=*n; i++)
	{
		fflush(stdin);
		printf("Nhap hoc sinh thu %d",i);
		printf("\nHo ten: ");
		gets(hs[i].ten);
		printf("Lop: ");
		gets(hs[i].lop);
		printf("Diem trung binh: ");
		scanf("%f",&tg);
		hs[i].dtb=tg;
	}
}
