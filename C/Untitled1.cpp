#include<stdio.h>
struct dslkdoi{
	int index;
	dslkdoi *next;
	dslkdoi *prev;
};
dslkdoi *add(dslkdoi *first,dslkdoi *it)
{
	dslkdoi *temp;
	if(first == NULL)
		first = it;
	else
	{
		temp = first;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=it;
		it->prev=temp;
	}
	return first;
}
void input(dslkdoi **first,dslkdoi **last)
{
	int i;
	dslkdoi *it;
	*first = NULL;
	*last = NULL;
	for(i=1;i<=5;i++)
	{
		it = new dslkdoi;
		printf("nhap gtri thu %d: ",i);
		scanf("%d",&it->index);
		it->next=NULL;
		it->prev=NULL;
		*first = add(*first,it);
		*last = it;
	}
}
void output1(dslkdoi *first)
{
	dslkdoi *temp;
	if(first == NULL)
		printf("danh sach null");
	else
	{
		temp = new dslkdoi;
		temp=first;
		while(temp!= NULL)
		{
			printf("%5d||",temp->index);
			temp = temp->next;
		}
	}
}
void output2(dslkdoi *last)
{
	dslkdoi *temp;
	if(last == NULL)
		printf("danh sach null");
	else
	{
		temp = new dslkdoi;
		temp = last;
		while(temp!=NULL)
		{
			printf("%5d||",temp->index);
			temp = temp->prev;
		}
	}
}
void sapxep(dslkdoi *first)
{
	dslkdoi *p,*temp;
	p=first;
	while(p->next!=NULL)
	{
		temp=p->next;
		while(temp!=NULL)
		{
			int tmp;
			if(p->index>temp->index)
			{
				tmp=p->index;
				p->index=temp->index;
				temp->index=tmp;
			}
			temp=temp->next;
		}
		p = p->next;
	}
}
void deletenode(dslkdoi **first,dslkdoi **last)
{
	dslkdoi *p,*temp;
	p = *first;
	while(p!=NULL)
	{
		if(p->index==5)
		{
			if(p->prev==NULL)
			{
				temp = new dslkdoi;
				temp = p->next;
				if(temp==NULL)
				{
					*first =NULL;
					*last =NULL;
				}
				else
				{
					temp->prev=NULL;
					*first = temp;
				}
			}
			else
			{
				temp = new dslkdoi;
				temp=*first;
				while(temp->next!=p)
					temp=temp->next;
				if(p->next==NULL)
				{
					temp->next=NULL;
					*last=temp;
				}
				else
				{
					temp->next=p->next;
					temp=*last;
					while(temp->prev!=p)
						temp = temp->prev;
					temp->prev=p->prev;
				}
			}
		}
		p=p->next;
	}
}
void chen(dslkdoi **first,dslkdoi **last,int info)
{
	dslkdoi *p,*temp,*tmp;
	p = new dslkdoi;
	p->index=info;
	if(last==NULL)
	{
		*last = p;
		*first =p;
	}
	else
	{
		temp = *last;
		while(temp!=NULL && temp->index>info)
		{
			tmp = temp;
			temp=temp->prev;
		}
		if(temp==*last)
		{
			p->prev=*last;
			temp->next=p;
			p->next=NULL;
			*last=p;
		}
		else
			if(temp==NULL)
			{
				p->next=*first;
				tmp->prev=p;
				p->prev=NULL;
				*first = p;
			}
			else
			{
				tmp->prev=p;
				p->next=tmp;
				temp->next=p;
				p->prev=temp;
			}
	}
}
main()
{
	dslkdoi *first,*last;
	input(&first,&last);
	output1(first);
	printf("\n");
	output2(last);
	sapxep(first);
	printf("\n");
	output1(first);
	printf("\n");
	output2(last);
	deletenode(&first,&last);
	printf("\n");
	output1(first);
	printf("\n");
	output2(last);
	chen(&first,&last,3);
	printf("\n");
	output1(first);
	printf("\n");
	output2(last);
	
}
