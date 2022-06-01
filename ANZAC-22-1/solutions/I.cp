#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;
typedef double ld;

const int N = 2e5+10 , mod = 1e9+7;

void solve(){
   string s , t;
   cin >> s >> t;
   vector <string> vec;
   int n = s.length() , m = t.length();
   for(int i = 0 ; i < m ; i++){
      string cur = "";
      for(int j = 0 ; j < m ; j++){
         cur += t[(i + j) % m];
      }
      vec.push_back(cur);
   }
   sort(vec.begin() , vec.end());
   vec.resize(unique(vec.begin() , vec.end()) - vec.begin());
   int ans = 0;
   int dp[n + 1][m + 1];
   for(string str : vec){
      memset(dp , 0 , sizeof(dp));
      dp[0][0] = 1;
      for(int i = 1 ; i <= n ; i++){
         dp[i][0] = 1;
         for(int j = 1 ; j <= m ; j++){
            dp[i][j] = dp[i - 1][j];
            if(s[i - 1] == str[j - 1]){
               dp[i][j] += dp[i - 1][j - 1];
               dp[i][j] %= mod;
            }
         }
      }
      ans += dp[n][m];
      ans %= mod;
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
