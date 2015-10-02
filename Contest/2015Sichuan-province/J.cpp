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
const int maxn = 1e3 + 3;

const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct node{
	int x, y, v, op;
	node(int x, int y, int v, int op):x(x), y(y), v(v), op(op){};
	void turn(int nx, int ny){
		op = (op + 1) % 4;
		x = nx, y = ny;
		++v;
	}
};

map<int, set<int> > X, Y;

int main(){
	int n;
	while(~scanf("%d", &n)){
		X.clear(); Y.clear();
		for(int i = 0; i < n; ++i){
			int x, y; scanf("%d%d", &x, &y);
			X[x].insert(y);
			Y[y].insert(x);
		}
		int ed = 4 * n + 10, ans;
		queue<node> Q;
		while(!Q.empty()) Q.pop();
		Q.push(node(0, 0, 0, 1));
		while(!Q.empty()){
			node tp = Q.front(); Q.pop();
			ans = tp.v;
			if(ans > ed) { ans = -1; break; }
			set<int>::iterator it;
			if(tp.op == 0 && X.find(tp.x) != X.end()){
				it = X[tp.x].lower_bound(tp.y);
				if(it == X[tp.x].end()) break;
				tp.turn(tp.x, *it - 1);
				Q.push(tp);
			}
			else if(tp.op == 2 && X.find(tp.x) != X.end()){
				it = X[tp.x].lower_bound(tp.y);
				if(it == X[tp.x].begin()) break;
				--it;
				tp.turn(tp.x, *it + 1);
				Q.push(tp);
			}
			else if(tp.op == 1 && Y.find(tp.y) != Y.end()){
				it = Y[tp.y].lower_bound(tp.x);
				if(it == Y[tp.y].end()) break;
				tp.turn(*it - 1, tp.y);
				Q.push(tp);
			}
			else if(tp.op == 3 && Y.find(tp.y) != Y.end()){
				it = Y[tp.y].lower_bound(tp.x);
				if(it == Y[tp.y].begin()) break;
				--it;
				tp.turn(*it + 1, tp.y);
				Q.push(tp);
			}
			else break;
		}
		cout << ans << '\n';
	}
	return 0;
}

