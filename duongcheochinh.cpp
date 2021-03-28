#include<stdio.h>
#include<conio.h>
void NHAP(int mtv[10][10],int *h, int *c)
{
	int i,j;
	for (i=1; i<=*h; i++)
		for (j=1; j<=*c; j++)
		{
			printf("a[%d%d]: ",i,j);
			scanf("%d",&mtv[i][j]);
		}
}
void IN(int mtv[10][10],int h, int c)
{
	int i,j;
	for (i=1; i<=h; i++)
	{
		for (j=1; j<=c; j++)
			printf("%d\t",mtv[i][j]);
		printf("\n");
	}
}
int TONG(int mtv[10][10], int h, int c)
{
	int i,j,sum;
	sum=0;
	for (i=1; i<=h; i++) 
	{
      for (j=1; j<=c; j++) 
		{
         if (i == j)
            sum = sum + mtv[i][j];
    	}
	}
	return sum;
}
int main() 
{
	int mt[10][10], h, c;
	printf("Nhap so hang cua ma tran: ");
	scanf("%d", &h);
	printf("Nhap so cot cua ma tran: ");
	scanf("%d", &c);
	if (h == c)
	{
		NHAP(mt,&h,&c);
		printf("Ma tran vuong:\n ");
		IN(mt,h,c);
		printf("\nTong duong cheo cua ma tran la: %d", TONG(mt,h,c));
	}
	else
		printf("Nhap sai! ");   
	getch();
km}
