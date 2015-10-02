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
const int maxn = 1e5 + 4;
//const int maxm = maxn * maxn;

char s[maxn], t[maxn];
int x[27][2];

int main(){
	int T; scanf("%d", &T);
	while(T--){
		scanf("%s", s);
		scanf("%s", t);
		int l1 = strlen(s), l2 = strlen(t), p1 = 0, p2 = 0;
		while(++p1 < l1 && s[p1] == s[p1-1]);
		while(++p2 < l2 && t[p2] == t[p2-1]);
		if(s[0] != t[0] || p1 < p2){
			puts("No"); continue;
		}
		memset(x, 0, sizeof(x));
		for(int i = 0; i < l1; ++i){
			++x[s[i]-'a'][0];
		}
		for(int i = 0; i < l2; ++i){
			++x[t[i]-'a'][1];
		}
		bool fail = 0;
		for(int i = 0; i < 27; ++i){
			if(x[i][0] > x[i][1])
				fail = 1;
		}
		if(!fail) puts("Yes");
		else puts("No");
	}
    return 0;
}

