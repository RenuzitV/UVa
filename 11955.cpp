#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long

using namespace std;

long long c[50][50];

long long calc(int n, int k){
    if (k > n/2) k = n-k;
    if (c[n][k] != 0) return c[n][k];
    else if (n == 1 || k == 0 || k == n) return c[n][k] = 1;
    else return c[n][k] = calc(n-1, k-1) + calc(n-1, k);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("code.inp", "r", stdin);
        freopen("code.out", "w", stdout);
    #endif // ONLINE_JUDGE
    int t;
    scanf("%d\n", &t);
    for (int h = 1; h <= t; ++h){
        string s, a, b;
        unsigned int n;
        getline(cin, s);
        unsigned int i = 0;
        for (; i < s.size(); ++i)
            if ('a' <= s[i] && s[i] <= 'z') break;
        for (; i < s.size(); ++i)
            if ('a' <= s[i] && s[i] <= 'z') a += s[i];
            else break;
        for (; i < s.size(); ++i)
            if ('a' <= s[i] && s[i] <= 'z') break;
        for (; i < s.size(); ++i)
            if ('a' <= s[i] && s[i] <= 'z') b += s[i];
            else break;
        s.erase(0, i+2);
        stringstream ss(s);
        ss >> n;
        printf("Case %d: ", h);
        for (i = 0; i <= n; ++i) {
            if (i > 0) printf("+");
            if (0 < i && i < n) printf("%I64d*", calc(n, i));
            if (n-i > 0) printf("%s", a.c_str());
            if (n-i > 1) printf("^%d", n-i);
            if (0 < i && i < n) printf("*");
            if (i > 0) printf("%s", b.c_str());
            if (i > 1) printf("^%d", i);
        }
        printf("\n");
    }
    return 0;
}
