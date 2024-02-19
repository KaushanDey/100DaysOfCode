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
        ll n;
        cin>>n;
        vector<char> arr(n);
        for(ll i=0;i<n;i++) cin>>arr[i];
        ll ans = 0;
        ll i=0;
        while(i<n){
            if(arr[i]=='@'){
                ans+=1;
            }
            if((i+2)<n && arr[i+1]=='*' && arr[i+2]=='*'){
                break;
            }
            if((i+2)<n && arr[i+1]=='*'){
                i+=2;
            }else{
                i++;
            }
        }
        cout<<ans<<"\n";
    }
}