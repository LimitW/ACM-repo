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
const int mod = 1e9 + 7;
const int maxn = 1e6 + 3;

int hs[maxn];
bool prime[maxn];
vector<int> x[10];

void init(){
	for(int i = 2; i <= 1000000; ++i){
		if(prime[i]) continue;
		for(int j = 2; j * i <= 1000000; ++j){
			prime[i*j] = 1;
			++hs[i*j];
		}
	}
	for(int i = 2; i <= 1000000; ++i){
		if(!prime[i]) x[1].push_back(i);
		else x[hs[i]].push_back(i);
	}
}

bool fd1(int id,int l,int r){
	vector<int>::iterator itl = lower_bound(x[id].begin(),x[id].end(),l),
			itr = upper_bound(x[id].begin(),x[id].end(),r);
	return itr - itl >= 2;
}

bool fd2(int id,int v,int op){
	vector<int>::iterator it = lower_bound(x[id].begin(),x[id].end(),v);
	if(op) return it != x[id].end();
	else return it != x[id].end() && *it <= v;
}

int query(int l,int r){
	if(fd1(7,l,r)) return 7;
	else if(fd1(6,l,r)) return 6;
	else if(fd1(5,l,r)) return 5;
	else if(fd1(4,l,r)) return 4;
	else if(fd1(3,l,r)) return 3;
	else if(fd1(2,l,r)) return 2;
	else if(fd2(6,l,1) && fd2(3,r,0)) return 3;
	else if(fd2(6,r,0) && fd2(3,l,1)) return 3;
	else if(fd2(2,l,1) && fd2(6,r,0)) return 2;
	else if(fd2(6,l,1) && fd2(2,r,0)) return 2;
	else if(fd2(4,l,1) && fd2(2,r,0)) return 2;
	else if(fd2(4,r,0) && fd2(2,l,1)) return 2;
	else return 1;
}

int main(){
	init();
	int T; scanf("%d",&T);
	for(int kase = 0; kase < T; ++kase){
		int l,r; scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
    return 0;
}

