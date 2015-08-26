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

class GoodString{
public:
	string dfs(string k){
		int sz = k.length();
		bool x = 0;
		for(int i = 0; i < sz - 1; ++i){
			if(k[i] == 'a' && k[i+1] == 'b'){
				string nxt = k.substr(0,i) + k.substr(i+2);
				if(nxt.length() == 0) return nxt;
				else{
					x = 1;
					return dfs(nxt);
				}
			}
		}
		if(!x) return "-1";
	};

	string isGood(string s){
		string a = "Good", b = "Bad";
		if(s.length() % 2 != 0) return b;
		for(int i = 0; i < s.length(); ++i)
			if(s[i] != 'a' && s[i] != 'b') return b;
		if(dfs(s) == "") return a;
		return b;
	}
};
