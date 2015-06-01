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
const long long INFL = 1LL << 62;

string s , t = "CODEFORCES";

int main(){
	cin >> s;
	bool fail = 0;
	string p;
	for(int i = 0; i < s.length(); ++i){
		for(int j = i; j < s.length(); ++j){
			p = "";
			for(int k = 0; k < s.length(); ++k){
				if(k > j || k < i) p += s[k];
			}
			if(p == t) {
				printf("YES\n"); return 0;
			}
		}
	}
	printf("NO\n");
    return 0;
}

