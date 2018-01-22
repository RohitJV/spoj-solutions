 #include<iostream>
#include<string>
#include<map>
#include<vector>
#include<cstring>
int arr[1000001];
int m[1000001];
using namespace std;
int main()
{
    int t,n,k,i;string s;
    cin>>t;
    while(t--){
               memset(m,0,sizeof(m));
               long long int ans=0,sum=0;
               cin>>n>>k>>s;long long int cnt=0;
               if(k==0){
                        for(i=0;i<s.length();i++){
                                                  if(s[i]=='1'){
							        ans+=(cnt*(cnt+1))/2;
                                                                cnt=0;
                                                                
                                                  }else cnt++;
                        }
			ans+=(cnt*(cnt+1))/2;
                        cout<<ans<<endl;
                        continue;
               }
 
               for(i=0;i<s.length();i++){
                                   if(s[i]=='1'){
                                                 
                                                 sum++;
                                   }
                                   arr[i]=sum;
                                   m[sum]++;
               }
		       
               for(i=0;i<s.length();i++){
                                   if(s[i]=='1' && arr[i]+k-1<1000001){
                                                 ans+=m[arr[i]+k-1];
                                   } else if(s[i]=='0' && arr[i]+k<1000001) 
                                                 ans+=m[arr[i]+k];
               }
              
               cout<<ans<<endl;
    }
    return 0;
}
