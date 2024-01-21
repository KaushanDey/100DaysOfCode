#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void Solution(ll m,ll n,vector<bool> &isPrime){
    for(ll i=m;i<=n;i++){
        if(isPrime[i]==1) cout<<i<<"\n";
    }
}
int main()
{
    fastio;
    ll t=1;
    cin>>t;
    ll Max = 1e7;
    vector<bool> isPrime(Max+1,1);
    isPrime[0]=0;
    isPrime[1]=0;
    for(ll i=2;i*i<=Max;i++){
        if(isPrime[i]==1){
            for(ll j=i*i;j<=Max;j+=i){
                isPrime[j]=0;
            }
        }
    }
    while(t--)
    {
        ll m,n;
        cin>>m>>n;
        Solution(m,n,isPrime);
        cout<<"\n";
    }
}