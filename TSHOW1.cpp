#include<iostream>
using namespace std;
int main()
{
        int t,i,a[10000],k,l;
        long long int n,j;
        cin>>t;
        for(i=0;i<t;i++)
        {
                l=1;
                j=2;
                cin>>n;
                while(n-j>0)
                {
                        n=n-j;
                        j=j*2;
                        l++;
                }
                j=0;
                n--;
                while(n!=0)
                {
                        if(n%2==0)
                                a[j++]=5;
                        else 
                                a[j++]=6;
                        n=n/2;
                }
                for(k=0;k<l-j;k++)
                {
                        cout<<5;
                }               
                for(k=j-1;k>=0;k--)
                {
                        cout<<a[k];
                }
                cout<<"\n";
        }
}
