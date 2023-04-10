#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("03")

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

inline void balance_deques(deque<ll> & big, 
                            deque<ll> & small){
                                while(small.size() > big.size()){
                                    big.push_back(small.front());
                                    small.pop_front();
                                }
                                
                                if (big.size() == small.size()) return;
                                if (big.size() - small.size() == 1) return;
                                
                                while(big.size() - small.size() > 1){
                                    small.push_front(big.back());
                                    big.pop_back();
                                }
                            }

inline void insert_normal(deque<ll> & big, 
                            deque<ll> & small){
    load_ll(ind);
    small.push_back(ind);
    
    balance_deques(big, small);
}
inline void insert_privileged(deque<ll> & big, 
                            deque<ll> & small){
    load_ll(ind);
    big.push_back(ind);
    
    balance_deques(big, small);
}

inline void solve(){
    load_ll(n);
    priority_queue<ll> q;
    long double ans = 0.0;
    rep(i, n){load_ll(x); q.push(-x);}
    
    while(q.size() - 1){
        ll f = -q.top(); q.pop();
        ll s = -q.top(); q.pop();
        ll r = f + s;
        q.push(-r);
        
        ans += ((long double)r)/20;
    }
    cout << fixed << setprecision(2) << ans;
}

int main() {
    start();
    ll q = 1;
    
    while(q--) solve();
}
