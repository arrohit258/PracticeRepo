#include<bits/stdc++.h>
using namespace std;


void buildTree(int *tree,int *arr, int si,int ei,int treeNode){
    if(si==ei){
        tree[treeNode]=arr[si];
       
        return;
    }
    int mid=(si+ei)/2;
    buildTree(tree,arr,si,mid,2*treeNode);
    buildTree(tree,arr,mid+1,ei,2*treeNode+1);
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
}

int getMin(int *tree,int start,int end,int treeNode,int left,int right){
   
    if(start>right || end<left)return INT_MAX;
    if(start>=left && end<=right)return tree[treeNode];
    int mid=(start+end)/2;
    int ans1=getMin(tree,start,mid,2*treeNode,left,right);
    int ans2=getMin(tree,mid+1,end,2*treeNode+1,left,right);
 
    return min(ans1,ans2);
    
}
void update(int *tree,int *arr,int start,int end,int treeNode,int idx,int value){
    if(start==end){
        arr[idx]=value;
        tree[treeNode]=value;
        return;
    }
    int mid=(start+end)/2;
    if(idx>mid){
        update(tree,arr,mid+1,end,2*treeNode+1,idx,value);
    }
    else
        update(tree,arr,start,mid,2*treeNode,idx,value);
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
}
void solve(){
    int n,q;cin>>n>>q;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int *tree=new int[4*n];
    buildTree(tree,arr,0,n-1,1);
 
    
    
    while(q--){
        char c;cin>>c;
        int a,b;
        cin>>a>>b;
        if(c=='q')
        {int ans=getMin(tree,0,n-1,1,a-1,b-1);
        cout<<ans<<endl;}
        else{
            update(tree,arr,0,n-1,1,a-1,b);
        }
    }
    
 
    
}


int main() {
   solve();
}
