#include <bits/stdc++.h>
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
    ll q;
    cin>>q;
    vector<vector<ll>> query(q,vector<ll> (2));
    for(ll i=0;i<q;i++) cin>>query[i][0]>>query[i][1];
    vector<ll> arr;
    for(ll i=0;i<q;i++){
        if(query[i][0]==1){
            arr.push_back(query[i][1]);
        }else{
            cout<<arr[arr.size()-query[i][1]]<<"\n";
        }
    }
}