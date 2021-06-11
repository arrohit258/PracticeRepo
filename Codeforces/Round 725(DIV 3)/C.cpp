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
ll binary2(ll *arr,ll n,ll key,ll si){
      ll ans=-1;
    ll ei=n-1;
    while(si<=ei){
        ll mid=(si+ei)/2;
        if(arr[mid]>=key){
            ans=mid;
            ei=mid-1;
        }
        else
        si=mid+1;
    }
    return ans;
}
ll binary1(ll *arr, ll n,ll key,ll si){
    ll ans=-1;
    ll ei=n-1;
    while(si<=ei){
        ll mid=si+(ei-si)/2;
        if(arr[mid]<=key){
            ans=mid;
            si=mid+1;
        }
        else
        ei=mid-1;
    }
    return ans;
}
void solve(){
ll n,l,r;
cin>>n>>l>>r;
ll a[n];
fr(i,n)cin>>a[i];
sort(a,a+n); ll ans=0;
fr(i,n){
    ll x=binary2(a,n,l-a[i],i+1);
    ll y=binary1(a,n,r-a[i],i+1);
    //cout<<x<<" "<<y<<" "<<a[i]<<"\n";
    if(y==-1)continue;

    if(x==-1)continue;
    else {
        ans+=(y-x)+1;
    }
    
}cout<<ans<<"\n";

}
int main() {
    int t;
   cin>>t;
    while(t--)
    solve();
   return 0;
}
