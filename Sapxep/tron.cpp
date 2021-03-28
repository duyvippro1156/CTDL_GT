#include <stdio.h>
void Input(int a[],int &n)
{
	printf("\n- Nhap so phan tu: ");
	scanf("%d" ,&n);
	for(int i=1;i<=n;i++)
	{
		printf(" + So thu %d: " ,i);
		scanf("%d" ,&a[i]);
	}
}
void Output(int a[], int n)
{
	for(int i=1;i<=n;i++)
		printf(" %d ",a[i]);
}
void Delete(int a[], int n)
{
	for(int i=1;i<n;i++)
		a[i]=a[i+1];
}
void Sort(int a[],int b[], int c[],int n1, int n2)
{
	int k=1;
	while(n1!=0 && n2!=0)
	{
		
		if(a[1]<=b[1])
		{
			c[k]=a[1];
			Delete(a,n1);
			n1--;
		}
		else
		{
			c[k]=b[1];
			Delete(b,n2);
			n2--;
		}
		printf("\n\n *Cong doan %d: \n  - Day so 1: " ,k);
		Output(a,n1);
		printf("\n  - Day so 2: ");
		Output(b,n2);
		printf("\n  - Output: ");
		Output(c,k);
		k++;
	}
	if(n1==0)
	{
		for(int i=1;i<=n2;i++)
		{
			c[k]=b[i];
			k++;
		}
		printf("\n\n *Cong doan cuoi: \n  - Day so 1: ");
		printf("\n  - Day so 2: ");
		printf("\n  - Output: ");
		Output(c,k-1);
	}
	else
	{
		for(int i=1;i<=n1;i++)
		{
			c[k]=a[i];
			i++;
		}
		printf("\n\n *Cong doan cuoi: \n  - Day so 1: ");
		printf("\n  - Day so 2: ");
		printf("\n  - Output: ");
		Output(c,k-1);
	}
}
main()
{
	int a[100],b[100],c[200],n1,n2;
	printf("- Day so 1: ");
	Input(a,n1);
	printf("\n- Day so 2: ");
	Input(b,n2);
	printf("\n\n- Day so 1: ");
	Output(a,n1);
	printf("\n\n- Day so 2: ");
	Output(b,n2);
	printf("\n\n* Qua trinh sap xep ");
	Sort(a,b,c,n1,n2);
	printf("\n\n* Day so da sap xep\n ");
	Output(c,n1+n2);
}
