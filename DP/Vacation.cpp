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

ll rec(vvi &v, ll n){
    
   vvi dp(n,vi(3));
   dp[0][0]=v[0][0];
   dp[0][1]=v[0][1];
   dp[0][2]=v[0][2];
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            dp[i][j]=INT_MIN;
            for(int k=0;k<3;k++){
                if(k==j)continue;
                dp[i][j]=max(dp[i][j],dp[i-1][k]+v[i][j]);
            }
        }
      
    }

return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));

}

void solve(){
 
ll n;
cin>>n;
vvi v(n,vi(3));
for(int i=0;i<n;i++)
for(int j=0;j<3;j++)cin>>v[i][j];
cout<<rec(v,n)<<endl;





}
int main() {
    int t=1;
   
    while(t--)
    solve();
   return 0;
}
