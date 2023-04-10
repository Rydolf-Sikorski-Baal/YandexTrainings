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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef stack<ll> sl;
typedef stack<pll> spll;
typedef priority_queue<pii> pq_pii;
typedef map<int, int> mii;

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

vvi graph;
vi is;
vi ans;

void dfs(int v, int color){
    is[v] = 1;ans[v] = color;
    for (int to : graph[v])
        if (!is[to]) dfs(to, 1 - color);
}

bool check(vl & x_c, vl & y_c, ld r){
    size_t n = x_c.size();
    graph.clear();graph.resize(n);
    is.assign(n, 0);
    ans.assign(n, -1);
    size_t k = 0;
    rep(i, n)
        rep(j, n){
            if (i == j) continue;
            ld x = x_c[i] - x_c[j]; x *= x;
            ld y = y_c[i] - y_c[j]; y *= y;
            
            if (x + y <= (ld) 4 * r * r){
                k++;
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    rep (i, n) if (!is[i]) dfs(i, 1);
    rep(i, n){
        for (int to : graph[i]) if (ans[to] != 1 - ans[i]) return false;
    }
    return true;
}

const ld eps = 0.000000000001;
ld bin_p(vl & x_c, vl & y_c){
    ld left = 0, right = 1e5;
    while(right - left > eps){
        ld mid = (left + right) / 2.0;
        //cout << left << " " << right << " " << mid << '\n';
        if (check(x_c, y_c, mid)){
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
    int n; cin >> n;
    
    vl x_c(n), y_c(n);
    rep(i, n) cin >> x_c[i] >> y_c[i];
    
    ld ans_r = bin_p(x_c, y_c);
    check(x_c, y_c, ans_r);
    
    cout << fixed << setprecision(12) << ans_r << '\n';
    rep(i, n) cout << ans[i] + 1 << (n - i - 1 ? " " : "");
}

int main() {
    start();
    int q = 1;
    while(q--) solve();
}
