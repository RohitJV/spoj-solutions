#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
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

int prime[10005];
vector <int> num;

void sieve()
{
    for(int i=2;i<10001;i++)
    {
        if(prime[i])
            continue;
        for(int j=2;j*i<10001;j++)
            prime[j*i]++;
    }
    for(int i=3;i<10001;i++)
    {
        if(prime[i]>=3)
            num.pb(i);
    }
}

int main()
{
    int t,x;
    cin>>t;
    sieve();
    while(t--)
    {
        cin>>x;
        cout<<num[x-1]<<"\n";;
    }
}
