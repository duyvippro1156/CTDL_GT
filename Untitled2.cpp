#include<stdio.h>
int tru2so(int a, int *b)
{
	*b=*b-a;
	a=a+*b;
	return (a-*b);
}
int main()
{
	int x=-4, y=8, c;
	c=tru2so(x,&y);
	printf("x = %d\n",x);
	printf("y = %d\n",y);
	printf("c = %d",c);
}
