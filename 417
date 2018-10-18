#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

map<string, int> m;

string base = "abcdefghijklmnopqrstuvwxyz", s;

int dem;

void dfs(int p, int h){
    for (int i = p; i < 26; ++i){
        s.push_back(base[i]);
        if (h == 5) m[s] = ++dem;
        else dfs(i+1, h+1);
        s.pop_back();
    }
}

int main(){
    freopen("work.inp", "r", stdin);
    for (int i = 5; i >= 1; --i)
        dfs(0, i);
    getline(cin, s);
    while (s != ""){
        printf("%d\n", m[s]);
        getline(cin, s);
    }
    return 0;
}
