#include<iostream>
#include<stdio.h>
//#include<conio.h>
#include<queue>
#include<string.h>
using namespace std;
 
queue <int> floor;
int f,s,g,u,d,flag=0,count=0,fs,i,temp;
int a[1000005];
 
int main()
{
    scanf("%d%d%d%d%d",&f,&s,&g,&u,&d);
    floor.push(s);
    memset(a,0,sizeof(a));
    while(!floor.empty())
    {
         fs=floor.size();
         for(i=0;i<fs;i++)
         {
                 temp=floor.front();
                 if(temp==g)
                 {
                            flag=1;
                            break;
                 }
                 else
                 {
                     if(temp+u<=f && a[temp+u]==0)
                     {
                             floor.push(temp+u);
                             a[temp+u]=1;
                     }
                     if(temp-d>0 && a[temp-d]==0)
                     {
                             floor.push(temp-d);                       
                             a[temp-d]=1;
                     }
                 }
                 a[temp]=1;
                 floor.pop();
         }
         if(flag==1)
                    break;
         count++;
    }
    if(flag==1)
               printf("%d",count);
    else
               printf("use the stairs");
//    getch();
}
 
 
