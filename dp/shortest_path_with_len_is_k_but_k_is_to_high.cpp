#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC target("avx,avx2,fma")
#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
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

const ull inf=1e14+5, mod=998244353, MOD=1e9+7, INF=2e18;

template <typename T>
struct Matrix {
  int n, m;
  vector<T> a;

  Matrix(int n = 0, int m = 0) : n(n), m(m), a(n * m, T(0)) {}

  Matrix(initializer_list<initializer_list<T>> init) {
    n = (int)init.size();
    m = n ? (int)init.begin()->size() : 0;
    a.assign(n * m, T(0));

    int i = 0;
    for (auto row : init) {
      int j = 0;
      for (auto x : row) {
        (*this)(i, j) = x;
        j++;
      }
      i++;
    }
  }

  T& operator()(int i, int j) {
    return a[i * m + j];
  }

  const T& operator()(int i, int j) const {
    return a[i * m + j];
  }

  static Matrix identity(int n) {
    Matrix res(n, n);
    for (int i = 0; i < n; i++) res(i, i) = T(1);
    return res;
  }

  Matrix operator*(const Matrix& other) const {
    assert(m == other.n);

    Matrix res(n, other.m);
    for(int i=0; i<m; i++){
    	for(int j=0; j<m; j++){
    		res(i, j)=INF;
    	}
    }

    for (int i = 0; i < n; i++) {
      for (int k = 0; k < m; k++) {
        T cur = (*this)(i, k);
        for (int j = 0; j < other.m; j++) {
        	res(i, j)=min(res(i, j), cur+other(k, j));
        }
      }
    }

    return res;
  }

  Matrix& operator*=(const Matrix& other) {
    *this = *this * other;
    return *this;
  }
};

template <typename T>
Matrix<T> binpow(Matrix<T> a, long long k) {
    assert(a.n == a.m);
    k--;
    Matrix<T> res = a;
    while (k > 0) {
        if (k & 1) res *= a;
        a *= a;
        k >>= 1;
    }
    return res;
}

template<typename T>
void pprint(const Matrix<T> &a) {
    for (int i = 0; i < a.n; i++) {
        for (int j = 0; j < a.m; j++) {
            cout << a(i, j) << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

//#define LOCAL
#ifdef LOCAL
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 123
#endif

const int maxn=2e5+123;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};

void solve(){
	int n, m, k; cin>>n>>m>>k;
	vector<vll> g(n+1, vll(n+1, INF));
	for(int i=1; i<=m; i++){
		ll u, v, len; cin>>u>>v>>len;
		g[u][v]=min(g[u][v], len);
	}

	Matrix<ll> A(n, n);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			A(i-1, j-1)=g[i][j];
		}
	}
	A=binpow(A, k);
	ll ans=INF;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			ans=min(ans, A(i, j));
		}
	}
	if(ans<=ll(1e18)){
		cout<<ll(ans);
	}else{
		cout<<"IMPOSSIBLE";
	}
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int ttt=1; //cin>>ttt;
    while(ttt--){
    	solve();
    	cout<<"\n";
//    	cout<<string(15, '-')<<"\n";
	}
}
