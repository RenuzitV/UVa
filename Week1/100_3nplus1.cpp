#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long

ll f[10005];

ll dfs(ll u){
    if (u <= 1e4 && f[u] != -1) return f[u];
    ll nx;
    if (u & 1) nx = u*3+1;
    else nx = u >> 1;
    ll res = dfs(nx) + 1;
    if (u <= 1e4 && nx <= 1e4) f[u] = res;
    return res;
}

int main(){
    //very useful for online judge platforms, you dont have to enter inputs via console and you also dont need to comment/delete the code.
    //CAUTION: some other OJs might not support this. kattis for example, does not.
    #ifndef ONLINE_JUDGE
        freopen("code.inp", "r", stdin);
        freopen("code.out", "w", stdout);
    #endif // ONLINE_JUDGE
    for (int i = 1; i <= 10000; ++i)
        f[i] = -1;
    f[1] = 1;
    int u, v;
    while (scanf("%d%d\n", &u, &v) != EOF){
        ll ans = 0;
        for (int i = min(u, v); i <= max(u, v); ++i){
            ans = max(ans, dfs(i));
        }
        printf("%d %d %lld\n", u, v, ans);
    }
    return 0;
}
