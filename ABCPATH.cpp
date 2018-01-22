#include<iostream>
using namespace std;

struct cord
{
       int i,j;
};

int main()
{
    cord q1[10000],q2[10000];
    int h,w,pos1,pos2,count,q,t=0;
    char s[52][52];
    while(1)
    {
    q=65;
            t++;
              count=0;
              pos1=pos2=0;
              int a[52][52]={0};
              cin>>h>>w;
              if(h==0 && w==0)
                      break;
              for(int i=0;i<=h+1;i++)
                      a[i][0]=a[i][w+1]=-1;
              for(int i=0;i<=w+1;i++)
                      a[0][i]=a[h+1][i]=-1;
              for(int i=1;i<=h;i++)
              {
                      for(int j=1;j<=w;j++)
                      {
                              cin>>s[i][j];
                              if(s[i][j]==65)
                              {
                                             count=1;
                                             a[i][j]=-1;
                                             q1[pos1].i=i;
                                             q1[pos1++].j=j;
                              }
                      }
              }    
              
              while(1)
              {
                      //cout<<"\n\nINI : ";
                      for(int i=0;i<pos1;i++)
                      {
                              int x=q1[i].i;
                              int y=q1[i].j;
                              //cout<<x<<"."<<y;
                              //cout<<"\n";
                              if(a[x+1][y]!=-1 && (int)s[x+1][y]==q+1)
                              {
                                               q2[pos2].i=x+1;
                                               q2[pos2++].j=y;
                                              // cout<<"x+1,y\n";
                                               a[x+1][y]=-1;
                              }
                              if(a[x+1][y+1]!=-1 && (int)s[x+1][y+1]==q+1)
                              {
                                               q2[pos2].i=x+1;
                                               q2[pos2++].j=y+1;
                                               //cout<<"x+1,y+1\n";
                                               a[x+1][y+1]=-1;
                              }
                              if(a[x+1][y-1]!=-1 && (int)s[x+1][y-1]==q+1)
                              {
                                               q2[pos2].i=x+1;
                                               q2[pos2++].j=y-1;
                                               //cout<<"x+1,y-1\n";
                                               a[x+1][y-1]=-1;
                              }
                              if(a[x-1][y]!=-1 && (int)s[x-1][y]==q+1)
                              {
                                               q2[pos2].i=x-1;
                                               q2[pos2++].j=y;
                                               //cout<<"x-1,y\n";
                                               a[x-1][y]=-1;
                              }                             
                              if(a[x-1][y-1]!=-1 && (int)s[x-1][y-1]==q+1)
                              {
                                               q2[pos2].i=x-1;
                                               q2[pos2++].j=y-1;
                                              // cout<<"x-1,y+1\n";
                                               a[x-1][y-1]=-1;
                              }                              
                              if(a[x-1][y+1]!=-1 && (int)s[x-1][y+1]==q+1)
                              {
                                               q2[pos2].i=x-1;
                                               q2[pos2++].j=y+1;
                                               //cout<<"x-1,y+1\n";
                                               a[x-1][y+1]=-1;
                              }                             
                              if(a[x][y-1]!=-1 && (int)s[x][y-1]==q+1)
                              {
                                               q2[pos2].i=x;
                                               q2[pos2++].j=y-1;
                                               //cout<<"x,y-1\n";
                                               a[x][y-1]=-1;
                              }                              
                              if(a[x][y+1]!=-1 && (int)s[x][y+1]==q+1)
                              {
                                               q2[pos2].i=x;
                                               q2[pos2++].j=y+1;
                                              // cout<<"x,y+1\n";
                                               a[x][y+1]=-1;
                              }                                                         
                      }
                      if(pos2==0)
                                 break;
                      pos1=0;
                      for(int i=0;i<pos2;i++)
                      {
                              q1[pos1].i=q2[i].i;
                              q1[pos1++].j=q2[i].j;
                      }
                      pos2=0;
                      q++;
                      count++;
              }
              cout<<"Case "<<t<<": "<<count<<"\n";
    }
 
}


