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

class CombiningSlimes{
public:
	int maxMascots(vector <int> a){
		int ans = 0;
		int n = a.size();
		int tp = a[0];
		for(int i = 1; i < n; ++i){
			ans += tp * a[i];
			tp += a[i];
		}
		return ans;
	}
};
