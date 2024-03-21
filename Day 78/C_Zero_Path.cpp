#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cin.exceptions(ios::badbit | ios::failbit);
#define all(v) v.begin(),v.end()
#define revall(v) v.rbegin(),v.rend()
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define F first
#define S second
#define pi acos(-1.0)
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define countv(v,a) count(all(v),a)
#define cntone(x) __builtin_popcountll(x) // number of ones
#define cntzero(x) __builtin_ctzll(x) // number of trailing zeros
#define rep(i, l, r) for(long long i = l; i<r; i++)
#define SUM accumulate
#define toint(a) atoi(a.c_str())
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define Unique(c) (c).resize(unique(all(c))-(c).begin())
#define sp(a) fixed<<setprecision(a)
#define printv(container) for(auto it:container) cout << it << " ";cout << endl
#define vll vector <ll>
#define pll pair<ll,ll>
#define mll map<ll, ll>
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vvch vector<vector<char>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vvvll vector<vector<vector<ll>>>
#define cases(i) cout << "Case " << i << ":"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define rand(V) random_shuffle(all(V))
#define lb(a,X) lower_bound(all(a),X)-a.begin()
#define ub(a,X) upper_bound(all(a),X)-a.begin()
#define Tc ll t=1;cin >> t;while(t--)
#define for0(i,l,r) for(ll i = l;i<r;i++)
#define for1(i,l,r) for(ll i = l;i<=r;i++)
#define rev0(i,r,l) for(ll i = r - 1;i>=l;i--)
ll N = 100000;
vector<int> spf(N + 1, 0);
void smallestPrimeFactor()
{
    for (int i = 2; i <= N; i++)
    {
        if (!spf[i])
        {
            spf[i] = i;
            for (int j = i * i; j <= N; j += i)
            {
                if (!spf[j])
                    spf[j] = i;
            }
        }
    }
}

ll maxSum(vvll &a, ll &n,ll &m, ll i, ll j, vvll &dp1){
    if(i==n-1 && j==m-1) return a[i][j];

    if(dp1[i][j]!=-1) return dp1[i][j];

    ll right = LLONG_MIN, down = LLONG_MIN;
    if(j+1<m) right = a[i][j]+maxSum(a,n,m,i,j+1,dp1);
    if(i+1<n) down = a[i][j]+maxSum(a,n,m,i+1,j,dp1);

    return dp1[i][j] = max(right, down);
}

ll minSum(vvll &a, ll &n,ll &m, ll i, ll j, vvll &dp2){
    if(i==n-1 && j==m-1) return a[i][j];

    if(dp2[i][j]!=-1) return dp2[i][j];

    ll right = LLONG_MAX, down = LLONG_MAX;
    if(j+1<m) right = a[i][j]+minSum(a,n,m,i,j+1,dp2);
    if(i+1<n) down = a[i][j]+minSum(a,n,m,i+1,j,dp2);

    return dp2[i][j] = min(right, down);
}

int main()
{
    fastio;
    Tc
    {
        ll n,m;
        cin>>n>>m;
        vvll a(n,vll(m));
        for0(i,0,n){
            for0(j,0,m){
                cin>>a[i][j];
            }
        }
        if((n+m)%2==0){
            cout<<"NO\n";
            continue;
        }
        vvll dp1(n,vll(m,-1));
        vvll dp2(n,vll(m,-1));
        ll maxi = maxSum(a,n,m,0ll,0ll,dp1);
        ll mini = minSum(a,n,m,0ll,0ll,dp2);
        if(maxi<0 || mini>0){
            cout<<"NO\n";
            continue;
        }
        if(maxi>=0 && mini<=0){
            cout<<"YES\n";
        }
    }
}