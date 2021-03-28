#include<stdio.h>
struct Node_BnTr{
	int data;
	Node_BnTr *adr_TrL, *adr_TrR;
};
void BRW_Node(Node_BnTr *Tr){
	if(Tr!=NULL){
		BRW_Node(Tr->adr_TrL);
		printf("%d   ",Tr->data);
		BRW_Node(Tr->adr_TrR);	
	}
}
Node_BnTr *Add(Node_BnTr *Tr, Node_BnTr *node){
	Node_BnTr *tmp, *TMP;
	if(Tr==NULL)
		Tr=node;
	else{
		tmp= Tr;
		while(tmp!=NULL){
			TMP=tmp;
			if(tmp->data>node->data)
				tmp=tmp->adr_TrL;
			else
				tmp=tmp->adr_TrR;
		}
		if(TMP->data>node->data)
			TMP->adr_TrL=node;
		else
			TMP->adr_TrR=node;
	}
	return Tr;
}
Node_BnTr *Input(Node_BnTr *tr){
	Node_BnTr *p;
	tr=NULL;
	do{
		p=new Node_BnTr;
		printf("Nhap 1 so khac 0: ");
		scanf("%d",&p->data);
		p->adr_TrL=NULL;
		p->adr_TrR=NULL;
		if(p->data!=0)
			tr=Add(tr,p);
	}
	while(p->data!=0);
	return tr;
}
main(){
	Node_BnTr *tree;
	tree=Input(tree);
	BRW_Node(tree);	
}
