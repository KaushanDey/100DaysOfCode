#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define fr(i,n) for(ll i=0;i<n;i++)
#define in_range(x,y,r,c) (x>=0 && x<r && y>=0 && y<c)

void Solution(vector<ll> &b, vector<ll> &c, ll index, ll k){

    ll tkae = INT_MIN

}
int main()
{
    fastio;
    ll t=1;
    cin>>t;

    vector<ll> dp(1001);
    dp[1]=0;
    for(ll i=2;i<1001;i++){
        ll n = floor(log2(i));
        ll t = __builtin_popcount(i);
        dp[i] = n+t-1;
    }
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        k = min(k,18*n);
        vector<ll> b(n);
        vector<ll> c(n);

    }
}