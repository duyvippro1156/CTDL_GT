#include <stdio.h>
#include <conio.h>
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
int DemSNT(int a[], int n)
{
	int i,j,d,dem;
	dem=0;
	for (i=1; i<=n; i++)
	{
		d=0;
		for (j=1; j<=a[i]; j++)
			if(a[i]%j==0)
				d=d+1;
		if (d==2)
			dem=dem+1;
	}
	return dem;
}
int main()
{
	int a[20],n;
	printf("Nhap mang! ");
	NHAP(a,&n);
	printf("So cac so nguyen to trong mang la %d",DemSNT(a,n));
}
