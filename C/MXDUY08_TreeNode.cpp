#include<stdio.h>
#include<string.h>
struct Node_BnTr8{
	char data8[10];
	Node_BnTr8 *adr_TrL8, *adr_TrR8;
};
void BRW_Node1_8(Node_BnTr8 *Tr8){
	if(Tr8!=NULL){
		printf("%s   ",Tr8->data8);
		BRW_Node1_8(Tr8->adr_TrL8);
		BRW_Node1_8(Tr8->adr_TrR8);	
	}
}
void BRW_Node2_8(Node_BnTr8 *Tr8){
	if(Tr8!=NULL){
		BRW_Node2_8(Tr8->adr_TrL8);
		BRW_Node2_8(Tr8->adr_TrR8);
		printf("%s   ",Tr8->data8);	
	}
}
Node_BnTr8 *Add8(Node_BnTr8 *Tr8, Node_BnTr8 *node8){
	Node_BnTr8 *tmp8, *TMP8;
	if(Tr8==NULL)
		Tr8=node8;
	else{
		tmp8= Tr8;
		while(tmp8!=NULL){
			TMP8=tmp8;
			if(strcmp(tmp8->data8,node8->data8)>0)
				tmp8=tmp8->adr_TrL8;
			else
				tmp8=tmp8->adr_TrR8;
		}
		if(strcmp(TMP8->data8,node8->data8)>0)
			TMP8->adr_TrL8=node8;
		else
			TMP8->adr_TrR8=node8;
	}
	return Tr8;
}
Node_BnTr8 *Input8(Node_BnTr8 *tr8){
	Node_BnTr8 *p8;
	tr8=NULL;
	do{
		p8=new Node_BnTr8;
		fflush(stdin);
		printf("Nhap mot ten sinh vien, nhap so 0 de ket thuc: ");
		scanf("%s",&p8->data8);
		p8->adr_TrL8=NULL;
		p8->adr_TrR8=NULL;
		if(strcmp(p8->data8,"0")!=0)
			tr8=Add8(tr8,p8);
	}
	while(strcmp(p8->data8,"0")!=0);
	return tr8;
}
int count8(Node_BnTr8 *Tr8){
	if(Tr8==NULL)
		return 0;
	else
		return 1+count8(Tr8->adr_TrL8)+count8(Tr8->adr_TrR8);
}
int countif8(Node_BnTr8 *Tr8,char info8[10]){
	if(Tr8==NULL)
		return 0;
	else
		if(strcmp(Tr8->data8,info8)==0)
			return 1+countif8(Tr8->adr_TrL8,info8)+countif8(Tr8->adr_TrR8,info8);
		else
			return countif8(Tr8->adr_TrL8,info8)+countif8(Tr8->adr_TrR8,info8);
}
main(){
	Node_BnTr8 *tree8;
	char infor8[10];
	printf("Mai Xuan Duy _ 08\n");
	tree8=Input8(tree8);
	printf("\n");
	printf("\nIn danh sach theo thu tu Goc Trai Phai!\n");
	BRW_Node1_8(tree8);
	printf("\n");
	printf("\nIn danh sach theo thu tu Trai Phai Goc!\n");
	BRW_Node2_8(tree8);
	printf("\n");
	printf("\nSo sinh vien trong danh sach la: %d",count8(tree8));
	printf("\nNhap ten sinh vien can dem: ");
	fflush(stdin);
	gets(infor8);
	if(countif8(tree8,infor8)==0)
		printf("\nSo sinh vien can dem trong danh sach la 0");
	else
		printf("\nSo sinh vien can dem trong danh sach la: %d",countif8(tree8,infor8));
}
