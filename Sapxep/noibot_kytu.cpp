#include <stdio.h>
void Input(char a[],int &n)
{
	printf("Nhap so phan tu: ");
	scanf("%d" ,&n);
	printf("\n\nNhap day so:\n\n");
	for(int i=1;i<=n;i++)
	{
		fflush(stdin);
		printf("\nKy tu thu %d: " ,i);
		scanf("%c" ,&a[i]);
	}
}
void Output(char a[], int n)
{
	for(int i=1;i<=n;i++)
		printf(" %c ",a[i]);
}
void Permutation(char &x, char &y)
{
	char tg=x;
	x=y;
	y=tg;
}
void Sort(char a[],int n)
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
	char a[100];
	int n;
	Input(a,n);
	if(n<=0)
		return 0;
	printf("\n\n Day ky tu\n");
	Output(a,n);
	printf("\n\n Qua trinh sap xep ");
	Sort(a,n);
	printf("\n\n Day ky tu da sap xep \n");
	Output(a,n);
}
