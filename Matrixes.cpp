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
