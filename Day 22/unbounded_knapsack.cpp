#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &profit,vector<int> &weight,int n,int w,int index,vector<vector<int>> &dp){

    if(w==0) return 0;
    if(index==0){
        if(w%weight[index]==0) return (w/weight[index])*profit[index];
        else return 0;
    }

    if(dp[index][w]!=-1) return dp[index][w];
    //take index
    int take=-1e9;
    if(w>=weight[index]) take = profit[index]+maxProfit(profit,weight,n,w-weight[index],index,dp);
    int notTake = maxProfit(profit,weight,n,w,index-1,dp);

    return dp[index][w]=max(take,notTake);

}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n,vector<int> (w+1,-1));
    return maxProfit(profit,weight,n,w,n-1,dp);
}

int main(){
    int n,w;
    cin>>n>>w;
    vector<int> profit(n);
    vector<int> weight(n);
    for(int i=0;i<n;i++) cin>>profit[i];
    for(int i=0;i<n;i++) cin>>weight[i];
    cout<<unboundedKnapsack(n,w,profit,weight);
}