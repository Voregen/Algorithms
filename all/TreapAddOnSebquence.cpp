class treap {
public:
    int sze, pr;
    treap *l, *r;
    llong sum, add, key, f, inc;
    treap(int x) {
        sze = 1;
        pr = rnd();
        key = sum = x;
        add = inc = 0;
        f = -1;
        l = r = nullptr;
    }
};

inline llong f(llong x) {
    return (1ll * x * (x + 1)) >> 1;
}

inline int lsze(treap* z) {
    int aa = 1;
    if (z == nullptr)
        return 0;
    if (z -> l == nullptr)
        return 1;
    aa += z -> l -> sze;
    return aa;
}

void update(treap* z) {
    if (z == nullptr)
        return;
    z -> sze = 1;
    z -> sum = z -> key;
    if (z -> l) {
        if (z -> f != -1) {
            z -> l -> add = z -> l -> inc = 0;
            z -> l -> f = z -> l -> key = z -> f;
            z -> l -> sum = z -> l -> sze * z -> f;
        }
        z -> l -> key += lsze(z -> l) * z -> add + z -> inc;
        z -> l -> sum += z -> l -> sze * z -> inc + z -> add * f(z -> l -> sze);
        z -> l -> inc += z -> inc;
        z -> l -> add += z -> add;
        z -> sze += z -> l -> sze;
        z -> sum += z -> l -> sum;
    }
    if (z -> r) {
        if (z -> f != -1) {
            z -> r -> add = z -> r -> inc = 0;
            z -> r -> f = z -> r -> key = z -> f;
            z -> r -> sum = z -> r -> sze * z -> f;
        }
        z -> r -> key += z -> inc + z -> add * lsze(z) + lsze(z -> r) * z -> add;
        z -> r -> sum += (z -> inc + z -> add * lsze(z)) * z -> r -> sze + z -> add * f(z -> r -> sze);
        z -> r -> inc += z -> inc + z -> add * lsze(z);
        z -> r -> add += z -> add;
        z -> sze += z -> r -> sze;
        z -> sum += z -> r -> sum;
    }
    z -> f = -1;
    z -> inc = 0;
    z -> add = 0;
}

void split(treap* t, treap* &l, treap* &r, int k) {
    if (t)
        update(t);
    if (t == nullptr) {
        r = l = nullptr;
        return;
    }
    if (lsze(t) <= k) {
        l = t;
        split(t -> r, l -> r, r, k - lsze(t));
    } else {
        r = t;
        split(t -> l, l, r -> l, k);
    }
    update(l);
    update(r);
}


void merch(treap* l, treap* r, treap* &t) {
    if (l)
        update(l);
    if (r)
        update(r);
    if (l == nullptr) {
        t = r;
        return;
    }
    if (r == nullptr) {
        t = l;
        return;
    }
    if (l -> pr > r -> pr) {
        t = l;
        merch(l -> r, r, t -> r);
    } else {
        t = r;
        merch(l, r -> l, t -> l);
    }
    update(t);
}
