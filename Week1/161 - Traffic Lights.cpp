#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<int, int> td;
typedef pair<int, td> tdd;
td di[8] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

td operator+(td a, td b){
    return mp(a.fi+b.fi, a.se+b.se);
}

int a[1005];

int main(){
    //very useful for online judge platforms, you dont have to enter inputs via console and you also dont need to comment/delete the code.
    //CAUTION: some other OJs might not support this. kattis for example, does not.
    #ifndef ONLINE_JUDGE
        freopen("code.inp", "r", stdin);
        freopen("code.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int x;
    while (scanf("%d", &x) != EOF){
        int minn = x;
        a[0] = x;
        int n = 1;
        while (scanf("%d", &a[n]) != EOF && a[n++] != 0) minn = min(minn, a[n-1]);
        if (a[0] == a[1] && a[0] == 0) return 0;
        --n;
        bool ok;
        for (int t = minn+1; t <= 60*60*5; ++t){
            ok = true;
            for (int i = 0; i < n; ++i){
                int temp = t % (a[i]*2);
                if (temp >= a[i]-5) {
                    ok = false;
                    break;
                }
            }
            if (ok){
                printf("%02d:%02d:%02d\n", t/3600, t/60%60, t%3600%60);
                break;
            }
        }
        if (!ok) printf("Signals fail to synchronise in 5 hours\n");
    }
    return 0;
}
