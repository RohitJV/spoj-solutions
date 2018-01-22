#include<iostream>
using namespace std;

struct node
{
	int z;
	int info;
	node *next;
};

void insert(node **q,int a,int b)
{
     node *temp=new node;
     temp->info=a;
     temp->next=NULL;
     temp->z=b;
     if(*q==NULL)
                 *q=temp;
     else
     {
         node *t=*q;
         node *p=NULL;
         while(t!=NULL && t->info<temp->info)
         {
                       p=t;
                       t=t->next;
         }
         if(t==NULL)
                    p->next=temp;
         else
         {
             if(p==NULL)
                        *q=temp;
             else 
                        p->next=temp;
             temp->next=t;
         }
     }
}
                    
int main()
{
	long int t,n,x,y;
	cin>>t;
	while(t--)
	{
             long int max=0,sum=0;
        node *q=NULL;
		cin>>n;
		while(n--)
		{
			cin>>x>>y;
			insert(&q,x,1);
			insert(&q,y,-1);
		}
		while(q!=NULL)
	    { 
                  sum=sum+q->z;
                  if(sum>max)
                             max=sum;
                  q=q->next;
        }
        	cout<<max<<"\n";
	}
}
		
