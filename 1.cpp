#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("03")

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <map>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define max_it(a, b) a = max(a, b);

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

inline void solve(){
  set<char> symbols;
  map<char, ll> res;
  
  string curr;
  ll max_res = 0;
  while (cin >> curr){
    for (char ch : curr){
        symbols.insert(ch);
        res[ch]++;
        max_it(max_res, res[ch]);
    }
  }

  while(max_res--){
    for (char ch : symbols)
        cout << (res[ch] >= max_res + 1 ? '#' : ' ');
    cout << '\n';
  }
        
  for (char ch : symbols) cout << ch;
}

int main() {
    int q = 1;
    while(q--) solve();
}
