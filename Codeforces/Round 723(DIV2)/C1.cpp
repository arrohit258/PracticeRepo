#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<ll> vi;
class mycompare{
    public:
    bool operator()(const pair<ll,ll>&p1,const pair<ll,ll>&p2){
        if(p1.first==p2.first)
        return p1.second<p2.second;
        return p1.first>p2.first;

    }
};

void solve(){
int n;cin>>n;
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,mycompare>pq;
vi v(n);
for(int i=0;i<n;i++)
cin>>v[i];
vi prefix(n+1,0);
int cnt=0;
for(int i=1;i<=n;i++){
  //  cout<<v[i-1]<<endl;
   if(v[i-1]<0){
       prefix[i]=prefix[i-1];
       pq.push({0-v[i-1],i});
   }
   else{
       cnt++;
       prefix[i]=prefix[i-1]+v[i-1];
   }
  // cout<<prefix[i]<<" ";

}//cout<<endl;
while(!pq.empty()){
    pair<int,int>p=pq.top();
    pq.pop();
    bool ok=true;
    for(int i=n;i>=p.second;i--){
        prefix[i]-=p.first;
        if(prefix[i]<0)
        ok=false;
    }
    if(ok){cnt++; 
   // cout<<-p.first<<" "<<p.second<<endl;
    }
    else{
        for(int i=n;i>=p.second;i--)
        prefix[i]+=p.first;
    }
}

cout<<cnt;

 
}
int main() {
    int t=1;//cin>>t;
    while(t--)
    solve();
   return 0;
}
