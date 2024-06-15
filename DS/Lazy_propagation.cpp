#include "bits/stdc++.h"
using namespace std ;
using ll = long long ;
struct Node {
    long long sum = 0;
};

struct SegmantTree {

#define LF (x * 2 + 1)
#define RT (x * 2 + 2)
#define md ((lx + rx )/2)

    int size = 1;
    vector<Node> seg;
    vector<long long> lazy;
    Node NEUTRAL_ELEMENT = {0};

    SegmantTree(vector<int> &a) {
        size = a.size();
        seg = vector<Node>(4 * size);
        lazy = vector<ll>(4 * size, 0ll);
        build(a);
    }

    Node Single(int val) {
        Node ret = {val};
        return ret;
    }

    Node merge(Node a, Node b) {
        return {max(a.sum , b.sum)};
    }

    void propagate(int x, int lx, int rx) {
        if (lazy[x]) {
            seg[x].sum = max(lazy[x] , seg[x].sum);
            if (lx != rx) {
                lazy[LF] = max(lazy[LF] , lazy[x]) ;
                lazy[RT] = max(lazy[RT] , lazy[x]) ;
            }
            lazy[x] = 0;
        }
    }

    void build(vector<int> &a) {
        build(a, 0, 0, size - 1);
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx == lx) {
            return void(seg[x].sum = a[lx]);
        }
        build(a, LF, lx, md);
        build(a, RT, md + 1, rx);
        seg[x] = merge(seg[LF], seg[RT]);
    }

    void update(int l, int r, int v) {
        update(0, 0, size - 1, l, r, v);
    }

    void update(int x, int lx, int rx, int l, int r, int v) {
        propagate(x, lx, rx);
        if (lx > r || rx < l)
            return;
        if (lx >= l && rx <= r) {
            seg[x].sum = max(seg[x].sum , 1ll * v );
            if (lx != rx) {
                lazy[LF] = max(lazy[LF] , 1ll * v) ;
                lazy[RT] = max(lazy[RT] , 1ll * v) ;
            }
            return;
        }
        update(LF, lx, md, l, r, v);
        update(RT, md + 1, rx, l, r, v);
        seg[x] = merge(seg[LF], seg[RT]);
    }

    Node query(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    Node query(int x, int lx, int rx, int l, int r) {
        propagate(x, lx, rx);
        if (lx > r or l > rx)
            return NEUTRAL_ELEMENT;
        if (lx >= l and r >= rx)
            return seg[x];
        return merge(query(LF, lx, md, l, r), query(RT, md + 1, rx, l, r));
    }

#undef LF
#undef RT
#undef md
};