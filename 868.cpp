#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair

using namespace std;

int t, n, m, a[110][110], ans1, ans2;
bool ktt, fr[110][110];
typedef pair<int, int> td;
td dir[4] = {mp(0, 1), mp(1, 0), mp(0, -1), mp(-1, 0)};

void nhap(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            scanf("%d", &a[i][j]);
            fr[i][j] = true;
        }
}

td operator +(td a, td b){
    return mp(a.x+b.x, a.y+b.y);
}

bool kt(td s, td hk){
    return (0 < s.x && s.x <= n && 0 < s.y && s.y <= m && fr[s.x][s.y] && a[s.x][s.y] == hk.y);
}

void dfs(td s, td hk){
    if (s.x == n){
        ktt = true;
        ans2 = min(ans2, s.y);
        return;
    }
    td nhk;
    if (hk.y == hk.x) nhk = mp(hk.x+1, 1);
    else nhk = mp(hk.x, hk.y+1);
    for (int i = 0; i < 4; ++i){
        td f = s + dir[i];
        if (kt(f, nhk)) {
            fr[f.x][f.y] = false;
            dfs(f, nhk);
            fr[f.x][f.y] = true;
        }
    }
}


int main() {
    scanf("%d", &t);
    while (t--){
        nhap();
        for (int i = 1; i <= m; ++i){
            td s = mp(1, i);
            if (a[s.x][s.y] == 1) {
                fr[s.x][s.y] = false;
                ans1 = i;
                ans2 = m;
                ktt = false;
                dfs(s, mp(1, 1));
                fr[s.x][s.y] = true;
                if (ktt) break;
            }
        }
        printf("1 %d\n%d %d\n\n", ans1, n, ans2);
    }
    return 0;
}
