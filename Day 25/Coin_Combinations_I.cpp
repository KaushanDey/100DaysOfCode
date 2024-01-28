#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll MOD=1e9+7;

ll noOfWays(vector<ll> &nums,ll &n,ll target,vector<ll> &dp){
    if(target==0) return 1;
    ll ans=0;
    if(dp[target]!=-1) return dp[target];
    for(ll i=0;i<n;i++){
        if(target>=nums[i]) ans= ((ans%MOD)+(noOfWays(nums,n,target-nums[i],dp)%MOD))%MOD;
    }
    return dp[target]=ans%MOD;
}
int main()
{
    fastio;
    ll n,x;
    cin>>n>>x;
    vector<ll> nums(n);
    for(ll i=0;i<n;i++) cin>>nums[i];
    vector<ll> dp(x+1,-1);
    cout<<noOfWays(nums,n,x,dp);
}