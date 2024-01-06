#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define max3(a, b, c) max(max(a, b), c)

ll maxHappiness(vector<vector<ll>> &points, ll n, ll index, ll last, ll happiness, vector<vector<ll>> &dp)
{

    ll Max = INT_MIN;

    if (index == n - 1)
    {
        for (ll i = 0; i < 3; i++)
        {
            Max = max(Max, maxHappiness(points, n, index - 1, i, happiness + points[index][i],dp));
        }
        return Max;
    }

    if(dp[index][last]!=-1){
        return happiness+dp[index][last];
    }
    if (index == 0)
    {
        for (ll i = 0; i < 3; i++)
        {
            if (last != i)
            {
                Max = max(Max, happiness + points[index][i]);
            }
        }
        return Max;
    }
    
    
    else
    {
        for (ll i = 0; i < 3; i++)
        {
            if (last != i)
            {
                Max = max(Max, maxHappiness(points, n, index - 1, i, happiness + points[index][i],dp));
            }
        }

        return dp[index][last]=Max;
    }
}
int main()
{
    fastio;
    ll n;
    cin >> n;
    vector<vector<ll>> points(n, vector<ll>(3));
    for (ll i = 0; i < n; i++)
        cin >> points[i][0] >> points[i][1] >> points[i][2];
    ll happiness = 0;
    vector<vector<ll>> dp(n,vector<ll> (3,-1));
    if (n >= 2)
    {
        cout << maxHappiness(points, n, n - 1,-1, happiness,dp);
    }
    else
    {
        cout << max3(points[0][0], points[0][1], points[0][2]);
    }
}