struct DSU {
	vector<int>par, ra;
	DSU(int n)
	{
		par.resize(n + 5); ra.resize(n + 5, 0);
		for (int i = 0; i <= n; i++)
			par[i] = i;
	}
	int get(int u)
	{
		if (par[u] == u)
			return u;
		return par[u] = get(par[u]);
	}
	void merge(int u, int v)
	{
		u = get(u), v = get(v);
		if (u == v) return;
		if (ra[v] > ra[u])swap(u, v);
		par[v] = u;
		if (ra[u] == ra[v])
			ra[u]++;
	}
};