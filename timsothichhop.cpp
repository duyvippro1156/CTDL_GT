#include<stdio.h>
#include<conio.h>
int main()
{
int a,b,c,d;
for(int a=0; a<10; a++)
for(int b=0; b<10; b++)
for(int c=0; c<10; c++)
for(int d=0; d<10; d++)

if(a*d*d==b*c*c*c)
printf("%d%d%d%d\n",a,b,c,d);

getch();
}
