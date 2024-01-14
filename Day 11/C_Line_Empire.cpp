#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

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