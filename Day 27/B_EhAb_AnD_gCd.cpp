#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll x;
        cin>>x;
        if(x==2){
            cout<<1<<" "<<1<<"\n";
            continue;
        }
        if(x%2==0) cout<<2<<" "<<x-2<<"\n";
        else cout<<1<<" "<<x-1<<"\n";
    }
}