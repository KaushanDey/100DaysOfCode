#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1e18
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define mii map<int, int>
#define seti set<int>
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define printList(a) for (auto &x : a) cout << x << " ";
#define printMap(a) for (auto &x : a) cout << x.ff << " " << x.ss << endl;
#define PI 3.1415926535897932384626
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define ps(x,y) fixed<<setprecision(y)<<x
#define w(x) int x; cin>>x; while(x--)
#define sortall(x) sort(all(x))
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vpii vector<pii>
#define matrix(N,M) vvi matrix(N, vi(M, 0));
#define printMatrix(matrix) for(auto &x:matrix){for(auto &y:x)cout<<y<<" ";cout<<endl;}
#define inputMatrix(matrix) for(auto &x:matrix)for(auto &y:x)cin>>y;
#define sortMatrix(matrix) for(auto &x:matrix)sortall(x);
#define rotateMatrix(matrix) reverse(all(matrix));for(int i=0;i<matrix.size();i++)for(int j=0;j<i;j++)swap(matrix[i][j],matrix[j][i]);
#define matrixSum(matrix) int sum=0;for(auto &x:matrix)for(auto &y:x)sum+=y;cout<<sum<<endl;
#define matrixProduct(matrix) int product=1;for(auto &x:matrix)for(auto &y:x)product*=y;cout<<product<<endl;
#define matrixMax(matrix) int mx=INT_MIN;for(auto &x:matrix)for(auto &y:x)mx=max(mx,y);cout<<mx<<endl;
#define matrixMin(matrix) int mn=INT_MAX;for(auto &x:matrix)for(auto &y:x)mn=min(mn,y);cout<<mn<<endl;
#define matrixTranspose(matrix) for(int i=0;i<matrix.size();i++)for(int j=0;j<i;j++)swap(matrix[i][j],matrix[j][i]);
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define maxEle(a) *max_element(all(a))
#define minEle(a) *min_element(all(a))
#define sumEle(a) accumulate(all(a),0)
#define productEle(a) accumulate(all(a),1,multiplies<int>())
#define maxIndex(a) max_element(all(a))-a.begin()
#define minIndex(a) min_element(all(a))-a.begin()
#define findIndex(a,x) find(all(a),x)-a.begin()
#define findEle(a,x) find(all(a),x)!=a.end()
#define countEle(a,x) count(all(a),x)
#define lowerEle(a,x) lower_bound(all(a),x)-a.begin()
#define upperEle(a,x) upper_bound(all(a),x)-a.begin()

int C(int n, int r) { if (r > n - r) r = n - r; int ans = 1; for (int i = 1; i <= r; i++) { ans *= n - r + i; ans /= i; } return ans; }
int BinExp(int a, int b) { int res = 1; a = a % MOD; while (b > 0) { if (b & 1) res = (res * a) % MOD; a = (a * a) % MOD; b >>= 1; } return res; }
int modInv(int a) { return BinExp(a, MOD - 2); }
bool isPrime(int n){ if(n<=1)return false; for(int i=2;i*i<=n;i++)if(n%i==0)return false; return true; }



using namespace std;
void solve()
{

   int n,m,x;
    cin>>n>>m>>x;

    vi ans;

    seti tmp;
    tmp.insert(x);

    while(m--){

        int a;
        char b;

        cin>>a>>b;

        if(b=='1'){
            vi tmp2;

            for(auto &x:tmp){

                int curr=x;

                int newLoc=(curr-a+n)%n;

                if(newLoc==0) newLoc=n;

                tmp2.pb(newLoc);
                

            }

               tmp.clear();

               for(auto &x:tmp2){
                   tmp.insert(x);
               }

        }
        else if(b=='0'){

            vi tmp2;

            for(auto &x:tmp){

                int curr=x;

                int newLoc=(curr+a)%n;

                if(newLoc==0) newLoc=n;

                tmp2.pb(newLoc);
                

            }
            tmp.clear();
              for(auto &x:tmp2){
                   tmp.insert(x);
               }

        }
        else{

            vi tmp2;

            for(auto &x:tmp){
                int curr=x;

               int newLoc1=(curr-a+n)%n;

               if(newLoc1==0) newLoc1=n;

               int newLoc2=(curr+a)%n;
               if(newLoc2==0) newLoc2=n;

               tmp2.pb(newLoc1);
               tmp2.pb(newLoc2);
               
              
            }

            tmp.clear();
           for(auto &x:tmp2){
                   tmp.insert(x);
               }
        }
       

    }

    cout<<tmp.size()<<endl;
    printList(tmp);
    cout<<endl;
}
int32_t main()
{   fastio();
    w(t)
    {
        solve();
    }
    return 0;
}