#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll maxSum(vector<ll> &arr, ll n, ll k)
{
    // k must be smaller than n
    if (n < k)
    {
       cout << "Invalid";
       return -1;
    }
 
    // Compute sum of first window of size k
    ll res = 0;
    for (ll i=0; i<k; i++)
       res += arr[i];

    ll curr_sum = res;
    for (ll i=k; i<n; i++)
    {
       curr_sum += arr[i] - arr[i-k];
       res = max(res, curr_sum);
    }
 
    return res;
}



int main()
{
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        vector<ll> a(n);
        vector<ll> Sum(n+1);
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=1;i<=n;i++){
            Sum[i]=maxSum(a,n,i);
        }
        for(ll k=0;k<=n;k++){
            ll maxi = INT_MIN;
            for(ll i=0;i<=n;i++){
                maxi=max(maxi,Sum[i]+(min(i,k)*x));
            }
            cout<<maxi<<" ";
        }
        cout<<"\n";
    }
}