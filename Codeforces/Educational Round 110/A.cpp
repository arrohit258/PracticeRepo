#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
 
 
void solve(){
 
int a,b,c,d;
cin>>a>>b>>c>>d;
if(min(a,b)>max(c,d) || min(c,d)>max(a,b)){
    cout<<"NO\n";
}
 else cout<<"YES\n";
 
 
}
int main() {
   int t;cin>>t;
    while(t--)
    solve();
   return 0;
}
