// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cin.exceptions(ios::badbit | ios::failbit);
// #define all(v) v.begin(),v.end()
// #define revall(v) v.rbegin(),v.rend()
// #define gcd(a,b) __gcd(a,b)
// #define lcm(a,b) (a*b)/gcd(a,b)
// #define pb push_back
// #define eb emplace_back
// #define mk make_pair
// #define F first
// #define S second
// #define pi acos(-1.0)
// #define maxv(v) *max_element(all(v))
// #define minv(v) *min_element(all(v))
// #define countv(v,a) count(all(v),a)
// #define cntone(x) __builtin_popcountll(x) // number of ones
// #define cntzero(x) __builtin_ctzll(x) // number of trailing zeros
// #define rep(i, l, r) for(long long i = l; i<r; i++)
// #define SUM accumulate
// #define toint(a) atoi(a.c_str())
// #define read freopen("input.txt","r",stdin)
// #define write freopen("output.txt","w",stdout)
// #define Unique(c) (c).resize(unique(all(c))-(c).begin())
// #define sp(a) fixed<<setprecision(a)
// #define printv(container) for(auto it:container) cout << it << " ";cout << endl
// #define vll vector <ll>
// #define pll pair<ll,ll>
// #define mll map<ll, ll>
// #define vpll vector<pair<ll, ll>>
// #define vvll vector<vector<ll>>
// #define vvch vector<vector<char>>
// #define vvpll vector<vector<pair<ll, ll>>>
// #define vvvll vector<vector<vector<ll>>>
// #define cases(i) cout << "Case " << i << ":"
// #define yes cout << "YES" << endl
// #define no cout << "NO" << endl
// #define rand(V) random_shuffle(all(V))
// #define lb(a,X) lower_bound(all(a),X)-a.begin()
// #define ub(a,X) upper_bound(all(a),X)-a.begin()
// #define Tc ll t=1;cin >> t;while(t--)
// #define for0(i,l,r) for(ll i = l;i<r;i++)
// #define for1(i,l,r) for(ll i = l;i<=r;i++)
// #define rev0(i,r,l) for(ll i = r - 1;i>=l;i--)
// ll N = 100000;
// vector<int> spf(N + 1, 0);
// void smallestPrimeFactor()
// {
//     for (int i = 2; i <= N; i++)
//     {
//         if (!spf[i])
//         {
//             spf[i] = i;
//             for (int j = i * i; j <= N; j += i)
//             {
//                 if (!spf[j])
//                     spf[j] = i;
//             }
//         }
//     }
// }

// // void dfs(vvll &adj, ll node, ll p, ll &j, vvll &par){

// //     par[node][0] = p;
// //     for1(i,1,j){
// //         if(par[node][i-1]!=-1){
// //             par[node][i] = par[par[node][i-1]][i-1];
// //         }else par[node][i] = -1;
        
// //     }
// //     for(auto &child: adj[node]){
// //         if(child!=p){
// //             dfs(adj,child,node,j,par);
// //         }
// //     }
// // }
// int main()
// {
//     fastio;
//     ll n,q;
//     cin>>n>>q;
//     vll par(n+1);
//     par[0] = -1;
//     par[1] = -1;
//     for1(i,2,n){
//         cin>>par[i];
//     }
//     ll j = log2(n);
//     vvll dp(n+1,vll (j+1,-1));
//     for(ll i=1;i<=n;i++) dp[i][0] = par[i];
//     for(ll k=1;k<=j;k++){
//         for(ll i=1;i<=n;i++){
//             if(dp[i][k-1]==-1){
//                 dp[i][k] = -1;
//                 continue;
//             }
//             dp[i][k] = dp[dp[i][k-1]][k-1];
//         }
//     }
//     for0(i,0,q){
//         ll a,k;
//         cin>>a>>k;
//         ll pos = 0;
//         for(ll i=k;i>0;i=(i>>1)){
//             if(i&1){
//                 a = dp[a][pos];
//             }
//             pos++;
//         }
//         cout<<a<<"\n";
//     }
// }

#include <bits/stdc++.h>
#define int long long
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
 
#define die(x) return cout << x << '\n', 0;
 
using namespace std;
 
int n;
vector<int> par;
vector<vector<int> > dp;
 
const int x = 24;  // You can also use x=log2(n)+1
 
void build() {
  for (int i = 0; i < n; i++) dp[i][0] = par[i];
  for (int j = 1; j <= x; j++) {
    for (int i = 0; i < n; i++) {
      if (dp[i][j - 1] == -1)
        dp[i][j] = -1;
      else
        dp[i][j] = dp[dp[i][j - 1]][j - 1];
    }
  }
}
 
int query(int s, int k) {
  for (int i = x; i >= 0; i--) {
    if ((1 << i) <= k) {
      s = dp[s][i];
      k -= (1 << i);
      if (s == -1) return -1;
    }
  }
  return s + 1;
}
 
int32_t main() {
  fastio;
  int q;
 
  cin >> n >> q;
  par.resize(n);
  par[0] = -1;
  for (int i = 1; i < n; i++) {
    cin >> par[i];
    par[i]--;
  }
  dp.assign(n, vector<int>(x + 1, -1));
  build();
  int node, k;
  while (q--) {
    cin >> node >> k;
    node--;
    cout << query(node, k) << '\n';
  }
 
  return 0;
}
