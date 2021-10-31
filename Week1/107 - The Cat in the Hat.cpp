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

ll h0, wk;

bool go(ll n){
    if (h0 % (n+1) == 0){
        ll res = 0, res2 = wk, initial = 1, temph = h0;
        while (temph % (n+1) == 0){
            res += initial;
            res2 += initial*temph;
            temph /= n+1;
            initial *= n;
        }
        if (initial == wk){
            printf("%lld %lld\n", res, res2);
            return true;
        }
    }
    return false;
}

int main(){
    //very useful for online judge platforms, you dont have to enter inputs via console and you also dont need to comment/delete the code.
    //CAUTION: some other OJs might not support this. kattis for example, does not.
    #ifndef ONLINE_JUDGE
        freopen("code.inp", "r", stdin);
        freopen("code.out", "w", stdout);
    #endif // ONLINE_JUDGE

    while (scanf("%lld%lld", &h0, &wk) != EOF && h0 && wk){
        bool ok = false;
        if (h0 == 1 && wk == 1){
            printf("0 1\n");
            continue;
        }
        for (int n = 1; n <= h0; ++n){
            if (ok = go(n)) break;
        }
    }
    return 0;
}
