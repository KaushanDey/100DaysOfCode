#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll gcd(ll a, ll b)
{
    return b==0?a:gcd(b,a%b);
}

ll maxLength(vector<ll> &arr, ll &n, ll index,ll last,map<pair<ll,ll>,ll> &dp){
    if(index==n-1){
        if(last==0) return 1;
        if(gcd(arr[index],last)>1){
            return 1;
        }
        return 0;
    }
    pair<ll,ll> mp;
    mp.first=index;
    mp.second=last;
    if(dp[mp]!=0) return dp[mp];
    ll take=INT_MIN;
    if(last==0){
        take=1+maxLength(arr,n,index+1,arr[index],dp);
    }else if(gcd(arr[index],last)>1){
        take=1+maxLength(arr,n,index+1,arr[index],dp);
    }
    ll notTake=maxLength(arr,n,index+1,last,dp);

    return dp[mp]=max(take,notTake);
}

int main()
{
    fastio;
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) cin>>arr[i];
    map<pair<ll,ll>,ll> dp;
    cout<<maxLength(arr,n,0,0,dp);
}