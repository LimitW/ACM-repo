#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

const int mod = 9973;

int a[100010];
char s[100010];

struct node{
    int v;
    int l, r;
}st[100010<<2];

void pushup(int o){
    st[o].v = st[o<<1].v * st[o<<1|1].v % mod;
}

void build(int o, int l, int r){
    if(l > r) return;
    st[o].l = l, st[o].r = r;
    if(l == r) { st[o].v = a[l]; return; }
    int mid = l + r >> 1;
    build(o<<1, l, mid);
    build(o<<1|1, mid + 1, r);
    pushup(o);
}

int query(int o, int l, int r){
    if(l > r) return 0;
    if(st[o].l == l && st[o].r == r)
        return st[o].v;
    int mid = st[o].l + st[o].r >> 1;
    if(l > mid) return query(o<<1|1, l, r);
    else if(r <= mid) return query(o<<1, l, r);
    else return query(o<<1, l, mid) * query(o<<1|1, mid + 1, r) % mod;
}

int main(){
    int n;
    while(~scanf("%d", &n)){
        scanf("%s", s);
        int len = strlen(s);
        for(int i = 1; i <= len; ++i){
            a[i] = s[i - 1] - 28;
        }
        build(1, 1, len);
        int l, r;
        int res;
        for(int i = 0; i < n; ++i){
            scanf("%d%d", &l, &r);
            if(l <= len && r <= len)
                res = query(1, l, r);
            printf("%d\n", res);
        }
    }
    return 0;
}
