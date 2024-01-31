#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) cin>>arr[i];
        ll mini = 1e9+1;
        for(ll i=0;i<n;i++){
            if(arr[i]<k) continue;
            else mini = min(mini,arr[i]%k);
        }
        if(mini==1e9+1) cout<<-1<<"\n";
        else cout<<mini<<"\n";
    }
    
}
