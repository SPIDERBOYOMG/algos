const int maxn=2e5+123, LOG=19;

int timer, tin[maxn], tout[maxn], up[maxn][LOG];
vi g[maxn];

void dfs(int v, int pr=0){
	tin[v]=++timer;
	
	up[v][0]=pr;
	for(int i=1; i<LOG; i++){
		up[v][i]=up[up[v][i-1]][i-1];
	}
	
	for(auto &to:g[v]){
		if(to==pr) continue;
		dfs(to, v);
	}
	
	tout[v]=++timer;
}

bool check(int u, int v){
	return tin[u]<=tin[v] and tout[v]<=tout[u];
}

int lca(int u, int v){
	if(check(u, v)) return u;
	if(check(v, u)) return v;
	for(int i=LOG-1; i>=0; i--){
		if(up[u][i] and !check(up[u][i], v)){
			u=up[u][i];
		}
	}
	return up[u][0];
}
