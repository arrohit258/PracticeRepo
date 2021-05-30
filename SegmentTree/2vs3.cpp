#include<bits/stdc++.h>
using namespace std;


int power[100001];
void buildpower(){
    power[0]=1;
    for(int i=1;i<=100000;i++){
        power[i]=(power[i-1]*2)%3;
    }
}

void updateQuery(int *tree,int *arr,int start,int end,int treeIndex,int idx,int value){
    if(idx<start || idx>end)return;
    if(start==end){
        if(!arr[idx]){
        arr[idx]=value;
        tree[treeIndex]=value;
        }
        
        return;
    }
   int mid=(start+end)/2;
    if(idx>mid)
        updateQuery(tree,arr,mid+1,end,2*treeIndex+1,idx,value);
    else
        updateQuery(tree,arr,start,mid,2*treeIndex,idx,value);
    
    int left=tree[2*treeIndex];
    int right=tree[2*treeIndex+1];
    tree[treeIndex]=(left*power[end-mid]+right)%3;
    
    
}

void buildTree(int *tree,int *arr,int treeIndex,int si,int ei){
    if(si==ei){
        tree[treeIndex]=arr[si];
       // cout<<si<<" "<<ei<<" "<<tree[treeIndex]<<endl;
        return;
    }
    int mid=(si+ei)/2;
    buildTree(tree,arr,2*treeIndex,si,mid);
    buildTree(tree,arr,2*treeIndex+1,mid+1,ei);
    int left=tree[2*treeIndex];
    int right=tree[2*treeIndex+1];
    tree[treeIndex]=((left*power[ei-mid])%3+right)%3;
    // cout<<si<<" "<<ei<<" "<<tree[treeIndex]<<endl;
    
}
int query(int *tree,int start,int end,int treeIndex,int left,int right){
    if(right<start ||left>end)return 0;
    if(start>=left && end<=right) return(tree[treeIndex]*power[right-end]) % 3;
    int mid=(start+end)/2;
    int temp1=query(tree,start,mid,2*treeIndex,left,right);
    int temp2=query(tree,mid+1,end,2*treeIndex+1,left,right);
    return (temp1+temp2)%3;
   
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int *arr=new int[n];
    int i=0;
    for(auto e:s)arr[i++]=e-'0';
    int *tree=new int [4*n];
    
    buildTree(tree,arr,1,0,n-1);
    
    int q;cin>>q;
    while(q--){
        int a;
        cin>>a;
        if(a==0){
            int b,c;
            cin>>b>>c;
            cout<<query(tree,0,n-1,1,b,c)<<endl;
        }
        else
        {
            int c;cin>>c;
            updateQuery(tree,arr,0,n-1,1,c,1);
        }
    }
}


int main() {
    buildpower();
   solve();
}


