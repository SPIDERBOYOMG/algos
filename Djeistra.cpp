for(int i=1; i<=n; i++){
	int v=-1;
	
	for(int j=1; j<=n; j++){
		if(!was[j] and (v==-1 or dist[j]>dist[v])){
			v=j;
		}
	}
	
	was[v]=1;
	
	for(auto &[to, len]:g[v]){
		dist[to]=min(dist[to], dist[v]+len);
	}
}
