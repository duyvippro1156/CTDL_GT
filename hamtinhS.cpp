#include<stdio.h>     
#include<conio.h>
float Stron(float R)
{
	float S;
	S = R*R*3.14;
	return S;
}
float Sthang(int dl, int db, int dc)
{
	float S;
	S = (dl+db)*dc/2.0;
	return S;
}
float Scnhat(int cd, int cr)
{
	int S;
	S = cd*cr;
	return S;
}
int main()
{
	float r;
	int dl,db,dc,cd,cr,n;
	printf("Nhap 1: h.tron, 2: h.thang, 3: h.chu nhat  ");
	scanf("%d",&n);
	switch(n)
	{
		case 1: printf("Nhap r: ");
				scanf("%f",&r);
				printf("Dien tich: %f",Stron(r));
				break;
		case 2: printf("Nhap dl, db, dc  ");
				scanf("%d%d%d",&dl,&db,&dc);
				printf("Dien tich: %f",Sthang(dl,db,dc));
				break;
		case 3: printf("Nhap cd, cr  ");
				scanf("%d%d",&cd,&cr);
				printf("Dien tich: %f",Scnhat(cd,cr));
				break;
	}
	getch();
}
