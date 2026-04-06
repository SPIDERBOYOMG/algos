struct Matrix {
	int M[2][2];
	Matrix(){
		M[0][0]=M[0][1]=M[1][0]=M[1][1]=0;
	}
	
	int &operator()(int i, int j) { return M[i][j]; }
	const int &operator()(int i, int j) const { return M[i][j]; }
	
	static Matrix identity(){
		Matrix res;
		res(0, 0)=res(1, 1)=1;
		return res;
	}
	
	Matrix operator*(const Matrix &other)const{
		Matrix res;
		res(0, 0)=(1ll*(*this)(0, 0)*other(0, 0)+1ll*(*this)(0, 1)*other(1, 0))%MOD;
		res(0, 1)=(1ll*(*this)(0, 0)*other(0, 1)+1ll*(*this)(0, 1)*other(1, 1))%MOD;
		res(1, 0)=(1ll*(*this)(1, 0)*other(0, 0)+1ll*(*this)(1, 1)*other(1, 0))%MOD;
		res(1, 1)=(1ll*(*this)(1, 0)*other(0, 1)+1ll*(*this)(1, 1)*other(1, 1))%MOD;
		return res;
	}
	
	Matrix &operator*=(const Matrix &other){
		*this=*this*other;
		return *this;
	}
};

struct Vec{
	int vec[2];
	
	Vec(){
		vec[0]=vec[1]=0;
	}
	
	int &operator()(int i){ return vec[i]; }
	const int &operator()(int i)const{ return vec[i]; }
	
	Vec operator+(const Vec &other)const{
		Vec res;
		res(0)=((*this)(0)+other(0))%MOD;
		res(1)=((*this)(1)+other(1))%MOD;
		return res;
	}
	
	Vec &operator+=(const Vec &other){
		*this = *this + other;
		return *this;
	}
};

Vec mul(Vec B, Matrix A){
	Vec res;
	res(0)=(1ll*B(0)*A(0, 0)+1ll*B(1)*A(1, 0))%MOD;
	res(1)=(1ll*B(0)*A(0, 1)+1ll*B(1)*A(1, 1))%MOD;
	return res;
}
