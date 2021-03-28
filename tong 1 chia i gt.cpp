#include <stdio.h>
#include <conio.h>
int main()
  {
  	float i,n,gt,S;
  	fflush(stdin);
  	gt=1;
  	S=0;
  	printf("nhap n: ");
  	scanf("%d",&n);
  	for (i=1; i<=n; i++){  
	      gt=gt*i;
	      S=S+1.0/gt;
	    }
  	printf("S= %f",S);
  	getch();
  }
