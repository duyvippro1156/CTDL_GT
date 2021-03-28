#include<stdio.h>
struct List{
	int data;
	List*Adr_Itaf;
};
List *Adr_It(List*H, List*It)
{
	List*tmp;
	if (H==NULL)
		H=It;
	else 
	{
		tmp=H;
		while (tmp->Adr_Itaf != NULL)
			tmp = tmp->Adr_Itaf;
		tmp->Adr_Itaf = It;
	}
	return H;	
}
main()
{
	List *hd, *t, *p;
	int i;
	hd = NULL;
	for(i=1; ;i++)
		{
		p=new List;
		printf("nhap so thu %d: ",i);
		scanf("%d",&p->data);
		if(p->data==0)
			break;
		p->Adr_Itaf=NULL;
		hd=Adr_It(hd,p);
		}
	printf("Mai Xuan Duy - 08\n");
	t=hd;
	do
		{
		printf("%d ",t->data);
		t=t->Adr_Itaf;
		}
	while (t!=hd);
}
