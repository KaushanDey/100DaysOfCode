#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)

ll noOfDigits(ll n)
{
    ll cnt = 0;
    while (n > 0)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}

ll noOfNines(ll n){
    ll cnt = 0;
    while(n>0){
        ll t = n%10;
        if(t==9) cnt++;
        n/=10;
    }
    return cnt;
}
int main()
{
    fastio;
    ll m = 2e5;
    ll mod = 1e9+7;
    vector<vector<ll>> dp(m+1,vector<ll> (10));
    for(ll i=0;i<10;i++) dp[0][i] = 1;
    for(ll i=1;i<=m;i++){
        for(ll j=0;j<10;j++){
            if(j<9){
                dp[i][j] = dp[i-1][j+1]%mod;
                continue;
            }
            dp[i][j] = (dp[i-1][0]%mod + dp[i-1][1]%mod)%mod;

        }
    }
    ll t = 1;
    cin >> t;
    while (t--)\
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> v(10,0);
        while(n>0){
            ll t = n%10;
            v[t]++;
            n/=10;
        }
        ll ans = 0;
        for(ll i=0;i<10;i++){
            ans=(ans%mod + ((dp[m][i]%mod)*(v[i]%mod))%mod)%mod;
        }
        cout<<ans<<"\n";
    }
}