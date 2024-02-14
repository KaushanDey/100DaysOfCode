#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define fr(i,n) for(ll i=0;i<n;i++)
ll gcd(ll a, ll b)
{
    return b==0?a:gcd(b,a%b);
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
        string p,c;
        cin>>p;
        cin>>c;
        vector<ll> k(n);
        for(ll i=0;i<n;i++){
            ll t1 = p[i];
            ll t2 = c[i];
            if(t2>=t1){
                if((t2-t1)%3==0){
                    k[i] = (t2-t1)/3;
                }else{
                    ll n1 = t2-t1;
                    while(n1%3!=0){
                        n1+=26;
                    }
                    k[i]=n1/3;
                }
            }else{
                if((26+t2-t1)%3==0){
                    k[i] = (26+t2-t1)/3;
                }else{
                    ll n = 26+t2-t1;
                    while(n%3!=0){
                        n+=26;
                    }
                    k[i]=n/3;
                }
            }
        }
        for(ll i=0;i<n;i++) cout<<k[i]<<" ";
        cout<<"\n";
    }
}