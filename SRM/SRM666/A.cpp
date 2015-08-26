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
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
const int maxn = 1 << 16;
//const int maxm = maxn * maxn;

class DevuAndGame{
public:
	bool vis[51];
	string canWin(vector<int> nextLevel){
		string a = "Win", b = "Lose";
		int i = 0;
		vis[0] = 1;
		while(true){
			if(nextLevel[i] == -1) return a;
			if(vis[nextLevel[i]]) return b;
			i = nextLevel[i];
			vis[i] = 1;
		}
		return b;
	}
};
