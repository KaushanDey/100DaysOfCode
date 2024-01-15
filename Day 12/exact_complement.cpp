#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
    fastio;
    ll n;
    cin>>n;
    ll len;
    for(ll i=1;i<=64;i++){
        if(n>>i==0){
            len=i;
            break;
        }
    }
    cout<<(~n&((1<<len)-1));
}