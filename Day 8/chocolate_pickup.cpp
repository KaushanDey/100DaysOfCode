#include <bits/stdc++.h>
using namespace std;

int maxChoco(int &r,int &c,vector<vector<int>> &grid,int i,int j1,int j2, vector<vector<vector<int>>> &dp){

    if(i>=r || j1<0 || j2<0 || j1>=c || j2>=c){
        return INT_MIN;
    }

    if(i==r-1){
        if(j1==j2){
            return grid[i][j1];
        }
        return grid[i][j1]+grid[i][j2];
    }

    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    
    int Max = INT_MIN;
    int choco;
    if(j1==j2){
        choco = grid[i][j1];
    }else{
        choco = grid[i][j1]+grid[i][j2];
    }
    for(int a=j1-1;a<=j1+1;a++){
        for(int j=j2-1;j<=j2+1;j++){
            Max = max(Max,maxChoco(r,c,grid,i+1,a,j,dp));
        }
    }

    return dp[i][j1][j2]=choco+Max;

}
int maximumChocolates(int &r, int &c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r,vector<vector<int>> (c,vector<int> (c,-1)));
    return maxChoco(r,c,grid,0,0,c-1,dp);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int r,c;
        cin>>r>>c;
        vector<vector<int>> grid(r,vector<int> (c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>grid[i][j];
            }
        }
        cout<<maximumChocolates(r,c,grid)<<"\n";
    }
}