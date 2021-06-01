#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<ll> vi;
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll,vector<ll>,greater<ll>>


ll max(ll a,ll b){
    if(a>b)return a;
    return b;
}



int dfs(vvi &graph, vi &dp,int i,vector<bool> &visited){
    //KNAPSACK PROBLEM
    if(dp[i]!=-1)
    return dp[i];
    visited[i]=true;
    int mx=0;
    for(int j=0;j<graph[i].size();j++){
        mx=max(mx,dfs(graph,dp,graph[i][j],visited));
    }
    return dp[i]=1+mx;

}

void solve(){
 
int n,m;
cin>>n>>m;
vvi graph(n);
vi dp(n,-1);
fr(i,m){
    int x,y;
    cin>>x>>y;
    graph[x-1].push_back(y-1);
}
vector<bool>visited(n,false);
fr(i,n){
    if(!visited[i]){
        dfs(graph,dp,i,visited);
    }
}
int mx=0;
for(auto e:dp)mx=max(mx,e);
cout<<mx-1;




}
int main() {
    int t=1;
   
    while(t--)
    solve();
   return 0;
}
