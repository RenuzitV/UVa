#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(){
    freopen("work.inp", "r", stdin);
    int n;
    scanf("%d", &n);
    while (n != 0){
        int ans = 0;
        priority_queue <int, vector<int>, greater<int> > pq;
        for (int i = 0; i < n; ++i){
            int s;
            scanf("%d", &s);
            pq.push(s);
        }
        for (int i = 1; i < n; ++i){
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            ans += f+s;
            pq.push(f+s);
        }
        printf("%d\n", ans);
        scanf("%d", &n);
    }
    return 0;
}
