#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <map>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_1(i, n) for (int i = 1; i < n; ++i)
#define rep_s(i, s, n) for (int i = s; i < n; ++i)
#define load_ll(a) ll a; cin >> a;
#define max_it(a, b) a = max(a, b);
#define min_it(a, b) a = min(a, b);

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

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

inline bool inter(ll l1, ll r1, ll l2, ll r2){
    if (min(r1, r2) - max(l1, l2) >= 0) return true;
    return false;
}

inline void solve(){
  load_ll(m); load_ll(n);
  vl left(n), right(n);
  rep(i, n) cin >> left[i] >> right[i];
  
  vl ans(n, 1);
  rep(i, n)
    rep(j, i){
        if (inter(left[i], right[i], left[j], right[j])) ans[j]--;
    }

  ll ans_f = 0;
  rep(i, n) ans_f += (ans[i] > 0 ? 1 : 0);
  cout << ans_f << '\n';
}

int main() {
    start();
    int q = 1;
    while(q--) solve();
}
