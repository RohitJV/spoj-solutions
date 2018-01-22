#include<iostream>
using namespace std;

struct stack
{
       int top;
       int items[10000];
};

void push(stack *s,int x)
{
     s->top++;
     s->items[s->top]=x;
}

int pop(stack *s)
{
     return(s->items[s->top--]);
}

int main()
{
    int t,n,i;
    stack side,main;
    while(1)
    {
            cin>>t;
            if(t==0)
                    break;
            side.top=-1;
            main.top=-1;
            for(i=0;i<t;i++)
            {
                            cin>>n;
                            //cout<<n<<" ";
                            if(main.top==-1)
                            {
                                            if(n==1)
                                            {
                                                    //cout<<"pushed into main\n";
                                                    push(&main,n);
                                            }
                                            else
                                            {
                                                    push(&side,n);
                                                    //cout<<"pushed into side\n";
                                            }
                            }
                            else
                            {
                                if(n==main.items[main.top]+1)
                                {
                                                             //cout<<"pushed into main\n";
                                                             push(&main,n);
                                }
                                else if(side.top!=-1 && side.items[side.top]==main.items[main.top]+1)
                                {
                                     while(side.top!=-1 && side.items[side.top]==main.items[main.top]+1)
                                     {
                                                     //cout<<"pushed into main\tpopped from side\n";
                                                     push(&main,pop(&side));
                                     }
                                     if(n==main.items[main.top]+1)
                                     {
                                                             //cout<<"pushed into main\n";
                                                             push(&main,n);
                                     }
                                     else 
                                     {
                                                             //cout<<"pushed into side\n";
                                                             push(&side,n);
                                     }
                                }
                                else 
                                {
                                     //cout<<"pushed into side\n";
                                     push(&side,n);
                                }
                            }
            }
            int r=1;
            for(i=side.top;i>=0;i--)
            {
                                    if(side.items[side.top]==main.items[main.top]+1)
                                    {
                                                                                   push(&main,pop(&side));
                                    }
                                    else
                                    {
                                        r=0;
                                        break;
                                    }
            }
            if(r==1)
                    cout<<"yes\n";
            else
                    cout<<"no\n";
            /*if(main.top==t-1)
                           cout<<"yes\n";
            else
                           cout<<"no\n";*/
    }
}
