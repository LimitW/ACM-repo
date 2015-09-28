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
const int mod = 1e9 + 7;
const int maxn = (1 << 10) + 3;

class LiveConcert{
public:
	int maxHappiness(vector <int> h, vector <string> s){
		map<string, int> mp;
		mp.clear();
		int n = s.size();
		for(int i = 0; i < n; ++i){
			mp[s[i]] = max(mp[s[i]], h[i]);
		}
		int ans = 0;
		for(map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it){
			ans += it->second;
		}
		return ans;
	}
};
