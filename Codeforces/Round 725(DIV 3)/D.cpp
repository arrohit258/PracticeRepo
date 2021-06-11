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
vector<int>prime;
void seive(){
    vector<bool>arr(100009,false);
    //bool arr[100009]={false};
    for(int i=2;i<=100000;i++){
        if(arr[i]==false){
            prime.push_back(i);
            for(int j=2;j*i<100009;j++)
            arr[j*i]=true;
        }
    }
    
}


ll powerfinder(ll a){
    ll ans=0;
   
    for(int i=0;i<prime.size();i++){
    while(a%prime[i]==0){
        ans++;a=a/prime[i];

    }

  }
  if(a!=1)ans++;
  return ans;
}
void solve(){//cout<<1<<endl;
ll x,y,k;
cin>>x>>y>>k;
ll a=max(x,y);
ll b=min(x,y);
ll ans1=powerfinder(a);
ll ans2=powerfinder(b);
if(a==1 && b==1){
    cout<<"NO\n";
    return;
}
if(a==b && k==1){
    cout<<"NO\n";
    return;
}
if(a%b==0 ){
    if(k==1 && a!=b){
        cout<<"YES\n";
        return;
    }
    

}


if(k>=2 && k<=ans1+ans2){
    cout<<"YES\n";return;
}
cout<<"NO\n";


}
int main() {
    int t;
   cin>>t;
   //cout<<1;
    seive();//cout<<2;
    while(t--)
    solve();
   return 0;
}
