#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define max3(a,b,c) max(max(a,b),c)

ll maxTugriks(ll index,ll n,ll m,ll c0,ll d0,vector<vector<ll>> buns,ll output){

    if(index>=m){
        return output;
    }
    if(n<=0 || buns[index][2]>n || buns[index][0]<=0 || buns[index][1]>buns[index][0]){
        return output;
    }

    //bun with no filling
    ll res1 = maxTugriks(index,n-c0,m,c0,d0,buns,output+d0);
    // bun without buns[index] filling
    ll res2 = maxTugriks(index+1,n,m,c0,d0,buns,output);
    //buns with index filling
    buns[index][0]-=buns[index][1];
    ll res3 = maxTugriks(index,n-buns[index][2],m,c0,d0,buns,output+buns[index][3]);

    return max3(res1,res2,res3);

}

int main()
{
    fastio;
    ll n,m,c0,d0;
    cin>>n>>m>>c0>>d0;
    vector<vector<ll>> buns(m,vector<ll> (4));
    for(ll i=0;i<m;i++){
        cin>>buns[i][0]>>buns[i][1]>>buns[i][2]>>buns[i][3];
    }
    ll output=0;
    cout<<maxTugriks(0,n,m,c0,d0,buns,output);
}