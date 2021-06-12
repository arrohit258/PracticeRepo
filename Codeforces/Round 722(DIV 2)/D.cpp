#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#include <bits/stdc++.h>
using namespace std;
  
// Function to find the number of divisors
// of all numbers in the range [1, n]
void findDivisors(int n,vector<ll>&multiply)
{
  
  
    for (int i = 1; i <= n; i++) {
  
        // Increase divisors count for
        // every number divisible by i
        for (int j = 1; j * i <= n; j++)
            multiply[i*j]++;
    }
  
    // Print the divisors
    
}
void solve(){
    ll mod=998244353;
    int n;cin>>n;
    if(n==1){cout<<1<<endl;return;}
    if(n==2){cout<<3<<endl;return;}
    vector<ll>dp(n);ll sum=4;
    dp[0]=1;dp[1]=3;
    vector<ll>multiply(n+1,0);
    findDivisors(n,multiply);
    for(int i=2;i<n;i++){
        ll x=multiply[i+1];
       
        dp[i]=((sum%mod+x)%mod+mod)%mod;
       // dp[i]=(dp[i]+x)%mod;
        sum=((sum%mod+dp[i]%mod)%mod+mod)%mod;
        
    }
   cout<<dp[n-1]<<endl;

}
int main() {
    int t;t=1;
    while(t--)solve();
}
