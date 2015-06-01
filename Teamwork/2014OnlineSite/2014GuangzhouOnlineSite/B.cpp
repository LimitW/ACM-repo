/************************************************
 * Title:
 * Author:LimitW
 * Date:
 * Source:
 * Note:
*************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 10;

struct POS{
    int left, right, col;
} tree[3*maxn];

bool color[31];

int ans[31];

void build(int l, int r, int now) {
    tree[now].left = l;
    tree[now].right = r;
    tree[now].col = 2;
    int mid = (l + r) / 2;
    if (r > l){
        build(mid + 1, r, now * 2 + 1);
        build(l, mid, now * 2);
    }
}

void insert_c(int a, int b, int val, int now) {
    if (tree[now].left >= a && tree[now].right <= b) {
        tree[now].col = val;
        return;
    }
    if (tree[now].col > 0){
        tree[now * 2].col = tree[now].col;
        tree[now * 2 + 1].col = tree[now].col;
    }
    tree[now].col = -1;
    int mid = (tree[now].left + tree[now].right) / 2;
    if (b <= mid)
        insert_c(a, b, val, now * 2);
    else if (a > mid)
        insert_c(a, b, val, now * 2 + 1);
    else {
        insert_c(a, mid, val, now * 2);
        insert_c(mid + 1, b, val, now * 2 + 1);
    }
}

void find(int a, int b, int now){
    if (tree[now].col > 0){
        color[tree[now].col] = 1;
        return;
    }
    if (tree[now].left < tree[now].right) {
        int mid = (tree[now].left + tree[now].right) / 2;
        if (b <= mid)
            find(a, b, now * 2);
        else if (a > mid)
            find(a, b, now * 2 + 1);
        else{
            find(a, mid, now * 2);
            find(mid + 1, b, now * 2 + 1);
        }
    }
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) && (m || n)){
		build(1,n,1);
		for(int i = 0; i < m; i++)
		{
			char op;
			scanf(" %c ",&op);
			if(op == 'P'){
				int l,r,c;
				scanf("%d %d %d",&l,&r,&c);
				insert_c(l,r,c,1);
			}
			if(op == 'Q'){
                memset(color,0,sizeof(color));
				int l,r;
				scanf("%d %d",&l,&r);
				find(l,r,1);
				int count = 0;
				for(int j = 1; j < 31; j++)
					if(color[j]) ans[count++] = j;
                for(int j = 0; j < count - 1; j++)
                    printf("%d ",ans[j]);
				printf("%d\n",ans[count-1]);
			}
		}
	}
	//system("pause");
	return 0;
}