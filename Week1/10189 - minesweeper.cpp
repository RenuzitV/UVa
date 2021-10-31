#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<int, int> td;
td di[8] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
char s[105][105];

td operator+(td a, td b){
    return mp(a.fi+b.fi, a.se+b.se);
}

int main(){
    //very useful for online judge platforms, you dont have to enter inputs via console and you also dont need to comment/delete the code.
    //CAUTION: some other OJs might not support this. kattis for example, does not.
    #ifndef ONLINE_JUDGE
        freopen("code.inp", "r", stdin);
        freopen("code.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int n, m;
    int t = 0;
    while (scanf("\n%d%d\n", &n, &m) != EOF && n != 0){
        if (t > 0) printf("\n");
        for (int i = 1; i <= n; ++i){
            string temp;
            getline(cin, temp);
            for (int j = 1; j <= m; ++j){
                s[i][j] = temp[j-1];
            }
        }
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                td u = mp(i, j);
                int res = 0;
                for (int h = 0; h < 8; ++h){
                    td v = u + di[h];
                    if (1 <= v.fi && v.fi <= n && 1 <= v.se && v.se <= m && s[v.fi][v.se] == '*') ++res;
                }
                if (s[u.fi][u.se] != '*') s[u.fi][u.se] = res+'0';
            }
        }
        printf("Field #%d:\n", ++t);
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                printf("%c", s[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
