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


int k;cin>>k;
fr(i,1<<(k+1))
dp[i]=1;
string s;
cin>>s; 
int q;cin>>q;
reverse(s.begin(),s.end());

for(int i=((1<<k)-1);i>=1;i--){
    if(s[i-1]=='1')dp[i]=dp[2*i];
    else if(s[i-1]=='0')dp[i]=dp[2*i +1];
    else dp[i]=dp[2*i]+dp[2*i+1];
}
while(q--){
int p;char c;
cin>>p>>c;
p=(1<<k)-p;
int temp=dp[p];
 if(s[p-1]==c){
     cout<<dp[1]<<"\n";
     continue;
 }
 s[p-1]=c;
 if(s[p-1]=='1')dp[p]=dp[2*p];
    else if(s[p-1]=='0')dp[p]=dp[2*p +1];
    else dp[p]=dp[2*p]+dp[2*p+1];

 while(p>1){
     int idx=p/2;
     int temp2=dp[idx];
     if((p%2==1 && s[idx-1]!='1') ||(p%2==0 && s[idx-1]!='0')){
        dp[idx]-=temp;
        dp[idx]+=dp[p];
     }
     temp=temp2;
     p=p/2;
 }   

 cout<<dp[1]<<"\n";
}


}
int main() {
    int t=1;
   
    while(t--)
    solve();
   return 0;
}
