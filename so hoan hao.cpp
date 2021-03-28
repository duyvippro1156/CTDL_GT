#include <stdio.h>
#include <conio.h>
int main()
{
	int n,i,s;
	s=0;
	printf("Nhap n: ");
	scanf("%d",&n);
	for (i=1; i<n; i++)
		if (n%i==0)
			s=s+i;
	if (s==n)
		printf("n la so hoan hao");
	else 
		printf("n khong la so hoan hao");
	getch();
}
