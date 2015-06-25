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
	int mp[110][110] , mp2[110][110];
	int n; cin >> n;
	for(int i = 0; i < n; ++i){
		string s; cin >> s;
		for(int j = 0; j < n; ++j)
			mp[i][j] = s[j] - '0';
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int _ = 0; _ < n; ++_)
			for(int __ = 0; __ < n; __++)
				mp2[_][__] = mp[_][__];
		for(int j = 0; j < n; ++j){
			if(!mp2[i][j]){
				for(int k = 0; k < n; ++k){
					mp2[k][j] = mp2[k][j] ^ 1;
				}
			}
		}
		int tmp = 0;
		for(int _ = 0; _ < n; ++_){
			bool flag = 1;
			for(int __ = 0; __ < n; __++){
				if(!mp2[_][__]) { flag = 0; break; }
			}
			if(flag) ++tmp;
		}
		ans = max(ans,tmp);
	}
	cout << ans << endl;
	return 0;
}

