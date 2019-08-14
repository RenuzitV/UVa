#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long

using namespace std;

int tree[1024010*4], lazy[1024010*4], a[1024010];

void build(int h, int l, int r){
    if (l > r) return;
    if (l == r) {
        tree[h] = a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(h<<1, l, mid);
    build(h<<1|1, mid+1, r);
    tree[h] = tree[h<<1] + tree[h<<1|1];
}

void change(int &tree, int val, int len){
    if (val == 1) tree = len;
    else if (val == 2) tree = 0;
    else if (val == 3) tree = len-tree;
}

void changelazy(int &lazy, int val){
    if (val == 3) lazy = 3-lazy;
    else lazy = val;
}

void down(int h, int len){
    if (lazy[h]) {
        change(tree[h], lazy[h], len);
        if (len > 1) {
            changelazy(lazy[h<<1], lazy[h]);
            changelazy(lazy[h<<1|1], lazy[h]);
        }
        lazy[h] = 0;
    }
}

void update(int h, int l, int r, int x, int y, int val){
    if (l > y || r < x) return;
    if (x <= l && r <= y) changelazy(lazy[h], val);
    down(h, r-l+1);
    if (x <= l && r <= y) return;
    int mid = (l+r) >> 1;
    down(h<<1, mid-l+1);
    down(h<<1|1, r-mid);
    update(h<<1, l, mid, x, y, val);
    update(h<<1|1, mid+1, r, x, y, val);
    tree[h] = tree[h<<1] + tree[h<<1|1];
}

int query(int h, int l, int r, int x, int y){
    if (l > y || r < x) return 0;
    down(h, r-l+1);
    if (x <= l && r <= y) return tree[h];
    int mid = (l+r) >> 1;
    return query(h<<1, l, mid, x, y) + query(h<<1|1, mid+1, r, x, y);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("11402.inp", "r", stdin);
        freopen("11402.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; ++tt){
        int m, q, n = 0;
        scanf("%d", &m);
        for (int h = 0; h < m; ++h){
            int l;
            string temp;
            scanf("%d\n", &l);
            getline(cin, temp);
            int ns = temp.size();
            for (int i = 0; i < l; ++i)
                for (int j = 0; j < ns; ++j)
                    a[++n] = temp[j]=='1';
        }
        for (int i = 1; i <= 4*n; ++i){
            tree[i] = 0;
            lazy[i] = 0;
        }
        build(1, 1, n);
        scanf("%d\n", &q);
        int cnt = 0;
        printf("Case %d:\n", tt);
        for (int i = 0; i < q; ++i){
            char c;
            int x, y;
            scanf("%c%d%d\n", &c, &x, &y);
            ++x;
            ++y;
            if (c == 'S'){
                ++cnt;
                printf("Q%d: %d\n", cnt, query(1, 1, n, x, y));
            }
            else {
                if (c == 'F') update(1, 1, n, x, y, 1);
                else if (c == 'E') update(1, 1, n, x, y, 2);
                else update(1, 1, n, x, y, 3);
            }
        }
    }
    return 0;
}
