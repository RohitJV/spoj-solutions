#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cstdio>
using namespace std;
 
char res[40];
int p=0;
 
struct node
{
    int prefix,flag,child;
    node *next[26];
    char min[40];
};
 
void search(char s[40],int pos,node *root)
{
        int d=s[pos]-'a';
        if(pos==-1)
        {
                //cout<<"pos=-1\n";
                strcpy(res,root->min);
                return;
        }
        if(root->next[d]==NULL)
        {
                //cout<<"NotFound\n";
                strcpy(res,root->min);
                return;
        }
        if(root->next[d]->prefix==1)
        {
                //cout<<"2Branches\n";
                char temp[40]="}";
                if(strcmp(root->next[d]->min,s)==0)
                {
                    for(int i=0;i<26;i++)
                    {
                        if(i!=d && root->next[i]!=NULL)
                        {
                            if(strcmp(root->next[i]->min,temp)<0)
                                strcpy(temp,root->next[i]->min);
                        }
                    }
                    if(strcmp(temp,"}")==0)
                    {
                        res[p]='\0';
                        for(int i=0;i<p/2;i++)
                        {
                            swap(res[i],res[p-1-i]);
                        }
                    }
                    else
                        strcpy(res,temp);
                }
                else
                    strcpy(res,root->next[d]->min);
                return;
        }
        else
        {
                //cout<<"Else\n";
                res[p++]=d+'a';
                search(s,pos-1,root->next[d]);
        }
}       
 
void insert(char s[40],int pos,node *root)
{
        if(pos!=-1 && strcmp(s,root->min)<0)
            strcpy(root->min,s);
        if(root->child==0)
            strcpy(root->min,s);
        if(pos==-1)
        {
                root->flag=1;
                return;
        }
        int d=s[pos]-'a';
        if(root->next[d]==NULL)
        {
                root->child++;
                root->next[d]=new node;
                node *temp=root->next[d];
                temp->prefix=temp->flag=temp->child=0;
                for(int i=0;i<26;i++)
                        temp->next[i]=NULL;
                strcpy(temp->min,s);
        }
        node *temp=root->next[d];
        temp->prefix++;
        insert(s,pos-1,temp);
}
 
int main()
{
        node root;
        root.prefix=root.flag=root.child=0;
        strcpy(root.min,"}");
        for(int i=0;i<26;i++)
                root.next[i]=NULL;
        char s[40];
        while(1)
        {
            gets(s);
            if(strcmp(s,"\0")==0)
                break;
            insert(s,strlen(s)-1,&root);
        }
        while(scanf("%s",&s)!=EOF)
        {
            //cout<<"============================================\n";
            p=0;
            search(s,strlen(s)-1,&root);
            cout<<res<<"\n";
        }
}