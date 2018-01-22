#include<iostream>
using namespace std;

struct node
{
	int info;
	node *next;
};

void insert(node **list,node *temp)
{
	if(*list==NULL)
	{
		temp->next=temp;
		*list=temp;
	}
	else
	{
		node *x=(*list)->next;
		temp->next=x;
		(*list)->next=temp;
		for(int i=0;i<=temp->info;i++)
			(*list)=(*list)->next;
	}
}
		

int main()
{
	node *list=NULL;
	int t,n,y,s[50000];
	cin>>t;
	while(t--)
	{
		list=NULL;
		cin>>n;
		y=n;
		while(n!=0)
		{
			node *temp=new node;
			temp->info=n;
			temp->next=NULL;
			insert(&list,temp);
			n--;
		}
		for(int i=0;i<y;i++)
		{
			s[i]=list->info;
			list=list->next;
		}
		int pos=0;
		for(int i=0;i<y;i++)
		{
			cout<<s[pos]<<" ";
			if(pos==0)
				pos=y-1;
			else
				pos--;
		}			
	}
}