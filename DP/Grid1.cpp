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

ll max(ll a,ll b){
    if(a>b)return a;
    return b;
}



ll dfs(vector<vector<char>> &v, vvi &dp,int i,int j,int h,int w){
    //KNAPSACK PROBLEM
    if(i>=h || j>=w || v[i][j]=='#')return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==h-1 && j==w-1)return dp[i][j]=1;
    
    return dp[i][j]=(((dfs(v,dp,i+1,j,h,w))%mod+(dfs(v,dp,i,j+1,h,w))%mod)%mod+mod)%mod;




}

void solve(){
 
int h,w;cin>>h>>w;
vector<vector<char>>v(h,vector<char>(w));
for(int i=0;i<h;i++)
for(int j=0;j<w;j++)cin>>v[i][j];
vvi dp(h,vi(w,-1));
cout<<dfs(v,dp,0,0,h,w);




}
int main() {
    int t=1;
   
    while(t--)
    solve();
   return 0;
}
