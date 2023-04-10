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
    graph.resize(64); is.assign(64, 0);ans.assign(64, -1);
    
    rep(i, 8)
        rep(j, 8){
            int curr_id = 8*i + j;
            int id_1 = 8*(i - 2) + (j - 1);
            int id_2 = 8*(i - 2) + (j + 1);
            int id_3 = 8*(i - 1) + (j - 2);
            int id_4 = 8*(i + 1) + (j - 2);
            int id_5 = 8*(i + 2) + (j - 1);
            int id_6 = 8*(i + 2) + (j + 1);
            int id_7 = 8*(i - 1) + (j + 2);
            int id_8 = 8*(i + 1) + (j + 2);
            
            if ((i >= 2) && (j >= 1)) graph[curr_id].push_back(id_1);
            if ((i >= 2) && (j <= 6)) graph[curr_id].push_back(id_2);
            if ((i >= 1) && (j >= 2)) graph[curr_id].push_back(id_3);
            if ((i <= 6) && (j >= 2)) graph[curr_id].push_back(id_4);
            if ((i <= 5) && (j >= 1)) graph[curr_id].push_back(id_5);
            if ((i <= 5) && (j <= 6)) graph[curr_id].push_back(id_6);
            if ((i >= 1) && (j <= 5)) graph[curr_id].push_back(id_7);
            if ((i <= 6) && (j <= 5)) graph[curr_id].push_back(id_8);
        }
    
    char x_ch; cin >> x_ch;int x = x_ch - 'a';
    cin >> x_ch;int y = x_ch - '1';
    int f_id = 8*y + x;
    pq_pii bfs; bfs.push({0, f_id});
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
    
    cin >> x_ch;x = x_ch - 'a';
    cin >> x_ch;y = x_ch - '1';
    int s_id = 8*y + x;
    //cout << f_id << " " << s_id << '\n';
    cout << (ans[s_id] % 2 ? -1 : ans[s_id] / 2);
}

int main() {
    start();
    int q = 1;
    while(q--) solve();
}
