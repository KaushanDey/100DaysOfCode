#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
    fastio;
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(ll i=0;i<(1<<n);i++){
        for(ll j=0;j<n;j++){
            if(i&(1<<j)!=0) cout<<arr[j]<<" ";
        }
        cout<<"\n";
    }
}