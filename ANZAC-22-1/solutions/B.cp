#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;
typedef double ld;

const int N = 2e5+10 , mod = 1e9+7;

void solve(){
   int a[4][4];
   memset(a , 0 , sizeof(a));
   int time;
   cin >> time;
   int h = time / 100 , m = time % 100;
   for(int i = 0 ; i < 4 ; i++){
      if((1 << i) & (h / 10)){
         a[3 - i][0] = 1;
      }
   }
   for(int i = 0 ; i < 4 ; i++){
      if((1 << i) & (h % 10)){
         a[3 - i][1] = 1;
      }
   }
   for(int i = 0 ; i < 4 ; i++){
      if((1 << i) & (m / 10)){
         a[3 - i][2] = 1;
      }
   }
   for(int i = 0 ; i < 4 ; i++){
      if((1 << i) & (m % 10)){
         a[3 - i][3] = 1;
      }
   }
   for(int i = 0 ; i < 4 ; i++){
      for(int j = 0 ; j < 4 ; j++){
         if(a[i][j] == 0){
            cout << ". ";
         }
         else{
            cout << "* ";
         }
         if(j == 1){
            cout << "  ";
         }
      }
      cout << "\n";
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
