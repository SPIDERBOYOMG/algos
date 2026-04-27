struct PairHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(const pair<long long, long long>& p) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();

        uint64_t h1 = splitmix64((uint64_t)p.first + FIXED_RANDOM);
        uint64_t h2 = splitmix64((uint64_t)p.second + FIXED_RANDOM);
        return h1 ^ (h2 << 1);
    }
};

gp_hash_table<pll, null_type, PairHash> was;
bool used[maxn];
gp_hash_table<pll, int, PairHash> dp;

void rec(int n, ll st){
	debug(n, st);
	was.insert({n, st});
	for(int i=1; i<=n; i++){
		if(st>>i&1) continue;
		pll to={n-i, st^(1ll<<i)};
		if(was.find(to)==was.end()) rec(to.f, to.s);
	}
	
	for(int i=1; i<=n; i++){
		if(st>>i&1) continue;
		pll to={n-i, st^(1ll<<i)};
		used[dp[to]]=1;
	}
	int mex=0;
	while(used[mex]) mex++;
	for(int i=1; i<=n; i++){
		if(st>>i&1) continue;
		pll to={n-i, st^(1ll<<i)};
		used[dp[to]]=0;
	}
	
	dp[{n, st}]=mex;
}
