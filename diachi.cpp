#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct DANHSACH
{
	char ten[20],dchi[20];
};

void NHAP(DANHSACH ds[], int n)
{
	int i;
	for(i=1; i<=n; i++)
	{
		fflush(stdin);
		printf("Ten: ");
		gets(ds[i].ten);
		printf("Dia chi: ");
		gets(ds[i].dchi);
	}
}

void IN(DANHSACH ds[], int n)
{
	int i;
	for(i=1; i<=n; i++)
		printf("%15s || %15s \n",ds[i].ten, ds[i].dchi);
}

void HOANVI(DANHSACH *t, DANHSACH *s)
{
	DANHSACH tg;
	tg=*t;
	*t=*s;
	*s=tg;
}

void SAPXEP(DANHSACH ds[],int n)
{
	int i,j;
	for(i=1; i<=n-1; i++)
		for(j=i; j<=n; j++)
		{
			if (strcmp(ds[i].ten,ds[j].ten)>0)
				HOANVI(&ds[i],&ds[j]);
			if (strcmp(ds[i].ten,ds[j].ten)==0)
				if (strcmp(ds[i].dchi,ds[j].dchi)>0)
					HOANVI(&ds[i],&ds[j]);
		}
}

int main()
{
	DANHSACH ds[25]; 
	int n;
	printf("Nhap so nguoi: ");
	scanf("%d",&n); 
	NHAP(ds,n);
	SAPXEP(ds,n); 
	IN(ds,n);
	getch();
}

