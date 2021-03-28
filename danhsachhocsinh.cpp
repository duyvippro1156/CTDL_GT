#include <stdio.h>
#include <conio.h>
typedef struct DSHS
{
   char ten[25], lop[10];
   float dtb;
};
void NHAP(DSHS hs[], int *n)
{
   int i;
   float tg;
   printf("Nhap bao nhieu hoc sinh: ");
   scanf("%d",n);
   for (i=1; i<=*n; i++)
   {
      fflush(stdin);
      printf("Nhap hoc sinh thu %d: ",i);
      gets(hs[i].ten);
      printf("Lop: ");
      gets(hs[i].lop);
      printf("Diem trung binh: ");
      scanf("%f",&tg);
      hs[i].dtb=tg;
   }
}
void IN(DSHS hs[], int n)
{
   int i;
   for (i=1; i<=n; i++)
      printf("%15s| %10s| %3.4f\n",hs[i].ten, hs[i].lop, hs[i].dtb);
}
void HV(DSHS *a, DSHS *b)
{
   DSHS tghv;
   tghv=*a;
   *a=*b;
   *b=tghv;
}
void SX(DSHS hs[], int n)
{
   int i,j;
   for (i=1; i<=n-1; i++)
      for (j=i+1; j<=n; j++)
	 if (hs[i].dtb > hs[j].dtb)
	    HV(&hs[i],&hs[j]);
}
int main()
{
   DSHS A[50];
   int n;
   NHAP(A,&n);
   printf("Danh sach hoc sinh la:\n ");
   IN(A,n);
   printf("Danh sach sau khi duoc sap xep:\n ");
   SX(A,n);
   IN(A,n);
   getch();
}
