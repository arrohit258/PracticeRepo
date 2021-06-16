
//https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1 
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int xr(int t1,int t2,int f1,int f2){
        return t1*f2+f1*t2;
    }
    int orop(int t1,int t2,int f1,int f2){
        return t1*f2 + t1*t2+f1*t2;
    }
    int andop(int t1,int t2,int f1,int f2){
        return t1*t2;
    }
    int opdecider(char c,int t1,int t2,int f1,int f2){
        if(c=='^')return xr(t1,t2,f1,f2);
        if(c=='|')return orop(t1,t2,f1,f2);
        return andop(t1,t2,f1,f2);
    }
    int countWays(int N, string S){
        // code here
        string expr;
        string op;
        for(auto e:S){
            if(e=='T'||e=='F')expr.push_back(e);
            else op.push_back(e);
        }
        int mod=1003;
        int n=expr.length();
        long long int dpT[n][n];
        long long int dpF[n][n];
        memset(dpT,0,sizeof dpT);
        memset(dpF,0,sizeof dpF);
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j){
                    if(expr[i]=='T')dpT[i][i]=1;
                    else dpF[i][j]=1;
                }
                // else if(j==i+1){
                //     dpT[i][j]=opdecider(op[i],dpT[i][i],dpT[j][j],dpF[i][i],dpF[j][j]);
                //     dpF[i][j]=4-dpT[i][j];
                    
                    
                // }
                else{
                    for(int k=i;k<j;k++){
                        long long int lt=dpT[i][k];
                        long long int rt=dpT[k+1][j];
                        long long int lf=dpF[i][k];
                        long long int rf=dpF[k+1][j];
                        if(op[k]=='^'){
                            dpT[i][j]+=lt*rf +lf*rt;
                            dpF[i][j]+=lf*rf+lt*rt;
                        }
                        else if(op[k]=='|'){
                            dpT[i][j]+=lt*rt+lt*rf+lf*rt;
                            dpF[i][j]+=lf*rf;
                        }
                        else if(op[k]=='&'){
                            dpT[i][j]+=lt*rt;
                            dpF[i][j]+=lt*rf+lf*rt+lf*rf;
                        }
                        
                    }
                    dpT[i][j]=(dpT[i][j]%mod +mod)%mod;
                        dpF[i][j]=(dpF[i][j]%mod+ mod)%mod;
                        
                    
                }
            }
        }
        
        return (dpT[0][n-1]%mod +mod)%mod;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
