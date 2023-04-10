#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("03")

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <stack>
#include <map>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_1(i, n) for (int i = 1; i < n; ++i)
#define rep_s(i, s, n) for (int i = s; i < n; ++i)
#define load_ll(a) ll a; cin >> a;
#define load_str(a) string a; cin >> a;
#define max_it(a, b) a = max(a, b);
#define min_it(a, b) a = min(a, b);

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef stack<ll> sl;

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

inline ll priority(char ch){
    if (ch == '+') return 1;
    if (ch == '-') return 1;
    if (ch == '*') return 2;
    if (ch == '/') return 2;
    if (ch == '(') return -1;
    if (ch == ')') return 12345;
}

inline string process_operation(stack<char> & stack, ll oper, char op){
    string res = "";
    
    while (stack.size() && (priority(stack.top()) >= oper)){
        res += stack.top();
        stack.pop();
    } 
    
    stack.push(op);
    return res;
}

inline string process_cl_br(stack<char> & stack){
    string res = "";
    if (!stack.size()) return res;
    
    while(stack.size() && (stack.top() != '(')){
        res += stack.top();
        stack.pop();
    }
    if (!stack.size()) return "a";
    if (stack.size()) stack.pop();
    return res;
}

inline void solve(){
    load_ll(n);
    vector<long double> a(n);
    vector<long double> sorted(n);
    stack<long double> rep;
    rep(i, n) {cin >> a[i]; sorted[i] = a[i];}
    
    sort(sorted.begin(), sorted.end());
    
    ll curr_pos = 0;
    ll curr_min = 0;
    while(curr_pos < n){
        if (abs(a[curr_pos] - sorted[curr_min]) < 0.0005){curr_pos++;curr_min++;continue;}
        if (rep.size())
            if (abs(rep.top() - sorted[curr_min]) < 0.0005){rep.pop();curr_min++;continue;}
        rep.push(a[curr_pos]);
        curr_pos++;
    }
    
    //cout << rep.size() << '\n';
    while(rep.size()){
        if (abs(rep.top() - sorted[curr_min]) < 0.0005){rep.pop();curr_min++;continue;}
        //cout << rep.top() << " " << sorted[curr_min] << " " << 5 << '\n';
        cout << 0 << '\n';
        return;
    }
    
    if (curr_min < n){cout << 0; return;}
    cout << 1 << '\n';
    return;
}

int main() {
    start();
    load_ll(q);
    while(q--) solve();
}
