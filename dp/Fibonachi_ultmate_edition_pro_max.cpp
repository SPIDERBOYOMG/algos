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

const ll inf=1e14+5, mod=998244353, MOD=1e9+7;
const ll INF=1e18;
const int maxn=2e5+123;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};

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

    for (int i = 0; i < n; i++) {
      for (int k = 0; k < m; k++) {
        T cur = (*this)(i, k);
        if (cur == T(0)) continue;
        for (int j = 0; j < other.m; j++) {
          res(i, j) += cur * other(k, j);
          res(i, j)%=MOD;
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
  Matrix<T> res = Matrix<T>::identity(a.n);

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

void solve(){
	ll n, k; cin>>n>>k;
	vll a(n), c(n);
	for(int i=1; i<=n; i++){
		cin>>a[i-1];
	}
	for(int i=1; i<=n; i++){
		cin>>c[i-1];
	}
	ll p, q, r; cin>>p>>q>>r;
	if(k<n){
		cout<<a[k];
		return;
	}
	k=k-n+1;
	
	Matrix<ll> DP(1, n+3);
	reverse(all(a));
	for(int i=0; i<n; i++){
		DP(0, i)=a[i];
	}
	DP(0, n)=1, DP(0, n+1)=n, DP(0, n+2)=n*n;
	
	Matrix<ll> T(n+3, n+3);
	for(int i=0; i<n; i++){
		T(i, 0)=c[i];
	}
	T(n, 0)=p, T(n+1, 0)=q, T(n+2, 0)=r;
	
	for(int i=0; i<n-1; i++){
		T(i, i+1)=1;
	}
	
	T(n, n)=T(n, n+1)=T(n, n+2)=1;
	T(n+1, n+1)=1, T(n+1, n+2)=2;
	T(n+2, n+2)=1;

	
	T=binpow(T, k);
	DP*=T;
	cout<<DP(0, 0);
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
