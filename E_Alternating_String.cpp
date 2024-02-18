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
    ll n,q;
    cin>>n>>q;
    string str;
    cin>>str;
    vector<char> s(n);
    for(ll i=0;i<n;i++) s[i] = str[i];
    vector<ld> arr(3);
    while(q--){
        cin>>arr[0]>>arr[1]>>arr[2];
        if(arr[0]==1){
            for(ll i=arr[i]-1;i<arr[2];i++){
                if(s[i]=='0') s[i] = '1';
                else s[i] = '0';
            }
        }else{
            ld t = arr[2]-arr[1]+1;
            if(t%2==0){
                if(s[arr[1]-1]=='0'){
                    ld a = (pow(4,t/2)-1)/3;
                    if()
                }
            }
        }
    }
}