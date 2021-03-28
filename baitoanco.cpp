#include <stdio.h>
#include <conio.h>
int main()
{
	int td,tn,tg;
	for (td=0; td<=20; td++)
		for (tn=0; tn<=33; tn++)
			if(td*5+tn*3+(100-td-tn)/3==100)
				printf("Trau dung %d, Trau nam %d, Trau gia %d\n",td,tn,100-td-tn);
	getch();
}
