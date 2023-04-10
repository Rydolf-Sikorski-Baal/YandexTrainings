#define _CRT_SECURE_NO_WARNINGS
//#pragma GCC optimize("03")

#include <iostream>
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
    load_ll(n); load_ll(k);
    multiset<ll> curr;
    queue<ll> wind;
    rep(i, k){
        ll x; cin >> x;
        curr.insert(x);
        wind.push(x);
    }
    if (curr.size()) cout << *curr.begin() << '\n';
    
    rep(i, n - k){
        ll x; cin >> x;
        //cout << wind.front() << " ";
        auto itr = curr.find(wind.front());
        if(itr != curr.end()) curr.erase(itr);
        wind.pop();
        wind.push(x);
        curr.insert(x);
        cout << *curr.begin() << '\n';
    }
}

int main() {
    start();
    ll q = 1;
    while(q--) solve();
}
