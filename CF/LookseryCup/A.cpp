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
#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

char mp[51][51];

int main(){
	int n,m; cin >> n >> m;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j){
			cin >> mp[i][j]; 
		}
	int ans = 0;
	if(n == 1 || m == 1) { cout << 0 << '\n'; return 0; }
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m - 1; ++j){
			char x[4];
			x[0] = mp[i][j]; x[1] = mp[i+1][j];
			x[2] = mp[i][j+1]; x[3] = mp[i+1][j+1];
			sort(x,x+4);
			if(x[0] == 'a' && x[1] == 'c' && x[2] == 'e' && x[3] == 'f') ans++;
		}
	cout << ans << '\n';
	return 0;
}