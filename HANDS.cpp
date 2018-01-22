#include<iostream>
using namespace std;
int main()
{
	int t,a[10000],h1,h2,m1,m2;
	char x[5],y[5];
	cin>>t;
	for(int i=0;i<t;i++)
	{
		a[i]=0;
		cin>>x>>y;
		h1 = ( (x[0]-48)*10 + x[1]-48 );
		m1 = ( (x[3]-48)*10 + x[4]-48 );
		h2 = ( (y[0]-48)*10 + y[1]-48 );
		m2 = ( (y[3]-48)*10 + y[4]-48 );
		
		if( (h1!=0 && h1!=12) && ( (h1%12)*5 + (m1/12) >= m1) )
			a[i]++; 
		if( ( (h2%12)*5 + (m2/12) < m2) )
			a[i]++;
		h1++;
		a[i]=a[i]+h2-h1;
		if(h1<=12 && h2>=12)
			a[i]--;
	}
	for(int k=0;k<t;k++)
		cout<<a[k]<<"\n";
}



