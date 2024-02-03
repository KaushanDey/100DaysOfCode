#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
    fastio;
    ll MAX = 1e6;
    vector<ll> spf(MAX+1);
    for(ll i=0;i<=MAX;i++) spf[i]=i;
    spf[0]=0;
    spf[1]=0;
    for(ll i=2;i*i<=MAX;i++){
        if(spf[i]==i){
            for(ll j=i*i;j<=MAX;j+=i){
                spf[j]=i;
            }
        }
    }

    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) cin>>arr[i];
    set<ll> st;
    bool isPairwise = 1;
    for(ll i=0;i<n;i++){
        ll k= arr[i];
        while(k>1){
            ll z = spf[k];
            while(k%z==0){
                k/=z;
            }
            if(st.find(z)==st.end()) st.insert(z);
            else{
                isPairwise = 0;
                break;
            }
        }
        if(!isPairwise) break;
    }
    if(isPairwise){
        cout<<"pairwise coprime";
        return 0;
    }

    ll gcc = arr[0];
    for(ll i=1;i<n;i++){
        gcc = __gcd(gcc,arr[i]);
    }
    if(gcc==1){
        cout<<"setwise coprime";
        return 0;
    }
    cout<<"not coprime";
}