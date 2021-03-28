#include <stdio.h>
#include <conio.h>
void NHAP(int a[], int *n)
{
	int i;
	printf("Nhap bao nhieu so: ");
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
void INSNT(int a[], int n)
{
	int i,j,d;
	for (i=1; i<=n; i++)
	{
		d=0;
		for (j=1; j<=a[i]; j++)
			if(a[i]%j==0)
				d=d+1;
		if (d==2)
			printf("%d\t",a[i]);
	}
}
int TONG(int a[], int n)
{
	int i,tong;
	tong=0;
	for (i=1; i<=n; i++)
		if (a[i]%5==0 && a[i]>0)
			tong=tong+a[i];
	return tong;
}
int DEM(int a[], int n, int x)
{
	int i,dem;
	dem=0;
	for (i=1; i<=n; i++)
		if (a[i]==x)
			dem=dem+1;
	return dem;
}
int KT(int a[], int n, int x)
{
	int i,kq;
	kq=0;
	for (i=1; i<=n; i++)
		if(a[i]==x)
			kq=kq+1;
	return kq;
}
void THAYTHE(int a[], int n, int x)
{
	int i,k;
	for (i=1; i<=n; i++)
		if(a[i]==x)
		{
			printf("Nhap lai a[%d] = ",i);
			scanf("%d",&k);
			a[i]=k;
		}
}
void SAPXEP(int a[], int n)
{
	int t,s,tg;
	for (t=1; t<=n-1; t++)
		for (s=t+1; s<=n; s++)
			if(a[t]>a[s])
			{
				tg=a[t];
				a[t]=a[s];
				a[s]=tg;
			}
}
int main()
{
	int a[20],pt,x,y,z;
	//bai 1a
	NHAP(a,&pt);
	//bai 1b
	printf("Day so trong mang: ");
	IN(a,pt);
	//bai 1c
	printf("\nSo nguyen to trong mang:  ");
	INSNT(a,pt);
	//bai 1d
	printf("\nTong cac so chia het cho 5 la %d",TONG(a,pt));
	//bai 1e
	printf("\nNhap so can dem: ");
	scanf("%d",&x);
	printf("\nSo lan xuat hien gia tri %d la %d",x, DEM(a,pt,x));
	//bai 1f
	printf("\nNhap so can kiem tra: ");
	scanf("%d",&y);
	if(KT(a,pt,y)==1)
		printf("Co!");
	else
		printf("Khong!");
	//bai 1g
	printf("\nNhap so can thay the: ");
	scanf("%d",&z);
	THAYTHE(a,pt,z);
	printf("\nMang sau khi duoc thay the: ");
	IN(a,pt);
	//bai 1h
	printf("\nMang sau khi duoc sap xep tang dan: ");
	SAPXEP(a,pt);
	IN(a,pt);
}
