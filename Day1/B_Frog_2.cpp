#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int minCost(vector<int> &h, int n, int k, vector<int> &dp){

    if(n==0) return dp[0]=0;
    if(n==1) return dp[1]=0;
    if(n==2) return dp[2]=abs(h[2]-h[1]);
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int Min = INT_MAX;
    for(int i=1;i<=k && n-i>=1;i++){
        Min=min(Min,abs(h[n]-h[n-i])+minCost(h,n-i,k,dp));
        
    }

    return dp[n] = Min;

}

int minCostIterative(vector<int> h, int n, int k, vector<int> &dp){

    dp[0]=0;
    dp[1]=0;
    dp[2] = abs(h[2]-h[1]);
    int Min = INT_MAX;
    for(int i=3;i<=n;i++){
        for(int j=1;j<=k && i-j>=1;j++){

            Min = min(Min,abs(h[i]-h[i-j])+dp[i-j]);
        }
        dp[i] = Min;
        Min = INT_MAX;
    }

    return dp[n];
}

int main()
{
    fastio;
    int N;
    cin>>N;
    int K;
    cin>>K;
    vector<int> h(N+1);
    vector<int> dp(N+1);
    for(int i=0;i<=N;i++) dp[i]=-1;
    for(int i=1;i<=N;i++) cin>>h[i];
    cout<<minCost(h,N,K,dp);
}