#include<bits/stdc++.h>
using namespace std;

long noOfWays(vector<int> &arr,int &n,int index,int value,vector<vector<long>> &dp){

    if(value==0) return 1;
    if(index==0){
        if(value%arr[index]==0) return 1;
        return 0;
    }

    if(dp[index][value]!=-1) return dp[index][value];

    //take arr[index]
    long take = 0;
    if(value>=arr[index]) take = noOfWays(arr,n,index,value-arr[index],dp);

    long notTake = noOfWays(arr,n,index-1,value,dp);

    return dp[index][value]=take+notTake;

}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<int> arr(n);
    for(long i=0;i<n;i++) arr[i]=denominations[i];
    vector<vector<long>> dp(n,vector<long> (value+1,-1));
    return noOfWays(arr,n,n-1,value,dp);
}

int main(){
    int n;
    cin>>n;
    int denominations[n];
    for(int i=0;i<n;i++) cin>>denominations[i];
    int value;
    cin>>value;
    cout<<countWaysToMakeChange(denominations,n,value);
}