#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int just_smaller_than(ll *arr, int key,int n){
int si=0,ei=n-1;
int ans=-1;
while(si<=ei){
    int mid=(si+ei)/2;
    if(arr[mid]==key)return mid;
    if(arr[mid]<key){
        ans=mid;
        si=mid+1;
    }
    else{
        ei=mid-1;
    }
}
return ans;
}
ll min(ll a, ll b){
    if(a<b)return a;
    return b;
}
void solve(){
    int n;cin>>n;
    ll arr[n];
    vector<ll>v1;
    int cnt=0;
    
   for(int i=0;i<n;i++){
       cin>>arr[i];
      
       if(arr[i]<=0)
       {cnt++;v1.push_back(arr[i]);}
   }
   sort(arr,arr+n);
    if(n==1 || !v1.size()){cout<<1<<endl;return;}
    if(v1.size()==1 ){cout<<2<<endl;return;}
    sort(v1.begin(),v1.end());
    int mn=INT_MAX;
    for(int i=1;i<v1.size();i++)
    mn=min(mn,v1[i]-v1[i-1]);
    int idx=just_smaller_than(arr,mn,n);
    if(idx==-1 || arr[idx]<=0){
        cout<<v1.size()<<endl;
        return;
    }
    cout<<v1.size()+1<<endl;
}
int main() {
    int t;cin>>t;
    while(t--)solve();
}
