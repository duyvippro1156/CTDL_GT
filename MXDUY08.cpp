#include<stdio.h>
#include<string.h>
struct SinhVien{
	char TenSV[20],MaSV[4],Lop[5];
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
Node_BnTr* Nhap(Node_BnTr*Tree)
{
	Node_BnTr*p;
	int i;
	for(i=1;;i++)
	{
		Nhap:
		p=new Node_BnTr;
		fflush(stdin);
		printf("Nhap sinh vien thu %d:\n",i);
		printf("Nhap ma sinh vien: ");
		gets(p->Data.MaSV);
		printf("Nhap ten sinh vien: ");
		gets(p->Data.TenSV);
		printf("Nhap lop sinh vien: ");
		gets(p->Data.Lop);
		printf("Nhap diem trung binh sinh vien: ");
		scanf("%f",&p->Data.Dtb);
		p->Adr_TrL=NULL;
		p->Adr_TrR=NULL;
		Tree=Add_Node(Tree,p);
		char yn;
		fflush(stdin);
		printf("Ban co muon nhap tiep (Y/N): ");
		scanf("%c" ,&yn);
		if(yn=='n' || yn=='N')
			return Tree;
	}
}
void BRW_Node_TGP(Node_BnTr*Tr)
{
	if(Tr!=NULL)
	{
		BRW_Node_TGP(Tr->Adr_TrL);
		printf(" %.4s | %20s |%5s |%.2f\n",Tr->Data.MaSV,Tr->Data.TenSV,Tr->Data.Lop,Tr->Data.Dtb);
		BRW_Node_TGP(Tr->Adr_TrR);
	}
}
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
main(){
	printf("Mai Xuan Duy _ 08\n");
	Node_BnTr*Tree;
	float d;
	Tree=Nhap(NULL);
	BRW_Node_TGP(Tree);
	printf("Nhap diem trung binh can dem:");
	scanf("%f",&d);
	if(Dem_Dtb(Tree,d) == 0)
		printf("\nKhong ");
	else
		printf("\nCay co %d SV co diem trung binh lon hon %f \n",Dem_Dtb(Tree,d),d);
}
