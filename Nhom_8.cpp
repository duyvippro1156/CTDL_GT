#include<stdio.h>
#include<string.h>
struct SinhVien{
	char TenSV[10],MaSV[13],Lop[10];
	float Dtb;
};
struct Node_BnTr
{
	SinhVien Data;
	Node_BnTr *Adr_TrL ,*Adr_TrR;
};
Node_BnTr*Add_Node(Node_BnTr*Tr,Node_BnTr*node)
{
	Node_BnTr*t,*T;
	if(Tr==NULL)
		Tr=node;
	else
	{
		t=Tr;
		while(t!=NULL)
			{
				T=t;
				if(t->Data.Dtb>node->Data.Dtb)
					t=t->Adr_TrL;
				else
					t=t->Adr_TrR;
			}
		if(T->Data.Dtb>node->Data.Dtb)
			T->Adr_TrL=node;
		else
			T->Adr_TrR=node;
	}
	return Tr;
}

// bo sung vao cay thong tin 1 sinh vien
Node_BnTr*BoSung(Node_BnTr*Tr)
{
	Node_BnTr*p;
	p = new Node_BnTr;
	fflush(stdin);
	printf("Nhap Ma sv: ");
	gets(p->Data.MaSV); 
	printf("Nhap Ho Ten sv: ");
	gets(p->Data.TenSV);
	printf("Nhap lop: ");
	gets(p->Data.Lop);
	printf("Nhap diem trung binh: ");
	scanf("%f",&p->Data.Dtb);
	p->Adr_TrL=NULL;
	p->Adr_TrR=NULL;
	Tr=Add_Node(Tr,p);
	return Tr;
}
//tao cay nhi phan
Node_BnTr* Nhap(Node_BnTr*Tree)
{
	Node_BnTr*p;
	int i;
	for(i=1;;i++)
	{	
		printf("\n ----------Nhap sinh vien thu: %d ------ \n",i);
		Tree = BoSung(Tree);
		char *yn;
		fflush(stdin);
		printf("Ban co muon nhap tiep (Y/N): ");
		scanf("%s",yn);
		if(( strcmp( yn , "N" ) == 0 ) || ( strcmp( yn , "n" ) == 0 ))
			return Tree;
	}
}
void BRW_Node_TGP(Node_BnTr*Tr)
{
	if(Tr!=NULL)
	{
		BRW_Node_TGP(Tr->Adr_TrL);
		printf(" %.13s |%.10s |%.10s |%.2f\n",Tr->Data.MaSV,Tr->Data.TenSV,Tr->Data.Lop,Tr->Data.Dtb);
		BRW_Node_TGP(Tr->Adr_TrR);
	}
}
//Dem diemtb >
int Dem_Dtb(Node_BnTr*Tr,float d)
{
	if(Tr!=NULL)
	{
		if(Tr->Data.Dtb>d)
			return 1+Dem_Dtb(Tr->Adr_TrL,d)+Dem_Dtb(Tr->Adr_TrR,d);
		else
			return Dem_Dtb(Tr->Adr_TrL,d)+Dem_Dtb(Tr->Adr_TrR,d);
	}
	return 0;
}
//In cay cac sinh vien co dtb>
void BRW_Dtb(Node_BnTr*Tr,float d)
{
	if(Tr!=NULL)
	{
		BRW_Dtb(Tr->Adr_TrL,d);
		if(Tr->Data.Dtb>d)
			printf(" %.13s | %.10s | %.10s | %.2f\n",Tr->Data.MaSV,Tr->Data.TenSV,Tr->Data.Lop,Tr->Data.Dtb);
		BRW_Dtb(Tr->Adr_TrR,d);
	}
}
//tim kiem
Node_BnTr *Search_Tr(Node_BnTr *Tr,float info)
{
	if(Tr==NULL)
		return NULL;
	else
	{
		Node_BnTr *tmp=Tr;
		while(tmp!=NULL && tmp->Data.Dtb>=info)
			tmp=tmp->Adr_TrL;
		if(tmp!=NULL)
			return tmp;
		else
			return NULL;
	}
}
//xoa
Node_BnTr *XoaGoc(Node_BnTr *Tr, Node_BnTr *tmp)
{
	Node_BnTr *R;
	if(tmp->Adr_TrL!=NULL)
	{
		Tr=Tr->Adr_TrL;
		R=tmp->Adr_TrR;
		tmp->Adr_TrL=NULL;
		tmp->Adr_TrR=NULL;
		tmp=Tr;
		while(tmp->Adr_TrR!=NULL)
			tmp=tmp->Adr_TrR;
		tmp->Adr_TrR=R;			
	}
	else
	{
		Tr=tmp->Adr_TrR;
		tmp->Adr_TrR=NULL;
	}
	return Tr;
}
Node_BnTr *XoaLa(Node_BnTr *Tr, Node_BnTr *tmp)
{
	Node_BnTr *t=Tr;
	while(t->Adr_TrL!=tmp && t->Adr_TrR!=tmp)
	{
		if(t->Data.Dtb>tmp->Data.Dtb)
			t=t->Adr_TrL;
		else
			t=t->Adr_TrR;
	}
	if(t->Adr_TrL==tmp)
		t->Adr_TrL=NULL;
	else
		t->Adr_TrR=NULL;
	return Tr;
}
Node_BnTr *XoaKoL(Node_BnTr *Tr, Node_BnTr *tmp)
{
	Node_BnTr *t=Tr;
	while(t->Adr_TrL!=tmp && t->Adr_TrR!=tmp)
	{
		if(t->Data.Dtb>tmp->Data.Dtb)
			t=t->Adr_TrL;
		else
			t=t->Adr_TrR;
	}
	if(t->Adr_TrL==tmp)
		t->Adr_TrL=tmp->Adr_TrR;
	else
		t->Adr_TrR=tmp->Adr_TrR;
	tmp->Adr_TrL=NULL;
	tmp->Adr_TrR=NULL;
	return Tr;
}
Node_BnTr *XoaKoR(Node_BnTr *Tr, Node_BnTr *tmp)
{
	Node_BnTr *t=Tr;
	while(t->Adr_TrL!=tmp && t->Adr_TrR!=tmp)
	{
		if(t->Data.Dtb>tmp->Data.Dtb)
			t=t->Adr_TrL;
		else
			t=t->Adr_TrR;
	}
	if(t->Adr_TrL==tmp)
		t->Adr_TrL=tmp->Adr_TrL;
	else
		t->Adr_TrR=tmp->Adr_TrL;
	tmp->Adr_TrL=NULL;
	tmp->Adr_TrR=NULL;
	return Tr;
}
Node_BnTr *XoaCoLR(Node_BnTr *Tr, Node_BnTr *tmp)
{
	Node_BnTr *t=Tr;
	while(t->Adr_TrL!=tmp && t->Adr_TrR!=tmp)
	{
		if(t->Data.Dtb>tmp->Data.Dtb)
			t=t->Adr_TrL;
		else
			t=t->Adr_TrR;
	}
	if(t->Adr_TrL==tmp)
	{
		t->Adr_TrL=tmp->Adr_TrL;
		t=t->Adr_TrL;	
	}
	else
	{
		t->Adr_TrR=tmp->Adr_TrL;
		t=t->Adr_TrR;	
	}
	while(t->Adr_TrR!=NULL)
		t=t->Adr_TrR;
	t->Adr_TrR=tmp->Adr_TrR;
	tmp->Adr_TrL=NULL;
	tmp->Adr_TrR=NULL;
	return Tr;
}
Node_BnTr *Xoa(Node_BnTr *Tr,float info)
{
	Node_BnTr *tmp= Search_Tr(Tr,info);
	while(tmp!=NULL)
	{
	if(tmp==Tr)
		Tr=XoaGoc(Tr,tmp);
	else
	{
		if(tmp->Adr_TrL==NULL && tmp->Adr_TrR==NULL)
			Tr=XoaLa(Tr,tmp);
		else
		{
			if(tmp->Adr_TrL!=NULL && tmp->Adr_TrR!=NULL)
				Tr=XoaCoLR(Tr,tmp);
			else
			{
				if(tmp->Adr_TrL!=NULL && tmp->Adr_TrR==NULL)
					Tr=XoaKoR(Tr,tmp);		
				else
					Tr=XoaKoL(Tr,tmp);
			}
		}
	}
	tmp= Search_Tr(Tr,info);
	}
	return Tr;
}
void menu()
{
	printf("\n=====================================================================\n");
    printf("1: Nhap danh sach sinh vien \n");
	printf("2: Dem so sinh vien co diem trung binh lon hon: \n");
	printf("3: In danh sach cac sinh vien co diem trung binh lon hon: \n");
	printf("4: Xoa sinh vien co diem trung binh nho hon:\n");
	printf("5: Bo sung mot sinh vien moi vao danh sach: \n");
	printf("6: Thoat\n");
	printf("\nSelect: ");
}
void display(Node_BnTr*Tree)
{	
	int choice;
	float d;
	do{
  		menu();
	    scanf("%d",&choice);
	    switch(choice){
			case 1:
			   	Tree=Nhap(NULL);
			   	BRW_Node_TGP(Tree);	
			    break;
			case 2:
				if(Dem_Dtb(Tree,d) == 0)
					printf("\nso sinh vien can dem trong danh sach la 0 ");
				else
				{
					printf("Dem so sinh vien co diem trung binh lon hon: ");
					scanf("%f",&d);
		 			printf("\nCay co %d SV co diem trung binh lon hon %0.2f \n",Dem_Dtb(Tree,d),d);
				}
			    break;
			case 3:
				printf("\n In danh sach cac sinh vien co diem trung binh lon hon:\n");
				scanf("%f",&d);
				BRW_Dtb(Tree,d);
				fflush(stdin);
				break;
			case 4: 
				printf("Xoa sinh vien co diem trung binh nho hon: \n");
				scanf("%f",&d);
				Tree=Xoa(Tree,d);
				BRW_Node_TGP(Tree);	
				break;
			case 5:
				printf("Bo sung mot sinh vien  \n");
				Tree=BoSung(Tree);
				BRW_Node_TGP(Tree);	
				break;
			case 6:
				printf("Thoat \n");
				break;
			default: 
				printf("Ban chon sai. Moi ban chon lai MENU!\n");
				break;
		}	
	}while(choice!=6);
}
main()
{
	Node_BnTr*Tree;
	display(Tree);	
}
