#include <bits/stdc++.h>
using namespace std;

int noOfElements(vector<int> &num,int &n,int x,int index,vector<vector<int>> &dp){

    if(x==0) return 0;
    if(index==0){
        if(x%num[0]==0) return x/num[0];
        else return 1e9;
    }
    if(dp[index][x]!=-1) return dp[index][x];
    //take index
    int take = 1e9;
    if(x>=num[index]) take = 1+noOfElements(num,n,x-num[index],index,dp);
    //not take index
    int notTake = noOfElements(num,n,x,index-1,dp);

    return dp[index][x]=min(take,notTake);
}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n,vector<int> (x+1,-1));
    int ans = noOfElements(num,n,x,n-1,dp);
    if(ans>=1e9) return -1;
    return ans;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> num(n);
        for(int i=0;i<n;i++) cin>>num[i];
        cout<<minimumElements(num,x)<<"\n";
    }
}