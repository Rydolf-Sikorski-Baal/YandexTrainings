#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("03")

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
    load_ll(k); load_ll(n);
    priority_queue<pll> arrival, exits;
    set<ll> places;
    rep(i, k) places.insert(i + 1);
    
    rep(i, n){
        ll a, e; cin >> a >> e;
        arrival.push({-a, i + 1});
        exits.push({-e, i + 1});
    }
    
    vl ans(n, 0);
    
    while(arrival.size()){
        ll curr_time = -arrival.top().first;
        ll curr_ind = arrival.top().second;
        
        while(exits.size() && (-exits.top().first < curr_time)){
            //cout << exits.top().first << '\n';
            ll ex_time = -exits.top().first;
            ll ex_ind = exits.top().second;
            exits.pop();
            places.insert(ans[ex_ind - 1]);
        }
        //cout << curr_time << " " << curr_ind << " " << places.size() << '\n';
        if (!places.size()){cout << 0 << " " << curr_ind; return;}
        ans[curr_ind - 1] = *places.begin();
        places.erase(places.begin());
        while(exits.size() && (-exits.top().first <= curr_time)){
            //cout << exits.top().first << '\n';
            ll ex_time = -exits.top().first;
            ll ex_ind = exits.top().second;
            exits.pop();
            places.insert(ans[ex_ind - 1]);
        }
        
        arrival.pop();
    }
    
    rep(i, n) cout << (i ? " " : "") << ans[i];
    return;
}

int main() {
    start();
    ll q = 1;
    while(q--) solve();
}
