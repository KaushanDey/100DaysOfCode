#include <bits/stdc++.h> 
using namespace std;

int pathsIterative(int &m,int &n,vector<int> &dpOptimized){

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0 && j==0){
				dpOptimized[0]=1;
				continue;
			}
			int up=0,left=0;
			if(i>0){
				up = dpOptimized[j];
			}
			if(j>0){
				left = dpOptimized[j-1];
			}
			dpOptimized[j]=up+left;
		}
	}

	return dpOptimized[n-1];


}

int uniquePaths(int m, int n) {
	
	int i=m-1;
	int j=n-1;
	int output=0;
	vector<vector<int>> dp(m,vector<int> (n,-1));
	vector<int> dpOptimized(n,0);
	//return paths(m,n,i,j,dp);
	return pathsIterative(m,n,dpOptimized);
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