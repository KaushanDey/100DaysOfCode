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

ll Solve(vll &a, ll ind, ll g, ll b, ll h, vvvll &dp){
    if(ind==0){
        if(h>a[ind]) return 1;
        while(g!=0){
            h*=2;
            g--;
        }
        while(b!=0){
            h*=3;
            b--;
        }
        if(h>a[ind]) return 1;
        return 0;
    }

    if(dp[ind][g][b]!=-1) return dp[ind][g][b];
    ll case1 = 0, case2 = 0, case3 = 0;
    if(h>a[ind]) {
        ll t = floor(a[ind]/2);
        case1 = 1 + Solve(a,ind-1,g,b,h+t,dp);
    }
    if(g!=0){
        ll t = h*2;
        case2 = Solve(a,ind,g-1,b,t,dp);
    }
    if(b!=0){
        ll t = h*3;
        case3 = Solve(a,ind,g,b-1,t,dp);
    }

    return dp[ind][g][b] = max(case1,max(case2,case3));
}

bool Compare(ll a, ll b){
    return (a>b);
}
int main()
{
    fastio;
    Tc
    {
        ll n,h;
        cin>>n>>h;
        vll a(n);
        for0(i,0,n) cin>>a[i];
        sort(a.begin(),a.end(),Compare);
        ll g = 2;
        ll b = 1;;
        vvvll dp(n,vector<vector<ll>> (3,vector<ll> (2,-1)));
        cout<<Solve(a,n-1,g,b,h,dp)<<"\n";
    }
}