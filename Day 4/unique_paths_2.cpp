#include <bits/stdc++.h>
using namespace std;

int paths(int &n,int &m,vector<vector<int>> &mat,int i,int j,int output,int &mod, vector<vector<int>> &dp){

    if(i<0 || j<0){
        return 0;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    if(mat[i][j]==-1){
        return dp[i][j]=0;
    }

    if(i==0 && j==0){
        return 1;
    }

    //go right
    int res1=paths(n,m,mat,i,j-1,output,mod,dp);
    //go down
    int res2=paths(n,m,mat,i-1,j,output,mod,dp);

    return dp[i][j]=(res1%mod+res2%mod)%mod;
}

int pathsIterative(int &n,int &m,vector<vector<int>> &mat,int &mod,vector<int> &dpOptimized){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dpOptimized[0]=1;
                continue;
            }
            if(mat[i][j]==-1){
                dpOptimized[j]=0;
                continue;
            }
            int up=0,left=0;
            if(i>0){
                up=dpOptimized[j];
            }
            if(j>0){
                left=dpOptimized[j-1];
            }
            dpOptimized[j] = (up%mod+left%mod)%mod;
        }
    }

    return dpOptimized[m-1]%mod;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    
    int output=0;
    int i=n-1;
    int j=m-1;
    int mod = 1e9+7;
    vector<vector<int>> dp(n,vector<int> (m,-1));
    vector<int> dpOptimized(m,-1);
    //return paths(n,m,mat,i,j,output,mod,dp);
    return pathsIterative(n,m,mat,mod,dpOptimized);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<vector<int>> mat(n,vector<int> (m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin>>mat[i][j];
        }
        cout<<mazeObstacles(n,m,mat)<<"\n";
    }
}