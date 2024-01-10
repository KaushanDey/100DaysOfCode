#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define max3(a,b,c) max(max(a,b),c)

ll maxTugriks(ll index,ll n,ll m,ll c0,ll d0,vector<vector<ll>> buns,ll output,vector<int> dp){

    if(index>=m){
        return output;
    }
    if(n==0){
        return output;
    }
    if(n<0 || buns[index][2]>n || buns[index][0]<0){
        return output;
    }

    if(dp[index]!=-1){
        return dp[index];
    }

    ll res1,res2,res3;
    //bun with no filling
    if(n-c0>=0){
        res1 = maxTugriks(index,n-c0,m,c0,d0,buns,output+d0,dp);
    }else{
        res1=INT_MIN;
    }
    
    // bun without buns[index] filling
    res2 = maxTugriks(index+1,n,m,c0,d0,buns,output,dp);
    //buns with index filling
    if(buns[index][0]-buns[index][1]>=0 && n-buns[index][2]>=0){
        buns[index][0]-=buns[index][1];
        res3 = maxTugriks(index,n-buns[index][2],m,c0,d0,buns,output+buns[index][3],dp);
    }else{
        res3=INT_MIN;
    }
    

    return dp[index]=max3(res1,res2,res3);

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
    vector<int> dp(m,-1);
    cout<<maxTugriks(0,n,m,c0,d0,buns,output,dp);
}

// ll maxTugriks(ll index,ll m,ll c0,ll d0,vector<vector<ll>> buns,ll output){

//     if(index>m){
//         return output;
//     }
//     if(buns[0][0]-buns[index][2]<0 || buns[index][0]-buns[index][1]<0){
//         return INT_MIN;
//     }
//     if(buns[0][0]==0 || buns[index][0]==0){
//         return output;
//     }
//     // bun without index filling
//     ll res1 = maxTugriks(index+1,m,c0,d0,buns,output);
//     //buns with index filling
//     buns[index][0]-=buns[index][1];
//     buns[0][0]-=buns[index][2];
//     ll res2 = maxTugriks(index,m,c0,d0,buns,output+buns[index][3]);

//     return max(res1,res2);

// }

// int main()
// {
//     fastio;
//     ll n,m,c0,d0;
//     cin>>n>>m>>c0>>d0;
//     vector<vector<ll>> buns(m+1,vector<ll> (4));
//     buns[0][0]=n;
//     buns[0][1]=0;
//     buns[0][2]=c0;
//     buns[0][3]=d0;
//     for(ll i=1;i<=m;i++){
//         cin>>buns[i][0]>>buns[i][1]>>buns[i][2]>>buns[i][3];
//     }
//     ll output=0;
//     cout<<maxTugriks(0,m,c0,d0,buns,output);
// }