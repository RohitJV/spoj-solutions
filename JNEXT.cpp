#include<iostream>
using namespace std;
 
int main()
{
        int t,n,i,s[10];
        char a[1000010];
        cin>>t;
        while(t--)
        {
                for(int j=0;j<10;j++)
                        s[j]=0;
                cin>>n;
                for(i=0;i<n;i++)
                        cin>>a[i];
                i=n-2;
                s[a[n-1]-48]++;
                while(i>=0)
                {
                        s[a[i]-48]++;
                        if(a[i]-48<a[i+1]-48)
                                break;
                        i--;
                }
                if(i<0)
                        cout<<-1<<"\n";
                else
                {
                        for(int j=0;j<i;j++)
                                cout<<a[j]-48;
                        for(int j=a[i]-47;j<10;j++)
                        {
                                if(s[j]!=0)
                                {
                                        cout<<j;
                                        s[j]--;
                                        break;
                                }
                        }
                        for(int j=0;j<10;j++)
                        {
                                while(s[j]--!=0)
                                        cout<<j;
                        }
                        cout<<"\n";
                }
        }
}