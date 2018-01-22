#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
 
int main()
{
    int n,l,temp,max=-1;
    char s[105];
    cin>>n;
    priority_queue<int> p1;
    priority_queue<int> p2;
    priority_queue<int> p3;
    priority_queue<int> p4;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        l=strlen(s);
        if(s[0]=='B' && s[l-1]=='B')
            p1.push(l);
        else if(s[0]=='B')
            p2.push(l);
        else if(s[0]=='C' && s[l-1]=='B')
            p3.push(l);
        else
            p4.push(l);
    }
    
    while(1)
    {
        int r=1;
        if(!p1.empty())
        {
            temp=p1.top();
            p1.pop();
            if(!p1.empty())
            {
                r=0;
                temp+=p1.top();
                p1.pop();
                p1.push(temp);
                if(temp>max)
                    max=temp;
            }
            if(!p2.empty())
            {
                r=0;
                temp+=p2.top();
                p2.pop();
                p2.push(temp);
                if(temp>max)
                    max=temp;
            }
        }
        if(!p2.empty())
        {
            temp=p2.top();
            p2.pop();
            if(!p3.empty())
            {
                r=0;
                temp+=p3.top();
                p3.pop();
                p1.push(temp);
                if(temp>max)
                    max=temp;
            }
            if(!p4.empty())
            {
                r=0;
                temp+=p4.top();
                p4.pop();
                p2.push(temp);
                if(temp>max)
                    max=temp;
            }
        }
        if(!p3.empty())
        {
            temp=p3.top();
            p3.pop();
            if(!p1.empty())
            {
                r=0;
                temp+=p1.top();
                p1.pop();
                p3.push(temp);
                if(temp>max)
                    max=temp;
            }
            if(!p2.empty())
            {
                r=0;
                temp+=p2.top();
                p2.pop();
                p4.push(temp);
                if(temp>max)
                    max=temp;
            }
        }
        if(!p4.empty())
        {
            temp=p4.top();
            p4.pop();
            if(!p4.empty())
            {
                r=0;
                temp+=p4.top();
                p4.pop();
                p4.push(temp);
                if(temp>max)
                    max=temp;
            }
            if(!p3.empty())
            {
                r=0;
                temp+=p3.top();
                p3.pop();
                p3.push(temp);
                if(temp>max)
                    max=temp;
            }
        }
        if(r==1)
            break;
    }
    /*while(!p1.empty())
    {
        cout<<p1.top()<<" ";
        p1.pop();
    }
    cout<<"\n";
    while(!p2.empty())
    {
        cout<<p2.top()<<" ";
        p2.pop();
    }
    cout<<"\n";
    while(!p3.empty())
    {
        cout<<p3.top()<<" ";
        p3.pop();
    }
    cout<<"\n";
    while(!p4.empty())
    {
        cout<<p4.top()<<" ";
        p4.pop();
    }*/
    cout<<max;
}