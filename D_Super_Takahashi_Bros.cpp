#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll minTime(vector<vector<ll>> &arr, ll &n, ll i,vector<ll> visited,vector<ll> &dp){

    if(i>=(n-1)){
        return 0;
    }
    visited[i]=1;
    if(dp[i]!=-1) return dp[i];
    //take ai seconds
    ll take1 = arr[i][0]+minTime(arr,n,i+1,visited,dp);
    //take bi seconds
    ll t = arr[i][2]-1;
    ll take2 = INT_MAX;
    if(t>=0 && t<n && visited[t]==0){
        take2 = arr[i][1]+minTime(arr,n,t,visited,dp);
    }
    

    return dp[i]=min(take1,take2);
}
int main()
{
    fastio;
    ll n;
    cin>>n;
    ll cnt=0;
    vector<vector<ll>> arr(n-1,vector<ll> (3));
    for(ll i=0;i<(n-1);i++) cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    vector<ll> dp(n-1,-1);
    vector<ll> visited(n-1,0);
    cout<<minTime(arr,n,0,visited,dp);

}