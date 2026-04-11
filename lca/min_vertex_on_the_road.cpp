int timer, tin[maxn], tout[maxn], h[maxn];
vi g[maxn], dist(maxn, MOD);
struct node{
	int to;
	int mn;
};
node up[maxn][LOG];

void dfs(int v, int pr=0){
	tin[v]=++timer;
	
	h[v]=h[pr]+1;
	up[v][0]={pr, min(dist[pr], dist[v])};
	for(int p=1; p<LOG; p++){
		int prev=up[v][p-1].to;
		up[v][p]={up[prev][p-1].to, min(up[v][p-1].mn, up[prev][p-1].mn)};
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

node lca(int u, int v){
	node ans={0, MOD};
	
	if(u==v){
		return {u, dist[u]};
	}
	
	for(int p=LOG-1; p>=0; p--){
		if(up[u][p].to and !check(up[u][p].to, v)){
			ans.mn=min(ans.mn, up[u][p].mn);
			u=up[u][p].to;
		}
	}
	for(int p=LOG-1; p>=0; p--){
		if(up[v][p].to and !check(up[v][p].to, u)){
			ans.mn=min(ans.mn, up[v][p].mn);
			v=up[v][p].to;
		}
	}
	
	if(check(u, v)){
		ans.mn=min(ans.mn, up[v][0].mn);
		ans.to=up[v][0].to;
	}else if(check(v, u)){
		ans.mn=min(ans.mn, up[u][0].mn);
		ans.to=up[u][0].to;
	}else{
		ans.mn=min(ans.mn, up[v][0].mn);
		ans.mn=min(ans.mn, up[u][0].mn);
		ans.to=up[u][0].to;
	}
	return ans;
}

void solve(){
	int n, q; cin>>n>>q;
	vi a(n+1);
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<n; i++){
		int u, v; cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	queue<int> que;
	for(int i=1; i<=n; i++){
		if(a[i]){
			dist[i]=0;
			que.push(i);
		}
	}
	
	while(!que.empty()){
		int v=que.front(); que.pop();
		for(auto &to:g[v]){
			if(dist[to]>dist[v]+1){
				dist[to]=dist[v]+1;
				que.push(to);
			}
		}
	}
	for(int i=1; i<=n; i++){
		dist[i]*=2;
	}
	
	dfs(1);
	
	while(q--){
		int u, v; cin>>u>>v;
		debug(u, v);
		auto res=lca(u, v);
		ll ans=h[u]+h[v]-2*h[res.to];
		cout<<ans+res.mn<<"\n";
	}
}

int main(){
	for(int i=0; i<maxn; i++){
		for(int p=0; p<LOG; p++){
			up[i][p]={0, MOD};
		}
	}
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int ttt=1; //cin>>ttt;
    while(ttt--){
    	solve();
    	cout<<"\n";
//    	cout<<string(15, '-')<<"\n";
	}
}
