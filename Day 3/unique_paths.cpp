#include <bits/stdc++.h> 
using namespace std;
int paths(int m,int n, int i, int j, int output, vector<vector<int>> &dp){

	if(i==m-1 && j==n-1){
		output+=1;
		return output;
	}

	if(i>=m || j>=n){
		return 0;
	}

	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	//go right
	int res1 = paths(m,n,i,j+1,output,dp);
	//go down
	int res2 = paths(m,n,i+1,j,output,dp);

	return dp[i][j]=res1+res2;

}

int uniquePaths(int m, int n) {
	
	int i=0;
	int j=0;
	int output=0;
	vector<vector<int>> dp(m,vector<int> (n,-1));
	return paths(m,n,i,j,output,dp);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        cout<<uniquePaths(m,n)<<"\n";
    }
}