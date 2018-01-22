#include<iostream>
using namespace std;

int main()
{
    long long int n,d[2000],m[2000],y[2000],s[2000],i,j,count,sum;
    while(1)
    {
                    count=0;
                    sum=0;
                    cin>>n;
                    if(n==0)
                            break;
                    for(j=0;j<n;j++)
                                    cin>>d[j]>>m[j]>>y[j]>>s[j];
                    for(j=0;j<n-1;j++)
                    {
                                      if(y[j]==y[j+1])
                                      {
                                                      
                                                      
                                      if(m[j]==1 && d[j]==31 && m[j+1]==2 && d[j+1]==1)
                                      {
                                                 count++;
                                                 sum=sum+s[j+1]-s[j];
                                      } 
                                      else if(m[j]==2 && d[j]==29 && m[j+1]==3 && d[j+1]==1 && ( (y[j]%4==0 && y[j]%100!=0) || y[j]%400==0 ) )
                                      {
                                                 count++;
                                                 sum=sum+s[j+1]-s[j];
                                      }
                                      else if(m[j]==2 && d[j]==28 && m[j+1]==3 && d[j+1]==1)
                                      {
                                                 count++;
                                                 sum=sum+s[j+1]-s[j];
                                      }
                                      else if(m[j]==3 && d[j]==31 && m[j+1]==4 && d[j+1]==1)
                                      {
                                                 count++;
                                                 sum=sum+s[j+1]-s[j];
                                      }
                                      else if(m[j]==4 && d[j]==30 && m[j+1]==5 && d[j+1]==1)
                                      {
                                                 count++;
                                                 sum=sum+s[j+1]-s[j];
                                      }
                                      else if(m[j]==5 && d[j]==31 && m[j+1]==6 && d[j+1]==1)
                                      {
                                                 count++;
                                                 sum=sum+s[j+1]-s[j];
                                      }
                                      else if(m[j]==6 && d[j]==30 && m[j+1]==7 && d[j+1]==1)
                                      {
                                                 count++;
                                                 sum=sum+s[j+1]-s[j];
                                      }
                                      else if(m[j]==7 && d[j]==31 && m[j+1]==8 && d[j+1]==1)
                                      {
                                                 count++;
                                                 sum=sum+s[j+1]-s[j];
                                      }
                                      else if(m[j]==8 && d[j]==31 && m[j+1]==9 && d[j+1]==1)
                                      {
                                                 count++;
                                                 sum=sum+s[j+1]-s[j];
                                      }
                                      else if(m[j]==9 && d[j]==30 && m[j+1]==10 && d[j+1]==1)
                                      {
                                                 count++;
                                                 sum=sum+s[j+1]-s[j];
                                      }
                                      else if(m[j]==10 && d[j]==31 && m[j+1]==11 && d[j+1]==1)
                                      {
                                                 count++;
                                                 sum=sum+s[j+1]-s[j];
                                      }
                                      else if(m[j]==11 && d[j]==30 && m[j+1]==12 && d[j+1]==1)
                                      {
                                                 count++;
                                                 sum=sum+s[j+1]-s[j];
                                      }
                                      
                                      else if(m[j]==m[j+1] && d[j+1]==d[j]+1)
                                      {
                                           count++;
                                           sum=sum+s[j+1]-s[j];
                                      }
                                      
                                      
                                      }
                                      
                                      
                                      
                                      else if(y[j+1]==y[j]+1 && m[j]==12 && m[j+1]==1 && d[j]==31 && d[j+1]==1)
                                      {
                                           count++;
                                           sum=sum+s[j+1]-s[j];
                                      }
                    }
                    cout<<count<<" "<<sum<<"\n";
                    
    }
}
