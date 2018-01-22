#include<iostream>
using namespace std;
 
int main()
{
        int n,i,j,k,sum,pro;
        while(1)
        {
                sum=0;
                pro=1;
                cin>>n;
                if(n==0)
                        break;
                for(i=0;;i++)
                {
                        sum=sum+pro;
                        if(sum>=n)
                        {
                                cout<<i<<"\n";
                                break;
                        }
                        else
                        {
                                pro=pro*2;
                        }
                }
        }
}