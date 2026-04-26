#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC target("avx,avx2,fma")
#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using ld = long double;
using ull = unsigned long long;

template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string& s) {
  return '"' + s + '"';
}
string to_string(const char* s) {
  return to_string((string) s);
}
string to_string(bool b) {
  return (b ? "true" : "false");
}
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) res += ", ";
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out(string) { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(string format, Head H, Tail... T) {
    if (format.find(',') == string::npos) {
        cout << format << " :: " << to_string(H) << endl;
    } else {
        cout << string(format.begin(), format.begin() + format.find(',')) << " :: " << to_string(H) << endl;
        format = string(format.begin() + format.find(',') + 2, format.end());
    }
    debug_out(format, T...);
}

#define LOCAL
#ifdef LOCAL
#define debug(...) cout << "[" << #__VA_ARGS__ << "]\n", debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 123
#endif

const ll inf=1e14+5, mod=998244353, MOD=1e9+7;
const ll INF=1e18;
const int maxn=2e5+123;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
struct PairHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(const pair<ll, ll>& p) const {
        uint64_t h1 = splitmix64((uint64_t)p.first + RANDOM);
        uint64_t h2 = splitmix64((uint64_t)p.second + RANDOM);
        return h1 ^ (h2 << 1);
    }
};

void solve(){
	
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int ttt=1; cin>>ttt;
    while(ttt--){
    	solve();
    	cout<<"\n";
//    	cout<<string(15, '-')<<"\n";
	}
}
