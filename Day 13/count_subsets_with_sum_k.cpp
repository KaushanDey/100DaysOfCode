#include<bits/stdc++.h>
using namespace std;

int noOfWays(vector<int> &arr,int &n,int index,int k,int &mod,vector<vector<int>> &dp){

	if(index==0){
		if(k==0 && arr[index]==0) return 2;
		if(k==0 || arr[index]==k) return 1;
		return 0;
	}

	if(dp[index][k]!=-1) return dp[index][k];
	int take=0;
	//take arr[index]
	if(arr[index]<=k) take=noOfWays(arr,n,index-1,k-arr[index],mod,dp);
	//not take arr[index]
	int notTake=noOfWays(arr,n,index-1,k,mod,dp);

	return dp[index][k]=(take%mod+notTake%mod)%mod;
}
int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	int mod = 1e9+7;
	vector<vector<int>> dp(n,vector<int>(k+1,-1));
	return noOfWays(arr,n,n-1,k,mod,dp)%mod;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<findWays(arr,k);
}