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
    ll n,m,k;
    cin>>n>>m>>k;
    ll a = min(n,m);
    ll b = max(n,m);
    ll temp = __gcd(b,a);
    ll temp1 = (a/temp)*b;
    ll cnt = 0;
    ll i = 1,j=1;
    ll ans = temp+temp1;
    cout<<ans;
    // while(cnt<k){
    //     if(i*a<b){
    //         cnt++;
    //         ans = i*a;
    //         i++;
    //     }else{
    //         if(i*a<j*b){
    //             cnt++;
    //             ans = i*a;
    //             i++;
    //         }else if(i*a>j*b){
    //             cnt++;
    //             ans = j*b;
    //             j++;
    //         }else if(i*a==j*b){
    //             i++;
    //             j++;
    //         }
    //     }
    // }
    // cout<<ans;
}