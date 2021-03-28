#include<stdio.h>
struct Node_List{
	char Data;
	Node_List *Adr_ItAf;
}; 
Node_List *Add_Af(Node_List *H, Node_List *It){
	Node_List *tmp;
	if (H==NULL)
		H=It;
	else{
		tmp=H;
		while(tmp->Adr_ItAf!=NULL)
			tmp=tmp->Adr_ItAf;
		tmp->Adr_ItAf=It;								  
	}
	return H;
}
void BRW_IT(Node_List *H){
	Node_List *tmp;
	if(H==NULL){
		printf("danh sach Null");
	}
	else{
		tmp=H;
		while(tmp!=NULL){
			printf("%c ",tmp->Data);
			tmp=tmp->Adr_ItAf;	
		}
	}
}
void NHAP(Node_List **H){
	int i,n;
   	Node_List *It;
	printf("nhap bao nhieu ki tu: ");
	scanf("%d",&n);

	*H=NULL;		
	for(i=1;i<=n;i++){
	    It=new Node_List;
		printf("nhap ky tu thu %d:",i);
		fflush(stdin);
		scanf("%c", &It->Data);
		It->Adr_ItAf=NULL;
		*H=Add_Af(*H,It);
	}	
}
main()
{
		Node_List *Hd;				
		NHAP(&Hd);
		BRW_IT(Hd);				 	
}

