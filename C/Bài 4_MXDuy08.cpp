#include<stdio.h>
#include <string.h>
struct SinhVien {
	char masv[15], tensv[20], lop[5];
	float dtb;
};
struct Node_List {
	SinhVien data;
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
	int i,n;
	H=NULL;
	Node_List *s;
	printf("\nNhap so sinh vien: ");
	scanf("%d" ,&n);
	for(i=1;i<=n;++i){
		fflush(stdin);
		s= new Node_List;
		printf("Sinh vien thu %d: \n" ,i);
		printf("MaSV: ");      
		gets(s->data.masv);
		printf("TenSV: ");
		gets(s->data.tensv);
		printf("Lop: ");
		gets(s->data.lop);
		printf("Diem TB: ");
		scanf("%f" ,&s->data.dtb);
		printf("-----------------\n");
		s->Adr_ItAf=NULL;
		H=Add_Af(H,s);
	}
	return H;                    
}
void In(Node_List *H){
	Node_List *tmp;
	if(H==NULL)
		printf("\nDanh sach NULL\n");
	else{
		tmp=H;
		while(tmp!=NULL){
			printf("\n%15s | %15s | %5s | %2.2f ",tmp->data.masv, tmp->data.tensv, tmp->data.lop, tmp->data.dtb);
			tmp=tmp->Adr_ItAf;
		}
	}	
}
Node_List *Search_It(Node_List *H,char info[]){
	Node_List *tmp;
	tmp=H;
	while(tmp!=NULL){
		if(strcmp(tmp->data.lop,info)==0)
			return tmp;
		tmp=tmp->Adr_ItAf;
	}
	return NULL;			
}
Node_List *Delete_Node(Node_List *H, char info[]){
	Node_List *p,*tmp;
	p=Search_It(H,info);
	if(p==NULL)
		return H;
	if(p==H){
		H=H->Adr_ItAf;
		p->Adr_ItAf=NULL;
		return Delete_Node(H,info);
	}
	else{
		tmp=H;
		while(tmp->Adr_ItAf!=p)
			tmp=tmp->Adr_ItAf;
		tmp->Adr_ItAf=p->Adr_ItAf;
		p->Adr_ItAf=NULL;
		return Delete_Node(H,info);
	}
}
Node_List *List1(Node_List *H){
	Node_List *Head,*tmp,*p;
	Head=NULL;
	tmp=H;
	while(tmp!=NULL){
		if(tmp->data.dtb<5){
			p=new Node_List;
			p->data=tmp->data;
			p->Adr_ItAf=NULL;
			Head=Add_Af(Head,p);
		}
		tmp=tmp->Adr_ItAf;
	}
	return Head;
}
Node_List *List2(Node_List *H){
	Node_List *Head,*tmp,*p;
	Head=NULL;
	tmp=H;
	while(tmp!=NULL){
		if(tmp->data.dtb>=5){
			p=new Node_List;
			p->data=tmp->data;
			p->Adr_ItAf=NULL;
			Head=Add_Af(Head,p);
		}
		tmp=tmp->Adr_ItAf;
	}
	return Head;
}
main(){
	int n;
	Node_List *Hd,*Hd1,*Hd2;
	char s[10];
	printf("MAI XUAN DUY 08\n");
	Hd=Nhap(Hd);
	In(Hd);
	printf("\nNhap 1 neu muon xoa, nhap 2 neu muon in danh sach: ");
	scanf("%d",&n);
	switch(n){
		case 1:	fflush(stdin);
				printf("\nNhap lop muon xoa: ");
				gets(s);
				Hd=Delete_Node(Hd,s);
				printf("Danh sach sau khi xoa:\n");
				In(Hd);
				break;
		case 2:	Hd1=List1(Hd);
				printf("\nDanh sach sinh vien co dTB <5\n");
				In(Hd1);
				Hd2=List2(Hd);
				printf("\nDanh sach sinh vien co dTB >=5 \n");
				In(Hd2);
				break;
	}
}
