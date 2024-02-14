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
ll compare(ll p1, ll p2){
    return (p1>p2);
}
int main()
{
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) cin>>arr[i];
        vector<ll> zeroes(n);
        for(ll i=0;i<n;i++){
            ll x = arr[i];
            ll cnt=0;
            while(x%10==0){
                cnt++;
                x/=10;
            }
            zeroes[i]=cnt;
        }
        sort(zeroes.begin(),zeroes.end(),compare);
        ll cut = 0;
        for(ll i=0;i<n;i+=2){
            cut+=zeroes[i];
        }
        ll sum=0;
        for(ll i=0;i<n;i++){
            ll temp = arr[i];
            while(temp>0){
                sum++;
                temp/=10;
            }
        }
        if(sum-cut>=m+1) cout<<"Sasha\n";
        else cout<<"Anna\n";
    }
}