#include<stdio.h>  
#include<conio.h>  

int main()  
{  
 int n1,n2,n3,i,n;  
 printf("Nhap so n: ");  
 scanf("%d",&n);
 n1=0;
 n2=1; 
 for(i=1;i<n;i++) 
 {  
  n3=n1+n2;    
  n1=n2;  
  n2=n3;
  if(i==n-1)
  printf("So fibonaci thu n la %d",n3);  
 }  
 }
