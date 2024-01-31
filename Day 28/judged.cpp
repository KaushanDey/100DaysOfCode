#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    
    ll t;
    cin>>t;
    while(t--){
        vector<ll> arr(5);
        for(ll i=0;i<5;i++) cin>>arr[i];
        ll cnt=0;
        for(ll i=0;i<5;i++) if(arr[i]==1) cnt++;
        if(cnt<4) cout<<"NO\n";
        else cout<<"YES\n";
    }
}
