#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int _pow(int a, int b){
    int res = 1, temp = a;
    while (b){
        if (b & 1) res *= temp;
        b >>= 1;
        temp *= temp;
    }
    return res;
}

int main(){
    freopen("work.inp", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int h = 0; h < t; ++h){
        int n = 1, cost = 0, a[40];
        scanf("%d", &a[0]);
        while (a[n-1] != 0){
            scanf("%d", &a[n++]);
        }
        --n;
        sort(a, a+n, greater<int>());
        bool ok = true;
        for (int i = 0; i < n; ++i){
            int res = 2*_pow(a[i], i+1);
            if (cost + res > 5000000){
                ok = false;
                break;
            }
            else cost += res;
        }
        if (ok) printf("%d", cost);
        else printf("Too expensive");
        printf("\n");
    }
    return 0;
}
