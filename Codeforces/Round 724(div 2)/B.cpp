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

unordered_map<string,int>mp;
for(int i=0;i<n;i++){
    for(int j=1;j<=3;j++){
        if(i+j-1>=n)continue;
        mp[s.substr(i,j)]++;
    }
}

for(int i=0;i<26;i++){
    string t;
    t+='a'+i;
    if(!mp[t]){
        cout<<t<<endl;return;
    }
}
for(int i=0;i<26;i++){
     string t;
    t.push_back('a'+i);
    for(int j=0;j<26;j++){
        t.push_back('a'+j);
        if(!mp[t]){//cout<<1;
            cout<<t<<endl;return;
        }
        t.pop_back();
    }
}
for(int i=0;i<26;i++){
     string t;
    t+='a'+i;
    for(int j=0;j<26;j++){
        t+='a'+j;
        for(int k=0;k<26;k++){
            t+='a'+k;
            if(!mp[t]){
            cout<<t<<endl;return;
        }t.pop_back();

        }
        t.pop_back();
        
    }
}



}



int main() {
    int t;cin>>t;
    while(t--)
    solve();
   return 0;
}
