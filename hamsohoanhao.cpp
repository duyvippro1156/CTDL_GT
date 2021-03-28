#include <stdio.h>
#include <conio.h>
int KT(int n)
{
	int s,i;
	s=0;
	for (i=1;i<n;i++)
		if (n%i==0)
			s=s+i;
	if (n==s)
		return 1;
	else 
		return 0;
}
int main()
{
	int x;
	printf("Nhap so x: ");
	scanf("%d",&x);
	if (KT(x)==1)
		printf("So hoan hao");
	else
		printf("So khong hoan hao");
	getch();
}
