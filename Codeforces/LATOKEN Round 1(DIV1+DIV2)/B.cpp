#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define pq_mx priority_queue<ll>
#define pq_mn priority_queue<ll,vector<ll>,greater<ll>>
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

void help(ll a[],int n){
  
for(int i=1;i<n+1;i++){
    if(a[i]>a[i-1] && a[i]>a[i+1]){
        ll x=a[i]-a[i-1];
        ll y=a[i]-a[i+1];
        
        a[i]=max(a[i+1],a[i-1]);
    }
}

}

void solve(){
int n;cin>>n;

ll a[n+2];a[0]=0;a[n+1]=0;ll ans1=0;
fr(i,n){cin>>a[i+1];}
for(int i=1;i<n+2;i++){
    ans1+=abs(a[i]-a[i-1]);
}

if(n==1){
    cout<<a[1]<<"\n";return;
}
help(a,n);
help(a,n);
ll ans=0;

for(int i=1;i<=n+1;i++){
    ans+=abs(a[i]-a[i-1]);

}
ans=ans+((ans1-ans)/2);
cout<<ans<<"\n";


}
int main() {
    int t;
   cin>>t;
    while(t--)
    solve();
   return 0;
}
