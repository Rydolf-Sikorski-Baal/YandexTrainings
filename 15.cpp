#pragma GCC optimize("02")

#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <stack>
#include <utility>
using namespace std;

inline bool check_str(string & str){
    stack<string> st;
    string name = "";
    for(char ch : str){
        if (ch == '>'){
            if (!name.size()) return false;
            if (name[0] == '/'){
                if (!st.size()) return false;
                if (name.substr(1, name.size() - 1) != st.top()) return false;
                st.pop();
                name = "";
                continue;
            }
            st.push(name);
            name = "";
            continue;
        }
        if (ch == '<') {if (name.size()) return false; name = ""; continue;}
        name += ch;
    }
    return !st.size();
}

inline void solve(){
    string s; cin >> s;
    for (int i = 0; i < s.size(); ++i){
        string new_str = s;
        for (int j = 0; j < 26; ++j)
            {new_str[i] = 'a' + j;if (check_str(new_str)){cout << new_str;return;}}
        new_str[i] = '/';if (check_str(new_str)){cout << new_str;return;}
        new_str[i] = '<';if (check_str(new_str)){cout << new_str;return;}
        new_str[i] = '>';if (check_str(new_str)){cout << new_str;return;}
    }
}

int main() {
    long long q = 1;
    while(q--) solve();
}
