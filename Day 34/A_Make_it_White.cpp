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
        string str;
        cin>>str;
        ll first=0,last=0;
        ll cnt=0;
        for(ll i=0;i<n;i++){
            if(str[i]=='B' && cnt==0){
                cnt++;
                first=i;
                last=i;
            }else if(str[i]=='B' && cnt==1){
                last=i;
            }
        }
        if(cnt==0){
            cout<<0<<"\n";
            continue;
        }
        cout<<last-first+1<<"\n";
    }
}