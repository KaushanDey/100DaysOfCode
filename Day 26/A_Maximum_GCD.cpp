#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
    fastio;
    ll t=1;
    cin>>t;
    ll MAX=1e6;
    vector<ll> spf(MAX+1);
    for(ll i=0;i<=MAX;i++) spf[i]=i;
    spf[0]=0;
    spf[1]=0;
    for(ll i=2;i*i<=MAX;i++){
        if(spf[i]==i){
            for(ll j=i*i;j<=MAX;j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
    while(t--)
    {
        ll n;
        cin>>n;
        if(n<=3){
            cout<<1<<"\n";
            continue;
        }else if(n%2!=0){
            ll ans = (n-1)/spf[n-1];
            cout<<ans<<"\n";
            continue;
        }else{
            ll ans = n/spf[n];
            cout<<ans<<"\n";
        }
    }
}