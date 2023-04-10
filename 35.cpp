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

vi zone_comp;
vvi graph;
vi is;
vi ans;
void dfs_comp(int v, int n){
    is[v] = 1; zone_comp[v] = n;
    //cout << "dfs: " << v << " " << n << '\n';
    for (int to : graph[v])
        if (!is[to]) dfs_comp(to, n);
}
inline void solve(){
    int n; cin >> n;
    vvi level(n);
    vi clossness(n, 0);
    
    rep(i, n){
        int m; cin >> m;
        //clossness[i] = m;
        rep(j, m){
            int x; cin >> x; --x;
            level[i].push_back(x);
            clossness[x]++;
        }
    }
        
    
    priority_queue<int> bfs; rep(i, n) if (!clossness[i]) bfs.push(i);
    vi ans(n); int k = n - 1;
    while(bfs.size()){
        int curr = bfs.top(); bfs.pop();
        ans[k--] = curr;
        for (int to : level[curr]){
            clossness[to]--;
            if (!clossness[to]) bfs.push(to);
        }
    }
    
    rep(i, n) cout << ans[i] + 1 << (n - i - 1 ? " " : "");
}

int main() {
    start();
    int q = 1;// cin >> q;
    while(q--) solve();
}
