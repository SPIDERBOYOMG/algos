ll p[maxn];

ll mod2(ll a){
	while(a>=MOD){
		a=(a&MOD)+(a>>61);
		if(a>=MOD){
			a-=MOD;
		}
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
	void build(int &n, string &s){
		for(int i=1; i<=n; i++){
			h[i]=mod2(h[i-1]+mul(p[i-1], s[i]));
		}
	}
	
	ll get(int l, int r){
		return mul(h[r]-h[l-1]+MOD, p[maxn-r]);
	}
	
	Polyhash(int &n, string &s):h(n+1, 0){
		build(n, s);
	}
};

int main(){
    mt19937 rnd(RANDOM);
    ll base=257+rnd()%(MOD-257);
    
    p[0]=1;
    for(int i=1; i<maxn; i++){
    	p[i]=mul(p[i-1], base);
    }
    
    int ttt=1; //cin>>ttt;
    while(ttt--){
    	solve();
	}
}
