#include <iostream>
#include <algorithm>
using namespace std;
 
const int MAX=100025;
 
class _x{
public:
  int s,e;
}v[MAX];
 
bool comp(const class _x a, const class _x b){
	return a.e<b.e;
}
 
int N;
 
int main(){
	int tc;
	int last,cnt;
	cin >> tc;
	while(tc--){
		last=-1;
		cnt = 0;
		cin >> N;
		for(int i=0;i<N;i++){
			cin>> v[i].s >> v[i].e;
			//v[i].e+= v[i].s;
			}
		sort(v, v+N, comp);
		for(int i=0;i<N;i++){
			if(v[i].s>last){
				cnt++;
				//cout << last << ' ' << v[i].s << ' ' << v[i].e << endl;
				last=v[i].e;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}