#include <iostream>
#include <cstdio>
#include <string>
#include <deque>

using namespace std;

int main(){
    freopen("work.inp", "r", stdin);
    string s;
    getline(cin, s);
    while (s != ""){
        string ans = "";
        int lindex = s.find_first_not_of("[]"), rindex = s.find_first_of("[]", lindex+1);
        while (lindex != -1){
            if (rindex == -1) rindex = s.size();
            string ss = s.substr(lindex, rindex-lindex);
            if (lindex == 0 || s[lindex-1] == '[') ans = ss + ans;
            else ans = ans + ss;
            if (rindex == (int)s.size()) break;
            lindex = s.find_first_not_of("[]", rindex+1), rindex = s.find_first_of("[]", lindex+1);
        }
        printf("%s", ans.c_str());
        printf("\n");
        getline(cin, s);
    }
    return 0;
}
