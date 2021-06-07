bool isPossible(vector<int>&C,long long int mid,int A){
    int no_of_painters=1;
    long long int curr_sum=0;
    for(int i=0;i<C.size();i++){
        if(C[i]>mid)return false;
        if(curr_sum+C[i]>mid){
            no_of_painters++;
            curr_sum=C[i];
            if(no_of_painters>A)return false;
        }
        else
        curr_sum+=C[i];
    }
    return true;
}

int Solution::paint(int A, int B, vector<int> &C) {
    long long int sum=0;
    for(auto e:C)sum+=e;
    long long int si=1,ei=sum;
    long long int ans=-1;
    int mod=10000003;
    if(A==1)return (sum*B)%mod;
    while(si<=ei){
        long long int mid=(si+ei)/2;
        if(isPossible(C,mid,A)){
            ans=mid;
            ei=mid-1;
        }
        else si=mid+1;
    }
    //cout<<(ans*B)<<endl;
    return ((ans%mod)*(B%mod))%mod;
}
