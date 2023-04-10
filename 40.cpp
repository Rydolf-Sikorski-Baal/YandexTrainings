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
    int n, k; cin >> n >> k;
    int comp = n;
    vvi n_graph(n + 3e5);
    
    vi ans_c(k);
    rep(curr_k, k){
        int m; cin >> m;
        is.assign(n, 0);
        graph.clear();graph.resize(n);
        zone_comp.assign(n, -1);
        rep(j, m){
            int f, t; cin >> f >>  t; --f;--t;
            //cout << "res: " << f << " " << t << '\n';
            //cout << "n: " << n << '\n';
            graph[f].push_back(t);
            graph[t].push_back(f);
        }
        rep(v, n) if ((graph[v].size()) && (zone_comp[v] == -1)) dfs_comp(v, comp++);
        //rep(v, n) cout << zone_comp[v] << (n - v - 1 ? ' ' : '\n');
        rep(v, n) if (zone_comp[v] != -1) {n_graph[zone_comp[v]].push_back(v);n_graph[v].push_back(zone_comp[v]);}
        ans_c[curr_k] = zone_comp[n - 1];
    }
    
    //cout << comp << '\n';
    //rep(i, k){rep(j, n) cout << zone_comp[i][j] << " "; cout << '\n';}
        
    ans.assign(comp, 2e9);is.assign(comp, 0);
    pq_pii bfs; bfs.push({-1, 0}); is[0] = 1;
    while(bfs.size()){
        pii curr = bfs.top();bfs.pop();
        int l = -curr.first; int v = curr.second;
        ans[v] = l;
        //cout << v << " " << l << '\n';
        for (int to : n_graph[v])
            if (!is[to]) {//cout << "f: " << v << " t: " << to << " l: " << l << '\n';
                bfs.push({-(l + 1), to}); is[to] = 1;}
    }
    
    int r_ans = 2e9;
    rep(i, k) min_it(r_ans, (ans_c[i] != -1 ? ans[ans_c[i]] : (int)2e9));
    //rep(i, k) cout << ans_c[i] << (k - i - 1 ? ' ' : '\n');
    cout << (r_ans == 2e9 ? -1 : r_ans/2);
}

int main() {
    start();
    int q = 1;// cin >> q;
    while(q--) solve();
}
