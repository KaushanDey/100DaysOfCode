#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
    fastio;
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) cin>>arr[i];

    ll curr=0;
    for(ll i=0;i<n;i++){
        curr+=arr[i];
        if(curr<0) curr = 0;
    }
    cout<<curr;
}