#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define fr(i,n) for(ll i=0;i<n;i++)
#define in_range(x,y,r,c) (x>=0 && x<r && y>=0 && y<c)
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
        ll l,r;
        cin>>l>>r;
        ll n = r-l+1;
        if(n%2==0){
            for(ll i=l;i<r;i+=2){
                cout<<i+1<<" "<<i<<" ";
            }
            cout<<"\n";
        }else{
            if(l%2==0){
                cout<<-1<<"\n";
            }else{
                for(ll i=l;i<r-2;i+=2){
                    cout<<i+1<<" "<<i<<" ";
                }
                cout<<r<<" ";
                for(ll i=r-2;i<r;i++){
                    cout<<i<<" ";
                }
                cout<<"\n";
            }
        }

    }
}