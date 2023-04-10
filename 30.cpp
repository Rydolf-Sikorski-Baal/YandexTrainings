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

inline void solve(){
    ll l, n; cin >> l >> n;
    vi coord(n + 2, 0); rep(i, n) cin >> coord[i + 1]; coord[n + 1] = l;
    vector< vector<int> > dp(n + 2, vector<int>(n + 2, 0));
    
    for (int k = 0; k < n + 2; ++k)
        rep(c, n + 2 - k){
            int left = c;
            int right = k + c;
            
            if (right <= left) continue;
            if ((left >= n + 2) || (right >= n + 2)) continue;
            
            if (right - left <= 1) continue;
            int res = 2e9;
            rep_s(i, left + 1, right) min_it(res, dp[left][i] + dp[i][right]);
            dp[left][right] = (coord[right] - coord[left]) + res;
        }
    //rep(i, n + 2)
      //  rep(j, n + 2)
        //    cout << dp[i][j] << (n + 2 - j - 1 ? ' ' : '\n');
    //print(dp[n - 1][m - 1]);
    cout << dp[0][n + 1];
}

int main() {
    start();
    int q = 1;
    while(q--) solve();
}
