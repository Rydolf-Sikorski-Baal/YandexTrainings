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
    load_ll(n);
    vl a(n); rep(i, n) cin >> a[i];
    
    vl len(n, 0), prev(n, -1);
    len[0] = 1;
    ll ans_ind = 0;
    rep(curr, n)
        rep(pr, curr){
            if (a[pr] >= a[curr]) continue;
            //if (a[curr] == 6) cout << a[pr] << " " << len[curr] << '\n';
            if (len[pr] + 1 >= len[curr]){len[curr] = len[pr] + 1; prev[curr] = pr;}
            if (len[curr] >= len[ans_ind]) ans_ind = curr;
        }
        
    vl ans(1, a[ans_ind]);
    while(prev[ans_ind] != -1){ans.push_back(a[prev[ans_ind]]); ans_ind = prev[ans_ind];}
    //cout << ans.size() << '\n';
    rep(i, ans.size()) cout << (i ? " " : "") << ans[ans.size() - i - 1];
}

int main() {
    start();
    ll q = 1;
    while(q--) solve();
}
