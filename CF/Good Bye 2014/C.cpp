#include <iostream>
#include <iomanip>
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
#include <functional>
#include <algorithm>
#include <fstream>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const int maxn = 500 + 5;
int w[maxn] , r[1010] , vis[maxn] , p[maxn];

int main(){
	int n , m; scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++)
		scanf("%d",&w[i]);
	int c = 0;
	for(int i = 0; i < m; i++){
		scanf("%d",&r[i]);
		if(!vis[r[i]]) { vis[r[i]] = 1; p[c++] = r[i]; }
	}
	int ans = 0;
	for(int i = 0; i < m; i++){
		int sum = 0 , pos = 0;
		for(int j = 0; j < n; j++){
			if(p[j] == r[i]) { ans += sum; pos = j; break; }
			else sum += w[p[j]-1];
		}
		for(int j = pos - 1; j >= 0; j--) p[j+1] = p[j];
		p[0] = r[i];
	}
	printf("%d\n",ans);
    return 0;
}
