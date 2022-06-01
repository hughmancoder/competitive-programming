#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MAXN = 2e5+5;
const ll maxpk = 1e9+5;

ll times[MAXN];
ll passes[MAXN];
ll nexts[MAXN];
ll seen[MAXN];
ll seen_ans[MAXN];

int main() {
    ll n,p,k;
    scanf("%lld %lld %lld", &n,&p,&k);
    for (ll i=1;i<=n;i++) {
        scanf("%lld", &times[i]);
        times[i] += times[i-1];
        // cout << times[i] << " ";
    }
    // cout << endl;
    for (ll i=0;i<n;i++) {
        ll timen = times[i] + p;
        passes[i] = timen/times[n];
        timen %= times[n];
        nexts[i] = (upper_bound(times, times+n+1, timen) - times)-1;
        // cout << timen << " ";
    }
    ll day = 2;
    ll cur_ans = passes[0];
    seen[0] = 1;
    seen_ans[0] = 0;
    ll cur_ind = nexts[0];
    // cout << cur_ans << " " << cur_ind << " " << endl;
    while ((!seen[cur_ind]) && day <= k) {
        seen[cur_ind] = day;
        seen_ans[cur_ind] = cur_ans;
        day += 1;
        cur_ans += passes[cur_ind];
        cur_ind = nexts[cur_ind];
        // cout << cur_ans << " " << cur_ind << " " << endl;
    }
    // cout << endl;
    if (day <= k) {
        ll modu = day-seen[cur_ind];
        ll number_loops = (k-seen[cur_ind])/modu;
        cur_ans += (cur_ans - seen_ans[cur_ind])*(number_loops-1);
        k = (k-seen[cur_ind])%modu;
        day = 0;
        // cout << cur_ans << " " << cur_ind << " " << endl;
    }
    // cout << endl;
    while (day <= k) {
        day += 1;
        cur_ans += passes[cur_ind];
        cur_ind = nexts[cur_ind];
        // cout << cur_ans << " " << cur_ind << " " << endl;
    }
    // cout << endl;
    printf("%lld\n", cur_ans);
}