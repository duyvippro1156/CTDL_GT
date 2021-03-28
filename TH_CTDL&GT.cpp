#include<stdio.h>
struct Node_BnTr{
	int Data;
	Node_BnTr *ADR_L, *ADR_R;
};
Node_BnTr *Add(Node_BnTr *Tr, Node_BnTr *Node){
	if(Tr==NULL)
		Tr=Node;
	else{
		Node_BnTr *tmp,*TMP;
		tmp=Tr;
		while(tmp!=NULL){
			TMP=tmp;
			if(tmp->Data>Node->Data)
				tmp=tmp->ADR_L;
			else
				tmp=tmp->ADR_R;
		}
		if(TMP->Data>Node->Data)
			TMP->ADR_L=Node;
		else
			TMP->ADR_R=Node;
	}	
	return Tr;
}
Node_BnTr *Input(Node_BnTr *Tr, int n){
	Tr=NULL;
	for(int i=1;i<=n;++i){
		fflush(stdin);
		Node_BnTr *Node= new Node_BnTr();
		printf("Nhap so thu %d: " ,i);
		scanf("%d" ,&Node->Data);
		Node->ADR_L=NULL;
		Node->ADR_R=NULL;
		Tr=Add(Tr,Node);
	}
	return Tr;
}
void Output(Node_BnTr *Tr){
	if(Tr!=NULL){
		Output(Tr->ADR_L);
		Output(Tr->ADR_R);
		printf(" %d ",Tr->Data);
	}
}
Node_BnTr *Search_Tr(Node_BnTr *Tr,int info){
	if(Tr==NULL)
		return NULL;
	else{
		Node_BnTr *tmp=Tr;
		while(tmp!=NULL && tmp->Data!=info){
			if(tmp->Data>info)
				tmp=tmp->ADR_L;
			else
				tmp=tmp->ADR_R;
		}
		if(tmp!=NULL)
			return tmp;
		else
			return NULL;
	}
}
Node_BnTr *XoaGoc(Node_BnTr *Tr, Node_BnTr *tmp){
	Node_BnTr *R;
	if(tmp->ADR_L!=NULL){
		Tr=Tr->ADR_L;
		R=tmp->ADR_R;
		tmp->ADR_L=NULL;
		tmp->ADR_R=NULL;
		tmp=Tr;
		while(tmp->ADR_R!=NULL)
			tmp=tmp->ADR_R;
		tmp->ADR_R=R;			
	}
	else{
		Tr=tmp->ADR_R;
		tmp->ADR_R=NULL;
	}
	return Tr;
}
Node_BnTr *XoaLa(Node_BnTr *Tr, Node_BnTr *tmp){
	Node_BnTr *t;
	t=Tr;
	while(t->ADR_L!=tmp && t->ADR_R!=tmp){
		if(t->Data>tmp->Data)
			t=t->ADR_L;
		else
			t=t->ADR_R;
	}
	if(t->ADR_L==tmp)
		t->ADR_L=NULL;
	else
		t->ADR_R=NULL;
	return Tr;
}
Node_BnTr *XoaKoL(Node_BnTr *Tr, Node_BnTr *tmp){
	Node_BnTr *t;
	t=Tr;
	while(t->ADR_L!=tmp && t->ADR_R!=tmp){
		if(t->Data>tmp->Data)
			t=t->ADR_L;
		else
			t=t->ADR_R;
	}
	if(t->ADR_L==tmp)
		t->ADR_L=tmp->ADR_R;
	else
		t->ADR_R=tmp->ADR_R;
	tmp->ADR_L=NULL;
	tmp->ADR_R=NULL;
	return Tr;
}
Node_BnTr *XoaKoR(Node_BnTr *Tr, Node_BnTr *tmp){
	Node_BnTr *t;
	t=Tr;
	while(t->ADR_L!=tmp && t->ADR_R!=tmp){
		if(t->Data>tmp->Data)
			t=t->ADR_L;
		else
			t=t->ADR_R;
	}
	if(t->ADR_L==tmp)
		t->ADR_L=tmp->ADR_L;
	else
		t->ADR_R=tmp->ADR_L;
	tmp->ADR_L=NULL;
	tmp->ADR_R=NULL;
	return Tr;
}
Node_BnTr *XoaCoLR(Node_BnTr *Tr, Node_BnTr *tmp){
	Node_BnTr *t;
	t=Tr;
	while(t->ADR_L!=tmp && t->ADR_R!=tmp){
		if(t->Data>tmp->Data)
			t=t->ADR_L;
		else
			t=t->ADR_R;
	}
	if(t->ADR_L==tmp){
		t->ADR_L=tmp->ADR_L;
		t=t->ADR_L;	
	}
	else{
		t->ADR_R=tmp->ADR_L;
		t=t->ADR_R;	
	}
	while(t->ADR_R!=NULL)
		t=t->ADR_R;
	t->ADR_R=tmp->ADR_R;
	tmp->ADR_L=NULL;
	tmp->ADR_R=NULL;
	return Tr;
}
Node_BnTr *Xoa(Node_BnTr *Tr, int info){
	while(Search_Tr(Tr,info)!= NULL){
		Node_BnTr *tmp;
		tmp= Search_Tr(Tr,info);
		if(tmp==Tr)
			Tr=XoaGoc(Tr,tmp);
		else{
			if(tmp->ADR_L==NULL && tmp->ADR_R==NULL)
				Tr=XoaLa(Tr,tmp);
			else{
				if(tmp->ADR_L!=NULL && tmp->ADR_R!=NULL)
					Tr=XoaCoLR(Tr,tmp);
				else{
					if(tmp->ADR_L!=NULL && tmp->ADR_R==NULL)
						Tr=XoaKoR(Tr,tmp);
					else
						Tr=XoaKoL(Tr,tmp);
				}
			}
		}
	}
	return Tr;
}
main()
{
	Node_BnTr *Tr,*c;
	int n_,info;
	printf("\nNhap so phan tu: ");
	scanf("%d" ,&n_);
	printf("\n");
	Tr=Input(Tr,n_);
	printf("\nDuyet trai phai goc:");
	Output(Tr);
	printf("\n");
	printf("\nNhap so can xoa: ");
	scanf("%d" ,&info);
	printf("\n");
	Tr=Xoa(Tr,info);
	printf("Duyet lai");
	Output(Tr);
}
