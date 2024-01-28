#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll minimumCoins(vector<ll> &nums,ll &n,ll target, vector<ll> &dp){

    if(target==0) return 0;
    if(dp[target]!=-1) return dp[target];
    ll ans=1e9;
    for(ll i=0;i<n;i++){
        if(target>=nums[i]) ans=min(ans,1+minimumCoins(nums,n,target-nums[i],dp));
    }

    return dp[target]=ans;
}
int main()
{
    fastio;
    ll n,x;
    cin>>n>>x;
    vector<ll> nums(n);
    for(ll i=0;i<n;i++) cin>>nums[i];
    vector<ll> dp(x+1,-1);
    ll ans = minimumCoins(nums,n,x,dp);
    if(ans>=1e9) cout<<-1;
    else cout<<ans;
}