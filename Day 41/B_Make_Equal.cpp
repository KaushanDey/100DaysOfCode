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
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) cin>>arr[i];
        ll sum=0;
        for(ll i=0;i<n;i++){
            sum+=arr[i];
        }
        ll x = sum/n;
        bool isPossible = true;
        for(ll i=0;i<n;i++){
            if(arr[i]<x){
                isPossible = false;
                break;
            }
            ll y = arr[i]-x;
            if(i<(n-1)) arr[i+1]+=y;
        }
        if(isPossible) cout<<"YES\n";
        else cout<<"NO\n";
    }
}