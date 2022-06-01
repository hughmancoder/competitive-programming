#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;
typedef double ld;

const int N = 2e5+10 , mod = 1e9+7;

void solve(){
   int a[3] = {0 , 0 , 0};
   int n;
   cin >> n;
   for(int i = 0 ; i < n ; i++){
      int x;
      cin >> x;
      a[x - 1]++;
   }
   int b[3] = {0 , 0 , 0};
   for(int i = 0 ; i < n ; i++){
      int x;
      cin >> x;
      b[x - 1]++;
   }
   for(int i = 0 ; i < 3 ; i++){
      if(a[i] != b[i]){
         cout << "error";
         return;
      }
   }
   cout << "marvelous";
}

int32_t main(){
   // freopen("dictionary.in" , "r" , stdin);
   // freopen("dictionary.out" , "w" , stdout);
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int t = 1;
   // cin >> t;
   int cur = 1;
   while(t--){
      //cout << "Case #" << cur++ << ": ";
      solve();
   }
   return 0;
}
