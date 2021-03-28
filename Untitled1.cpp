#include<stdio.h>
#include<conio.h>
typedef  struct	DIEM
{
	float toan, ly, hoa;
};

typedef struct SV
{
	char masv[15],hoten[50];
	DIEM diem;
};

void NHAP(SV ds[],int n)
{
	int i; 
	float tg;
	for(i=1; i<=n; i++)
	{
		fflush(stdin);
		printf("Ma so sinh vien: ");
		gets(ds[i].masv);
		printf("Ho va ten sinh vien: ");
		gets(ds[i].hoten);
		printf("Diem toan: ");
		scanf("%f",&tg);
		ds[i].diem.toan=tg;
		printf("Diem ly: ");
		scanf("%f",&tg);
		ds[i].diem.ly=tg;
		printf("Diem hoa: ");
		scanf("%f",&tg);
		ds[i].diem.hoa=tg;
	}
}

void DTB(SV ds[], float dtb[], int n)
{
	int i;
	float dtb1;
	for(i=1;i<=n;i++)
	{
		dtb1=(ds[i].diem.toan+ds[i].diem.ly+ds[i].diem.hoa)/3; 
		dtb[i]=dtb1;
	}
}

void IN(SV ds[],float dtb[],int n)
{
	int i;
	for(i=1;i<=n;i++)
		printf("%10s ||%10s || %0.2f\n",ds[i].masv,ds[i].hoten,dtb[i]);
}

void LDTB(SV ds[],float dtb[],int n)
{
	int i,d;
	d=0;
	printf("Sinh vien co diem TB>5\n");
	for(i=1;i<=n;i++)
		if(dtb[i]>5)
		{
			printf("%10s || %10s || %0.2f\n",ds[i].masv,ds[i].hoten,dtb[i]); 
			d=d+1;
		}
	if(d==0)
		printf("Khong co sinh vien nao co diem TB tren 5");
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
	SV ds[100];
	float dtb[100];
	int n;
	printf("Nhap so hoc sinh: ");
	scanf("%d",&n);
	NHAP(ds,n);
	DTB(ds,dtb,n);
	IN(ds,dtb,n);
	LDTB(ds,dtb,n);
	SAPXEP(ds,dtb,n); 
	printf("Danh sach diem TB tang dan la:\n");
	IN(ds,dtb,n);
	getch();
}

