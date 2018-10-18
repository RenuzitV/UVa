#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(){
    freopen("work.inp", "r", stdin);
    priority_queue <int> f;
    priority_queue <int, vector<int>, greater<int> > b;
    int s;
    while (scanf("%d", &s) != EOF){
        if (f.empty() || s < f.top()) f.push(s);
        else b.push(s);
        while (f.size() != b.size() && f.size()-1 != b.size()){
            if (f.size() > b.size()) {
                b.push(f.top());
                f.pop();
            }
            else{
                f.push(b.top());
                b.pop();
            }
        }
        if (f.size() > b.size()) printf("%d", f.top());
        else printf("%d", (f.top()+b.top())/2);
        printf("\n");
    }
    return 0;
}
