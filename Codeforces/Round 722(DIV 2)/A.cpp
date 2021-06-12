#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    int i=1;
    while(i<n){
        if(arr[i]!=arr[i-1])break;
        i++;
    }
    cout<<n-i<<endl;
}
int main() {
    int t;cin>>t;
    while(t--)solve();
}
