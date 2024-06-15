#include<bits/stdc++.h>
using namespace std ;

struct DSU {
    vector<int> par;
    vector<int> size;

    DSU(int n) {
        par = vector<int>(n + 1);
        size = vector<int>(n + 1, 1);
        iota(par.begin(), par.end(), 0);
    }

    int findParent(int u) {
        if (par[u] == u)
            return u;
        return par[u] = findParent(par[u]);
    }

    bool isConected(int v, int u) {
        return findParent(u) == findParent(v);
    }

    void conect(int v, int u) {
        if (isConected(v, u))
            return;

        int p1 = findParent(u);
        int p2 = findParent(v);

        if (size[p1] > size[p2]) {
            par[p2] = p1;
            size[p1] += size[p2];
        } else {
            par[p1] = p2;
            size[p2] += size[p1];
        }
    }
};