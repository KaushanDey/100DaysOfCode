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
ll si, ti, sj, tj;

struct Point
{
    ll i,j,e;

    bool operator==(const Point &o) const {
        return i == o.i && j == o.j;
    }

    bool operator<(const Point &o) const{
        return i < o.i || (i == o.i && j < o.j);
    }
};

bool bfs(map<pair<ll, ll>, ll> &mp, vvch &grid,ll &h, ll &w)
{

    queue<Point> q;
    map<Point, bool> vis;
    // Point temp1;
    // temp1.i = si;
    // temp1.j = sj;
    // temp1.e = mp[{si,sj}];
    q.push({si,sj,mp[{si,sj}]});
    bool isPossible = false;
    while (!q.empty())
    {
        Point node = q.front();
        q.pop();
        vis[node] = 1;
        ll i = node.i;
        ll j = node.j;
        if(i==ti && j==tj){
            isPossible = true;
            break;
        }
        ll e = node.e;
        ll temp = mp[{i, j}];
        if (temp > e)
            e = temp;
        vll a = {-1, 0, 1, 0};
        vll b = {0, 1, 0, -1};

        ll cnt = 0;
        for0(k, 0, 4)
        {
            ll p = i + a[k];
            ll q1 = j + b[k];
            Point temp2;
            temp2.i = p;
            temp2.j = q1;
            temp2.e = e-1;
            if (p>=1 && p<=h && q1>=1 && q1<=w)
            {
                if (grid[p][q1] != '#' && e > 0 && !vis[temp2])
                {
                    q.push(temp2);
                }
            }
        }
    }
    return isPossible;
}
int main()
{
    fastio;
    ll h, w;
    cin >> h >> w;
    vvch grid(h + 1, vch(w + 1));
    for1(i, 1, h)
    {
        string str;
        cin >> str;
        for1(j, 1, w)
        {
            grid[i][j] = str[j];
            if (str[j] == 'S')
            {
                si = i;
                sj = j;
            }
            if (str[j] == 'T')
            {
                ti = i;
                tj = j;
            }
        }
    }

    ll n;
    cin >> n;
    map<pair<ll, ll>, ll> mp;
    for0(i, 0, n)
    {
        ll r, c, e;
        cin >> r >> c >> e;
        mp[{r, c}] = e;
    }

    if(bfs(mp,grid,h,w)) cout<<"Yes";
    else cout<<"No";
}