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

int main(){
	int mp[102][102];
	memset(mp,0,sizeof(mp));
	int n; cin >> n;
	for(int i = 0; i < n; ++i){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int j = x1; j <= x2; ++j)
			for(int k = y1; k <= y2; ++k)
				mp[j][k]++;
	}
	int ans = 0;
	for(int i = 1; i <= 100; ++i)
		for(int j = 1; j <= 100; ++j)
			ans += mp[i][j];
	cout << ans << endl;
    return 0;
}

