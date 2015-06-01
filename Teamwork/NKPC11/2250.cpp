#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 1e5 +3;

unsigned int p[maxn];
vector<int> G[maxn];

int getnum(int r){
	if(G[r].size() == 0){
		return p[r] = 1;
	}
	int ans = 1;
	for(int i = 0; i < G[r].size(); ++i){
		ans += getnum(G[r][i]);
	}
	return p[r] = ans;
}

int main(){
	int n; scanf("%d",&n);
	for(int i = 1 ; i <= n; ++i)
	{
		int nn; scanf("%d",&nn);
		for(int j = 0;  j < nn; ++j){
			int tmp; scanf("%d",&tmp);
			G[i].push_back(tmp);
		}
	}
	getnum(1);
	unsigned int ans = 0;
	int m; scanf("%d",&m);
	for(int i = 0 ; i < m; ++i){
		char op; int x,v;
		getchar(); scanf("%c",&op);
		if(op == 'A'){
			scanf("%d%d",&x,&v);
			ans += v*p[x];
		}
		else if(op == 'B'){
			scanf("%d%d",&x,&v);
			ans -= v*p[x];
		}
		else if(op == 'Q') printf("%u\n",ans);
	}
	return 0;
}

