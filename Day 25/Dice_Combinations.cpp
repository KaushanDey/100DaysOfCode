#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll MOD=1e9+7;

ll noOfWays(ll target,vector<ll> &dp){
    if(target==0) return 1;
    ll ans=0;
    if(dp[target]!=-1) return dp[target];
    for(ll i=1;i<=6;i++){
        if(target>=i) ans= ((ans%MOD)+(noOfWays(target-i,dp)%MOD))%MOD;
    }
    return dp[target]=ans%MOD;
}
int main()
{
    fastio;
    ll n;
    cin>>n;
    vector<ll> dp(n+1,-1);
    cout<<noOfWays(n,dp);
}