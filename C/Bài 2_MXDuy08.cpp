#include<stdio.h>
struct Dathuc{
	int coso, mu;
};
struct Node_List{
	Dathuc data;
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
Node_List *Nhap(Node_List *H ,Node_List*p)
{       
    int i,n;
    H=NULL;
	printf("Nhap so phan tu: ");
    scanf("%d" ,&n);	    
	for( i=1;i<=n;i++)  
	{	
	    p= new Node_List;
		printf("Nhap co so cua phan tu thu %d: ",i);
		scanf("%d",&p->data.coso);
		printf("Nhap so mu cua phan tu thu %d: ",i );
		scanf("%d",&p->data.mu);
		printf("\n");
		p->Adr_ItAf=NULL;
		H=Add_Af(H,p);
	}
	return H;
}
void In(Node_List *H){
	Node_List *tmp;	   
    tmp=H;
    printf("-------------------------------\n");
    printf("Da thuc: ");
	do{
		if(tmp->data.coso%2==0){
			printf("+");
			if(tmp->data.coso==0)
				printf("      ");
			else{
				if(tmp->data.mu==0)
					printf("%d",tmp->data.coso);
				else
					printf("(%d)X^%d",tmp->data.coso,tmp->data.mu);
			}
		}
		tmp=tmp->Adr_ItAf;
	}
	while (tmp!=NULL);
}
main()
{
	Node_List *Hd,*p;	
  	printf("MAI XUAN DUY 08\n");	
	Hd=Nhap(Hd,p);
	In(Hd);	
}

