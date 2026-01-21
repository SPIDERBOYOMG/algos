struct DSU{
	vi siz, par;
	DSU(int n):siz(n+1, 1), par(n+1), mn(n+1){
		for(int i=1; i<=n; i++){
			par[i]=i;
		}
	}
	
	int get(int v){
		if(v==par[v]){
			return v;
		}else{
			return par[v]=get(par[v]);
		}
	}
	
	bool check(int u, int v){
		u=get(u), v=get(v);
		return u==v;
	}
	
	void connect(int u, int v){
		u=get(u), v=get(v);
		if(u==v){
			return;
		}
		
		if(siz[u]<siz[v]){
			swap(u, v);
		}
		
		siz[u]+=siz[v];
		par[v]=u;
	}
};