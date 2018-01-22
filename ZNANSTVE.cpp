#include<iostream>
using namespace std;
 
int m=-1;
 
struct node
{
    node *next[26];
    int prefix;
};
 
void insert(node *root,char s[1005][1005],int c,int pos,int count)
{
    int d=s[pos][c]-'a';
    if(pos==-1)
        return;
    if(root->next[d]!=NULL)
    {
        count++;
        insert(root->next[d],s,c,pos-1,count);
        return;
    }
    if(count>m)
        m=count;
    root->next[d]=new node;
    root->next[d]->prefix=0;
    insert(root->next[d],s,c,pos-1,count);
}
 
int main()
{
    m=-1;
    node root;
    root.prefix=0;
    for(int i=0;i<26;i++)
        root.next[i]=NULL;
    int r,c;
    cin>>r>>c;
    char s[1005][1005];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>s[i][j];
    for(int i=0;i<c;i++)
        insert(&root,s,i,r-1,0);
    cout<<r-m-1;
}
