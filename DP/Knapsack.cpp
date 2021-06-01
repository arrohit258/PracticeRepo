#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll,vector<ll>,greater<ll>>


ll max(ll a,ll b){
    if(a>b)return a;
    return b;
}

ll rec(vi &value, vi&weight,ll n,ll W){
    //KNAPSACK PROBLEM
    vvi dp(n+1,vi(W+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            dp[i][j]=dp[i-1][j];
            if(j-weight[i-1]>=0)
            dp[i][j]=max(dp[i][j],dp[i-1][j-weight[i-1]]+value[i-1]);

        }
    }


    return dp[n][W];   

}

void solve(){
 
ll n,w;
cin>>n>>w;
vi value(n);
vi weight(n);
for(int i=0;i<n;i++)
cin>>weight[i]>>value[i];
cout<<rec(value,weight,n,w)<<endl;





}
int main() {
    int t=1;
   
    while(t--)
    solve();
   return 0;
}
