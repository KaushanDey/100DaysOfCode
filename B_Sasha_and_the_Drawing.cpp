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
        ll n,k;
        cin>>n>>k;
        ll t = 4*n-2;
        if(k==t){
            cout<<2*n<<"\n";
            continue;
        }
        if(k==(t-1)){
            cout<<2*n-1<<"\n";
            continue;
        }
        if(k%2==0){
            cout<<k/2<<"\n";
        }else{
            ll t = (k-3)/2;
            cout<<t+2<<"\n";
        }
    }
}