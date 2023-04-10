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

inline void solve(){
  load_ll(n); load_ll(k);
  load_ll(f); load_ll(l);
  
  ll f_pl = 2*(f - 1) + l;
  ll b_res = 2e9, a_res = 2e9; 
  if (f_pl + k <= n) a_res = f_pl + k;
  if (f_pl - k > 0)  b_res = f_pl - k;
  //cout << f_pl << " " << a_res << " " << b_res << '\n';
  //cout << (a_res/2) + (a_res%2) << '\n';
  //cout << (b_res/2) + (b_res%2) << '\n';
  
  if (b_res == a_res){cout << "-1"; return;}
  if (a_res != 2e9)
  if (abs((a_res/2) + (a_res%2) - f) <= abs(f - (b_res/2) - (b_res%2))){
      cout << (a_res/2) + (a_res%2) << " " << 2 - (a_res%2) << '\n';
      return;
  }
  cout << (b_res/2) + (b_res%2) << " " << 2 - (b_res%2) << '\n';
}

int main() {
    start();
    int q = 1;
    while(q--) solve();
}
