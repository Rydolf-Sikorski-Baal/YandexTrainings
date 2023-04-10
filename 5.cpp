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
  load_ll(n);
  vl a(n); rep(i,n) cin >> a[i];
  
  ll ans = 0;
  while(true){
    ll res = 0;
    ll m = 2e9;
    rep(i, n) if (a[i]) min_it(m, a[i]);
    //cout << m << '\n';
    if (!(m - 2e9)) break;
    
    rep(i, n){
        //cout << "ans: " << ans << " ";
        if (!a[i]) {ans += m*max(res - 1, (ll)0); res = 0; continue;}
        a[i] -= m;
        res++;
    }
    ans += m*max(res - 1, (ll)0);
    //cout << "ans: " << ans << " res: " << res << '\n';
    //rep(i, n) cout << a[i] << " ";
    //cout << '\n';
  }
  
  cout << ans << '\n';
}

int main() {
    start();
    int q = 1;
    while(q--) solve();
}
