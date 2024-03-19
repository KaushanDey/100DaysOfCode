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
    string str;
    ll n,q;
    cin>>n;
    cin>>str;
    cin>>q;
    map<char,vector<ll>> mp;
    for(ll i=0;i<n;i++){
        char ch = str[i];
        mp[ch].push_back(i);
    }
    vector<char> arr(n);
    for(ll i=0;i<n;i++){
        arr[i]=str[i];
    }
    for(ll i=0;i<q;i++){
        char x,y;
        cin>>x>>y;
        for(ll j=0;j<mp[x].size();j++){
            arr[mp[x][j]] = y;
            mp[y].push_back(mp[x][j]);
        }
        mp[x].clear();
    }
    string st = "";
    for(ll i=0;i<n;i++){
        st+=arr[i];
    }
    cout<<st;


}