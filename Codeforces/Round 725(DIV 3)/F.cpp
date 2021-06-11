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




void solve(){
ll l,r;
cin>>l>>r;
ll x=10;ll ans=r-l;
for(ll i=1;i<=9;i++){
    for(ll k=0;k<=9;k++){
        if(l>=x*(k) && r>x*k && l<x*(k+1)&&r<x*(k+1)){
            cout<<ans<<"\n";return;
        }
    }
  ll a=(r-l)/x;
  ll b= ((r%x) <l%x)?1:0;
  ans=ans+a+b;
x=x*10;
}
cout<<ans<<"\n";


}
int main() {
    int t;
   cin>>t;
    while(t--)
    solve();
   return 0;
}
