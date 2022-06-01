#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;
typedef double ld;

const int N = 2e5+10 , mod = 1e9+7 , L = 18;

int m , pw[N] , par[N][L] , val[N][L][2] , h[N] , a[N];
vector <int> g[N];

void dfs(int v , int p , int hei){
   h[v] = hei;
   par[v][0] = p;
   val[v][0][0] = val[v][0][1] = a[p];
   for(int i = 1 ; i < L ; i++){
      par[v][i] = par[par[v][i - 1]][i - 1];
      val[v][i][0] = (1ll * val[v][i - 1][0] * pw[1 << (i - 1)] % m + val[par[v][i - 1]][i - 1][0]) % m;
      val[v][i][1] = (1ll * val[par[v][i - 1]][i - 1][1] * pw[1 << (i - 1)] % m + val[v][i - 1][1]) % m;
   }
   for(int u : g[v]){
      if(u != p){
         dfs(u , v , hei + 1);
      }
   }
}

int pr(int v , int x){
   for(int i = 0 ; i < L ; i++){
      if((1 << i) & x){
         v = par[v][i];
      }
   }
   return v;
}

int lca(int u , int v){
   if(h[u] > h[v]){
      swap(u , v);
   }
   v = pr(v , h[v] - h[u]);
   if(u == v){
      return v;
   }
   for(int i = L - 1 ; i >= 0 ; i--){
      if(par[v][i] != par[u][i]){
         v = par[v][i];
         u = par[u][i];
      }
   }
   return par[v][0];
}

int getval0(int v , int x){
   int curval = a[v];
   for(int i = 0 ; i < L ; i++){
      if((1 << i) & x){
         curval = (1ll * curval * pw[1 << i] % m + val[v][i][0]) % m;
         v = par[v][i];
      }
   }
   return curval;
}

int getval1(int v , int x){
   int curval = a[v];
   int num = 1;
   for(int i = 0 ; i < L ; i++){
      if((1 << i) & x){
         curval = (1ll * val[v][i][1] * pw[num] % m + curval) % m;
         num += (1 << i);
         v = par[v][i];
      }
   }
   return curval;
}

void solve(){
   int n , q;
   cin >> n >> m >> q;
   pw[0] = 1 % m;
   for(int i = 1 ; i < N ; i++){
      pw[i] = 1ll * pw[i - 1] * 10 % m;
   }
   for(int i = 0 ; i < n - 1 ; i++){
      int u , v;
      cin >> u >> v;
      u--; v--;
      g[u].push_back(v);
      g[v].push_back(u);
   }
   for(int i = 0 ; i < n ; i++){
      cin >> a[i];
      a[i] %= m;
   }
   dfs(0 , 0 , 0);
   for(int i = 0 ; i < q ; i++){
      int u , v;
      cin >> u >> v;
      u--; v--;
      int p = lca(u , v);
      int ans = getval0(u , h[u] - h[p]);
      if(v != p){
         int len = h[v] - h[p] - 1;
         ans = (1ll * ans * pw[len + 1] % m + getval1(v , len)) % m;
      }
      cout << ans << "\n";
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
