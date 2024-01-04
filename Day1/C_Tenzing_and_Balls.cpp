#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fr(i,n) for(ll i=0;i<n;i++)
const ll MAX = 1e6;
ll dp[MAX+1];

ll maxRemove(ll n, vector<ll> a, map<ll,ll> mx){
    
    dp[0]=0;
    dp[1]=0;
    dp[2]=0;
    for(ll i=1;i<=n;i++){
        dp[i]=max(i+mx[a[i]], dp[i-1]);
        mx[a[i]] = max(mx[a[i]],dp[i-1]-i+1);
    }

    return dp[n];
}
int main()
{
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
        for(ll i=0;i<=MAX;i++) dp[i]=-1;
        ll n;
        cin>>n;
        vector<ll> a(n+1);
        for(ll i=1;i<=n;i++) cin>>a[i];
        map<ll,ll> mx;
        for(ll i=0;i<=n;i++) mx[i] = INT_MIN;
        cout<<maxRemove(n,a,mx)<<"\n";
    }
}