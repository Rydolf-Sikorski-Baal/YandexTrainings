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
    if (ch == '!') return 3;
    if (ch == '&') return 2;
    if (ch == '|') return 1;
    if (ch == '^') return 1;
    if (ch == '(') return -1;
    if (ch == ')') return 12345;
}

inline string process_operation(stack<char> & stack, ll oper, char op){
    string res = "";
    if (stack.size())
    //cout << "processing: " << op << " " << priority(op) << " " << stack.top() << '\n';
    
    while (stack.size() && (priority(stack.top()) >= oper)){
        res += stack.top();
        res += " ";
        stack.pop();
    } 
    //cout << res << '\n';
    
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

set<char> numb;

inline ll get_res(string & s){
  stack<ll> stack;
  string number = "";
  for (char ch : s){
      if (number.size() && !numb.count(ch)){
          stack.push(stoll(number));
          number = "";
      }
      
      if (numb.count(ch)) {number += ch; continue;}
      if (ch == ' ') continue;
      if (ch == '&') {
          if (stack.size() < 2) {cout << "WRONG";return -1;}
          ll f = stack.top(); stack.pop();
          ll s = stack.top(); stack.pop();
          stack.push(f & s);
          continue;
      }
      if (ch == '|') {
          if (stack.size() < 2) {cout << "WRONG";return -1;}
          ll f = stack.top(); stack.pop();
          ll s = stack.top(); stack.pop();
          stack.push(s | f);
          continue;
      }
      if (ch == '^') {
          if (stack.size() < 2) {cout << "WRONG";return -1;}
          ll f = stack.top(); stack.pop();
          ll s = stack.top(); stack.pop();
          stack.push(f ^ s);
          continue;
      }
      if (ch == '!') {
          if (stack.size() < 1) {cout << "WRONG";return -1;}
          ll f = stack.top(); stack.pop();
          stack.push(1 - f);
          continue;
      }
      cout<< "WRONG";
      return -1;
  }
  if (number.size()) stack.push(stoll(number));
  if (stack.size() != 1){cout << "WRONG"; return -1;}
  
  cout << stack.top();
  return stack.top();
}

inline void solve(){
    numb.insert('0');numb.insert('1');
  stack<char> stack;
  string ans = "";
  char ch;
  string number = "";
  string inp; getline(cin, inp);
  for (char ch : inp){
      if (numb.count(ch)) {ans += ch; ans+=" ";}
      if (ch == ' ') continue;
      if (ch == '!') ans += process_operation(stack, 3, '!');
      if (ch == '&') ans += process_operation(stack, 2, '&');
      if (ch == '|') ans += process_operation(stack, 1, '|');
      if (ch == '^') ans += process_operation(stack, 1, '^');
      if (ch == '(') stack.push('(');
      if (ch == ')') ans += process_cl_br(stack);
      //cout << ans << '\n';
  }
  while(stack.size()) {ans += stack.top(); stack.pop();}
  
  //cout << '\n' << ans <<'\n';
  get_res(ans);
}

int main() {
    start();
    int q = 1;
    while(q--) solve();
}
