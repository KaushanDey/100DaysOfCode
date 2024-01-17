#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
int main()
{
    fastio;
    ll n,m,k;
    ll mod = 998244353;
    cin>>n>>m>>k;
    ll ans=m%mod;
    for(ll i=0;i<k;i++){
        ans=((ans%mod)*(m-1)%mod*((n-1-i)%mod))%mod;
    }
    cout<<ans;
}