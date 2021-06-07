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
vi v(n);unordered_map<ll,bool>mp;
fr(i,n){cin>>v[i];mp[v[i]]=true;}

while(true){
   
    int n1=v.size();
    if(n1>300){
        cout<<"NO\n";return;
    }
    bool flag=true;
    for(int i=0;i<n1-1;i++){
        for(int j=i+1;j<n1;j++){
            ll x=abs(v[j]-v[i]);
            if(x>1000000000){
                cout<<"NO\n";return;
            }
            if(!mp[x]){
                flag=false;
                v.push_back(x);
                mp[x]=true;
            }
        }
    }
    if(flag){
        cout<<"YES\n"<<v.size()<<"\n";
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";

        }cout<<"\n";
        return;
        
    }
}

}



int main() {
    int t;cin>>t;
    while(t--)
    solve();
   return 0;
}
