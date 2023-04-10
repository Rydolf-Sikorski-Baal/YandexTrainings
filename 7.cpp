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
  string a_ch, a_m, a_s; 
  getline(cin, a_ch, ':');getline(cin, a_m, ':');getline(cin, a_s, '\n');
  int a = 60*60*stoi(a_ch) + 60*stoi(a_m) + stoi(a_s);
  
  string b_ch, b_m, b_s; 
  getline(cin, b_ch, ':');getline(cin, b_m, ':');getline(cin, b_s, '\n');
  int b = 60*60*stoi(b_ch) + 60*stoi(b_m) + stoi(b_s);
  
  string c_ch, c_m, c_s; 
  getline(cin, c_ch, ':');getline(cin, c_m, ':');getline(cin, c_s, '\n');
  int c = 60*60*stoi(c_ch) + 60*stoi(c_m) + stoi(c_s);
  
  if (c < a) c += 24*3600;
  int d = c - a;
  d = (d/2) + (d%2);
  int res = b + d;
  int h = (res/3600)%24;
  res -= (res/3600) * 3600;
  int m = res/60;
  res -= m * 60;
  cout << (h < 10 ? "0" : "") << h << ":" << (m < 10 ? "0" : "") << m << ":" << (res < 10 ? "0" : "") << res << '\n';
}

int main() {
    int q = 1;
    while(q--) solve();
}
