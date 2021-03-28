#include<stdio.h>
void Input(int a[],int *n)
{
	printf("nhap bao nhieu so:");
	scanf("%d",&*n);
	for(int i=0;i<*n;i++)
	{
		printf("nhap so thu %d: ",i);
		scanf("%d",&a[i]);
	}
}
void Output(int a[],int n)
{
	for(int i=0;i<n;i++)
		printf("%5d",a[i]);
}
void Sort(int a[],int n)
{
	int x,i,pos;
	for(i=1;i<n;i++)
	{
		x=a[i];
		pos=i-1;
		while(pos>=0 && a[pos]>x)
		{
			a[pos+1]=a[pos];
			pos--;
		}
		if(pos>=-1 && a[pos+1]>x)
		{
			printf("iI= %d:  ",i);
			a[pos+1]=x;
			Output(a,n);	
			printf("\n");
		}
		else
			a[pos+1]=x;
	}
}
main()
{
	int a[50],n;
	Input(a,&n);
	printf("\nDay so\n");
	Output(a,n);
	printf("\nQua trinh sap xep\n");
	Sort(a,n);
	printf("\nDay so da sap xep\n");
	Output(a,n);
}
