#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;
typedef double ld;

const int N = 2e5+10 , mod = 1e9+7;

void solve(){
   int n , m;
   cin >> n >> m;
   int a[n][m];
   int cnt[3] = {0 , 0 , 0};
   for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
         cin >> a[i][j];
         cnt[a[i][j]]++;
      }
   }
   if(cnt[0] > 1){
      cout << "0";
      return;
   }
   if(cnt[0] == 1){
      if(cnt[1] && (min(n , m) > 1 || a[n - 1][m - 1] == 1 || a[n - 1][0] == 1 || a[0][m - 1] == 1 || a[0][0] == 1)){
         cout << 1;
         return;
      }
      cout << 2;
      return;
   }
   if(cnt[2] & 1){
      ll ans = 1;
      for(int i = 0 ; i < cnt[2] / 2 ; i++){
         ans *= 2;
      }
      cout << ans;
   }
   else{
      cout << 0;
   }
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
