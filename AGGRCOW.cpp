#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define pb push_back

int t,n,c,l,r,inp,mid;
vector <int> a;

bool check(int x)
{
    int temp=a[0],cnt=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]-temp >= x)
        {
            cnt++;
            temp=a[i];
        }
    }
    if(cnt >= c)
        return true;
    return false; 
}

int main()
{
    cin>>t;
    while(t--)
    {
        a.clear();
        cin>>n>>c;
        c--;
        for(int i=0;i<n;i++)
        {
            cin>>inp;
            a.pb(inp);
        }
        sort(a.begin(),a.end());
        l=0;
        r=a[n-1];
        while(l<=r)
        {
            mid=(l+r)/2;
            if( check(mid) )
                l=mid+1;
            else
                r=mid-1;
        }
        cout<<l-1<<"\n";
    }
}
