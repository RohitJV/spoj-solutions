#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main()
{
        int n,a[1000001],b[1000001],c[101];
        cin>>n;
        for(int i=0;i<n;i++)
                cin>>c[i];
        int t1=0,t2=0;
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        for(int k=0;k<n;k++)
                        {
                                a[t1++]=c[i]*c[j]+c[k];
                                if(c[k]!=0)
                                        b[t2++]=(c[i]+c[j])*c[k];
                        }
                }
        }
        vector<int> a1 (a,a+t1);
        vector<int> b1 (b,b+t1);
        sort(a1.begin(),a1.begin()+t1);
        sort(b1.begin(),b1.begin()+t2);
        int j=0,count=0,temp=0;
        for(int i=0;i<t1;i++)
        {
        if(i!=0 && a1[i]==a1[i-1])
            count=count+temp;
        else
        {
            temp=0;
                    while(b1[j]<a1[i] && j<t2)
                j++;
            while(b1[j]==a1[i] && j<t2)
            {
                temp++;
                j++;
            }
            count=count+temp;
        }
        }
        cout<<count;
}