#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll,vector<ll>,greater<ll>>
int mod=1000000007;
double mul=1.000000000;

ll max(ll a,ll b){
    if(a>b)return a;
    return b;
}





void solve(){


int n,k;
cin>>n>>k;
vector<int>v(n);
fr(i,n)cin>>v[i];
//rec(v,k);
  int dp[k+1];
   dp[0]=0;
   for(int i=1;i<=k;i++){
       dp[i]=0;
       for(int j=0;j<v.size();j++){
           int move=v[j];
           if(move-i>0)continue;
           if(dp[i-move]==0)
           dp[i]=1;
       }
   }
   if(dp[k]==1)cout<<"First\n";
   else cout<<"Second\n";



}
int main() {
    int t=1;
   
    while(t--)
    solve();
   return 0;
}
