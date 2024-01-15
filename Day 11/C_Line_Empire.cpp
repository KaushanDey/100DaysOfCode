#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

/*ll minCost(vector<ll> &arr,ll &n,ll &a,ll &b,ll index,ll cap,vector<vector<ll>> &dp){

    if(index==n){
        return b*abs(arr[cap]-arr[index]);
    }

    // pair<ll,ll> mp;
    // mp.first=index;
    // mp.second=cap;
    if(dp[index][cap]!=-1) return dp[index][cap];

    //change capital position to index
    ll res1 = a*abs(arr[cap]-arr[index])+minCost(arr,n,a,b,index+1,index,dp);
    //not change capital position
    ll res2 = minCost(arr,n,a,b,index+1,cap,dp);

    return dp[index][cap]=min(res1,res2)+b*abs(arr[cap]-arr[index]);
}

int main()
{
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n,a,b;
        cin>>n>>a>>b;
        vector<ll> arr(n+1);
        arr[0]=0;
        for(ll i=1;i<=n;i++) cin>>arr[i];
        map<pair<ll,ll>,ll> dpOptimised;
        vector<vector<ll>> dp(n+1,vector<ll> (n+1,-1));
        // for(ll i=0;i<=arr[n];i++) dp[0][i]=0;
        cout<<minCost(arr,n,a,b,1,0,dp)<<"\n";
    }
}*/

ll Solution(vector<ll> &arr,ll n,ll a,ll b){
    ll Min = INT_MAX;
    vector<ll> prefixSum(n+1);
    ll sum=0;
    for(ll i=0;i<=n;i++){
        sum+=arr[i];
        prefixSum[i]=sum;
    }
    for(ll i=0;i<=n;i++){
        ll minCost = ((prefixSum[n]-prefixSum[i])-(n-i)*arr[i])*b + arr[i]*b + arr[i]*a;
        Min = min(Min,minCost);
    }

    return Min;
}
int main()
{
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n,a,b;
        cin>>n>>a>>b;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) cin>>arr[i];
        vector<ll> prefixSum(n,0);
        prefixSum[0]=arr[0];
        for(ll i=1;i<n;i++) prefixSum[i]=prefixSum[i-1]+arr[i];
        ll ans = b*prefixSum[n-1];
        ll prev=b*arr[0];
        for(ll i=0;i<n;i++){
            ans=min(ans,prev +(arr[i]*a)+(prefixSum[n-1]-prefixSum[i]-((n-i-1)*arr[i]))*b);
            if(i+1!=n) prev+=(arr[i+1]-arr[i])*b;
        }
        cout<<ans<<"\n";
        //cout<<Solution(arr,n,a,b)<<"\n";
    }
}