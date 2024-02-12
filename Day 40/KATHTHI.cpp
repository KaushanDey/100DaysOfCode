// #include <bits/stdc++.h>
// #include<string>
// using namespace std;
// typedef long long ll;
// typedef long double ld;
// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define in_range(x,y,r,c) (x>=0 && x<r && y>=0 && y<c)

// void bfs(vector<vector<char>> &arr, vector<vector<ll>> &killed, ll &r, ll &c){

//     queue<pair<ll,ll>> q;
//     pair<ll,ll> mp = {0,0};
//     killed[0][0]=0;
//     q.push(mp);
//     ll a,b;
//     while(!q.empty()){
//         pair<ll,ll> front = q.front();
//         ll i = front.first;
//         ll j = front.second;
//         q.pop();
//         //north
//         a = i-1;
//         b = j;
//         if(in_range(a,b,r,c)){
//             pair<ll,ll> mp = {a,b};
//             q.push(mp);
//             if(arr[i][j]==arr[a][b] && killed[a][b]>killed[i][j]){
//                 killed[a][b]=killed[i][j];
//             }else if(arr[i][j]!=arr[a][b] && killed[a][b]>(killed[i][j]+1)){
//                 killed[a][b]=killed[i][j]+1;
//             }
//         }
//         //east
//         a = i;
//         b = j+1;
//         if(in_range(a,b,r,c)){
//             pair<ll,ll> mp = {a,b};
//             if(!(i==(r-1) && j==(c-1))) q.push(mp);
//             if(arr[i][j]==arr[a][b] && killed[a][b]>killed[i][j]){
//                 killed[a][b]=killed[i][j];
//             }else if(arr[i][j]!=arr[a][b] && killed[a][b]>(killed[i][j]+1)){
//                 killed[a][b]=killed[i][j]+1;
//             }
//         }
//         //south
//         a = i+1;
//         b = j;
//         if(in_range(a,b,r,c)){
//             pair<ll,ll> mp = {a,b};
//             if(!(i==(r-1) && j==(c-1))) q.push(mp);
//             if(arr[i][j]==arr[a][b] && killed[a][b]>killed[i][j]){
//                 killed[a][b]=killed[i][j];
//             }else if(arr[i][j]!=arr[a][b] && killed[a][b]>(killed[i][j]+1)){
//                 killed[a][b]=killed[i][j]+1;
//             }
//         }
//         //west
//         a = i;
//         b = j-1;
//         if(in_range(a,b,r,c)){
//             pair<ll,ll> mp = {a,b};
//             q.push(mp);
//             if(arr[i][j]==arr[a][b] && killed[a][b]>killed[i][j]){
//                 killed[a][b]=killed[i][j];
//             }else if(arr[i][j]!=arr[a][b] && killed[a][b]>(killed[i][j]+1)){
//                 killed[a][b]=killed[i][j]+1;
//             }
//         }
//     }
// }
// int main()
// {
//     fastio;
//     ll t=1;
//     cin>>t;
//     while(t--)
//     {
//         ll r,c;
//         cin>>r>>c;
//         vector<vector<char>> arr(r, vector<char> (c));
//         for(ll i=0;i<r;i++){
//             for(ll j=0;j<c;j++){
//                 cin>>arr[i][j];
//             }
//         }

//         vector<vector<ll>> killed(r,vector<ll> (c,0));
//         bfs(arr,killed,r,c);
//         cout<<killed[r-1][c-1]<<"\n";

//     }
// }

#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<utility>
#include<string>
#include<cstring>
#include<set>
#include<cmath>
#include<vector>
#include<fstream>
#include<map>
#include<list>
#include<algorithm>
#define INF 100000000
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
 
typedef long long int LLD;
typedef unsigned long long int LLU;
 
using namespace std;
 
char mat[1000][1000];
int dis[1000][1000];
 

void init(int r, int c){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            dis[i][j] = INF;
}
 
void bfs(int startX, int startY, int r, int c){
    dis[startX][startY] = 0;
    deque< pair<int, int> > q;
    pair<int, int> p;
    q.push_front(make_pair(startX, startY));
    while(!q.empty()){
        p = q.front();
        q.pop_front();
        int x = p.first;
        int y = p.second;
        int a[] = {0, -1, 0, 1};
        int b[] = {-1, 0, 1, 0};
        for(int i=0;i<4;i++){
            int tmpX = x + a[i];
            int tmpY = y + b[i];
            if(in_range(tmpX, tmpY, r, c)){
                if(mat[tmpX][tmpY] == mat[x][y] && dis[tmpX][tmpY] > dis[x][y]){
                    q.push_front(make_pair(tmpX, tmpY));
                    dis[tmpX][tmpY] = dis[x][y];
                }
                else if(mat[tmpX][tmpY] != mat[x][y]){
                    if(dis[tmpX][tmpY] > dis[x][y] + 1){
                        q.push_back(make_pair(tmpX, tmpY));
                        dis[tmpX][tmpY] = dis[x][y] + 1;
                    }
                }
            }
        }
    }
}
 
void display(int r, int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
}
 
int main(){
 
    int t, r, c;
    char ch;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &r, &c);
        scanf("%c", &ch);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                scanf("%c", &mat[i][j]);
            scanf("%c", &ch);
        }
        init(r, c);
        bfs(0, 0, r, c);
        cout << dis[r-1][c-1] << endl;
    }
    return 0;
}