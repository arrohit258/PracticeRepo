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
 
void solve(){
        
ll a,b,x,y;
cin>>a>>b>>x>>y;

ll dist1=abs(x-a)+abs(y-b)+abs(x-1)+abs(y-1);
ll dist2=abs(x-1)+abs(y-b)+abs(y-1)+abs(x-a);
if(dist1>dist2)
    cout<<a<<" "<<b<<" "<<1<<" "<<1<<endl;
else cout<<1<<" "<<b<<" "<<a<<" "<<1<<endl;
 
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
 
