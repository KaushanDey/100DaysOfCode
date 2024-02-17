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
    while(t--)
    {
        ll n;
        cin>>n;
        string str= "";
        for(ll i=0;i<(2*n+1);i++){
            if(i%2==0){
                str+='1';
            }else{
                str+='0';
            }
        }
        cout<<str;
    }
}   