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
    int n; cin >> n;
    stack< pair<string, ll> > p; map<string, ll> rev;
    
    while(n--){
        string type; cin >> type;
        if (type == "add"){
            ll numb; cin >> numb;
            string name; cin >> name;
            p.push({name, numb});
            rev[name] += numb;
        }
        if (type == "delete"){
            ll x; cin >> x;
            while(x){
                pair<string, ll> curr = p.top(); p.pop();
                string name = curr.first; ll c_n = curr.second;
                rev[name] -= c_n;
                x -= c_n;
                if (x < 0) {p.push({name, -x});rev[name] += -x;x = 0;}
            }
        }
        if (type == "get"){
            string name; cin >> name;
            cout << rev[name] << '\n';
        }
    }
}

int main() {
    start();
    int q = 1;// cin >> q;
    while(q--) solve();
}
