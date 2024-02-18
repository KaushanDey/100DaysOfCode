#include <bits/stdc++.h>
#include<string>
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
    vector<ll> a(n);
    vector<pair<ll,ll>> s(n-1);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<(n-1);i++) cin>>s[i].first>>s[i].second;
    for(ll i=0;i<(n-1);i++){
        ll t = a[i]/(s[i].first);
        a[i+1] += t*(s[i].second);
    }
    cout<<a[n-1];
}