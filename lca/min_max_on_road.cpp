struct node{
	int to;
	int mn;
	int mx;
};

int timer, tin[maxn], tout[maxn];
vector up(maxn, vector<node>(LOG, {0, MOD, -MOD}));
vector<pii> g[maxn];

void dfs(int v, int pr=0, int len=0){
	tin[v]=++timer;
	
	if(pr!=0) up[v][0]={pr, len, len};
	for(int p=1; p<LOG; p++){
	    up[v][p] = {
	        up[up[v][p-1].to][p-1].to,
	        min(up[v][p-1].mn, up[up[v][p-1].to][p-1].mn),
	        max(up[v][p-1].mx, up[up[v][p-1].to][p-1].mx)
	    };
	}
	
	for(auto &[to, len]:g[v]){
		if(to==pr) continue;
		dfs(to, v, len);
	}
	
	tout[v]=++timer;
}

bool check(int u, int v){
	return tin[u]<=tin[v] and tout[v]<=tout[u];
}

node lca(int u, int v){
	node ans={0, MOD, -MOD};
	
	for(int p=LOG-1; p>=0; p--){
		if(up[u][p].to and !check(up[u][p].to, v)){
			ans.mn=min(ans.mn, up[u][p].mn);
			ans.mx=max(ans.mx, up[u][p].mx);
			u=up[u][p].to;
		}
	}
	for(int p=LOG-1; p>=0; p--){
		if(up[v][p].to and !check(up[v][p].to, u)){
			ans.mn=min(ans.mn, up[v][p].mn);
			ans.mx=max(ans.mx, up[v][p].mx);
			v=up[v][p].to;
		}
	}
	
	if(check(u, v)){
		ans={up[v][0].to, min(ans.mn, up[v][0].mn), max(ans.mx, up[v][0].mx)};
	}else if(check(v, u)){
		ans={up[u][0].to, min(ans.mn, up[u][0].mn), max(ans.mx, up[u][0].mx)};
	}else{
		ans={up[v][0].to, min(ans.mn, up[v][0].mn), max(ans.mx, up[v][0].mx)};
		ans={up[u][0].to, min(ans.mn, up[u][0].mn), max(ans.mx, up[u][0].mx)};
	}
	return ans;
}
