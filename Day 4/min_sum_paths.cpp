#include <bits/stdc++.h>
using namespace std;

int minSum(int &n,int &m,vector<vector<int>> &grid, int i, int j,vector<vector<int>> &dp){

    if(i==0 && j==0){
        return grid[i][j];
    }
    if(i<0 || j<0){
        return INT_MAX;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    //go up
    int res1 = minSum(n,m,grid,i-1,j,dp);

    //go left
    int res2 = minSum(n,m,grid,i,j-1,dp);

    return dp[i][j]=grid[i][j]+min(res1,res2);

}

int minSumIterative(int &n, int &m, vector<vector<int>> &grid, vector<int> &dpOptimized){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dpOptimized[j]=grid[i][j];
                continue;
            }
            int up=INT_MAX,left=INT_MAX;
            if(i>0){
                up=dpOptimized[j];
            }
            if(j>0){
                left=dpOptimized[j-1];
            }
            dpOptimized[j]=grid[i][j]+min(up,left);
        }
    }
    return dpOptimized[m-1];
}

int minSumPath(vector<vector<int>> &grid) {

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    vector<int> dpOptimized(m,-1);
    //return minSum(n,m,grid,n-1,m-1,dp);
    return minSumIterative(n,m,grid,dpOptimized);

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int m;
        cin>>n>>m;
        vector<vector<int>> grid(n,vector<int> (m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        cout<<minSumPath(grid)<<"\n";
    }
}