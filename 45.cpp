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
typedef vector<vvi> vvvi;
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
inline void solve(){
    int n, m; cin >> n >> m;
    vvi zone(n, vi(m, 1));
    vvvi ans(n, vvi(m, vi(8, 2e9)));
    
    rep(i, n)
        rep(j, m){
            char x; cin >> x;
            if (x == 'X') zone[i][j] = 0;
        }
        
    int s_x, s_y; cin >> s_y >> s_x; --s_y; s_x = n - s_x;
    //cout << s_x << " " << s_y << '\n';
    priority_queue< pair<int, pair<int, pii> > > bfs;
    rep(i, 8) bfs.push({-1, {s_x, {s_y, i}}});
    while(bfs.size()){
        pair<int, pair<int, pii> > curr = bfs.top(); bfs.pop();
        int l = -curr.first;
        pair<int, pii> v = curr.second;
        int i = v.first;
        int j = v.second.first;
        int k = v.second.second;
        //if (ans[i][j][k] != 2e9) continue;
        
        ans[i][j][k] = l; //cout << i << " " << j << " " << k << " " << l << '\n';
        if (k == 0) if (i) if (ans[i - 1][j][k] > l) if (zone[i - 1][j])
            {bfs.push({-l, {i - 1, {j, k}}});ans[i - 1][j][k] = l;}
        if (k == 2) if (j < m - 1) if (ans[i][j + 1][k] > l) if (zone[i][j + 1])
            {bfs.push({-l, {i, {j + 1, k}}});ans[i][j + 1][k] = l;}
        if (k == 4) if (i < n - 1) if (ans[i + 1][j][k] > l) if (zone[i + 1][j])
            {bfs.push({-l, {i + 1, {j, k}}});ans[i + 1][j][k] = l;}
        if (k == 6) if (j) if (ans[i][j - 1][k] > l) if (zone[i][j - 1])
            {bfs.push({-l, {i, {j - 1, k}}});ans[i][j - 1][k] = l;}
        
        if (k == 1) if ((i) && (j < m - 1)) if (ans[i - 1][j + 1][k] > l) if (zone[i - 1][j + 1])
            {bfs.push({-l, {i - 1, {j + 1, k}}});ans[i - 1][j + 1][k] = l;}
        if (k == 3) if ((i < n - 1) && (j < m - 1)) if (ans[i + 1][j + 1][k] > l) if (zone[i + 1][j + 1])
            {bfs.push({-l, {i + 1, {j + 1, k}}});ans[i + 1][j + 1][k] = l;}
        if (k == 5) if ((i < n - 1) && (j)) if (ans[i + 1][j - 1][k] > l) if (zone[i + 1][j - 1])
            {bfs.push({-l, {i + 1, {j - 1, k}}});ans[i + 1][j - 1][k] = l;}
        if (k == 7) if ((i) && (j)) if (ans[i - 1][j - 1][k] > l) if (zone[i - 1][j - 1])
            {bfs.push({-l, {i - 1, {j - 1, k}}});ans[i - 1][j - 1][k] = l;}
            
        l++;
        rep(curr_k, 8) if (ans[i][j][curr_k] > l) 
            {bfs.push({-l, {i, {j, curr_k}}});ans[i][j][curr_k] = l;}
    }
    
    /*rep(i, n){
        rep(j, m){
            int r = 100;
            rep(k, 8) min_it(r, ans[i][j][k]);
            cout << r << " ";
        }
        cout << '\n';
    }*/
    
    int f_x, f_y; cin >> f_y >> f_x;--f_y;f_x = n - f_x;
    int f_ans = 2e9;
    rep(i, 8) min_it(f_ans, ans[f_x][f_y][i]);
    
    cout << (f_ans == 2e9 ? -1 : f_ans);
}

int main() {
    start();
    int q = 1;// cin >> q;
    while(q--) solve();
}
