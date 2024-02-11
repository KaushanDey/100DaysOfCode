// #include <bits/stdc++.h>
// #include<string>
// using namespace std;
// typedef long long ll;
// typedef long double ld;
// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define max3(a,b,c) max(max(a,b),c)
// #define max4(a,b,c,d) max(max(a,b),max(c,d))
// #define fr(i,n) for(ll i=0;i<n;i++)
// #define in_range(x,y,n,m) (x>=0 && x<n && y>=0 && y<m)

// void bfs(vector<vector<ll>> &arr, ll &n, ll &m){

// }
// int main()
// {
//     fastio;
//     ll t=1;
//     cin>>t;
//     while(t--)
//     {
//         ll n,m;
//         cin>>n>>m;
//         vector<vector<ll>> arr(n,vector<ll> (m));
//         vector<string> temp(n);
//         for(ll i-0;i<n;i++) cin>>temp[i];
//         for(ll i=0;i<n;i++){
//             for(ll j=0;j<m;j++){
//                 if(temp[i][j]=='1') arr[i][j]=1;
//                 else arr[i][j]=0;
//             }
//         }

//         vector<vector<ll>> dis(n,vector<ll> (m,INT_MAX));

//         for(ll i=0;i<n;i++){
//             for(ll j=0;j<m;j++){
//                 if(arr[i][j]){
//                     bfs()
//                 }
//             }
//         }
//     }
// }   
#include<bits/stdc++.h>
#include<string>
#define MAX 10000000
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
 
using namespace std;
 
//queue<int> myq;
queue<pair<int,int>> myq;
void bfs(char mat[182][182], int dis[182][182], int x, int y, int r, int c){
    
    int i, j, a, b;
    
    dis[x][y] = 0;
    myq.push({x,y});
    
    while(!myq.empty()){
        
        i = myq.front().first;
        j = myq.front().second;
        myq.pop();
        //i,j
        a = i-1;
        b = j;
        // dist[a][b] initially INT_MAX hai
        if(in_range(a, b, r, c) && dis[a][b] > dis[i][j] + 1 && mat[a][b] == '0'){
            myq.push({a,b});
            dis[a][b] = dis[i][j] + 1;
        }
        
        a = i+1;
        b = j;
        
        if(in_range(a, b, r, c) && dis[a][b] > dis[i][j] + 1 && mat[a][b] == '0'){
            myq.push({a,b});
            dis[a][b] = dis[i][j] + 1;
        }
        
        a = i;
        b = j-1;
        
        if(in_range(a, b, r, c) && dis[a][b] > dis[i][j] + 1 && mat[a][b] == '0'){
            myq.push({a,b});
            dis[a][b] = dis[i][j] + 1;
        }
        
        a = i;
        b = j+1;
        
        if(in_range(a, b, r, c) && dis[a][b] > dis[i][j] + 1 && mat[a][b] == '0'){
            myq.push({a,b});
            dis[a][b] = dis[i][j] + 1;
        }
        
    }
}
 
int main(){
    
    char mat[182][182], ch;
    int t, r, c, dis[182][182];
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%c", &r, &c, &ch);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                scanf("%c", &mat[i][j]);
                dis[i][j] = MAX;
            }
            scanf("%c", &ch);
        }


        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                if(mat[i][j] == '1')
                    bfs(mat, dis, i, j, r, c);
            }
            
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                printf("%d ", dis[i][j]);
            printf("\n");
        }
    }
    return 0;
}
