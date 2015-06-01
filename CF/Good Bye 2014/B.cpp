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
const int maxn = 300 + 5;
int vis[maxn] , a[maxn] , x[maxn] , y[maxn];
bool mp[maxn][maxn];

void floyd(int n){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
			{
				mp[i][j] = mp[i][j] || (mp[i][k] && mp[k][j]);
			}
}

int main(){
	int n; scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(int j = 0; j < n; j++)
			mp[i][j] = s[j] - '0';
	}
	floyd(n);
	for(int i = 0; i < n; i++){
		if(vis[i]) continue;
		int b = 0 , e = 0; x[0] = i; y[0] = a[i]; vis[i] = 1;
		while(b <= e) {
			for(int j = 0; j < n; j++)
			{
				if(!vis[j] && mp[x[b]][j]) {
					e++;
					x[e] = j; y[e] = a[j];
					vis[j] = 1;
				}
			}
			b++;
		}
		sort(x,x+e+1); sort(y,y+e+1);
		for(int k = 0; k <= e; k++)
			a[x[k]] = y[k];
	}
	for(int i = 0; i < n - 1; i++) printf("%d ",a[i]);
	printf("%d\n",a[n-1]);
    return 0;
}

