class treap {
public:
    int sze, pr, key;
    treap *l, *r;
    treap(int x) {
        sze = 1;
        pr = rnd();
        this -> key = x;
        l = r = nullptr;
    }
};

void update(treap* z) {
    if (z == nullptr)
        return;
    z -> sze = 1;
    if (z -> l){
        z -> sze += z -> l -> sze;
    }
    if (z -> r){
        z -> sze += z -> r -> sze;
    }
}

int lsze(treap* z) {
    int aa = 1;
    if (z == nullptr)
        return 0;
    if (z -> l == nullptr)
        return 1;
    aa += z -> l -> sze;
    return aa;
}

void split(treap* t, treap* &l, treap* &r, int k) {
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
