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
typedef vector<vi> vvi;
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
vvi graph;
vi is;
int dfs(int v){
    ++is[v];int res = 1;
    for (int to : graph[v])
        if (!is[to])
            res += dfs(to);
    return res;
}

inline void solve(){
    int n; cin >> n;
    graph.resize(n * n); is.assign(n * n, 1);
    rep(i, n)
        rep(j, n){
            char x; cin >> x; if (x == '*') continue;
            int curr_id = n*i + j; is[curr_id] = 0;
            int id_up = n*(i - 1) + j;
            int id_down = n*(i + 1) + j;
            int id_left = n*i + (j - 1);
            int id_right = n*i + (j + 1);
            
            graph[curr_id].push_back(id_up);
            graph[curr_id].push_back(id_down); 
            graph[curr_id].push_back(id_left); 
            graph[curr_id].push_back(id_right);
            graph[id_up].push_back(curr_id);
            graph[id_down].push_back(curr_id);
            graph[id_left].push_back(curr_id);
            graph[id_right].push_back(curr_id);
        }
        
    int x, y; cin >> x >> y; --x;--y;
    cout << dfs(x*n + y);
}

int main() {
    start();
    int q = 1;
    while(q--) solve();
}
