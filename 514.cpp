#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main(){
    freopen("work.inp", "r", stdin);
    int n;
    scanf("%d", &n);
    while (n != 0){
        int so;
        scanf("%d", &so);
        while (so != 0){
            stack <int> s;
            int dem = 0;
            for (int i = 1; i < n; ++i){
                while (dem <= n && (s.empty() || s.top() != so)) s.push(++dem);
                while (!s.empty() && s.top() == so) s.pop();
                scanf("%d", &so);
            }
            s.push(so);
            while (dem <= n && (s.empty() || s.top() != so)) s.push(++dem);
            while (!s.empty() && s.top() == so) s.pop();
            if (s.empty()) printf("Yes");
            else printf("No");
            printf("\n");
            scanf("%d", &so);
        }
        printf("\n");
        scanf("%d", &n);
    }
    return 0;
}
