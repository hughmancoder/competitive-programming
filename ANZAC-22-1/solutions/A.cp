#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;
typedef double ld;

const int N = 2e5+10 , mod = 1e9+7;

void solve(){
   int n , s;
   cin >> n >> s;
   int cur = s;
   int ans = 0;
   for(int i = 0 ; i < n ; i++){
      string t;
      cin >> t;
      int add = 0;
      if(t[t.size() - 1] == 'L'){
         t.pop_back();
         add = 1;
      }
      int need = stoi(t) + add;
      if(need > cur){
         ans++;
         cur = s;
      }
      cur -= need;
   }
   cout << ans;
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
