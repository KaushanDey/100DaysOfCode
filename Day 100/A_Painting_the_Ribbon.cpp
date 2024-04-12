#include <iostream> 
 
typedef long long ll; 
 
 
 
void solve() 
{ 
    ll a,b,c; 
    std::cin>>a>>b>>c; 
    std::cout<<(b>c?"YES":"NO")<<std::endl; 
} 
int main() 
{ 
    int testcases=1; 
    std::cin>>testcases; 
    while(testcases--) solve(); 
    //system("pause"); 
    return 0; 
}