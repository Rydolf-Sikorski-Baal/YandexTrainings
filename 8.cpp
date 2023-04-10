#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <map>
using namespace std;


#define rep(i, n) for (int i = 0; i < n; ++i)
#define load_ll(a) ll a; cin >> a;
#define max_it(a, b) a = max(a, b);
#define min_it(a, b) a = min(a, b);

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

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
  vl x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  
  ll x_min = 2e9, x_max = 0;
  ll y_min = 2e9, y_max = 0;
  rep(i, n){
      min_it(x_min, x[i]); min_it(y_min, y[i]);
      max_it(x_max, x[i]); max_it(y_max, y[i]);
  }
  cout << x_min << " " << y_min << " " << x_max << " " << y_max << '\n';
}

int main() {
    int q = 1;
    while(q--) solve();
}
