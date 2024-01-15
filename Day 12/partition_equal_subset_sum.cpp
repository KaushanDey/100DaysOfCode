#include<bits/stdc++.h>
using namespace std;

bool Solution(vector<int> &arr,int &n,int index,int k, vector<vector<int>> &dp){

	if(index==n-1) return (arr[index]==k);

	if(k==0) return true;

	if(dp[index][k]!=-1) return dp[index][k];
	bool take=false;
	if(k>=arr[index]){
		take = Solution(arr,n,index+1,k-arr[index],dp);
	}
	bool notTake = Solution(arr,n,index+1,k,dp);

	dp[index][k]=(take || notTake);
	return (take || notTake);
}

bool canPartition(vector<int> &arr, int n)
{
	int target=0;
	for(int i=0;i<n;i++){
		target+=arr[i];
	}
	if(target%2!=0) return false;
	int k=target/2;
	vector<vector<int>> dp(n,vector<int> (k+1,-1));
	return Solution(arr,n,0,k,dp);
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        if(canPartition(arr,n)) cout<<"true"<<"\n";
        else cout<<"false"<<"\n";
    }
}
