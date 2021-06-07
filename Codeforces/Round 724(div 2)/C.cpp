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
int n;cin>>n;
string s;
cin>>s;

int dp[n]={0};
dp[0]=1;
int itr=1;
int sumD[n]={0};
int sumK[n]={0};
sumD[0]=0;
sumK[0]=0;
if(s[0]=='D')sumD[0]++;
else sumK[0]++;
while(itr<n && s[itr]==s[0]){
    dp[itr]=itr+1;
    if(s[0]=='D')sumD[itr]=dp[itr];
    else sumK[itr]=dp[itr];
    itr++;
}
if(itr==n){
    fr(i,n)cout<<dp[i]<<" ";
    cout<<endl;
    return;
}
map<double,int>mp;
for(int i=itr;i<n;i++){
    sumD[i]=sumD[i-1];
    sumK[i]=sumK[i-1];
    if(s[i]=='D')sumD[i]++;
    else sumK[i]++;
    double temp=(sumD[i]*1.0)/sumK[i];
   
        dp[i]=mp[temp]+1;
      
        mp[temp]=dp[i];
    

}
fr(i,n)cout<<dp[i]<<" ";
cout<<"\n";


}



int main() {
    int t;cin>>t;
    while(t--)
    solve();
   return 0;
}
