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

int mp[51][51];
int nmp[51][51];
int ans[110][110];

struct mv {
	int dx,dy;
};

vector<mv> ps;
vector<pii> cs;

int main(){
	int n , mx = 0 , my = 0;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string s; cin >> s;
		for(int j = 0; j < n; ++j){
			if(s[j] == 'o') {
				mp[i][j] = 1;
				cs.push_back(make_pair(i,j));
				mx = max(mx , max(n - i , i));
				my = max(my , max(n - j , j));
			}
			else if(s[j] == 'x') mp[i][j] = -1;
		}
	}
	memset(nmp,0,sizeof(nmp));
	for(int dx = -mx; dx < mx; ++dx){
		for(int dy = -my; dy < my; ++dy){
			bool fail = 0 , flag = 0;
			for(int z = 0; z < cs.size(); ++z){
				int i = cs[z].first , j = cs[z].second;
				nmp[i][j] = 1;
				if(i + dx >= 0 && i + dx < n && j + dy >= 0 && j + dy < n){
					flag = 1;
					if(mp[i+dx][j+dy] == 0) fail = 1;
				}
			}
			if(!fail && flag) {
				mv x; x.dx = dx , x.dy = dy;
				ps.push_back(x);
			}
		}
	}
	bool fail = 0;
	for(int k = 0; k < cs.size(); ++k){
		int i = cs[k].first , j = cs[k].second;
		for(int z = 0; z < ps.size(); ++z){
			int dx = ps[z].dx , dy = ps[z].dy;
			if(i + dx >= 0 && i + dx < n && j + dy >= 0 && j + dy < n)
				if(nmp[i+dx][j+dy] == 0) nmp[i+dx][j+dy] = -1;
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(mp[i][j] != nmp[i][j]) fail = 1;
		}
	}
	if(!fail && ps.size() > 0){
		printf("YES\n");
		memset(ans,0,sizeof(ans));
		ans[n-1][n-1] = 1;
		for(int z = 0 ; z < ps.size(); ++z){
			mv x = ps[z];
			int dx = x.dx , dy = x.dy;
			if(n-1 + dx >= 0 && n-1 + dx < 2*n-1 && n-1 + dy >= 0 && n-1 + dy < 2*n-1)
				if(ans[n-1+dx][n-1+dy] == 0) ans[n+dx-1][n+dy-1] = -1;
			}
		for(int i = 0 ; i < 2*n-1; ++i){
			for(int j = 0; j < 2*n-1; ++j){
				if(ans[i][j] == 1){
					printf("o");
				}
				else if(ans[i][j] == -1){
					printf("x");
				}
				else printf(".");
			}
			puts("");
		}
	}
	else printf("NO\n");
    return 0;
}

