#include<iostream>
using namespace std;

int r,n,m;
char str[10]={'A','L','L','I','Z','Z','W','E','L','L'};

struct cord
{
	int x,y;
};

int check(cord s[500],int s1)
{
	for(int i=0;i<s1;i++)
	{
		if(s[i].x==s[s1].x && s[i].y==s[s1].y)
			return(0);
	}
	return(1);
}

void dfs(char a[501][501],cord q,cord s[500],int s1)
{
        //cout<<q.x<<" "<<q.y<<"\n";
	if(s1==10)
		r=1;
	else
	{
	//	cout<<"Else\n";
		//cout<<a[q.x][q.y+1]<<" "<<str[s1]<<"\n";
		if(q.x-1>=0 && a[q.x-1][q.y]==str[s1])
		{
			s[s1].x=q.x-1;
			s[s1].y=q.y;	
			if(check(s,s1))
				dfs(a,s[s1],s,s1+1);
		}
		if(q.x-1>=0 && q.y-1>=0 && a[q.x-1][q.y-1]==str[s1])
		{
			s[s1].x=q.x-1;
			s[s1].y=q.y-1;	
			if(check(s,s1))
				dfs(a,s[s1],s,s1+1);
		}
		if(q.y-1>=0 && a[q.x][q.y-1]==str[s1])
		{
			s[s1].x=q.x;
			s[s1].y=q.y-1;	
			if(check(s,s1))
				dfs(a,s[s1],s,s1+1);
		}
		if(q.x+1<n && q.y-1>=0 && a[q.x+1][q.y-1]==str[s1])
		{
			s[s1].x=q.x+1;
			s[s1].y=q.y-1;	
			if(check(s,s1))
				dfs(a,s[s1],s,s1+1);
		}
		if(q.x+1<n && a[q.x+1][q.y]==str[s1])
		{
			s[s1].x=q.x+1;
			s[s1].y=q.y;	
			if(check(s,s1))
				dfs(a,s[s1],s,s1+1);
		}
		if(q.x+1<n && q.y+1<m && a[q.x+1][q.y+1]==str[s1])
		{
			s[s1].x=q.x+1;
			s[s1].y=q.y+1;	
			if(check(s,s1))
				dfs(a,s[s1],s,s1+1);
		}
		if(q.y+1<m && a[q.x][q.y+1]==str[s1])
		{
			s[s1].x=q.x;
			s[s1].y=q.y+1;	
			if(check(s,s1))
				dfs(a,s[s1],s,s1+1);
		}
		if(q.x-1>=0 && q.y+1<m && a[q.x-1][q.y+1]==str[s1])
		{
			s[s1].x=q.x-1;
			s[s1].y=q.y+1;	
			if(check(s,s1))
				dfs(a,s[s1],s,s1+1);
		}
	}
}

int main()
{
	cord q[500],s[500];
	int q1=0,s1=0,t;
	char a[501][501];
	cin>>t;	
	while(t--)
	{
			q1=0;
			s1=0;
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>a[i][j];
				if(a[i][j]=='A')
				{
					q[q1].x=i;
					q[q1].y=j;
					q1++;
				}
			}
		}
		int r1=0;
		for(int i=0;i<q1;i++)
		{
			r=0;
			s[0].x=q[i].x;
			s[0].y=q[i].y;
			s1=1;
			dfs(a,q[i],s,s1);
			if(r==1)
			{
				cout<<"YES\n";
				r1=1;
				break;
			}
		}
		if(r1==0)
			cout<<"NO\n";
	}

}

