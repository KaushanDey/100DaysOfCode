#include <bits/stdc++.h>
using namespace std;
#define ll long long int
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()    
{
    fastio;
    ll t=1;
    cin>>t;
    ll m = 5000004;
    vector<ll> pff(m+1,1);
    vector<ll> p;
    pff[0]=0;
    pff[1]=0;
    for(ll i=2;i*i<=m;i++){
        if(pff[i]==1){
            p.push_back(i);
            for(ll j=i*i;j<=m;j+=i) pff[j]=0;
        }
    }
    //prime factor of i*prime number = prime factor of i + 1
    for(ll i=2;i<=m;i++){
        for(ll j=0;j<p.size();j++){
            if(i*p[j]>m) break;
            pff[i*p[j]] = pff[i]+1;
        }
    }

    //pff[n] = pff[n-1] + prime factor of n
    for(ll i=2;i<=m;i++){
        pff[i]=pff[i-1]+pff[i];
    }

    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<pff[a]-pff[b]<<"\n";
    }
}