#include<stdio.h>
#include<conio.h>
typedef  struct	DIEM
{
	float toan, ly, hoa;
};

typedef struct SV
{
	char hoten[25], masv[10];
	DIEM diem;
};

void NHAP(SV sv[],int n)
{
	int i; 
	float tg;
	for(i=1; i<=n; i++)
	{
		fflush(stdin);
		printf("Ma sinh vien: ");
		gets(sv[i].masv);
		printf("Ho ten sinh vien: ");
		gets(sv[i].hoten);
		printf("Diem toan: ");
		scanf("%f",&tg);
		sv[i].diem.toan=tg;
		printf("Diem ly: ");
		scanf("%f",&tg);
		sv[i].diem.ly=tg;
		printf("Diem hoa: ");
		scanf("%f",&tg);
		sv[i].diem.hoa=tg;
	}
}

void DTB(SV sv[], float dtb[], int n)
{
	int i;
	float DTB;
	for(i=1;i<=n;i++)
	{
		DTB=(sv[i].diem.toan+sv[i].diem.ly+sv[i].diem.hoa)/3; 
		dtb[i]=DTB;
	}
}

void IN(SV sv[], float dtb[], int n)
{
	int i;
	for(i=1;i<=n;i++)
		printf("%10s ||%10s || %0.2f\n",sv[i].masv, sv[i].hoten, dtb[i]);
}

void LHTB(SV sv[],float dtb[],int n)
{
	int i,d;
	d=0;
	printf("Sinh vien co diem TB>5\n");
	for(i=1;i<=n;i++)
		if(dtb[i]>5)
		{
			printf("%10s || %10s || %0.2f\n",sv[i].masv, sv[i].hoten, dtb[i]); 
			d=d+1;
		}
	if(d==0)
		printf("Khong co sinh vien nao co diem TB tren 5.");
}

void HVIDTB(float *t,float *s)
{
	float tg;
	tg=*t;
	*t=*s;
	*s=tg;
}

void HOANVI(SV *t,SV *s)
{
	SV tg;
	tg=*t;
	*t=*s;
	*s=tg;
}

void SAPXEP(SV ds[],float dtb[],int n)
{
	int i,j;
	for(i=1;i<=n-1;i++)
		for(j=i;j<=n;j++)
			if(dtb[i]>dtb[j])
			{
				HOANVI(&ds[i],&ds[j]);
				HVIDTB(&dtb[i],&dtb[j]);
			}
}

int main()
{
	SV ds[25];
	float dtb[25];
	int n;
	printf("Nhap so hoc sinh: ");
	scanf("%d",&n);
	NHAP(ds,n);
	DTB(ds,dtb,n);
	IN(ds,dtb,n);
	LHTB(ds,dtb,n);
	SAPXEP(ds,dtb,n); 
	printf("Danh sach diem TB tang dan la:\n");
	IN(ds,dtb,n);
	getch();
}

