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
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n,x,y;
        cin>>n>>x>>y;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) cin>>arr[i];
        map<pair<ll,ll>,ll> num;
        ll ans=0;
        for(ll i=0;i<n;i++){
            ll a = arr[i]%x;
            ll b = arr[i]%y;
            ans+=num[{x-a,b}];
            if(a==0){
                a=x;
            }
            num[{a,b}]++;
        }
        cout<<ans<<"\n";
    }
}