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
int n;cin>>n;
vi arr(n);
fr(i,n)cin>>arr[i];
int min_pos=-1,max_pos=-1,min_ele=INT_MAX,max_ele=INT_MIN;
fr(i,n){
    if(arr[i]>max_ele){
        max_ele=arr[i];
        max_pos=i;
    }
    if(arr[i]<min_ele){
        min_ele=arr[i];
        min_pos=i;
    }
}
int ans1=max(max_pos,min_pos)+1;
int ans2=max(n-max_pos,n-min_pos);
int ans3=max_pos+1+n-min_pos;
int ans4=min_pos+1+n-max_pos;
cout<<min(min(ans1,ans2),min(ans3,ans4))<<endl;


}
int main() {
    int t;
   cin>>t;
    while(t--)
    solve();
   return 0;
}
