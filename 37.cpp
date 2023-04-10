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
vi ans;
void dfs(int v){
    is[v] = 1;ans[v] = 1;
    if (graph[v].size()) 
        for (int to : graph[v])
            if (!is[to]) dfs(to);
}

inline void solve(){
    int n = 9*1000 + 9*100 + 9*10 + 9;
    graph.resize(n); is.assign(n, 0);ans.assign(n, -1);
    
    mii ids;
    rep(i_1, 9)
        rep(i_2, 9)
            rep(i_3, 9)
                rep(i_4, 9){
                    int curr_id = i_1 + 10*i_2 + 100*i_3 + 1000*i_4;
                    ids[curr_id] = 1000*(i_1 + 1) + 100*(i_2 + 1) + 10*(i_3 + 1) + (i_4 + 1);
                    
                    int id_1 = curr_id + 1;
                    int id_2 = curr_id - 1000;
                    int id_3 = i_2 + 10*i_3 + 100*i_4 + 1000*i_1;
                    int id_4 = i_4 + 10*i_1 + 100*i_2 + 1000*i_3;
                    
                    if (i_1 < 9) graph[curr_id].push_back(id_1);
                    if (i_4 >= 1) graph[curr_id].push_back(id_2);
                    graph[curr_id].push_back(id_3);
                    graph[curr_id].push_back(id_4);
                }
    
    int start; cin >> start;
    int s_id = ((start % 10) - 1)*1000; start /= 10;
    s_id += ((start % 10) - 1)*100; start /= 10;
    s_id += ((start % 10) - 1)*10; start /= 10;
    s_id += (start % 10) - 1; start /= 10;
    pq_pii bfs; bfs.push({0, s_id});
    while(bfs.size()){
        pii curr = bfs.top();bfs.pop();
        int l = -curr.first; int v = curr.second;
        if (is[v]) continue;
        is[v] = 1;ans[v] = l;
        //if (v == 10) cout << v << " " << l << '\n';
        for (int to : graph[v])
            if (!is[to]) bfs.push({-(l + 1), to});
    }
    
    //rep(i, graph[8].size()) cout << graph[8][i] << (graph[8].size() - i - 1 ? ' ' : '\n');
    
    int final; cin >> final;
    int f_id = ((final % 10) - 1)*1000; final /= 10;
    f_id += ((final % 10) - 1)*100; final /= 10;
    f_id += ((final % 10) - 1)*10; final /= 10;
    f_id += (final % 10) - 1; final /= 10;
    
    vi f_ans;int next = f_id; int l = ans[f_id];
    while(--l>=0){
        int r_c = ids[next];
        f_ans.push_back(ids[next]);
        int i_4 = (r_c % 10) - 1; r_c /= 10;
        int i_3 = (r_c % 10) - 1; r_c /= 10;
        int i_2 = (r_c % 10) - 1; r_c /= 10;
        int i_1 = (r_c % 10) - 1; r_c /= 10;
        
        int id_1 = next - 1;
        int id_2 = next + 1000;
        int id_3 = i_2 + 10*i_3 + 100*i_4 + 1000*i_1;
        int id_4 = i_4 + 10*i_1 + 100*i_2 + 1000*i_3;
                    
        //cout << l << " " << ans[id_1] << " " << ans[id_2] << " " << ans[id_3] << '\n';
        if (i_1 >= 1) if (ans[id_1] == l) next = id_1;
        if (i_4 < 9) if (ans[id_2] == l) next = id_2;
        if (ans[id_3] == l) next = id_3;
        if (ans[id_4] == l) next = id_4;
    }
    if (s_id != f_id) f_ans.push_back(ids[next]);
    
    //cout << ans[f_id] << " " << ans[f_id + 1000] << " " << ans[f_id + 1000 + 1000] << '\n';
    rep(i, f_ans.size()) cout << f_ans[f_ans.size() - i - 1] << (f_ans.size() - i - 1 ? "\n" : "");
}

int main() {
    start();
    int q = 1;
    while(q--) solve();
}
