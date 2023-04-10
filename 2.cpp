#pragma GCC optimize("03")

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
  load_ll(k);
  string s; cin >> s;
  
  vvl pos(26);
  rep(i, s.size()){
      ll curr = (int)s[i] - (int)'a';
      pos[curr].push_back(i);
  }
  
  vl max_r(26, 0);
  rep(i, 26){
      ll left = 0;
      rep(right, pos[i].size()){
          ll inb = right - left - 1;
          if (pos[i][right] - pos[i][left] - inb - 1 > k) 
            while((left!=right)&&(pos[i][right] - pos[i][left] - inb > k)) left++;
          //if (i == 0) cout << pos[i][left] << " " << pos[i][right] << '\n';
          inb = right - left - 1;
          ll ost = k - (pos[i][right] - pos[i][left] - 1) + inb;
          if (left!=right)
            max_it(max_r[i], pos[i][right] - pos[i][left] + 1 + ost);
      }
  }
  
  //rep(i , 26) cout << max_r[i] << " ";
  //cout << '\n';
  
  ll ans = k + 1;
  rep(i, 26) max_it(ans, (max_r[i] ? max_r[i] : 0));
  //cout << s.size() << '\n';
  cout << min((ll)s.size(), ans) << '\n';
}

int main() {
    start();
    int q = 1;
    while(q--) solve();
}
