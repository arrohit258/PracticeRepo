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
 
int n;cin>>n;
double *p=new double[n];
fr(i,n)cin>>p[i];

double dp[n+1][n+1];

// dp[i][j] represents i heads in j turns
double ans=0;
for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
        if(i==0 && j==0)dp[i][j]=mul;
        // probabilty of 0 heads in k turns =(1-p1)*(1-p2)*(1-p3)...*(1-pk)
        else if(i==0) dp[i][j]=(1-p[j-1])*dp[i][j-1]*mul;
       
        
        else dp[i][j]=0.0;
       
    }

}

for(int h=1;h<=n;h++)
{for(int j=1;j<=n;j++)
{if(j>=h)
    {dp[h][j]=mul*dp[h][j-1]*(1-p[j-1])+mul*dp[h-1][j-1]*p[j-1];
  
   }
    if(h>(n/2) && j==n) ans+=dp[h][j];

}
}
cout<<setprecision(10)<<ans;





}
int main() {
    int t=1;
   
    while(t--)
    solve();
   return 0;
}
