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

int main(){
    //very useful for online judge platforms, you dont have to enter inputs via console and you also dont need to comment/delete the code.
    //CAUTION: some other OJs might not support this. kattis for example, does not.
    cin.tie(0);
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("code.inp", "r", stdin);
        freopen("code.out", "w", stdout);
    #endif // ONLINE_JUDGE

    string s, alphabet, ans, alphanum, numeric;
    for (char x = 'a'; x <= 'z'; ++x){
        alphabet += x;
        alphabet += toupper(x);
    }
    for (char x = '0'; x <= '9'; ++x){
        numeric += x;
    }
    alphanum = alphabet + numeric;
    vector <string> v;
    while (getline(cin, s) && s != "0"){
        int i = 0, j = 0, n = s.size();
        while (i < s.size() && j < s.size()){
            j = s.find_first_not_of(alphabet, i);
            string word;
            if (j == -1) j = s.size();
            if (i < j){
                word = s.substr(i, j-i);
                ans += word;
                v.push_back(word);
            }
            i = s.find_first_of(alphanum, j);
            if (i == -1) i = s.size();
            string notword = s.substr(j, i-j);
            ans += notword;

            j = s.find_first_not_of(numeric, i);
            if (j == -1) j = s.size();
            string snum = s.substr(i, j-i);
            int num = strtol(snum.c_str(), NULL, 10);
            if (num > 0) {
                string temp = v[v.size()-num];
                v.erase(v.begin() + (v.size()-num));
                v.push_back(temp);
                ans += v.back();
            }
            else {
                ans += snum;
            }

            i = j;
        }
        ans += '\n';
    }
    printf("%s", ans.c_str());
    return 0;
}
