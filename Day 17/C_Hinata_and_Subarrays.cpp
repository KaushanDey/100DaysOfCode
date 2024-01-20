#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void maxSum(vector<ll> &a, ll &n, ll &x, ll k){

    ll sum=0;
    ll Max=INT_MIN;
    ll cnt=0;
    for(ll i=0;i<n;i++){
        if(cnt<k){
            if(a[i]+x<0){
                Max = max(Max,sum);
                sum=0;
                cnt=0;
            }else{
                sum+=a[i]+x;
                cnt++;
            }
        }
        else{
            if(a[i]<0){
                Max=max(Max,sum);
                sum=0;
                cnt=0;
                if(cnt<k && a[i]+x>=0) {
                    sum+=a[i]+x;
                    cnt++;
                }
            }else{
                sum+=a[i];
            }
        }
    }
    Max = max(Max,sum);
    if(k==n){
        cout<<Max<<"\n";
        return;
    }
    cout<<Max<<" ";
}

int main()
{
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        vector<ll> a(n);
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll k=0;k<=n;k++) maxSum(a,n,x,k);
    }
}