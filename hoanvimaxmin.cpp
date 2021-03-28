#include <stdio.h>
#include <conio.h>
void NHAP(int ds[], int *n)
{
	int i;
	printf ("Nhap bao nhieu so: ");
	scanf ("%d",n);
	for (i=1; i<=*n; i++)
	{
		printf("Nhap so thu %d: ",i);
		scanf("%d", &ds[i]);
	}
}
void IN(int ds[], int n)
{
	int i;
	for (i=1; i<=n; i++)
		printf("%d",ds[i]);
}
void HOANVI(int *a, int *b)
{
	int tg;
	tg=*a;
	*a=*b;
	*b=tg;
}
void HVMAXMIN(int ds[], int n)
{
	int i,max,imax,min,imin;
	max=ds[1];
	min=ds[1];
	imax=1;
	imin=1;
	for (i=1; i<=n; i++)
	{
		if (ds[i]>max)
		{
			max=ds[i];
			imax=i;
		}
		if(ds[i]<min)
		{
			min=ds[i];
			imin=i;
		}
	}
	HOANVI(&ds[imax],&ds[imin]);
}
int main()
{
	int a[10],pt;
	NHAP(a,&pt);
	printf("Day so chua hoan vi: ");
	IN(a,pt);
	HVMAXMIN(a,pt);
	printf("\nDay so da hoan vi: ");
	IN(a,pt);
	getch();
}
