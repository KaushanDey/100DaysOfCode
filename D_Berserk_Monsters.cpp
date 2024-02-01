#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll dead(vector<ll> &a,vector<ll> &d){
    for(ll i=0;i<a.size();i++){
        if(i==0){
            d[i]-=a[i+1];
            continue;
        }
        if(i==a.size()-1){
            d[i]-=a[i-1];
            continue;
        }
        d[i]=d[i]-(a[i-1]+a[i+1]);

    }
    ll cnt=0;
    vector<ll> temp;
    for(ll i=0;i<a.size();i++){
        if(d[i]<0){
            temp.push_back(i);
            cnt++;
        }
    }
    if(cnt!=0){
        ll n=0;
        for(ll i=0;i<temp.size();i++){
            auto itr1=a.begin();
            auto itr2=d.begin();
            a.erase(itr1+temp[i]-n);
            d.erase(itr2+temp[i]-n);
            n++;
        }
    }

    return cnt;
}
int main()
{
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> a(n);
        vector<ll> d(n);
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++) cin>>d[i];
        for(ll i=0;i<n;i++){
            cout<<dead(a,d)<<" ";
        }
        cout<<"\n";
    }
}