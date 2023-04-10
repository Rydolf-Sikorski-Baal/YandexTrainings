#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("03")

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <stack>
#include <map>
#include <utility>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_1(i, n) for (int i = 1; i < n; ++i)
#define rep_s(i, s, n) for (int i = s; i < n; ++i)
#define load_ll(a) ll a; cin >> a;
#define load_2ll(a, b) ll a, b; cin >> a >> b;
#define load_3ll(a, b, c) ll a, b, c; cin >> a >> b >> c;
#define load_str(a) string a; cin >> a;
#define max_it(a, b) a = max(a, b);
#define min_it(a, b) a = min(a, b);

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef stack<ll> sl;
typedef stack<pll> spll;

void fast(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
void file(){
	freopen("joseph.in", "r", stdin);
	freopen("joseph.out", "w", stdout);
}
void start(){
  fast(); 
  //file();
}

ll bin_p(vl & a, ll p){
    ll left = 0, right = a.size();
    while(left + 1 != right){
        ll mid = (left + right) >> 1;
        //cout << left << " " << right << " " << mid << '\n';
        if (mid >= a.size()) return -1;
        if (a[mid] < p){
            left = mid;
        }else{
            right = mid;
        }
    }
    return left;
}

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

map<char, string> dict;
vvi dp(6, vi(101, -1));
inline int find_ans(char comm, int param){
    //cout << comm << " " << param << '\n';
    int icomm = -1;
    if (comm == 'N') icomm = 0;if (comm == 'S') icomm = 1;if (comm == 'W') icomm = 2;
    if (comm == 'E') icomm = 3;if (comm == 'U') icomm = 4;if (comm == 'D') icomm = 5;
    //cout << dp[icomm][param] << '\n';
    
    if (dp[icomm][param] != -1) return dp[icomm][param];
    int ans = 1;
    for (char ch : dict[comm]) ans += find_ans(ch, param - 1);
    dp[icomm][param] = ans;
    return ans;
}

inline void solve(){
    for (char ch : {'N', 'S', 'W', 'E', 'U', 'D'}){string x;getline(cin, x);dict[ch] = x;}
    
    char comm; cin >> comm;
    int param; cin >> param;
    rep(i, 6) dp[i][0] = 0;
    cout << find_ans(comm, param);
}

int main() {
    start();
    int q = 1;
    while(q--) solve();
}
