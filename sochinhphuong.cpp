#include <stdio.h>
#include <conio.h>
#include <math.h>
void NHAP(int a[], int *n)
{
	int i;
	printf("\nNhap bao nhieu so: ");
	scanf("%d",n);
	for (i=1; i<=*n; i++)
	{
		printf("a[%d]: ",i);
		scanf("%d",&a[i]);
	}
}
void IN(int a[], int n)
{
	int i;
	for (i=1; i<=n; i++)
		printf("%d\t",a[i]);
}
int main()
{
	int a[20],i,n,tg;
	printf("Nhap mang! ");
	NHAP(a,&n);
	printf("Day so trong mang: ");
	IN(a,n);
	printf("\nSo chinh phuong la: ");
	for (i=1; i<=n; i=i+2)
	{
		tg=sqrt(a[i]);
		if (tg*tg==a[i])
			printf("%d\t",a[i]);
	}
}
