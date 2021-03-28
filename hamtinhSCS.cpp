#include <stdio.h>
#include <conio.h>
int DEM(int so, int sochuso)
{
	int dv;
	sochuso=0;
	while (so>0)
		{
			dv=so%10;
			sochuso=sochuso+1;
			so=so/10;
		}
	return sochuso;
}
int main()
{
	int x,SCS;
	printf("Nhap so x: ");
	scanf("%d",&x);
	SCS=DEM(x,SCS);
	printf("So chu so cua x la %d",SCS);
	getch();
}
