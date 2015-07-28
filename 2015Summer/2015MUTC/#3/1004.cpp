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
const int mod = 1e9 + 7;
const int maxn = 1e6 + 3;

int mp[52][52];

int main(){
	int T; scanf("%d",&T);
	for(int kase = 0; kase < T; ++kase){
		int n,l; scanf("%d",&n);
		char s[52];
		for(int i = 0; i < n; ++i){
			scanf("%s",s);
			l = strlen(s);
			for(int j = 0; j < l; ++j){
				if(s[j] == 'R') mp[i][j] = 1;
				else if(s[j] == 'G') mp[i][j] = 3;
				else if(s[j] == 'B') mp[i][j] = 2;
				else mp[i][j] = 0;
			}
		}
		int ans = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < l; ++j){
				if(mp[i][j] == 1){
					++ans;
					mp[i][j] = 0;
					int dx = i , dy = j;
					while(dx + 1 < n && dy + 1 < l && (mp[dx+1][dy+1] == 1 || mp[dx+1][dy+1] == 3)){
						mp[dx+1][dy+1] -= 1;
						++dx,++dy;
					}
				}
				else if(mp[i][j] == 2){
					++ans;
					mp[i][j] = 0;
					int dx = i , dy = j;
					while(dx + 1 < n && dy - 1 >= 0 && mp[dx+1][dy-1] >= 2){
						mp[dx+1][dy-1] -= 2;
						++dx,--dy;
					}
				}
				else if(mp[i][j] == 3){
					ans += 2;
					mp[i][j] = 0;
					int dx = i , dy = j;
					while(dx + 1 < n && dy - 1 >= 0 && mp[dx+1][dy-1] >= 2){
						mp[dx+1][dy-1] -= 2;
						++dx,--dy;
					}
					dx = i , dy = j;
					while(dx + 1 < n && dy + 1 < l && (mp[dx+1][dy+1] == 1 || mp[dx+1][dy+1] == 3)){
						mp[dx+1][dy+1] -= 1;
						++dx,++dy;
					}
				}
			}
		printf("%d\n",ans);
	}
    return 0;
}

