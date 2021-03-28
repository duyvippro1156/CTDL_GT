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
int main()
{
	int a[20],n,i,j,d;
	printf("Nhap mang! ");
	NHAP(a,&n);
	printf("Day so trong mang: ");
	IN(a,n);
	for(i=1;i<=n;i++)
    {
    	d=0;
    	for(j=1;j<=a[i];j++)
    		if(a[i]%j==0)
				d=d+1;
		if (d==2 && a[i]<n)		
			printf("%d\t",a[i]);
	}
}
