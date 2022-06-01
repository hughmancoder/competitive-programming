#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;
typedef double ld;

const int N = 2e5+10 , mod = 1e9+7;

void solve(){
   int a , b;
   cin >> a >> b;
   string s;
   cin >> s;
   int num = 0;
   pii fnd = {-1 , -1};
   for(int i = 1 ; i <= 9 ; i++){
      if(i == a || i == b){
         continue;
      }
      for(int j = i + 1 ; j <= 9 ; j++){
         if(j == a || j == b){
            continue;
         }
         int al[2] = {a , b};
         int bo[2] = {i , j};
         int cura = 0 , curb = 0;
         vector <int> ans;
         for(int k = 0 ; k < 4 ; k++){
            if(s[k] == 'A'){
               ans.push_back(al[cura++]);
            }
            else{
               ans.push_back(bo[curb++]);
            }
         }
         bool good = true;
         for(int k = 1 ; k < 4 ; k++){
            if(ans[k] < ans[k - 1]){
               good = false;
            }
         }
         if(good){
            fnd = {i , j};
         }
         num += good;
      }
   }
   if(num == 1){
      cout << fnd.first << " " << fnd.second;
   }
   else{
      cout << "-1";
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
