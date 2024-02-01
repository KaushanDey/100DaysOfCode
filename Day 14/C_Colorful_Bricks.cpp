#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll binaryExponentiation(ll n,ll m,ll mod){
    if(m==0) return 1;
    if(m%2==0) return ((n%mod)*(binaryExponentiation(((n%mod)*(n%mod))%mod,(m-1)/2,mod)%mod))%mod;
    return (binaryExponentiation(((n%mod)*(n%mod))%mod,(m-1)/2,mod)%mod);
}

ll fact(ll n,ll mod){

    if(n==1 || n==0) return 1;
    return ((n%mod)*(fact(n-1,mod)%mod))%mod;
}
int main()
{
    fastio;
    ll n,m,k;
    ll mod = 998244353;
    cin>>n>>m>>k;
    ll ans=m%mod;
    ll temp=fact(k,mod)%mod;
    for(ll i=1;i<=k;i++){
        ans=((ans%mod)*((n-i)%mod))%mod;
    }
    ll temp3 = binaryExponentiation(m-1,k,mod)%mod;
    ll temp2 = binaryExponentiation(temp,mod-2,mod)%mod;
    ans = ((ans%mod)*(temp2%mod)*(temp3%mod))%mod;
    cout<<ans;
}