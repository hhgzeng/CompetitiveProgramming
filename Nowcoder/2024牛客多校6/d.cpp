#include <bits/stdc++.h>

using i64 = long long;

std::set<std::pair<int, int>> lun, qie;
std::set<std::pair<int, int>> E;

struct EBCC {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> dfn, low, bel;
    std::vector<int> stk;
    int cur, cnt;
    
    EBCC() {}
    EBCC(int n) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        stk.clear();
        cur = cnt = 0;
    }
    
    void addEdge(int u, int v) {
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    
    void dfs(int x, int p) {
        dfn[x] = low[x] = cur++;
        stk.emplace_back(x);
        
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            if (dfn[y] == -1) {
            	E.emplace(x, y);
                dfs(y, x);
                low[x] = std::min(low[x], low[y]);
                if (low[y] > dfn[x]) {
                	lun.erase({x, y});
                	lun.erase({y, x});
                }
            } else if (bel[y] == -1 && dfn[y] < dfn[x]) {
            	E.emplace(x, y);
                low[x] = std::min(low[x], dfn[y]);
            }
        }
        
        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
            } while (y != x);
            cnt++;
        }
    }
    
    std::vector<int> work() {
    	for (int i = 0; i < n; i++) {
    		if (dfn[i] == -1) {
    			dfs(i, -1);
    		}
    	}
        return bel;
    }
    
    struct Graph {
        int n;
        std::vector<std::pair<int, int>> edges;
        std::vector<int> siz;
        std::vector<int> cnte;
    };
    Graph compress() {
        Graph g;
        g.n = cnt;
        g.siz.resize(cnt);
        g.cnte.resize(cnt);
        for (int i = 0; i < n; i++) {
            g.siz[bel[i]]++;
            for (auto j : adj[i]) {
                if (bel[i] < bel[j]) {
                    g.edges.emplace_back(bel[i], bel[j]);
                } else if (i < j) {
                    g.cnte[bel[i]]++;
                }
            }
        }
        return g;
    }
};

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
	int n, m;
	std::cin >> n >> m;

	EBCC ebcc(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		std::string s;
		std::cin >> u >> v >> s;
		u--;
		v--;
		if (s == "Lun") {
			ebcc.addEdge(u, v);
			lun.emplace(u, v);
		} else {
			qie.emplace(u, v);
		}
	}

	std::vector<int> bel;
	bel = ebcc.work();

	DSU dsu(n);
	std::vector<std::pair<int, int>> ans;
	for (auto [x, y] : lun) {
		dsu.merge(x, y);
		ans.emplace_back(x, y);
	}
	for (auto [x, y] : qie) {
		if (bel[x] != bel[y] && dsu.merge(x, y)) {
			ans.emplace_back(x, y);
		}
	}

	for (int i = 1; i < n; i++) {
		if (!dsu.same(i, i - 1)) {
			std::cout << "NO\n";
			return;
		}
	}
	std::cout << "YES\n";
	std::cout << ans.size() << "\n";
	for (auto [x, y] : ans) {
		std::cout << x + 1 << " " << y + 1 << "\n";
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    while (T--) {
    	solve();
    }

    return 0;
}