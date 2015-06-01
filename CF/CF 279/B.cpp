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

const int maxn = 2e5 + 10;
const int maxv = 1e6 + 5;

int pos[maxn];
map<int,int> mp_l , mp_r;
int vis[maxv];

int main(){
	int n; scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		if(u == 0) { pos[1] = v; vis[v]++; }
		if(v == 0) { pos[n-2] = u; vis[u]++; }
		if(u != 0 && v != 0) {
			mp_l[u] = v; mp_r[v] = u;
			vis[u]++; vis[v]++;
		}
	}
	for(int i = 1; i + 2 < n; i += 2)
		pos[i+2] = mp_l[pos[i]];
	for(int i = n - 2; i - 2 >= 0; i -= 2)
		pos[i-2] = mp_r[pos[i]];
	if(n % 2 !=0){
	int _in,_out;
	int flag = 1;
	for(int i = 1; i <= maxv; i++)
		if(vis[i] % 2 == 1 && flag) { _in = i; flag = 0; }
		else if(vis[i] % 2 == 1 && !flag) { _out = i; break; }
	if(mp_l[_in] == 0) swap(_in,_out);
	pos[0] = _in; pos[n-1] = _out;
	for(int i = 0; i + 2 < n; i += 2)
		pos[i+2] = mp_l[pos[i]];
	for(int i = n - 1; i - 2 >= 0; i -= 2)
		pos[i-2] = mp_r[pos[i]];
	}
	for(int i = 0; i < n; i++)
		printf("%d%c",pos[i] , i==n-1? '\n' : ' ' );
	return 0;
}
