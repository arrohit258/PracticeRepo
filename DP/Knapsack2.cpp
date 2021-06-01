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
    vvi dp(n+1,vi(100001,INT_MAX));
    for(int i=0;i<=n;i++)
    dp[i][0]=0;
    ll mx=INT_MIN;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=100000;j++){
            dp[i][j]=dp[i-1][j];
            if(j-value[i-1]>=0)
            dp[i][j]=min(dp[i][j],dp[i-1][j-value[i-1]]+weight[i-1]);
         

            if(dp[i][j]<=W ){
                mx=max(mx,j);
            
        }
        
        }
        
    }


    return mx;   

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
