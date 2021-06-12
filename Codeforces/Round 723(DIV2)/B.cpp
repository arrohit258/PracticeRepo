#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<ll> vi;

bool cal(ll a){
    if(a<0)return false;
    ll b=a;
    while(a>0){
        if(a%11==0)return true;
        a=a-111;
        
    }
return a==0;
}

void solve(){
ll a;
cin>>a;
bool ans1=cal(a-11111111);
bool ans2=cal(a-2*11111111);
if(ans1 || ans2){
    cout<<"YES\n";
    return;
}

bool ans=cal(a);
if(ans)cout<<"YES\n";
else
cout<<"NO\n";



 
}
int main() {
    int t;cin>>t;
    while(t--)
    solve();
   return 0;
}
