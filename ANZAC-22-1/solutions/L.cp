#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;
typedef double ld;

const int N = 751 , mod = 1e9+7;

int n , m;
string s[N];
bool mark[N][N] , fut[N][N];
int att[N][N];
int attx[] = {1 , 2 , 2 , 1 , -1 , -2 , -2 , -1};
int atty[] = {2 , 1 , -1 , -2 , -2 , -1 , 1 , 2};

bool in(int x , int y){
   if(x < 0 || x >= m || y < 0 || y >= n){
      return false;
   }
   return true;
}

void reset(){
   memset(mark , 0 , sizeof(mark));
   memset(att , 0 , sizeof(att));
   for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
         if(s[i][j] != 'K'){
            continue;
         }
         for(int k = 0 ; k < 8 ; k++){
            int x = j + attx[k];
            int y = i + atty[k];
            if(!in(x , y)){
               continue;
            }
            att[y][x]++;
         }
      }
   }
}

void dfs(int x , int y){
   mark[y][x] = true;
   if(s[y][x] == 'K'){
      s[y][x] = '.';
      for(int i = 0 ; i < 8 ; i++){
         int xx = x + attx[i];
         int yy = y + atty[i];
         if(!in(xx , yy)){
            continue;
         }
         att[yy][xx]--;
         if(att[yy][xx] == 0 && fut[yy][xx] && !mark[yy][xx]){
            dfs(xx , yy);
         }
      }
   }
   for(int i = y + 1 ; i < n ; i++){
      if(!att[i][x] && !mark[i][x]){
         dfs(x , i);
      }
      else if(att[i][x]){
         fut[i][x] = true;
      }
      if(s[i][x] == 'K'){
         break;
      }
   }
   for(int i = y - 1 ; i >= 0 ; i--){
      if(!att[i][x] && !mark[i][x]){
         dfs(x , i);
      }
      else if(att[i][x]){
         fut[i][x] = true;
      }
      if(s[i][x] == 'K'){
         break;
      }
   }
   for(int i = x + 1 ; i < m ; i++){
      if(!att[y][i] && !mark[y][i]){
         dfs(i , y);
      }
      else if(att[y][i]){
         fut[y][i] = true;
      }
      if(s[y][i] == 'K'){
         break;
      }
   }
   for(int i = x - 1 ; i >= 0 ; i--){
      if(!att[y][i] && !mark[y][i]){
         dfs(i , y);
      }
      else if(att[y][i]){
         fut[y][i] = true;
      }
      if(s[y][i] == 'K'){
         break;
      }
   }
}

void go(){
   int x = -1 , y = -1;
   for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
         if(s[i][j] == 'R'){
            x = j , y = i;
         }
      }
   }
   dfs(x , y);
   bool upd = false;
   for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
         if(s[i][j] == 'T' && mark[i][j]){
            cout << "yes";
            exit(0);
         }
      }
   }
}

void solve(){
   cin >> n >> m;
   for(int i = 0 ; i < n ; i++){
      cin >> s[i];
   }
   reset();
   go();
   cout << "no";
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
