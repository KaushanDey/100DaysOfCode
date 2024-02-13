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
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) cin>>arr[i];
        ll i=0,j=n-1;
        while(i<j){
            while(arr[i]==arr[i+1] && i<j) i++;
            while(arr[j]==arr[j-1] && i<j) j--;
            break;
        }
        if(arr[i]==arr[j] && i==j){
            cout<<0<<"\n";
        }else if(arr[i]==arr[j]){
            cout<<j-i-1<<"\n";
        }else if(arr[i]!=arr[j]){
            ll temp = j-i-1;
            if((n-j)>(i+1)){
                cout<<temp+i+1<<"\n";
            }else{
                cout<<temp+n-j<<"\n";
            }
        }

    }
}