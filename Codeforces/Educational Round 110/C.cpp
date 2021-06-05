#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;



void solve(){
 
string s;
cin>>s;
int n=s.length();
ll dp[n];dp[0]=1;
ll idx=-1;char c='*';
if(s[0]!='?'){
    c=s[0];
    idx=0;

}
ll ans=1;
for(ll i=1;i<n;i++){dp[i]=1;
    if((s[i]=='1' && s[i-1]=='0') ||(s[i]=='0' && s[i-1]=='1') )dp[i]+=dp[i-1];
    else if(s[i]=='?')dp[i]+=dp[i-1];
    else if(s[i-1]=='?'){
        if(idx==-1)dp[i]+=dp[i-1];
        else{
            if((c==s[i] && (i-idx)%2==0)||(c!=s[i] && (i-idx)%2==1))dp[i]=dp[i]+dp[i-1];
            else dp[i]=dp[i]+(dp[i-1]-dp[idx]);
        }
    }
   ans+=dp[i];
   if(s[i]!='?'){
       
    c=s[i];
    idx=i;


   }
  
}
cout<<ans<<"\n";


}
int main() {
   int t;cin>>t;
    while(t--)
    solve();
   return 0;
}
