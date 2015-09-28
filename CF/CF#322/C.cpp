#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <bitset>
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const long double eps = 1e-9;
const int mod = 1e9 + 7;
const int maxn = (1 << 10) + 3;

struct node{
    int v;
    bool operator < (node b) const {
        return v % 10 < b.v % 10 || (v % 10 == b.v % 10 && v > b.v);
    }
};

priority_queue<node> pq;

int main(){
    int n, k; scanf("%d%d", &n, &k);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        node x; scanf("%d", &x.v);
        pq.push(x);
        ans += x.v / 10;
    }
    while(!pq.empty()){
        node tp = pq.top();
        if(tp.v % 10 == 0) break;
        if(k >= 10 - tp.v % 10){
            pq.pop();
            ans++; k -= 10 - tp.v % 10;
            node x;
            x.v = tp.v + 10 - tp.v % 10;
            pq.push(x);
        }
        else break;
    }
    if(k <= 0) printf("%d\n", ans);
    else {
        int cnt = 0, num = 0;
        while(!pq.empty()){
            node y = pq.top();
            pq.pop();
            ++num;
            cnt += y.v;
        }
        ans += min(k / 10, (100 * num - cnt) / 10);
        printf("%d\n", ans);
    }
    return 0;
}
