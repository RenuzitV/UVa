#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

string base = "abcdefghijklmnopqrstuvwxyz";

int main(){
    freopen("work.inp", "r", stdin);
    int t;
    scanf("%d\n", &t);
    for (int h = 1; h <= t; ++h){
        string s, temp;
        unsigned int n = 0, dem = 0, ansl = 0, ansr;
        getline(cin, s);
        unordered_map <string, int> m;
        unordered_set <string> se;
        vector <string> v;
        while (s != "END") {
            int lindex = s.find_first_of(base);
            int rindex = s.find_first_not_of(base, lindex+1);
            while (lindex != -1){
                if (rindex == -1) rindex = s.size();
                temp = s.substr(lindex, rindex-lindex);
                if (se.count(temp) == 0){
                    se.insert(temp);
                    ++n;
                }
                v.push_back(temp);
                if (rindex == (int)s.size()-1) break;
                lindex = s.find_first_of(base, rindex+1), rindex = s.find_first_not_of(base, lindex+1);
            }
            getline(cin, s);
        }
        ansr = v.size()-1;
        unsigned int itl = 0, itr = 0;
        while (itr < v.size()){
            if (m[v[itr]] == 0) ++dem;
            ++m[v[itr]];
            if (dem == n){
                while (m[v[itl]] > 1){
                    --m[v[itl]];
                    ++itl;
                }
                if (itr-itl < ansr-ansl){
                    ansl = itl;
                    ansr = itr;
                }
                m[v[itl]] = 0;
                --dem;
                ++itl;
            }
            ++itr;
        }
        printf("Document %d: %d %d\n", h, ansl+1, ansr+1);
    }
    return 0;
}
