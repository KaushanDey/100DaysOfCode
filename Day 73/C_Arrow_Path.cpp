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
#define cntzero(x) __builtin_ctzll(x) // number of zeros
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
#define in_range(x,y,r,c) (x>=0 && x<r && y>=0 && y<c)
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

void Solve(vector<vector<ll>> &arr, ll i,ll j, ll &r, ll &c, bool &isPossible, vector<vector<bool>> &vis){

    if(i==(r-1) && j==(c-1)){
        isPossible = true;
    }
    if(isPossible) return;
    vis[i][j]=1;
    vector<ll> a = {1,0,-1,0};
    vector<ll> b = {0,1,0,-1};
    for(ll k=0;k<4;k++){
        ll p = i+a[k];
        ll q = j+b[k];
        if(in_range(p,q,r,c)){
            if(arr[p][q]==1){
                if(!vis[p][q+1]) Solve(arr,p,q+1,r,c,isPossible,vis);
            }else{
                if(!vis[p][q-1]) Solve(arr,p,q-1,r,c,isPossible,vis);
            }
        }
    }

}
int main()
{
    fastio;
    Tc
    {
        ll n;
        cin>>n;
        string s1,s2;
        cin>>s1;
        cin>>s2;
        vector<vector<ll>> arr(2,vector<ll> (n));
        
        for(ll i=0;i<n;i++){
            if(s1[i]=='>') arr[0][i] = 1;
            else arr[0][i] = 0;
        }
        for(ll i=0;i<n;i++){
            if(s2[i]=='>') arr[1][i] = 1;
            else arr[1][i] = 0;
        }

        vector<vector<bool>> vis(2,vector<bool> (n,false));
        ll r = 2;
        bool isPossible = false;
        Solve(arr,0,0,r,n,isPossible,vis);
        if(isPossible) cout<<"YES\n";
        else cout<<"NO\n";
    }
}