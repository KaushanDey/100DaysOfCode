#include<bits/stdc++.h>
using namespace std;

int maxCost(vector<int> &price,int &n,int len,int index,vector<vector<int>> &dp){

	if(len==0) return 0;
	if(index==0){
		return price[index]*len;
	}
	if(dp[index][len]!=-1) return dp[index][len];
	int take=-1e9;
	//take index
	if(len>=(index+1)) take = price[index]+maxCost(price,n,len-index-1,index,dp);
	int notTake = maxCost(price,n,len,index-1,dp);

	return dp[index][len]=max(take,notTake);
}
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n,vector<int> (n+1,-1));
	return maxCost(price,n,n,n-1,dp);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<cutRod(price,n)<<"\n";
    }
}
