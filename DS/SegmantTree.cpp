#include "bits/stdc++.h"
using namespace std ;

struct Node {
    int sum;
};

struct SegmantTree {

#define LF (x * 2 + 1)
#define RT (x * 2 + 2)
#define md ((lx + rx )/2)

    int size = 1;
    vector<Node> seg;
    Node NEUTRAL_ELEMENT = {0};

    SegmantTree(vector<int> &a) {
        size = a.size();
        seg = vector<Node>(4 * size);
        build(a);
    }

    Node Single(int val) {
        Node ret = {val};
        return ret;
    }

    Node merge(Node a, Node b) {
        return {(a.sum + b.sum)};
    }

    void build(vector<int> &a) {
        build(a, 0, 0, size - 1);
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx == lx) {
            return void(seg[x] = Single(a[lx]));
        }
        build(a, LF, lx, md);
        build(a, RT, md + 1, rx);
        seg[x] = merge(seg[LF], seg[RT]);
    }

    void update(int i, int val) {
        update(i, val, 0, 0, size - 1);
    }

    void update(int i, int val, int x, int lx, int rx) {
        if (rx == lx)
            return void(seg[x] = Single(val));
        if (i <= md) {
            update(i, val, LF, lx, md);
        } else {
            update(i, val, RT, md + 1, rx);
        }
        seg[x] = merge(seg[LF], seg[RT]);
    }

    Node query(int l, int r) {
        return query(l, r, 0, 0, size - 1);
    }

    Node query(int l, int r, int x, int lx, int rx) {
        if (lx > r or l > rx)
            return NEUTRAL_ELEMENT;
        if (lx >= l and r >= rx)
            return seg[x];
        return merge(query(l, r, LF, lx, md), query(l, r, RT, md + 1, rx));
    }

    int find(int k, int j) {
        return find(k, j, 0, 0, size - 1);
    }

    int find(int k, int j, int x, int lx, int rx) {
        if (seg[x].sum < k or rx < j ) { return -1; }
        if (lx == rx) { return lx; }
        int ret = find(k, j, LF, lx, md);
        if (ret == -1) {
            ret = find(k, j, RT, md + 1, rx);
        }
        return ret;
    }

#undef LF
#undef RT
#undef md

};