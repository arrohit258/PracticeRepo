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

ll dp[1<<19];


void solve(){
ll n;cin>>n;
ll a[n];
ll sum=0;
fr(i,n){cin>>a[i];sum+=a[i];}
if(sum%n !=0){
    cout<<-1<<"\n";
    return;
}
else{
    ll k=sum/n;
    ll ans=0;
    fr(i,n)
    if(a[i]>k)ans++;
    cout<<ans<<"\n";
}


}
int main() {
    int t;
   cin>>t;
    while(t--)
    solve();
   return 0;
}
