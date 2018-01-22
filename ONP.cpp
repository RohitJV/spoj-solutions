#include<iostream.h>
//#include<conio.h>
//#include<process.h>
#include<ctype.h>

struct stack
{
       int top;
       char x[500];
};

void push(stack *s1,int key)
{
     s1->x[++(s1->top)]=key;
}

int underflow(stack *s1)
{
    if(s1->top==-1)
                  return(1);
    return(0);
}

char pop(stack *s1)
{
     if(underflow(s1))
     {
                       cout<<"Underflow";
                      // exit(0);
     }                  
     return(s1->x[(s1->top)--]);
}

int prec(char c)
{
    if(c=='(')
              return(4);
    else if(c=='^')
              return(3);
    else if(c=='*' || c=='/')
              return(2);
    else if(c=='+' || c=='-')
              return(1);
    else
              return(0);
}

char stacktop(stack *s1)
{
     return(s1->x[s1->top]);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    stack s;
    s.top=-1;
    char a[500],exp[500],temp;
    int n=0,i;
    cin>>exp;
    for(i=0;exp[i]!='\0';i++)
    {
                             if(isalpha(exp[i]))
                             {
                                               a[n++]=exp[i];
                             }
                             else
                             {   
                                               while( ( prec(exp[i]) <= prec(stacktop(&s)) ) && (s.top!=-1) && (stacktop(&s)!='(') )
                                               {
                                                      a[n++]=pop(&s);
                                                      
                                                      if(underflow(&s))
                                                                       break;
                                               }
                                               if(exp[i]==')' && stacktop(&s)=='(')
                                                              temp=pop(&s);
                                               if(exp[i]!=')')
                                                              push(&s,exp[i]);
                             }
    }
    a[n]='\0';
    cout<<a;
    while(!underflow(&s))
                         cout<<pop(&s);
    cout<<"\n";
    }
    //getch();
}

