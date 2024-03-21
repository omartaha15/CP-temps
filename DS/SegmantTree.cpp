//
// Created by otaha on 3/21/2024.
//
#include "bits/stdc++.h"
using namespace std ;

struct Node {
    int val = 0;
};

struct SegmantTree {

#define LF (x * 2 + 1)
#define RT (x * 2 + 2)
#define md ((lx + rx ) / 2)

    int size = 1;
    vector<Node> seg;
    SegmantTree(vector<int> &a) {
        size = a.size();
        seg = vector<Node>(4 * size);
        build(a);
    }

    Node Single(int val) {
        Node ret ;
        ret.val = val ;
        return ret ;
    }

    Node merge(Node a, Node b) {
        Node ret;
        ret.val = (a.val ^ b.val) ;
        return ret;
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

    Node query(int l, int r) {
        return query(l, r, 0, 0, size - 1);
    }

    Node query(int l, int r, int x, int lx, int rx) {
        if (lx > r or l > rx)
            return {};
        if (lx >= l and r >= rx)
            return seg[x];
        return merge(query(l, r, LF, lx, md), query(l, r, RT, md + 1, rx));
    }

#undef LF
#undef RT
#undef md
};