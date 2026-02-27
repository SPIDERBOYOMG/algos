ll mod2(ll a){
	while(a>MOD){
		a=(a&MOD)+(a>>61);
		if(a>=MOD){
			a-=MOD;
		}
	}
	if(a==MOD){
		a-=MOD;
	}
	return a;
}

ll mul(ll a, ll b){
	a=mod2(a);
	__int128 res=__int128(a)*b;
	ll x=ll(res&MOD)+ll(res>>61);
	if(x>=MOD){
		x-=MOD;
	}
	return x;
}

struct Polyhash{
	vll h;
	string s;
	int n;
	void build(){
		for(int i=1; i<=n; i++){
			h[i]=mod2(h[i-1]+mul(p[i-1], s[i]));
		}
	}
	
	ll get(int l, int r, bool type){
		if(type==0){
			return mul(h[r]-h[l-1]+MOD, p[maxn-r]);
		}else{
			l=n-l+1;
			r=n-r+1;
			if(l>r){
				swap(l, r);
			}
			return mul(h[r]-h[l-1]+MOD, p[maxn-r]);
		}
	}
	
	Polyhash(string str, int num):h(num+1, 0){
		s=str;
		n=num;
		build();
	}
};
