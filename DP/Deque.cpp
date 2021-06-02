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
 
ll dp[3001][3001][2];
 
ll rec(vi &v,int i,int j,int turn){
  if(i>j) return 0;
  if(dp[i][j][turn]!=-1)return dp[i][j][turn];
  if(turn==0)
  return dp[i][j][turn]=max(v[i]+rec(v,i+1,j,1),v[j]+rec(v,i,j-1,1));
  return dp[i][j][turn]=min(rec(v,i+1,j,0),rec(v,i,j-1,0));
 
}
 
void solve(){
 
 
int n;cin>>n;
vi v(n);
ll sum=0;
fr(i,n){
    cin>>v[i];
    sum+=v[i];
}
memset(dp,-1 ,sizeof dp);
cout<<2*rec(v,0,n-1,0)-sum;
 
 
 
}
int main() {
    int t=1;
   
    while(t--)
    solve();
   return 0;
}
