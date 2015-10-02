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
const double pi = acos(-1.0);
const long double eps = 1e-9;

const int maxn = 1e9 + 1;

map<int, int> mp;

int main(){
	mp.clear();
	for(int i = 0; i * i < maxn; ++i){
		++mp[i*i];
	}
	int n;
	while(~scanf("%d", &n)){
		bool fail = 0;
		for(int i = 0; i < n; ++i){
			int v; scanf("%d", &v);
			if(mp.find(v) == mp.end())
				fail = 1;
		}
		if(fail) puts("No");
		else puts("Yes");
	}
    return 0;
}
