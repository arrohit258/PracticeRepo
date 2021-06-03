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
ll min(ll a,ll b){
    if(a>b)return b;
    return a;
}


void solve(){

int n,k;
cin>>n>>k;
vi v(n);
vvi dp(n+1, vi(k+1,0));
vvi prefix_sum(n+1,vi(k+1,0));
fr(i,n)cin>>v[i];
sort(v.begin(),v.end());
for(int i=0;i<=k;i++){
    if(i<=v[0])
    dp[1][i]=1;
    if(i==0)
    prefix_sum[1][i]=1;
   else
    prefix_sum[1][i]=prefix_sum[1][i-1]+dp[1][i];
   prefix_sum[1][i]=prefix_sum[1][i]%mod;

}

for(int i=2;i<=n;i++){
    
    for(int j=0;j<=k;j++){
        //dp[i][j] represents giving jcandies to first i students
          //dp(i,j)=dp(i-1,j)+dp(i-1,j-1)+dp(i-1,j-2)....+dp(i-1,max(0,j-v[i-1]))
        if(j==0)dp[i][j]=1;
       if(j<=v[i-1])
        dp[i][j]=prefix_sum[i-1][j]%mod;
       else
        dp[i][j]=((prefix_sum[i-1][j])%mod-(prefix_sum[i-1][j-v[i-1]-1])%mod+mod)%mod;
       
        if(j==0)prefix_sum[i][j]=1;
        else prefix_sum[i][j]=(((prefix_sum[i][j-1])%mod+dp[i][j])+mod)%mod;
        
      
    }

}
cout<<dp[n][k];

}
int main() {
    int t=1;
   
    while(t--)
    solve();
   return 0;
}
