#include<iostream>
using namespace std;

int main()
{
    int a[300000],n,i,j;
    long long int s[300000],m,max,store,temp;
    cin>>n>>m;
    s[0]=0;
    store=0;
    temp=0;
    max=0;
    for(i=0;i<n;i++)
    {
    	cin>>a[i];
    	if(i==0)
    		s[i]=a[i];
    	else
    		s[i]=s[i-1]+a[i];
    }
    for(i=0;i<n;i++)
    {
    	if(s[i]-store>m)
    	{
    		for(j=temp;j<=i;j++)
    		{
    			if(s[i]-s[j]<=m)
    			{
    				temp=j+1;
    				store=s[j];
    				if(s[i]-s[j]>max)
    					max=s[i]-s[j];
    				break;
    			}
    		}
    	}
    	else
    	{
    		if(s[i]-store>max)
    			max=s[i]-store;
    	}
    }
    cout<<max;
}
    



