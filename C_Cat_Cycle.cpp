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
        ll n,k;
        cin>>n>>k;
        if(n%2==0){
            if(k%n==0) cout<<n<<"\n";
            else cout<<k%n<<"\n";
        }else{
            ll cycles = k/n;
            ll rem = k%n;
            ll repeatCycles = (n-1)/2;
            ll remRepeat = cycles%repeatCycles;
            if(rem==0 && remRepeat==0) cout<<2*repeatCycles<<'\n';
            else if(remRepeat!=0 && rem==0) cout<<2*remRepeat<<"\n";
            else if(remRepeat==0 && rem!=0){
                ll temp = (n+1)/2;
                if(rem>=temp) cout<<rem+1<<"\n";
                else cout<<rem<<"\n";
            }else{
                ll temp1 = (n+1)/2;
                ll temp2 = (n-1)/2;
                ll ind1 = temp1;
                ll ind2 = n;
                ll last = 2*remRepeat;
                ll change1 = ind1-remRepeat+1;
                ll change2 = ind2-remRepeat+1;
                ll temp3 = (last+rem);
                if(rem<change1){
                    if(temp3%n==0) cout<<n<<"\n";
                    else cout<<temp3<<"\n";
                    continue;
                }else if(rem>=change1 && rem<change2){
                    if((temp3+1)%n==0) cout<<n<<"\n";
                    else cout<<temp3+1<<"\n";
                    continue;
                }else if(rem>=change2){
                    if((temp3+2)%n==0) cout<<n<<"\n";
                    else cout<<temp3+2<<"\n";
                    continue;
                }
                
            }
        }
    }
}