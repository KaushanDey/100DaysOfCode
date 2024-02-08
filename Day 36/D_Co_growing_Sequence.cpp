#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> x(n);
        for(ll i=0;i<n;i++) cin>>x[i];
        cout<<0<<" ";
        ll prev = x[0];
        for(ll i=1;i<n;i++){
            ll temp = 0;
            for(ll j=0;j<30;j++){
                if((((prev>>j)&1)==1) && (((x[i]>>j)&1)==0)){
                    temp=temp+(1<<j);
                }
            }
            prev = x[i]^temp;
            cout<<temp<<" ";
        }
        cout<<"\n";
    }
}