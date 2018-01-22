#include<iostream>
using namespace std;
//#include<conio.h>

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
              int s[201][201]={0},c[201]={0},n,i,j;
              char a[201];
              cin>>n;
              for(i=0;i<n;i++)
              {
                              cin>>a[i];
                              if(i==0)
                              {
                                      if(a[i]=='1')
                                      {
                                                   s[0][0]=1;
                                                   c[i]=1;
                                      }
                                      else
                                      {
                                                   s[0][0]=0;
                                                   c[i]=-1;
                                      }
                              }
                              else
                              {
                                  if(a[i]=='1')
                                  {
                                               s[i][i]=1;
                                               c[i]=c[i-1]+1;
                                  }
                                  else
                                  {
                                               c[i]=c[i-1]-1;
                                               s[i][i]=0;
                                  }
                              }
              }                 
              for(i=1;i<n;i++)
              {
                               for(j=0;j<n-i;j++)
                               {
                                                   int temp=-300;
                                                   if(j==0)
                                                   {
                                                           if(c[j+i]>0)
                                                                       temp=i+1;
                                                   }
                                                   else
                                                   {
                                                       if(c[j+i]-c[j-1]>0)
                                                                          temp=i+1;
                                                   }
                                                   if(temp==-300)      
                                                   {
                                                                       for(int k=j;k<=j+i;k++)
                                                                       {
                                                                               if(temp<s[j][k]+s[k+1][j+i])
                                                                                                         temp=s[j][k]+s[k+1][j+i];
                                                                       }
                                                   }
                                                   s[j][j+i]=temp;
    //                                               cout<<temp<<" ";
                                                   
                               }
  //                             cout<<"\n";
              }
              cout<<s[0][n-1]<<"\n";
    }
   // getch();
}
                                                           
                              
