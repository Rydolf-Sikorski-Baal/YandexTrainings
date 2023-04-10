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

inline void solve(){
    load_3ll(n, k, p);
    vector< queue<int> > next(n + 1);
    vi t_to_ind(p, 0);
    set<int> current;
    
    ll ans = 0;
    rep(i, p){
        load_ll(x); t_to_ind[i] = x;
        next[x].push(i);
    }
    rep(i, n) next[i + 1].push(p + 1);
    
    rep(i, p){
        int x = t_to_ind[i];
        //cout << "x: " << x << " " << ans << '\n';
        if (current.count(-i)){
            //cout << x << '\n';
            current.erase(-i);
            next[x].pop();
            current.insert(-next[x].front());
            continue;
        }
        if (current.size() == k){
            int min_ind = -*current.begin();
            current.erase(current.begin());
            //cout << min_ind << " " << t_to_ind[min_ind] << '\n';
            //next[t_to_ind[min_ind]].pop();
        }
        
        next[x].pop();
        current.insert(-next[x].front());
        ans++;
    }
    cout << ans;
}

int main() {
    start();
    ll q = 1;
    while(q--) solve();
}
