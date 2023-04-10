#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <map>
using namespace std;


#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_1(i, n) for (int i = 1; i < n; ++i)
#define load_ll(a) ll a; cin >> a;
#define max_it(a, b) a = max(a, b);
#define min_it(a, b) a = min(a, b);

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

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
  load_ll(n);load_ll(m);
  load_ll(k);
  
  vvl a(n + 1, vl(m + 1));
  rep(i, n) rep(j, m) cin >> a[i + 1][j + 1];
  
  vvl pref(n + 1, vl(m + 1, 0));
  rep_1(i, n + 1) rep_1(j, m + 1)
    pref[i][j] = a[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    
  rep(i, k){
      load_ll(x1); load_ll(y1);
      load_ll(x2); load_ll(y2);
      
      x1--;y1--;
      ll res = pref[x2][y2] - pref[x2][y1] - pref[x1][y2] + pref[x1][y1];
      cout << res << '\n';
  }
}

int main() {
    int q = 1;
    while(q--) solve();
}
