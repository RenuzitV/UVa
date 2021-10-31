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

double a[1005];

int main(){
    //very useful for online judge platforms, you dont have to enter inputs via console and you also dont need to comment/delete the code.
    //CAUTION: some other OJs might not support this. kattis for example, does not.
    #ifndef ONLINE_JUDGE
        freopen("code.inp", "r", stdin);
        freopen("code.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int n;
    while (scanf("%d", &n) != EOF && n){
        int sum = 0;
        for (int i = 0; i < n; ++i){
            int x, y;
            scanf("%d.%d", &x, &y);
            a[i] = x*100 + y;
            sum += a[i];
        }
        int sum2 = sum % n ? sum/n+1 : sum/n;
        sum /= n;
        int res = 0, res2 = 0;
         for (int i = 0; i < n; ++i){
            int temp = sum-a[i];
            int temp2 = a[i]-sum2;
            if (temp > 0) res += temp;
            if (temp2 > 0) res2 += temp2;
        }
        printf("$%.2f\n", 1.0*max(res, res2)/100);
    }
    return 0;
}
