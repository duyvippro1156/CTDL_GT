#include <stdio.h>
void Input(int a[],int &n)
{
	printf("Nhap so phan tu: ");
	scanf("%d" ,&n);
	printf("\nNhap day so:\n");
	for(int i=1;i<=n;i++)
	{
		printf("\nSo thu %d: ",i);
		scanf("%d",&a[i]);
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
	for(int i=1;i<n;++i)
	{
		int min=a[i],vt=0;
		for(int j=i+1;j<=n;++j)
		{
			if(min>a[j])
			{
				min=a[j];	
				vt=j;
			}
		}
		if(min!=a[i])
		{
			Permutation(a[i],a[vt]);
			printf("\n\n * vt=%d: ",i);
			Output(a,n);
		}
	}
}
main()
{
	int a[50], n;
	Input(a,n);
	if(n<=0)
		return 0;
	printf("\n\nDay so\n");
	Output(a,n);
	printf("\n\nQua trinh sap xep:");
	Sort(a,n);
	printf("\n\nDay so da sap xep\n ");
	Output(a,n);
}
