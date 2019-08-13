#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define ll long long

using namespace std;

int a[100010], tree[400010], la[100010], ra[100010], cnt[100010], n;

void build(int h, int l, int r){
    if (l > r) return;
    if (l == r) {
        tree[h] = cnt[l];
        return;
    }
    int mid = (l+r) >> 1;
    build(h*2, l, mid);
    build(h*2+1, mid+1, r);
    tree[h] = max(tree[h*2], tree[h*2+1]);
}

int query(int h, int l, int r, int x, int y){
    if (r < x || l > y || x > y) return 0;
    if (l >= x && r <= y) return tree[h];
    int mid = (l+r) >> 1;
    return max(query(h*2, l, mid, x, y), query(h*2+1, mid+1, r, x, y));
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("11235.inp", "r", stdin);
        freopen("11235.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int n, q;
    scanf("%d%d", &n, &q);
    while (n){
        la[1] = 1;
        for (int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            if (i > 1 && a[i] == a[i-1]) la[i] = la[i-1];
            else la[i] = i;
        }
        ra[n] = n;
        for (int i = n-1; i >= 1; --i)
            if (a[i] == a[i+1]) ra[i] = ra[i+1];
            else ra[i] = i;
        cnt[1] = 1;
        for (int i = 2; i <= n; ++i)
            if (a[i] == a[i-1]) cnt[i] = cnt[i-1]+1;
            else cnt[i] = 1;
        build(1, 1, n);
        for (int i = 0; i < q; ++i){
            int l, r, x, y, ans = 0;
            scanf("%d%d", &l, &r);
            if (a[l] == a[r]) ans = r-l+1;
            else {
                if (la[l] != l){
                    ans = max(ans, ra[l]-l+1);
                    x = ra[l]+1;
                } else x = l;
                if (ra[r] != r){
                    ans = max(ans, r-la[r]+1);
                    y = la[r]-1;
                } else y = r;
                ans = max(ans, query(1, 1, n, x, y));
            }
            printf("%d\n", ans);
        }
        scanf("%d%d", &n, &q);
    }
    return 0;
}
