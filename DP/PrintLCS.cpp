#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll,vector<ll>,greater<ll>>


ll max(ll a,ll b){
    if(a>b)return a;
    return b;
}

void printString(vvi &dp,string s,string t, int m,int n){
    string temp;
    int mx=dp[0][0];
    if(mx==0)return;
    int k=-1;
    
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(int i=0;i<m;i++){
        for(int j=k+1;j<n;j++){
            if(s[i]==t[j] && dp[i][j]==mx){
                temp.push_back(s[i]);
                k=j;

                mx--;
                break;
            }

        }
        if(mx<=0)break;
    }
   
    cout<<temp;
}

void rec(string s, string t){
    //KNAPSACK PROBLEM
    int m=s.length(),n=t.length();
   vvi dp(m+1,vi(n+1,0));
   if(s[m-1]==t[n-1])
   dp[m-1][n-1]=1;
   for(int i=m-1;i>=0;i--){
       for(int j=n-1;j>=0;j--){
           dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
           if(s[i]==t[j])
           dp[i][j]=max(dp[i][j],1+dp[i+1][j+1]);
       }
   }  

   printString(dp,s,t,m,n);

}

void solve(){
 
string a,b;
cin>>a>>b;
rec(a,b);





}
int main() {
    int t=1;
   
    while(t--)
    solve();
   return 0;
}
