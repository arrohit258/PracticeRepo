#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<ll> vi;

void solve(){
int n;cin>>n;
vi v(2*n);
for(int i=0;i<2*n;i++)
cin>>v[i];
sort(v.begin(),v.end());
if(n<=1){
    for(auto e:v)
    cout<<e<<" ";
    cout<<endl;
    return;
}
for(int i=1;i<2*n;i=i+2){
    ll x=v[i];
    v[i]=v[i-1];
    v[i-1]=x;
}
ll x=v[0];
v[0]=v[2*n-1];
v[2*n-1]=x;
for(auto e:v)
cout<<e<<" ";
cout<<endl;

 
}
int main() {
    int t;cin>>t;
    while(t--)
    solve();
   return 0;
}
