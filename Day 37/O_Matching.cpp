#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define fr(i,n) for(ll i=0;i<n;i++)

ll noOfWays(vector<vector<ll>> &arr, ll mask, ll &n, ll i,ll &m,vector<vector<ll>> &dp){

    if(i==n){
        return 1;
    }

    if(dp[i][mask]!=-1) return dp[i][mask];

    ll ans = 0;
    for(ll j=0;j<n;j++){
        if(arr[i][j]==1 && !((mask>>j)&1)){
            ans=((ans%m)+(noOfWays(arr,(mask | (1<<j)),n,i+1,m,dp)%m))%m;
        }
    }

    return dp[i][mask]=ans%m;
}

ll noOfWaysIterative(vector<vector<ll>> &arr, ll &n, ll mask, ll &m, vector<ll> &dp){

    ll i = __builtin_popcount(mask);
    if(i==n) return 1;
    if(dp[mask]!=-1) return dp[mask];
    ll ans=0;
    for(ll j=0;j<n;j++){
        if(arr[i][j] && !((mask>>j)&1)){
            ans = ((ans%m) + noOfWaysIterative(arr,n,(mask|(1<<j)),m,dp)%m)%m;
        }
    }
    return dp[mask] = ans%m;
}
int main()
{
    fastio;
    ll n;
    cin>>n;
    vector<vector<ll>> arr(n,vector<ll> (n));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++) cin>>arr[i][j];
    }
    ll m = 1e9+7;
    //vector<vector<ll>> dp(n,vector<ll> (pow(2,n),-1));
    //cout<<noOfWays(arr,0,n,0,m,dp)%m;
    vector<ll> dpOptimised(pow(2,n),-1);
    cout<<noOfWaysIterative(arr,n,0,m,dpOptimised);
}