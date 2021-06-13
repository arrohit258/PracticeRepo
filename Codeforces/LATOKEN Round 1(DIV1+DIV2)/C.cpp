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

ll power(ll a,ll b){
    if(b==0)return 1;
    if(b==1)return a%mod;
    ll sub=((power(a,b/2)*power(a,b/2))%mod+mod)%mod;
    if(b%2==1)return ((a*sub)%mod +mod)%mod;
    else return sub;
    
}

void solve(){
int n;cin>>n;
ll a1[n+1],a2[n+1];
unordered_map<int,int>mp1;
unordered_map<int,int>mp2;
int pairs=0;
unordered_map<int,bool>done;
for(int i=1;i<=n;i++)
{cin>>a1[i];mp1[a1[i]]=i;}
for(int i=1;i<=n;i++)
{cin>>a2[i];mp2[a2[i]]=i;}
for(int i=1;i<=n;i++){
    if(a1[i]==a2[i]){
        cout<<0<<"\n";return;
    }
}

for(int i=1;i<=n;i++){
    if(done[i])continue;
   
    int x=a1[i];
    int y=a2[i];
    done[i]=true;
    while(a1[mp2[x]]!=y){
           done[mp2[x]]=true;
        x=a1[mp2[x]];
     

    }done[mp1[y]]=true;
    pairs++;
}
cout<<power(2,pairs)<<"\n";

}
int main() {
    int t;
   cin>>t;
    while(t--)
    solve();
   return 0;
}
