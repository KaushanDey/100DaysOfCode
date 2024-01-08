#include <bits/stdc++.h>
using namespace std;

int minSum(vector<vector<int>> &triangle, int n, int i, int j, vector<vector<int>> &dp){

    if(i==n-1 && j<n && j>=0){
        return triangle[i][j];
    }

    if(dp[i][j]!=-1) return dp[i][j];

    int res1 = minSum(triangle,n,i+1,j,dp);

    int res2 = minSum(triangle,n,i+1,j+1,dp);

    return dp[i][j]=triangle[i][j]+min(res1,res2);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return minSum(triangle,n,0,0,dp);
    //return minSumIterative(triangle,n,dp);
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> triangle(n);
        int x;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cin>>x;
                triangle[i].push_back(x);
            }
        }
        cout<<minimumPathSum(triangle,n)<<"\n";
    }
}