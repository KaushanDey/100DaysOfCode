#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
    fastio;
    ll n,k;
    cin>>n>>k;
    vector<bool> isPrime(n+1,1);
    isPrime[0]=0;
    isPrime[1]=0;
    for(ll i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(ll j=i*i;j<=n;j+=i){
                isPrime[j]=0;
            }
        }
    }
    vector<ll> spf(n+1);
    spf[0]=0;
    spf[1]=1;
    for(ll i=2;i<=n;i++) spf[i]=i;
    for(ll i=2;i*i<=n;i++){
        if(spf[i]==i){
            for(ll j=i*i;j<=n;j+=i){
                spf[j]=i;
            }
        }
    }
    vector<ll> factors;
    ll temp=n;
    ll res=1;
    ll isDone=false;
    ll cnt=0;
    ll factor;
    while(temp>0){
        if(cnt+1==k){
            factors.push_back(n/res);
            isDone=true;
            break;
        }
        factor=spf[temp];
        if(factor==1 && cnt!=k){
            cout<<-1;
            break;
        }
        while(temp%factor==0){
            if(cnt+1==k){
                factors.push_back(n/res);
                isDone=true;
                break;
            }
            factors.push_back(factor);
            cnt++;
            res*=factor;
            temp/=factor;
        }
        if(isDone) break;
    }
    if(isDone){
        for(ll i=0;i<factors.size();i++) cout<<factors[i]<<" ";
    }
}