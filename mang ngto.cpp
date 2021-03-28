#include<stdio.h>
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
int ktranto(int a[],int n)
{
	int i,j,ok;
	for(i=1;i<=n;i++)
    {
    	ok=0;
		if(a[i]<2)
			return 1;
    	for(j=1;j<=a[i];j++)
    		if(a[i]%j==0)
				ok=ok+1;	
		if (ok==2)		
			return 0;
	}
}
int main()
{
	int a[20],n;
	printf("\nNhap mang! ");
	NHAP(a,&n);
	IN(a,n);
	if(ktranto(a,n) == 0) 
    	printf("\nmang toan nguyen to");
    else 
		printf("\nmang khong toan nguyen to");

}
