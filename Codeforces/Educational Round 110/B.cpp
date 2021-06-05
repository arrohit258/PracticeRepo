#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;



void solve(){
 
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)cin>>a[i];
sort(a,a+n);
vector<int>v;
for(int i=0;i<n;i++)
if(a[i]%2==0)v.push_back(a[i]);
for(int i=0;i<n;i++)
if(a[i]%2==1)v.push_back(a[i]);
int ans=0;
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(__gcd(v[i],2*v[j])>1)ans++;
    }
}
cout<<ans<<"\n";



}
int main() {
   int t;cin>>t;
    while(t--)
    solve();
   return 0;
}
