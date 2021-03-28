#include <stdio.h>
#include <conio.h>
#define MAX 20
void NHAP(int a[], int *n)
{
	int i;
	do
	{
		printf("\nNhap bao nhieu so: ");
		scanf("%d",n);
		if (*n<=0 || *n> MAX)
			printf("Khong hop le");
	}
	while (*n<=0 || *n>MAX);
	for (i=1; i<=*n; i++)	
	{
		printf("a[%d]: ",i);
		scanf("%d",&a[i]);
	}
}
int main()
{
	int a[20],i,n,tong;
	printf("Nhap mang! ");
	NHAP(a,&n);
	tong=0;
	for (i=1; i<=n; i++)
		if (a[i]>0)
			tong=tong+a[i];
	printf("Tong cac  so duong trong day so: %d",tong);
}
