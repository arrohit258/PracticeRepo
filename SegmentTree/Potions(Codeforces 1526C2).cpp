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
 
void buildTree(ll *tree,vi &prefix,int treeNode,int si,int ei){
    if(si==ei){
        tree[treeNode]=prefix[si];
        return;
    }
    int mid=(si+ei)/2;
    buildTree(tree,prefix,2*treeNode,si,mid);
    buildTree(tree,prefix,2*treeNode+1,mid+1,ei);
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
    
}
 
void updateRange(ll *lazy,ll *tree,int start,int end,int treeNode,int left,int right,int val ){
    if(lazy[treeNode]!=0){
        tree[treeNode]+=lazy[treeNode];
        if(start!=end){
            lazy[2*treeNode]+=lazy[treeNode];
            lazy[2*treeNode+1]+=lazy[treeNode];
            
        }
        lazy[treeNode]=0;
       
    }
    if(start>right || left>end)return;
    if(start>=left && end<=right){
        tree[treeNode]+=val;
        if(start!=end){
            lazy[2*treeNode]+=val;
            lazy[2*treeNode+1]+=val;
        }
        return;
    }
    int mid=(start+end)/2;
    updateRange(lazy,tree,start,mid,2*treeNode,left,right,val);
    updateRange(lazy,tree,mid+1,end,2*treeNode+1,left,right,val);
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
    
}

ll query(ll *lazy,ll *tree,int start,int end,int treeNode,int left,int right){
    if(lazy[treeNode]!=0){
        tree[treeNode]+=lazy[treeNode];
        if(start!=end){
            lazy[2*treeNode]+=lazy[treeNode];
            lazy[2*treeNode+1]+=lazy[treeNode];
            
        }
        lazy[treeNode]=0;
    }
    if(start>right || end<left)return INT_MAX;
    if(start>=left && end<=right)return tree[treeNode];
    int mid=(start+end)/2;
    ll leftMin=query(lazy,tree,start,mid,2*treeNode,left,right);
    ll rightMin=query(lazy,tree,mid+1,end,2*treeNode+1,left,right);
    return min(leftMin,rightMin);
    
    
}
 
 
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
 
}

ll *tree=new ll[4*(n)];
buildTree(tree,prefix,1,1,n);
ll *lazy=new ll[4*(n)];
for(int i=0;i<4*n;i++)lazy[i]=0;


while(!pq.empty()){
    pair<int,int>p=pq.top();
    pq.pop();
    
    ll temp=query(lazy,tree,1,n,1,p.second,n);
    
    if((temp-p.first)>=0){cnt++; 
    updateRange(lazy,tree,1,n,1,p.second,n,-p.first);
   // cout<<-p.first<<" "<<p.second<<endl;
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
