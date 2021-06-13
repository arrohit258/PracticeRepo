#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define pq_mx priority_queue<ll>
#define pq_mn priority_queue<ll,vector<ll>,greater<ll>>
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

bool bfs(vector<vector<char>>&v,int n,int m){
    queue<pair<int,int>>q;
    vector<vector<int>>visited(n,vector<int>(m,0));
    char col='.';
    for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
         if(v[i][j]!='.'){
        q.push({i,j});col=v[i][j];break;
    }

    }
    if(col!='.')break;
    }

    int dx[]={0,0,-1,1};
    int dy[]={-1,1,0,0};
    while(!q.empty()){
        int len=q.size();
        for(int i=0;i<len;i++){
           pair<int,int>front=q.front();
            q.pop();
            //cout<<front.first<<" "<<front.second<<"\n";
            int x=front.first,y=front.second;
            if(v[x][y]=='.')v[x][y]=col;
            if(v[x][y]!=col)return false;
            for(int j=0;j<4;j++){
                int x1=x+dx[j];
                int y1=y+dy[j];
                if(x1>=0 && y1>=0 &&x1<n && y1<m && visited[x1][y1]==0){
                    visited[x1][y1]=1;
                    
                    q.push({x1,y1});
                }
            }
        }
        if(col=='R')col='W';
        else col='R';
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<v[i][j];
    }cout<<"\n";
    }
  return true;
   
}

void solve(){
int n,m;cin>>n>>m;
vector<vector<char>>v(n,vector<char>(m));
fr(i,n){
    for(int j=0;j<m;j++)cin>>v[i][j];
}
bool isempty=true;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(v[i][j]!='.'){
            isempty=false;
            
            break;

        }if(!isempty)break;
    }
}
if(isempty)v[0][0]='R';
bool ans=bfs(v,n,m);
if(!ans)cout<<"NO\n";


}
int main() {
    int t;
   cin>>t;
    while(t--)
    solve();
   return 0;
}
