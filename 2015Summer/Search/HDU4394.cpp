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

LL n;

int c;
int pow10[20];
int digit[20];

vector<int> u[10];

struct node{
	LL v;
	int l;
	bool operator < (node b) const {
		return l > b.l || (l == b.l && v > b.v);
	}
};

int getl(LL x){
    int len = 0;
    while(x > 0){
        x /= 10;
        ++len;
    }
    return min(1,len);
}

bool bfs(){
	priority_queue<node> q;
	while(!q.empty()) q.pop();
	int sz = u[digit[1]].size();
	for(int i = 0; i < sz; ++i){
		node x;
	    x.v = u[digit[1]][i];
	    x.l = 1;
        q.push(x);
	}
	while(!q.empty()){
		node u = q.top();
		q.pop();
		if(u.l > 9 || u.v > 2e9) continue;
		if(u.v * u.v % pow10[u.l] == n){
			printf("%I64d\n",u.v);
			return 1;
		}
		for(int i = 0; i < 10; ++i){
            node x;
            x.v = pow10[u.l] * (i*1LL) + u.v;
            LL vv = x.v * x.v;
			if((vv % pow10[u.l+1]) == (n % pow10[u.l+1])){
				x.l = u.l + 1;
                q.push(x);
			}
		}
	}
	return 0;
}


int main(){
	for(int i = 0; i < 10; ++i){
		u[i * i % 10].push_back(i);
	}
	pow10[0] = 1LL;
    for(int i = 1; i < 19; ++i)
        pow10[i] = pow10[i-1] * 10LL;
	int T; scanf("%d",&T);
	while(T--){
		scanf("%I64d",&n);
		c = 0;
		int k = n;
		while(k > 0){
			digit[++c] = k % 10;
			k /= 10;
		}
		if(!bfs()) printf("None\n");
	}
}
