#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    fastio;
    ll t = 1;
    cin >> t;
    ll n = 1e6;
    vector<bool> isPrime(n + 1, 1);

    isPrime[0] = 0;
    isPrime[1] = 0;
    for (ll i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j <= n; j+=i)
            {
                isPrime[j] = 0;
            }
        }
    }
    while (t--)
    {
        ll a;
        cin >> a;
        vector<ll> arr;
        if (a == 2)
        {
            cout << "2 2\n";
            continue;
        }
        if (a % 2 == 0)
        {
            for (ll i = 2; i <= n; i++)
            {
                if (arr.size() == a)
                    break;
                if (isPrime[i])
                {
                    arr.push_back(i);
                    arr.push_back(i);
                }
            }
        }
        else
        {
            arr.push_back(1);
            for (ll i = 2; i <= n; i++)
            {
                if (arr.size() == a)
                    break;
                if (isPrime[i])
                {
                    arr.push_back(i);
                    arr.push_back(i);
                }
            }
        }
        for (ll i = 0; i < a; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
}