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

int main()
{
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> w(n);
        for(ll i=0;i<n;i++) cin>>w[i];
        sort(w.begin(),w.end());
        ll maxi = INT_MIN;
        for(ll i=0;i<n;i++){
            maxi = max(maxi,w[i]*(n-i));
        }
        cout<<maxi<<"\n";
    }
}