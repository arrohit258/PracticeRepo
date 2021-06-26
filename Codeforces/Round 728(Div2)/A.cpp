#include <bits/stdc++.h>

using namespace std;
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define F first
#define S second
#define setbit(n) __builtin_popcountll(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))

#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define endl "\n" //delete if interactive
//using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define pq_mx priority_queue<ll>
#define pq_mn priority_queue<ll,vector<ll>,greater<ll>>

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);


int mod=1e9 +7;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

// ll power(ll a,ll b){
//     if(b==0)return 1;
//     if(b==1)return a%mod;
//     ll sub=((power(a,b/2)*power(a,b/2))%mod+mod)%mod;
//     if(b%2==1)return ((a*sub)%mod +mod)%mod;
//     else return sub;
    
// }

// ll findpar(vector<ll>&dsu,int i){
// if(dsu[i]==i)return i;
// return dsu[i]=findpar(dsu,dsu[i]);
// }
ll max(ll a,ll b){
    if(a<b)return b;
    return a;
}
ll min(ll a,ll b){
    if(a<b)return a;
    return b;
}
/*
int binary_just_greater_than(ll *a,ll n,ll key){
    //return index of anumbers just greater than or equal to the given key element
    ll si=0,ei=n-1;
    ll ans=-1;
    while(si<=ei){
        ll mid=(si+ei)/2;
        if(a[mid]>=key){
            ans=mid;
            ei=mid-1;
        }
        else
            si=mid+1;
    }
    return ans;
}

int binary_just_smaller_than(ll*a, ll n,ll key){
    //return index of a number just smaller than or equal to the given key element
    ll si=0,ei=n-1;
    ll ans=-1;
    while(si<=ei){
        ll mid=si+((ei-si)/2);
        if(a[mid]<=key){
            ans=mid;
            ei=mid-1;
        }
        else
            si=mid+1;
    }
    return ans;
}

ll modofanumber(ll a){
    return (a%mod+mod)%mod;
}
ll modofsum(ll a,ll b){
    return ((a%mod + b%mod)%mod +mod)%mod;
}
ll modofproduct(ll a, ll b){
    return (((a%mod)*(b%mod))%mod +mod)%mod;
}
*/

void solve(){
        

int n;cin>>n;
if(n%2==1){
if(n==3){
    cout<<3<<" "<<1<<" "<<2<<"\n";
}
else {
    
    for(int i=1;i<=n-3;i=i+2){
        cout<<i+1<<" "<<i<<" ";

    }
    cout<<n<<" "<<n-2<<" "<<n-1<<"\n";
}
}
else {
    for(int i=1;i<=n;i=i+2){
        cout<<i+1<<" "<<i<<" ";
    }
    cout<<"\n";
}

 
}






int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("err.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
 
    int t;
    cin >> t;
    while (t--)
    {solve();}
    return 0;
}
 
