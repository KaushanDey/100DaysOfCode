#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll binaryExponentiation(ll x,ll n,ll &m){

    if(n==0) return 1;

    if(n%2==0) return binaryExponentiation(((x%m)*(x%m))%m,n/2,m);
    return ((x%m)*(binaryExponentiation(((x%m)*(x%m))%m,(n-1)/2,m)%m))%m;
}
int main()
{
    fastio;
    ll m = 1e9+7;
    ll n;
    cin>>n;
    if(n==0){
        cout<<1;
        return 0;
    }
    ll temp1 = binaryExponentiation(2,(2*n)-1,m)%m;
    ll temp2 = binaryExponentiation(2,n-1,m)%m;
    ll ans = (temp1%m + temp2%m)%m;
    cout<<ans;
}