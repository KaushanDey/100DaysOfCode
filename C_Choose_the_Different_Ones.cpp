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
        ll n,m,k;
        cin>>n>>m>>k;
        vector<ll> a(n),b(m);
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll j=0;j<m;j++) cin>>b[j];
        set<ll> a1,b1;
        for(ll i=0;i<n;i++){
            if(a[i]>=1 && a[i]<=k){
                a1.insert(a[i]);
            }
            
        }
        for(ll i=0;i<n;i++){
            if(b[i]>=1 && b[i]<=k){
                b1.insert(b[i]);
            }
        }
        ll cnt1 = a1.size();
        ll cnt2=b1.size();
        auto it1 = a1.begin();
        auto it2 = b1.begin();
        vector<ll> arr(k+1,0);
        while(it1!=a1.end()){
            arr[*it1]++;
            it1++;
        }
        while(it2!=b1.end()){
            arr[*it2]++;
            it2++;
        }
        ll cnt3=0;
        for(ll i=1;i<=k;i++){
            if(arr[i]==2) cnt3++;
        }
        bool isPossible = false;
        if((cnt1+cnt2-cnt3)>=k) isPossible=true;
        if(isPossible) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}

