#include <bits/stdc++.h>
using namespace std;

bool isPresent(int index,int n,int k,vector<int> &arr,vector<vector<int>> &dp){

    if(k==0){
        return true;
    }

    if(index==n-1){
        return (arr[n-1]==k);
    }

    if(dp[index][k]!=-1) return (dp[index][k]);

    bool take=false;
    //include arr[index]
    if(k>=arr[index]){
        take=isPresent(index+1,n,k-arr[index],arr,dp);
    }

    //exclude arr[index]
    bool notTake=isPresent(index+1,n,k,arr,dp);

    dp[index][k]=(take || notTake);
    return (take || notTake);

}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int> (k+1,-1));
    return isPresent(0,n,k,arr,dp);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        if(subsetSumToK(n,k,arr)){
            cout<<"true"<<"\n";
        }else cout<<"false"<<"\n";
    }
}