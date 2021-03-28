#include<stdio.h>
struct Node_BnTr{
	int Data_8;
	Node_BnTr *ADR_L8, *ADR_R8;
};
Node_BnTr *Add8(Node_BnTr *Tr_8, Node_BnTr *Node_8){
	if(Tr_8==NULL)
		Tr_8=Node_8;
	else{
		Node_BnTr *tmp_8,*TMP_8;
		tmp_8=Tr_8;
		while(tmp_8!=NULL){
			TMP_8=tmp_8;
			if(tmp_8->Data_8>Node_8->Data_8)
				tmp_8=tmp_8->ADR_L8;
			else
				tmp_8=tmp_8->ADR_R8;
		}
		if(TMP_8->Data_8>Node_8->Data_8)
			TMP_8->ADR_L8=Node_8;
		else
			TMP_8->ADR_R8=Node_8;
	}	
	return Tr_8;
}
Node_BnTr *Input(Node_BnTr *Tr_8, int n_8){
	Tr_8=NULL;
	for(int i=1;i<=n_8;++i){
		fflush(stdin);
		Node_BnTr *Node_8= new Node_BnTr();
		printf("Nhap so thu %d: " ,i);
		scanf("%d" ,&Node_8->Data_8);
		Node_8->ADR_L8=NULL;
		Node_8->ADR_R8=NULL;
		Tr_8=Add8(Tr_8,Node_8);
	}
	return Tr_8;
}
void Output(Node_BnTr *Tr_8){
	if(Tr_8!=NULL){
		Output(Tr_8->ADR_L8);
		Output(Tr_8->ADR_R8);
		printf(" %d ",Tr_8->Data_8);
	}
}
Node_BnTr *Search_Tr(Node_BnTr *Tr_8,int info){
	if(Tr_8==NULL)
		return NULL;
	else{
		Node_BnTr *tmp_8=Tr_8;
		while(tmp_8!=NULL && tmp_8->Data_8!=info){
			if(tmp_8->Data_8>info)
				tmp_8=tmp_8->ADR_L8;
			else
				tmp_8=tmp_8->ADR_R8;
		}
		if(tmp_8!=NULL)
			return tmp_8;
		else
			return NULL;
	}
}
Node_BnTr *XoaGoc(Node_BnTr *Tr_8, Node_BnTr *tmp_8){
	Node_BnTr *R8;
	if(tmp_8->ADR_L8!=NULL){
		Tr_8=Tr_8->ADR_L8;
		R8=tmp_8->ADR_R8;
		tmp_8->ADR_L8=NULL;
		tmp_8->ADR_R8=NULL;
		tmp_8=Tr_8;
		while(tmp_8->ADR_R8!=NULL)
			tmp_8=tmp_8->ADR_R8;
		tmp_8->ADR_R8=R8;			
	}
	else{
		Tr_8=tmp_8->ADR_R8;
		tmp_8->ADR_R8=NULL;
	}
	return Tr_8;
}
Node_BnTr *XoaLa(Node_BnTr *Tr_8, Node_BnTr *tmp_8){
	Node_BnTr *t_8;
	t_8=Tr_8;
	while(t_8->ADR_L8!=tmp_8 && t_8->ADR_R8!=tmp_8){
		if(t_8->Data_8>tmp_8->Data_8)
			t_8=t_8->ADR_L8;
		else
			t_8=t_8->ADR_R8;
	}
	if(t_8->ADR_L8==tmp_8)
		t_8->ADR_L8=NULL;
	else
		t_8->ADR_R8=NULL;
	return Tr_8;
}
Node_BnTr *XoaKoL(Node_BnTr *Tr_8, Node_BnTr *tmp_8){
	Node_BnTr *t_8;
	t_8=Tr_8;
	while(t_8->ADR_L8!=tmp_8 && t_8->ADR_R8!=tmp_8){
		if(t_8->Data_8>tmp_8->Data_8)
			t_8=t_8->ADR_L8;
		else
			t_8=t_8->ADR_R8;
	}
	if(t_8->ADR_L8==tmp_8)
		t_8->ADR_L8=tmp_8->ADR_R8;
	else
		t_8->ADR_R8=tmp_8->ADR_R8;
	tmp_8->ADR_L8=NULL;
	tmp_8->ADR_R8=NULL;
	return Tr_8;
}
Node_BnTr *XoaKoR(Node_BnTr *Tr_8, Node_BnTr *tmp_8){
	Node_BnTr *t_8;
	t_8=Tr_8;
	while(t_8->ADR_L8!=tmp_8 && t_8->ADR_R8!=tmp_8){
		if(t_8->Data_8>tmp_8->Data_8)
			t_8=t_8->ADR_L8;
		else
			t_8=t_8->ADR_R8;
	}
	if(t_8->ADR_L8==tmp_8)
		t_8->ADR_L8=tmp_8->ADR_L8;
	else
		t_8->ADR_R8=tmp_8->ADR_L8;
	tmp_8->ADR_L8=NULL;
	tmp_8->ADR_R8=NULL;
	return Tr_8;
}
Node_BnTr *XoaCoLR(Node_BnTr *Tr_8, Node_BnTr *tmp_8){
	Node_BnTr *t_8;
	t_8=Tr_8;
	while(t_8->ADR_L8!=tmp_8 && t_8->ADR_R8!=tmp_8){
		if(t_8->Data_8>tmp_8->Data_8)
			t_8=t_8->ADR_L8;
		else
			t_8=t_8->ADR_R8;
	}
	if(t_8->ADR_L8==tmp_8){
		t_8->ADR_L8=tmp_8->ADR_L8;
		t_8=t_8->ADR_L8;	
	}
	else{
		t_8->ADR_R8=tmp_8->ADR_L8;
		t_8=t_8->ADR_R8;	
	}
	while(t_8->ADR_R8!=NULL)
		t_8=t_8->ADR_R8;
	t_8->ADR_R8=tmp_8->ADR_R8;
	tmp_8->ADR_L8=NULL;
	tmp_8->ADR_R8=NULL;
	return Tr_8;
}
Node_BnTr *Xoa(Node_BnTr *Tr_8, int info){
	while(Search_Tr(Tr_8,info)!= NULL){
		Node_BnTr *tmp_8;
		tmp_8= Search_Tr(Tr_8,info);
		if(tmp_8==Tr_8){
			Tr_8=XoaGoc(Tr_8,tmp_8);
			printf("Xoa Node goc\n");
		}
		else{
			if(tmp_8->ADR_L8==NULL && tmp_8->ADR_R8==NULL){
				Tr_8=XoaLa(Tr_8,tmp_8);
				printf("Xoa Node la\n");
			}
			else{
				if(tmp_8->ADR_L8!=NULL && tmp_8->ADR_R8!=NULL){
					printf("Xoa Node co cay con ben trai va phai\n");
					Tr_8=XoaCoLR(Tr_8,tmp_8);
				}
				else{
					if(tmp_8->ADR_L8!=NULL && tmp_8->ADR_R8==NULL){
						printf("Xoa Node ko co cay con ben phai\n");
						Tr_8=XoaKoR(Tr_8,tmp_8);
					}	
					else{
						printf("Xoa Node ko co cay con ben trai\n");
						Tr_8=XoaKoL(Tr_8,tmp_8);}
				}
			}
		}
	}
	return Tr_8;
}
main()
{
	Node_BnTr *Tr8,*c;
	int n_8,info;
	printf("Mai Xuan Duy _ 08\n");
	printf("\nNhap so phan tu: ");
	scanf("%d" ,&n_8);
	printf("\n");
	Tr8=Input(Tr8,n_8);
	printf("\nDuyet trai phai goc:");
	Output(Tr8);
	printf("\n");
	printf("\nNhap so can xoa: ");
	scanf("%d" ,&info);
	printf("\n");
	Tr8=Xoa(Tr8,info);
	printf("Duyet lai");
	Output(Tr8);
}
