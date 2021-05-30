#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
class Node{
    public:
    ll sum;
    ll max_sum;
    ll max_sum_si;
    ll max_sum_ei;
    
};
Node getMax(Node*tree,int start,int end,int treeIndex,int left,int right){
    if(start>right || end<left){
        Node temp;
       temp.sum=LLONG_MIN;temp.max_sum_ei=LLONG_MIN,temp.max_sum_si=LLONG_MIN,temp.max_sum=LLONG_MIN;
        return temp;
    }
    if(start >=left &&end<=right){
		return tree[treeIndex];
	}
	int mid=(start+end)/2; Node temp;
    Node temp1=getMax(tree,start,mid,2*treeIndex,left,right);
	Node temp2=getMax(tree,mid+1,end,2*treeIndex+1,left,right);
	if(temp1.sum==LLONG_MIN)return temp2;
	if(temp2.sum==LLONG_MIN)return temp1;
    temp.sum=temp1.sum+temp2.sum;
    temp.max_sum_si=max(temp1.max_sum_si,temp1.sum+temp2.max_sum_si);
    temp.max_sum_ei=max(temp2.max_sum_ei,temp2.sum+temp1.max_sum_ei);
    temp.max_sum=max(max(max(temp1.max_sum,temp2.max_sum),max(temp1.max_sum_ei+temp2.max_sum_si,temp.max_sum_ei)),temp.max_sum_si);
	return temp;

}

void build(Node*tree,int *arr,int si,int ei,int treeIndex){
    if(si==ei){
        Node temp;
        temp.max_sum=arr[si],temp.max_sum_si=arr[si],temp.max_sum_ei=arr[si],temp.sum=arr[si];
        tree[treeIndex]=temp;
        return;
    }
    int mid=(si+ei)/2;
    build(tree,arr,si,mid,2*treeIndex);
    build(tree,arr,mid+1,ei,2*treeIndex+1);
    Node temp;
    Node temp1=tree[2*treeIndex];
    Node temp2=tree[2*treeIndex+1];
    temp.sum=temp1.sum+temp2.sum;
    temp.max_sum_si=max(temp1.max_sum_si,temp1.sum+temp2.max_sum_si);
    temp.max_sum_ei=max(temp2.max_sum_ei,temp2.sum+temp1.max_sum_ei);
    temp.max_sum=max(max(max(temp1.max_sum,temp2.max_sum),max(temp1.max_sum_ei+temp2.max_sum_si,temp.max_sum_ei)),temp.max_sum_si);
    tree[treeIndex]=temp;
}


void solve(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    Node *tree=new Node[4*n];
    build(tree,arr,0,n-1,1);
	int q;cin>>q;
	while(q--){
		int a,b;cin>>a>>b;
		cout<<getMax(tree,0,n-1,1,a-1,b-1).max_sum<<endl;
	}
}
int main(){
    solve();
}
