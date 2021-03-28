#include<stdio.h>
struct dathuc{
	int coso, mu;
};
struct Node_list{
	dathuc data;
	Node_list*Adr_Itaf;
};
Node_list*Adr_It(Node_list*h,Node_list*It)
{
	Node_list*tmp;
	if(h==NULL)
		h=It;
	else 
		{
		tmp=h;
		while (tmp->Adr_Itaf!=NULL)
			tmp=tmp->Adr_Itaf;
		tmp->Adr_Itaf=It;
		}
	return h;
}
main()
{
	Node_list *hd, *d, *tmp;
	int i, n;
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	hd=NULL;
	for (i=1;i<=n;i++)
	{
		d= new Node_list;
		printf("Nhap phan tu thu %d:\n",i);
		printf("Nhap co so: ");
		scanf("%d",&d->data.coso);
		printf("Nhap so mu: ");
		scanf("%d",&d->data.mu);
		d->Adr_Itaf=NULL;
		hd=Adr_It(hd,d);
	}
	tmp=hd;
	printf("Mai Xuan Duy _ 08\n");
	do
	{
		if(tmp->data.coso%2==0)
		{
			printf("+");
			if(tmp->data.coso==0)
				printf("      ");
			else
			{
				if(tmp->data.mu==0)
					printf("%d",tmp->data.coso);
				else
					printf("(%d)X^%d",tmp->data.coso,tmp->data.mu);
			}
		}
		tmp=tmp->Adr_Itaf;
	}
	while (tmp!=NULL);
}

