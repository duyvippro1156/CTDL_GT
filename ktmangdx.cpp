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
void IN(int a[], int n)
{
	int i;
	for (i=1; i<=n; i++)
		printf("%d\t",a[i]);
}
int KiemTraMangDoiXung(int a[], int n)
{
	int i,kq;
	kq=0;
	for(i=1; i<n/2; i++)
	{
		if(a[i] != a[n+1-i])
			kq=1;
	}
	return kq;
}
int KTTang(int a[],int n)
{
    int i,k;
    k=1;
	for(i=1;i<=n;i++)
    	if(a[i]>a[i+1])
    	{
        	k=0;
        	break;
    	}
    return k;
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
	int a[20],n;
	printf("\nNhap mang! ");
	NHAP(a,&n);
	IN(a,n);
	if(KiemTraMangDoiXung(a,n) == 0)
		printf("\nMang doi xung! ");
	else
		printf("\nMang khong doi xung! ");
	if(KTTang(a,n)==0)
	{
		printf("\nMang khong tang!");
		printf("\nMang duoc sap xep lai: ");
		SAPXEP(a,n);
		IN(a,n);
	}
	else
		printf("\nMang tang!");	
}
