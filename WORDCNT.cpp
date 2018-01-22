#include<iostream>
using namespace std;
int main()
{
        int t,count,store,words,max;
        char s[50000];
        cin>>t;
        for(int i=0;i<t;i++)
        {
                        max=0;
                        words=0;
                        count=0;
                        store=0;
                        do
                        {
                                gets(s);
                        }while(s[0]=='\0');
                        for(int j=0;s[j]!='\0';j++)
                        {
                                if(s[j]!=' ')
                                        count++;
                                else if(s[j]==' ')
                                {
                                        if(count==store)
                                        {
                                                words++;
                                        }
                                        if(count!=store)
                                        {
                                                words=1;
                                                store=count;
                                        }
                                        if(words>max)
                                                        max=words;
                                        count=0;
                                }
                        }
                        if(count==store)
                        {
                                words++;
                        }
                        if(count!=store)
                        {
                                words=1;
                                store=count;
                        }
                        if(words>max)
                                max=words;
                        cout<<max<<"\n";
        }       
}   
