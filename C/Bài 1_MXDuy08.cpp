#include<stdio.h>
struct Node_List{
	int Data;
	Node_List *Adr_ItAf;
};
Node_List *Add_Af(Node_List *H, Node_List *It){
	Node_List *tmp;
	if(H==NULL)
		H=It;
	else{
		tmp=H;
		while(tmp->Adr_ItAf!=NULL)
			tmp=tmp->Adr_ItAf;
		tmp->Adr_ItAf=It;
	}
	return H;
}
Node_List *Nhap(Node_List *H){
	Node_List *p;
	int i=1;
	do{
		p=new Node_List;
		printf("Nhap so thu %d: ",i);
		scanf("%d",&p->Data);
		if(p->Data!=0){
			p->Adr_ItAf=NULL;
			H=Add_Af(H,p);
		}
		i=i+1;
	}
	while(p->Data!=0);
	return H;
}
Node_List *In(Node_List *H){
	Node_List *tmp;
	printf("------------------\n");
	printf("Danh sach lien ket: ");
	if(H==NULL)
		printf("Danh sach NULL! ");
	else{
		tmp=H;
		while(tmp!=NULL){
			printf("\t%d",tmp->Data);
			tmp=tmp->Adr_ItAf;
		}
	}
}
main(){
	Node_List *Hd;
	printf("MAI XUAN DUY 08\n");
	Hd=NULL;
	Hd=Nhap(Hd);
	In(Hd);
}
