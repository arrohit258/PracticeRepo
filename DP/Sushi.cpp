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


double dp[301][301][301];

double rec(int x,int y,int z,int n){
    if(x==0 && y==0 && z==0)return 0;
    if(x<0 || y<0 ||z<0)return 0;
    if(dp[x][y][z]>=0)return dp[x][y][z];
  // Dp [x][y][z]=1+p0*dp[x][y][z]+px*dp[x-1][y][z]+py*dp[x+1][y-1][z]+pz*dp[x][y+1][z-1];
  //dp(x,y,z) represents expected no of moves from x,y,z to reach 0,0,0
    double exp=n+x*rec(x-1,y,z,n)+y*rec(x+1,y-1,z,n)+z*rec(x,y+1,z-1,n);
    int den=x+y+z;
    return dp[x][y][z]=(1.0*exp)/den;
}

void solve(){
 
memset(dp,-1,sizeof dp);

int n;
cin>>n;
int cnt1=0,cnt2=0,cnt3=0;
fr(i,n){
    int x;
    cin>>x;
    if(x==1)cnt1++;
    else if(x==2)cnt2++;
    else cnt3++;
    
}
cout<<setprecision(10)<<rec(cnt1,cnt2,cnt3,n);


}
int main() {
    int t=1;
   
    while(t--)
    solve();
   return 0;
}
