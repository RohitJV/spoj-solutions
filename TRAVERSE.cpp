#include<iostream>
using namespace std;
 
int count=0;
 
void rec(int a[100][100],int n,int i,int j)
{
        if(i==n-1 && j==n-1)
                count++;
        else if(a[i][j]!=0)
        {
                if(i+a[i][j]<n)
                        rec(a,n,i+a[i][j],j);
                if(j+a[i][j]<n)
                        rec(a,n,i,j+a[i][j]);
        }
}       
 
int main()
{
        int i,j,n,a[100][100];
        char s[100][100];
        cin>>n;
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        cin>>s[i][j];
                        a[i][j]=s[i][j]-48;
                }
        }
        rec(a,n,0,0);
        cout<<count;
}