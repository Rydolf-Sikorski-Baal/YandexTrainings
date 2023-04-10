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
    int n, m; cin >> n >> m;
    graph.resize((n + 2)*(m + 2)); is.assign((n + 2)*(m + 2), 0);ans.assign((n + 2)*(m + 2), 1e9);
    
    vvi sp(n + 2, vi(m + 2, 1));
    rep_1(i, n + 1)
        rep_1(j, m + 1)
            cin >> sp[i][j];
    
    rep_1(i, n + 1)
        rep_1(j, m + 1){
            if (sp[i][j]) continue;
            int curr = i*(m + 2) + j;
            //cout << curr << " ";
            
            int n_i = i; int n_j = j;
            while(n_i >= 1){
                //cout << curr << ": " << sp[n_i]
                if (sp[n_i - 1][n_j] == 2){graph[curr].push_back((n_i - 1)*(m + 2) + n_j);break;}
                if (sp[n_i - 1][n_j]){graph[curr].push_back(n_i*(m + 2) + n_j);break;}
                n_i--;
            }
            n_i = i; n_j = j;
            while(n_i <= n){
                if (sp[n_i + 1][n_j] == 2){graph[curr].push_back((n_i + 1)*(m + 2) + n_j);break;}
                if (sp[n_i + 1][n_j]){graph[curr].push_back(n_i*(m + 2) + n_j);break;}
                n_i++;
            }
            n_i = i; n_j = j;
            while(n_j >= 1){
                if (sp[n_i][n_j - 1] == 2){graph[curr].push_back(n_i*(m + 2) + (n_j - 1));break;}
                if (sp[n_i][n_j - 1]){graph[curr].push_back(n_i*(m + 2) + n_j);break;}
                n_j--;
            }
            n_i = i; n_j = j;
            while(n_j <= m){
                if (sp[n_i][n_j + 1] == 2){graph[curr].push_back(n_i*(m + 2) + (n_j + 1));break;}
                if (sp[n_i][n_j + 1]){graph[curr].push_back(n_i*(m + 2) + n_j);break;}
                n_j++;
            }
            //cout << graph[curr].size() << '\n';
        }
    
    pq_pii bfs; bfs.push({0, m + 3});
    while(bfs.size()){
        pii curr = bfs.top();bfs.pop();
        int l = -curr.first; int v = curr.second;
        if (is[v]) continue;
        is[v] = 1;ans[v] = l;
        for (int to : graph[v])
            if (!is[to]) bfs.push({-(l + 1), to});
    }
    //rep(i, (n + 2)*(m + 2)) cout << graph[i].size() << '\n';
    //rep(i, graph[m + 3].size()) cout << graph[m + 3][i] << (graph[m + 3].size() - i - 1 ? ' ' : '\n');
    //rep(i, graph[29].size()) cout << graph[29][i] << (graph[29].size() - i - 1 ? ' ' : '\n');
    //rep(i, graph[30].size()) cout << graph[30][i] << (graph[30].size() - i - 1 ? ' ' : '\n');
    int f_ans = 1e9;
    //cout << ans[30] << '\n';
    rep(i, n + 2) rep(j, m + 2) if (sp[i][j] == 2) min_it(f_ans, ans[i*(m + 2) + j]);
    cout << f_ans;
}

int main() {
    start();
    int q = 1;
    while(q--) solve();
}
