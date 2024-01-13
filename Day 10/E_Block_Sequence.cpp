#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int minRemoval(vector<ll> &arr,ll &n,vector<ll> &dp){

    dp[n]=0;
    dp[n-1]=1;
    for(ll i=n-2;i>=0;i--){
        ll pick=INT_MAX;
        //take arr[index]
        if(i+arr[i]<n){
            pick = dp[i+arr[i]+1];
        }
        //not take arr[index]
        ll notPick = 1+dp[i+1];
        dp[i] = min(pick,notPick);
    }

    return dp[0];
}
int main()
{
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) cin>>arr[i];
        vector<ll> dp(n+1,-1);
        cout<<minRemoval(arr,n,dp)<<"\n";
    }
}