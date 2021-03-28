#include <stdio.h>
void Input(int a[],int &n)
{
	printf("Nhap so phan tu: ");
	scanf("%d" ,&n);
	printf("\n\nNhap day so:\n\n");
	for(int i=1;i<=n;i++)
	{
		printf("\nSo thu %d: " ,i);
		scanf("%d" ,&a[i]);
	}
}
void Output(int a[], int n)
{
	for(int i=1;i<=n;i++)
		printf(" %d ",a[i]);
}
void Permutation(int &x, int &y)
{
	int tg=x;
	x=y;
	y=tg;
}
void Sort(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		for(int j=n;j>i;j--)
		{
			if(a[j]<a[j-1])
			{
				Permutation(a[j],a[j-1]);
				printf("\n\n * i=%d j=%d: " ,i ,j);
				Output(a,n);
			}			
		}
	}
}
main()
{
	int a[100], n;
	Input(a,n);
	if(n<=0)
		return 0;
	printf("\n\n Day so\n");
	Output(a,n);
	printf("\n\n Qua trinh sap xep ");
	Sort(a,n);
	printf("\n\n Day so da sap xep \n");
	Output(a,n);
}
