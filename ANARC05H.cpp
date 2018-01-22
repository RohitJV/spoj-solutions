#include<iostream>
#include<string.h>
using namespace std;
int count;
 
int f(int val[25][25],char a[26],int pos,int presum)
{
    for(int i=pos+1;i<strlen(a);i++)
    {
        if(val[pos][i-1]<=val[i][strlen(a)-1] && val[pos][i-1]>=presum)
        {
            //cout<<pos<<"-"<<i-1<<" , "<<i<<"-"<<strlen(a)-1<<"\n";
            count++;
            f(val,a,i,val[pos][i-1]);
        }
    }
}
 
int main()
{
    char a[26];
    int val[25][25]={ {-1 } },t=1;
    while(1)
    {
        count=1;
        cin>>a;
        if(strcmp(a,"bye")==0)
            break;
        else
        {
            for(int i=0;a[i]!='\0';i++)
            {
                val[i][i]=a[i]-48;
                if(i!=0)
                    val[0][i]=val[0][i-1]+val[i][i];
                for(int j=1;j<i;j++)
                    val[j][i]=val[j][i-1]+val[i][i];
            }
            f(val,a,0,-1);
        }
        cout<<t++<<". "<<count<<"\n";
    }
}