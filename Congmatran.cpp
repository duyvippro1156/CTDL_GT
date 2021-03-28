#include <stdio.h>
#include <conio.h>
void NHAP(int a[10][10], int *h, int *c)
{
	int m,n;
	printf("Nhap hang: ");
	scanf("%d",h);
	printf("Nhap cot: ");
	scanf("%d",c);
	for (m=1; m<=*h; m++)
		for (n=1; n<=*c; n++)
		{
			printf("a[%d%d]: ",m,n);
			scanf("%d",&a[m][n]);
		}
}
void IN(int a[10][10], int h, int c)
{
	int m,n;
	for (m=1; m<=h; m++)
	{
		for (n=1; n<=c; n++)
			printf("%d\t",a[m][n]);
		printf("\n");	
	}
}
int main()
{
	int a[10][10], b[10][10],c[10][10],H1,C1,H2,C2,m,n;
	printf("Nhap ma tran A:\n ");
	NHAP(a,&H1,&C1);
	printf("Nhap ma tran B:\n ");
	NHAP(b,&H2,&C2);
	printf("Ma tran A:\n ");
	IN(a,H1,C1);
	printf("Ma tran B:\n ");
	IN(b,H2,C2);
	if (H1!=H2 || C1!=C2)
		printf("Hai ma tran khong cung kich co !");
	else
	{
		for (m=1; m<=H1; m++)
			for (n=1; n<=C1; n++)
				c[m][n]=a[m][n]+b[m][n];
		printf("Ma tran A + Ma tran B = \n");
		IN(c,H1,C1);
	}
	getch();
}
