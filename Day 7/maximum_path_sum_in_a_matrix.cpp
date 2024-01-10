#include <bits/stdc++.h>
#define max3(a,b,c) max(a,max(b,c))
using namespace std;

int maxSum(vector<vector<int>> &matrix,int &n,int &m,int i,int j,vector<vector<int>> &dp){

    if(i>=n || j>=m || j<0){
        return INT_MIN;
    }

    if(i==n-1){
        return matrix[i][j];
    }

    if(dp[i][j]!=-1) return dp[i][j];

    //going to (i+1,j)
    int res1 = maxSum(matrix,n,m,i+1,j,dp);
    //going to (i+1,j-1)
    int res2 = maxSum(matrix,n,m,i+1,j-1,dp);
    //going to (i+1,j+1)
    int res3 = maxSum(matrix,n,m,i+1,j+1,dp);

    return dp[i][j]=matrix[i][j]+max3(res1,res2,res3);
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    int Max = INT_MIN;
    for(int i=0;i<m;i++){
        Max=max(Max,maxSum(matrix,n,m,0,i,dp));
    }
    return Max;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> matrix(n,vector<int> (m));
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) cin>>matrix[i][j];
        cout<<getMaxPathSum(matrix)<<"\n";
    }
}