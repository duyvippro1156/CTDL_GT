#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#define MAX 100
void nhapmang(int a[], int &n);
void xuatmang(int a[], int n);
int KiemTraMangDoiXung(int a[], int n);
int main()
{
	int a[MAX],n;
	nhapmang(a,n);
	printf("\nNoi dung cua mang");
	xuatmang(a,n);
	if(KiemTraMangDoiXung(a,n) == 1)
		printf("\nMang doi xung ");
	else
		printf("\nMang khong doi xung ");
	printf("\nChuc cac ban hoc tot");
	getch();
}
void nhapmang(int a[], int &n)
{
	do
	{
		printf("\nSo phan tu trong mang ");
		scanf("%d",&n);
	}while(n<=0 && n>100);
	for(int i=0 ; i<n ; i++ )
	{
		printf("\nSo phan tu a[%d] la: ",i);
		scanf("%d",&a[i]);
	}
}
void xuatmang(int a[], int n)
{
	for(int i=0 ; i<n ; i++ )
		printf("%4d",a[i]);
}
int KiemTraMangDoiXung(int a[], int n)
{
	for(int i = 0; i < n/2; i++)
	{
		if(a[i] != a[n - i - 1])
			return 0;
	}
	return 1;
}
