#include <stdlib.h>
#include <stdio.h>
#include <time.h>
struct Node_List{
	int Data;
	Node_List *Adr_ItAf;
};
Node_List *Add_Af(Node_List *H,Node_List *It){
	Node_List *tmp;
	if (H == NULL)
		H=It;
	else{
		tmp = H;
		while (tmp->Adr_ItAf != NULL)
			tmp = tmp->Adr_ItAf;
		tmp->Adr_ItAf= It;
	}
	return H;
}
int Search_It(Node_List*H,int x){
	Node_List *tmp;
	tmp=H;
	while(tmp!=NULL){
		if(tmp->Data == x)
			return 1;
		else
			tmp=tmp->Adr_ItAf;
	}
	return 0;			
}
Node_List *Random(int a){
	srand(time(NULL));
	Node_List *H, *p;
	H= NULL;
	int i =1;
	while (i<=a){
		p = new Node_List;
		p->Adr_ItAf = NULL;
		p->Data = rand()% a +1;
		while (Search_It(H,p->Data)){
			p->Data = rand() % a +1;
		}
		H = Add_Af(H,p);
		i++;
	}
	return H;
}
void In(Node_List *H){
	Node_List *tmp;
	if(H==NULL)
		printf("Danh sach NULL! ");
	else{
		tmp=H;
		while(tmp!=NULL){
			printf("%d\t",tmp->Data);
			tmp=tmp->Adr_ItAf;
		}
	}
}
main(){
	Node_List *Hd;
	int n;
	printf("MAI XUAN DUY 08\n");
	printf("Nhap n: ");
	scanf("%d",&n);
	Hd = Random(n);
	In(Hd);
}
