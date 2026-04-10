int timer, tin[maxn], tout[maxn], a[maxn];
vi g[maxn];
ll t[maxn*4];

void dfs(int v, int pr=0){
	tin[v]=++timer;
	
	for(auto &to:g[v]){
		if(to==pr) continue;
		dfs(to, v);
	}
	
	tout[v]=timer;
}

void update(int v, int tl, int tr, int pos, int val){
	if(tl==tr){
		t[v]=val;
	}else{
		int mid=(tl+tr)>>1;
		if(pos<=mid){
			update(v+v, tl, mid, pos, val);
		}else{
			update(v+v+1, mid+1, tr, pos, val);
		}
		t[v]=t[v+v]+t[v+v+1];
	}
}

ll get(int v, int tl, int tr, int l, int r){
	if(l>tr or r<tl){
		return 0;
	}else if(l<=tl and tr<=r){
		return t[v];
	}else{
		int mid=(tl+tr)>>1;
		ll x=get(v+v, tl, mid, l, r);
		ll y=get(v+v+1, mid+1, tr, l, r);
		return x+y;
	}
}

void solve(){
	int n, q; cin>>n>>q;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<n; i++){
		int u, v; cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	dfs(1);
	
	for(int i=1; i<=n; i++){
		update(1, 1, n, tin[i], a[i]);
	}
	
	while(q--){
		int type; cin>>type;
		if(type==1){
			int u, val; cin>>u>>val;
			update(1, 1, n, tin[u], val);
		}else{
			int u; cin>>u;
			cout<<get(1, 1, n, tin[u], tout[u])<<"\n";
		}
	}
}
