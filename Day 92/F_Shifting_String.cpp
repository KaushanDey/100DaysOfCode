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
#define vch vector <char>
#define vbool vector <bool>
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
ll N = 1e5;
ll MOD = 1e9+7;
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

vvll adj;
vbool vis;
string str;
vch cycle;

void dfs(ll node){

    vis[node] = 1;
    cycle.pb(str[node-1]);
    for(auto &child: adj[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
}
bool isSame(string a, string b){

    ll n = a.size();
    ll i=0;
    while(i<n){
        if(a[i]!=b[i]) return false;
        i++;
    }
    return true;
}
ll find_kj(){

    string og = "";
    ll n = cycle.size();
    for0(i,0,n){
        og+=cycle[i];
    }

    string prev = og;
    string curr = "";
    for0(i,0,n){
        curr+=prev[n-1];
        for0(j,0,n-1){
            curr+=prev[j];
        }
        if(isSame(og,curr)) return i+1;
        prev = curr;
        curr = "";
    }
}

int main()
{
    fastio;
    Tc
    {
        ll n;
        cin>>n;
        cin>>str;
        vll p(n);
        for0(i,0,n) cin>>p[i];

        adj.clear();
        adj.resize(n+1);
        vis.clear();
        vis.assign(n+1,false);
        cycle.clear();
        for0(i,0,n){
            adj[p[i]].pb(i+1);
        }
        vll times;
        for1(i,1,n){
            if(!vis[i]){
                cycle.clear();
                dfs(i);
                times.pb(find_kj());
            }
        }
        ll LCM = times[0];
        for0(i,1,times.size()){
            LCM = (LCM*times[i])/(__gcd(LCM,times[i]));
        }
        cout<<LCM<<"\n";

    }
}