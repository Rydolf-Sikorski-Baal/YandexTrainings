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
vi is_ch, is_nch;
inline void solve(){
    int n, k; cin >> n >> k;
    vvi dang(n);
    rep(i, k){
        int f, t; cin >> f >> t;--f;--t;
        dang[f].push_back(t);
        dang[t].push_back(f);
    }
    
    int m; cin >> m;
    vi start(m); rep(i, m) {cin >> start[i];start[i]--;}
    
    pq_pii bfs;
    vvi ans_ch (m, vi(n, 2e9));
    vvi ans_nch(m, vi(n, 2e9));
    rep(i, m){
        bfs.push({0, start[i]});
        is_ch.assign(n, 0);is_nch.assign(n, 0);
        is_ch[start[i]] = 1;
        while(bfs.size()){
            pii curr = bfs.top();bfs.pop();
            int l = -curr.first; int v = curr.second;
            if (!(l % 2)){ans_ch[i][v] = l;}else{ans_nch[i][v] = l;}
            l++;
            for (int to : dang[v]){
                if ((l % 2)){
                    if (!is_nch[to]){
                        bfs.push({-l, to}); 
                        is_nch[to] = 1;
                    }  
                }else{ 
                    if (!is_ch[to]){
                        bfs.push({-l, to}); 
                        is_ch[to] = 1;
                    }
                }
            }
        }
    }
    
    double r_ans = 2e9;
    
    //rep(i, m) {rep(j, n) cout << ans_ch[i][j] << " "; cout << '\n';}
    rep(i, n){
        int res_ch_max  = ans_ch[0][i];
        int res_nch_max = ans_nch[0][i];
        rep_1(j, m) max_it(res_ch_max, ans_ch[j][i]);
        rep_1(j, m) max_it(res_nch_max, ans_nch[j][i]);
        int res = min(res_ch_max, res_nch_max);
        min_it(r_ans, (double)res);
    }
    
    rep(i, n)
        for(int to : dang[i]){
            int res_ch = 0, res_nch = 0;
            int res = 2e9;
            rep(rob, m){
                max_it(res_ch, min(ans_ch[rob][to], ans_ch[rob][i]));
                max_it(res_nch, min(ans_nch[rob][to], ans_nch[rob][i]));
            }
            res = min(res_ch, res_nch);
            min_it(r_ans, (double)res_ch + 0.5);
            min_it(r_ans, (double)res_nch + 0.5);
            min_it(r_ans, (double)res + 0.5);
      //cout << res_ch << " " << res_nch << " " << res << '\n';
        }
    cout << (r_ans == 2e9 ? -1 : r_ans);
}

int main() {
    start();
    int q = 1;// cin >> q;
    while(q--) solve();
}
