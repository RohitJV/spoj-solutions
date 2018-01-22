#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
using namespace std;

#define mp make_pair
#define pb push_back
#define INF -1
#define MAX 10000007
#define X first
#define Y second
#define all(x) x.begin(),x.end()

double x1,y1,x2,y2,x3,y3,s,r;
set < pair<int,int> > ss;

void square()
{
    cin>>x1>>y1>>s;
    for(int i=x1;i<=x1+s;i++)
    {
        for(int j=y1;j<=y1+s;j++)
            ss.insert(mp(i,j));
    }
}

void circle()
{
    int count=0;
    cin>>x1>>y1>>r;
    for(int i=x1-r-1;i<=x1+r+1;i++)
    {
        for(int j=y1-r-1;j<=y1+r+1;j++)
        {
            if( (i-x1)*(i-x1)+(j-y1)*(j-y1) <= r*r )
                ss.insert(mp(i,j));
        }
    }
}

double area(int a1,int b1,int a2,int b2,int a3,int b3)
{
    return ( abs(a1*(b2-b3) + a2*(b3-b1) + a3*(b1-b2))/2.0 );
}

void triangle()
{
    int count=0;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    int v1,v2,h1,h2;
    v1=min(x1,min(x2,x3));
    v2=max(x1,max(x2,x3));
    h1=min(y1,min(y2,y3));
    h2=max(y1,max(y2,y3));
    for(int i=v1-1;i<=v2+1;i++)
    {
        for(int j=h1-1;j<=h2+1;j++)
        {
            if(area(i,j,x1,y1,x2,y2)+area(i,j,x1,y1,x3,y3)+area(i,j,x3,y3,x2,y2) == area(x3,y3,x1,y1,x2,y2))
                ss.insert(mp(i,j));
        }
    }
}

int main()
{
    char ch;
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        ss.clear();
        while(m--)
        {
            cin>>ch;
            switch(ch)
            {
                case 'S' : square();
                            break;
                case 'C' : circle();
                            break;
                case 'T' : triangle();
                            break;
            }
        }
        cout<<ss.size()<<"\n";
    }
}
