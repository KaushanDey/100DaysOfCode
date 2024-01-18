#include <bits/stdc++.h>
using namespace std;

int maxValue(vector<int> &weight,vector<int> &value, int &n,int maxWeight,int index,vector<vector<int>> &dp){

    if(index==0){

        if(maxWeight>=weight[index]) return value[index];
        return 0;

    }
    if(maxWeight==0) return 0;
    if(dp[index][maxWeight]!=-1) return dp[index][maxWeight];
    
    int take=INT_MIN;
    //take index
    if(maxWeight>=weight[index]) take = value[index]+maxValue(weight,value,n,maxWeight-weight[index],index-1,dp);
    //not take index
    int notTake = maxValue(weight,value,n,maxWeight,index-1,dp); 

    return dp[index][maxWeight]=max(take,notTake);

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return maxValue(weight,value,n,maxWeight,n-1,dp);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> weight(n);
        vector<int> value(n);
        for(int i=0;i<n;i++) cin>>weight[i];
        for(int i=0;i<n;i++) cin>>value[i];
        int w;
        cin>>w;
        cout<<knapsack(weight,value,n,w)<<"\n";

    }
}