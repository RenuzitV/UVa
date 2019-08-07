#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long

using namespace std;

int modu[4] = {60, 300, 1500, 15000};
int power[4] = {10, 100, 1000, 10000};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("code.inp", "r", stdin);
        freopen("code.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int t;
    scanf("%d", &t);
    while (t--){
        int a, b, n, m;
        scanf("%d%d%d%d", &a, &b, &n, &m);
        int r = modu[m-1];
        n %= r;
        r = power[m-1];
        for (int i = 0; i < n; ++i){
            b += a;
            a = b - a;
            b %= r;
            a %= r;
        }
        printf("%d\n", a);
    }
    return 0;
}
