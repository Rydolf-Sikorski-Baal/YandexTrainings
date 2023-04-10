#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("03")
#pragma GCC target("sse")

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
    ll start = 9*60*60;
    ll br_start = 13*60*60;
    ll br_end = 14*60*60;
    ll end = 18*60*60;
    
    load_ll(n);
    vl prog_start(n), prog_eff(n);
    rep(i, n){
        string h, m, s; getline(cin, h, ':');getline(cin, m, ':');getline(cin, s, ' ');
        prog_start[i] = 60*60*stol(h) + 60*stol(m) + stol(s);
        string eff; getline(cin, eff, '\n');
        prog_eff[i] = stol(eff);
    }
    
    vl dp1(br_start - start + 1, 0);
    ll k = 0;
    rep(i, dp1.size()){
        while((k != n - 1) && (start + i >= prog_start[k + 1])) k++;
        if (i + 1 < dp1.size())          max_it(dp1[i + 1], dp1[i]);
        if (i + prog_eff[k] < dp1.size())max_it(dp1[i + prog_eff[k]], dp1[i] + 1);
    }
    
    ll ans = 0;
    rep(i, dp1.size()) max_it(ans, dp1[i]);
    
    vl dp2(end - br_end + 1, ans);
    rep(i, dp2.size()){
        while((k != n - 1) && (br_end + i >= prog_start[k + 1])) k++;
        if (i + 1 < dp2.size())          max_it(dp2[i + 1], dp2[i]);
        if (i + prog_eff[k] < dp2.size())max_it(dp2[i + prog_eff[k]], dp2[i] + 1);
    }
    
    rep(i, dp2.size()) max_it(ans, dp2[i]);
    cout << ans;
}

int main() {
    start();
    ll q = 1;
    while(q--) solve();
}
