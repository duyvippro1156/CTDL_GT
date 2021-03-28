#include <stdio.h>
#include <conio.h>
void NHAP(int a[], int *n )
{
	int i;
	for (i=1; i<=*n; i++)
	{
		printf("Nhap a[%d]: ",i);
		scanf("%d",&a[i]);
	}
}
int main()
{
	int A[10],B[10],x,y;
	printf("Nhap day so a: ");
	printf("Nhap spt a: ");
	scanf("%d",&x);
	NHAP(A,&x);
	printf("Nhap day so b: ");
	printf("Nhap spt b: ");
	scanf("%d",&y);
	NHAP(B,&y);
	printf("%d + %d = %d",A[1],B[2],A[1]+B[2]);
	getch();
}
