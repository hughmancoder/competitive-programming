#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;
typedef double ld;

const int N = 2e5+10 , mod = 1e9+7;

void solve(){
   string s;
   cin >> s;
   int n = s.length();
   ll dp[n][n];
   memset(dp , 0 , sizeof(dp));
   for(int i = 0 ; i < n - 1 ; i++){
      dp[i + 1][i] = 1;
   }
   char close[] = {')', ']', '}', '>'};
   char open[] = {'(', '[', '{', '<'};
   map <char , char> mat;
   mat['('] = ')';
   mat['['] = ']';
   mat['{'] = '}';
   mat['<'] = '>';
   int can[n][n];
   memset(can , 0 , sizeof(can));
   for(int i = 0 ; i < n ; i++){
      for(int j = i + 1 ; j < n ; j += 2){
         bool bad = false;
         for(int p = 0 ; p < 4 ; p++){
            if(s[i] == close[p] || s[j] == open[p]){
               bad = true;
            }
         }
         if(bad){
            continue;
         }
         if(s[i] == '?' && s[j] == '?'){
            can[i][j] = 4;
         }
         else if(s[i] == '?' || s[j] == '?' || mat[s[i]] == s[j]){
            can[i][j] = 1;
         }
      }
   }
   for(int l = 2 ; l <= n ; l += 2){
      for(int i = 0 ; i + l <= n ; i++){
         int j = i + l - 1;
         for(int k = i + 1 ; k < j ; k += 2){
            dp[i][j] += 1ll * dp[i + 1][k - 1] * can[i][k] * dp[k + 1][j];
         }
         // cout << dp[i][j] << " ";
         dp[i][j] += 1ll * dp[i + 1][j - 1] * can[i][j];
         // cout << i << " " << j << " " << dp[i][j] << endl;
      }
   }
   cout << dp[0][n - 1];
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
