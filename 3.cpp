#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("03")
#pragma GCC target("sse2")


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

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

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
  set<ll> numb;
  vl a;
  rep(i, n){
      ll x; cin >> x;
      if (!numb.count(x)){
          numb.insert(x);
          a.push_back(x);
      }
  }
  sort(a.begin(), a.end());
  
  load_ll(k);
  rep(i, k){ 
      load_ll(q);
      if (!(n - 1)){
          if (a[0] < q) {cout << 1 << '\n'; continue;}
          cout << 0 << '\n';
          continue;
      }
      
      ll ans = (bin_p(a, q));
      cout << (a[ans] < q ? ans + 1 : 0) << '\n';
  }
}

int main() {
	start();
    int q = 1;
    while(q--) solve();
}
