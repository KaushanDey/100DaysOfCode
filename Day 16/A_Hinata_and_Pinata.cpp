#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define fr(i,n) for(ll i=0;i<n;i++)

int main()
{
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) cin>>arr[i];
        ll cnt=0;
        for(ll i=0;i<n;i++){
            if(arr[i]==2) cnt++;
        }
        if(cnt%2!=0) {
            cout<<-1<<"\n"; 
            continue;
        }
        if(cnt==0){
            cout<<1<<"\n";
            continue;
        }

        ll k = cnt/2;
        ll i;
        for(i=0;i<n && k!=0;i++){
            if(arr[i]==2) k--;
        }
        cout<<i<<"\n";
    }
}