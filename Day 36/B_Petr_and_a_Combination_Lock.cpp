#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define fr(i,n) for(ll i=0;i<n;i++)
ll gcd(ll a, ll b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    fastio;
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) cin>>arr[i];
    bool isPossible = false;
    for(ll i=0;i<(1<<n);i++){
        ll sum=0;
        for(ll j=0;j<n;j++){
            if((i>>j)&1){
                sum-=arr[j];
            }else{
                sum+=arr[j];
            }
        }
        if(sum%360==0){
            isPossible = true;
            break;
        }
    }

    if(isPossible) cout<<"YES";
    else cout<<"NO";
}