#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node_List{
	char Data;
    Node_List *Adr_ItAf;
};
Node_List *Add_Af(Node_List *H, Node_List *It){
	if(H==NULL)
		H=It;
	else{
		Node_List *tmp;
		tmp=H;
		while(tmp->Adr_ItAf!=NULL)
			tmp=tmp->Adr_ItAf;
		tmp->Adr_ItAf=It;
	}
	return H;
}
Node_List *Nhap(Node_List *H ,Node_List*p)
{   
    int n,i;
    H=NULL;
    srand((int)time(0));	
    n=rand()%16;
	printf("So ki tu random:  %d\n",n);	
	for (i=1;i<=n;i++)
	{
		p = new Node_List ;
		p->Data=65+rand()%26;
		p->Adr_ItAf=NULL;
		H=Add_Af(H,p);	
	}
	return H;
}
void In(Node_List *H) {       
    Node_List *tmp;      
    if(H==NULL)
        printf("Danh sach NULL");
    else{
		tmp=H;
		while(tmp!=NULL){
			printf(" %c(%d)" ,tmp->Data,tmp->Data);
			tmp=tmp->Adr_ItAf;
		}	
	}     	
}
main(){
	Node_List*Hd, *p;	
	printf("MAI XUAN DUY 08\n");
    Hd=Nhap(Hd,p);
	In(Hd);
}
