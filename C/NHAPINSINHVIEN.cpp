#include <stdio.h>
#include <string.h>
struct SinhVien
	{
		char masv[13], tensv[20], lop[8];
		float dtb;
	};
struct Node_List 
	{
		SinhVien data;
		Node_List *Adr_ItAf;
	};
Node_List *Add_Af(Node_List *H, Node_List *p)
{
	if(H==NULL)
		H=p;
	else
		{
			Node_List *tmp=H;
			while(tmp->Adr_ItAf!=NULL)
				tmp=tmp->Adr_ItAf;
			tmp->Adr_ItAf=p;
		}
	return H;
}
Node_List *Input(Node_List *H,int n)
{
	for(int i=1;i<=n;++i)
	{
		fflush(stdin);
		Node_List *It= new Node_List;
		printf("\nSinh vien thu %d: " ,i);
		printf("\nNhap ma sinh vien: ");
		gets(It->data.masv);
		printf("Nhap ten sinh vien: ");
		gets(It->data.tensv);
		printf("Nhap lop sinh vien: ");
		gets(It->data.lop);
		printf("Nhap diem trung binh: ");
		scanf("%f" ,&It->data.dtb);
		It->Adr_ItAf=NULL;
		H=Add_Af(H,It);
	}
	return H;
}
void display(Node_List *H)
{
	Node_List *tmp=H;
	if(H==NULL)
		printf("\n\nDanh sach NULL\n\n");
	while(tmp!=NULL)
	{
		printf("\n\n %13s | %20s | %8s | %4.2f |" ,tmp->data.masv ,tmp->data.tensv ,tmp->data.lop ,tmp->data.dtb) ;
		tmp=tmp->Adr_ItAf;
	}
}
main()
{
	Node_List *Hd;
	int n;
	char lop[8];
	printf("\n VoThanhLuan_22 \n");
	printf("\nNhap so phan tu: ");
	scanf("%d" ,&n);
	Hd= Input(NULL,n)	;
	display(Hd);
}
