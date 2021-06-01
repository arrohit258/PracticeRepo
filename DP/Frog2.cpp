#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll,vector<ll>,greater<ll>>


ll max(ll a,ll b){
    if(a>b)return a;
    return b;
}

ll rec(ll*arr, ll*dp,ll k,ll n,ll i){
    if(n<2)return 0;
    dp[0]=0;
    for(int i=1;i<n;i++){
        dp[i]=INT_MAX;
        for(int j=1;j<=k;j++){
            if((i-j)>=0)
                dp[i]=min(dp[i],abs(arr[i]-arr[i-j])+dp[i-j]);

            
        }
       // cout<<dp[i]
    }

return dp[n-1];

}

void solve(){
 
ll n,k;cin>>n>>k;
ll *arr=new ll[n];
fr(i,n) cin>>arr[i];
ll *dp=new ll[n]();
cout<<rec(arr,dp,k,n,n-1)<<endl;





}
int main() {
    int t=1;
   
    while(t--)
    solve();
   return 0;
}
