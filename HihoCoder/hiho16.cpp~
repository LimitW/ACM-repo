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
#include <utility>
#include <bitset>
#include <algorithm>

using namespace std;

const int maxn = 1e6+5;
int v[maxn];
int q[maxn][20];
int pow2[21];

void RMQ(int n){
	for(int j = 0; pow2[j] < n; j++)
		for(int i = 0; i < n; i++)
		{
			if(j == 0) q[i][j] = v[i];
			else if(i + pow2[j] - 1 < n)
				q[i][j] = min( q[i][j-1] , q[i+pow2[j-1]][j-1] );
			else break;
		}
}

int query(int l,int r){
	if(l == r) return v[l];
	else {
		int e = log((double)(r-l+1))/log(2.0);
		return min(q[l][e],q[r-pow2[e]+1][e]);
	}
}


int main(){
	pow2[0] =1;
	for(int i = 1; i < 21; i++) pow2[i] = pow2[i-1] * 2;
	int n; scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d",&v[i]);
	RMQ(n);
	int m; scanf("%d",&m);
	for(int i = 0; i < m; i++){
		int l,r; scanf("%d%d",&l,&r);
		printf("%d\n",query(l-1,r-1));
	}
	return 0;
}

