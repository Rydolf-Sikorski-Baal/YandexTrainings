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

inline void solve(){
    string a, b; cin >> a >> b;
    vvl dp(a.size(), vl(b.size(), 1e9));
    rep(i, a.size()) dp[i][0] = i + (a[i] != b[0]);
    rep(j, b.size()) dp[0][j] = j + (a[0] != b[j]);
    rep(i, a.size())
        rep(j, b.size()){
            if (i) min_it(dp[i][j], dp[i - 1][j] + 1);
            if (j) min_it(dp[i][j], dp[i][j - 1] + 1);
            if (i && j) 
                min_it(dp[i][j], dp[i - 1][j - 1] + (a[i] != b[j]));
        }
    //rep(i, a.size())
      //  rep(j, b.size())
        //    cout << dp[i][j] << (b.size() - j - 1 ? ' ' : '\n');
    cout << dp[a.size() - 1][b.size() - 1];
}

int main() {
    start();
    int q = 1;
    while(q--) solve();
}
