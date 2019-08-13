#include <bits/stdc++.h>
#include "bigint.h"
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long

using namespace std;

bigint fibo[120];

void extract(bigint &a, char c[120]){
    int n = strlen(c);
    for (int i = 0; i < n; ++i)
        if (c[i] == '1') a = a + fibo[n-i+1];
}

string compile(bigint a){
    int i;
    string res = "";
    for (i = 111; i >= 2; --i)
        if (a >= fibo[i-1]) break;
    for (--i; i >= 2; --i)
        if (a >= fibo[i]) {
            res += '1';
            a = a - fibo[i];
        }
        else res += '0';
    return res;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("763.inp", "r", stdin);
        freopen("763.out", "w", stdout);
    #endif // ONLINE_JUDGE
    fibo[1] = 1;
    for (int i = 2; i <= 120; ++i)
        fibo[i] = fibo[i-1] + fibo[i-2];
    char c1[120], c2[120];
    bool fudgeuva = false;
    while (scanf("%s\n%s\n\n", c1, c2) != EOF){
        if (!fudgeuva) fudgeuva ^= 1;
        else printf("\n\n");
        bigint a, b;
        extract(a, c1);
        extract(b, c2);
        a = a + b;
        string s = compile(a);
        if (s.size() > 0) printf("%s", s.c_str());
        else printf("0");
    }
    printf("\n");
    return 0;
}
