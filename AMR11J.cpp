#include<iostream>
#include<stdio.h>
#include<ctype.h>
using namespace std;
 
 
char s[602][602],a;
int t,m,n,pos[2];
 
struct civ
{
    int x,y;
    char ch;
}q[2][4000000];
 
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        //cout<<"\n\n";
        pos[0]=pos[1]=0;
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                do
                {
                    a=getchar();
                    if(a=='#' || a=='.' || isalpha(a))
                    {
                        s[i][j]=a;
                        break;
                    }
                }while(1);
                if(isalpha(s[i][j]))
                {
                    q[0][pos[0]].x=i;   
                    q[0][pos[0]].y=j;
                    q[0][pos[0]].ch=s[i][j];
                    //q[0][pos[0]].tym=0;
                    pos[0]++;
                }
            }
        }
        // for(int i=0;i<pos[0];i++)
        //    cout<<q[0][i].x<<" "<<q[0][i].y<<" "<<q[0][i].ch<<"\n\n";
        int z=0;
        while(pos[z]!=0)
        {
            int nxt=(z+1)%2;
            pos[nxt]=0;
            for(int i=0;i<pos[z];i++)
            {
                 int x=q[z][i].x,y=q[z][i].y;
                 char ch=q[z][i].ch;
                 if(s[x][y]!='*')
                    s[x][y]=toupper(ch);
            }
            
            int temp=0;
            for(int i=0;i<pos[z];i++)
            {
                int x=q[z][i].x,y=q[z][i].y;
                char ch=q[z][i].ch;
                if(s[x][y]!='*')
                {
                    if(x-1>=0 && s[x-1][y]!='#')
                    {
                        if(s[x-1][y]=='.' || s[x-1][y]==tolower(s[x][y]))
                        {
                            if(s[x-1][y]!=tolower(s[x][y]))
                            {
                            q[nxt][temp].x=x-1;
                            q[nxt][temp].y=y;
                            q[nxt][temp].ch=ch;
                            s[x-1][y]=ch;
                            temp++;
                            }
                        }
                        else
                        {
                            if(isalpha(s[x-1][y]) && s[x-1][y]>96)
                            {
                                q[nxt][temp].x=x-1;
                                q[nxt][temp].y=y;
                                q[nxt][temp].ch='*';
                                s[x-1][y]='*';
                                temp++;
                            }
                        }
                    }
                    
                    if(y-1>=0 && s[x][y-1]!='#')
                    {
                        if(s[x][y-1]=='.' || s[x][y-1]==tolower(s[x][y]))
                        {
                            if(s[x][y-1]!=tolower(s[x][y]))
                            {
                            q[nxt][temp].x=x;
                            q[nxt][temp].y=y-1;
                            q[nxt][temp].ch=ch;
                            s[x][y-1]=ch;
                            temp++;
                            }
                        }
                        else
                        {
                            if(isalpha(s[x][y-1]) && s[x][y-1]>96)
                            {
                                q[nxt][temp].x=x;
                                q[nxt][temp].y=y-1;
                                q[nxt][temp].ch='*';
                                s[x][y-1]='*';
                                temp++;
                            }
                        }
                    }
                    
                    if(x+1<m && s[x+1][y]!='#')
                    {
                        if(s[x+1][y]=='.' || tolower(s[x][y])==s[x+1][y])
                        {
                            if(s[x+1][y]!=tolower(s[x][y]))
                            {
                            q[nxt][temp].x=x+1;
                            q[nxt][temp].y=y;
                            q[nxt][temp].ch=ch;
                            s[x+1][y]=ch;
                            temp++;
                            }
                        }
                        else
                        {
                            if(isalpha(s[x+1][y]) && s[x+1][y]>96)
                            {
                                q[nxt][temp].x=x+1;
                                q[nxt][temp].y=y;
                                q[nxt][temp].ch='*';
                                s[x+1][y]='*';
                                temp++;
                            }
                        }
                    }
                    
                    if(y+1<n && s[x][y+1]!='#')
                    {
                        if(s[x][y+1]=='.' || s[x][y+1]==tolower(s[x][y]))
                        {
                            if(s[x][y+1]!=tolower(s[x][y]))
                            {
                            q[nxt][temp].x=x;
                            q[nxt][temp].y=y+1;
                            q[nxt][temp].ch=ch;
                            s[x][y+1]=ch;
                            temp++;
                            }
                        }
                        else
                        {
                            if(isalpha(s[x][y+1]) && s[x][y+1]>96)
                            {
                                q[nxt][temp].x=x;
                                q[nxt][temp].y=y+1;
                                q[nxt][temp].ch='*';
                                s[x][y+1]='*';
                                temp++;
                            }
                        }
                    }
                    
                }
                //break;
            }
            
            z=nxt;
            pos[nxt]=temp;
            /*for(int i=0;i<m;i++)
            {
                    for(int j=0;j<n;j++)
                    {
                        cout<<s[i][j]<<" ";
                    }
                    cout<<"\n";
            }*/
            
        }
        
            for(int i=0;i<m;i++)
            {
                    for(int j=0;j<n;j++)
                    {
                        if(isalpha(s[i][j]))
                        {
                            s[i][j]=tolower(s[i][j]);
                            cout<<s[i][j];
                        }
                        else
                            cout<<s[i][j];
                    }
                    cout<<"\n";
            }
            cout<<"\n";
        
    }
}
 