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
const int maxn = 1e5 + 100;

int a[maxn], b[maxn];
int n;

vector<pii> ans;

int main(){
	int T; scanf("%d",&T);
	for(int kase = 0; kase < T; ++kase){
		scanf("%d",&n);
		LL sum = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d",&a[i]);
			sum += (LL)a[i];
		}
		if(n == 1){
			printf("YES\n0\n");
			continue;
		}
		else if(n == 2){
			if(abs(a[0] - a[1]) != 2 && a[0] != a[1]) puts("NO");
			else{
				puts("YES");
				if(a[0] == a[1]) puts("0");
				else if(a[0] - a[1] == 2){
					printf("1\n1 2\n");
				}
				else printf("1\n2 1\n");
			}
			continue;
		}
		if(sum % n != 0){
			puts("NO");
			continue;
		}
		sum /= n;
		ans.clear();
		for(int i = 0; i < n; ++i) b[i] = a[i];
		bool fail = 0;
		for(int i = 0; i < n; ++i){
			if(b[i] != sum) { fail = 1; break; }
		}
		if(!fail){ printf("YES\n0\n"); continue; }
		for(int op = -1; op < 2; ++op){
			if(b[0] + op >= 0 && b[1] - op >= 0){
				b[0] += op, b[1] -= op;
				if(op == 1) ans.push_back(make_pair(2,1));
				else if(op == -1) ans.push_back(make_pair(1,2));
			}
			else continue;
			for(int i = 1; i < n; ++i){
				int nxt = i + 1;
				if(nxt == n) nxt = 0;
				if(b[i] == sum - 1 && b[nxt] > 0){
					b[nxt]--, b[i]++;
					ans.push_back(make_pair(nxt+1,i+1));
				}
				else if(b[i] == sum + 1){
					b[nxt]++, b[i]--;
					ans.push_back(make_pair(i+1,nxt+1));
				}
			}
			fail = 0;
			for(int i = 0; i < n; ++i){
				if(b[i] != sum) { fail = 1; break; }
			}
			if(fail){
				for(int i = 0; i < n; ++i) b[i] = a[i];
				ans.clear();
			}
			else break;
		}
		if(fail) puts("NO");
		else {
			puts("YES");
			int sz = ans.size();
			printf("%d\n", sz);
			for(int i = 0; i < sz; ++i){
				printf("%d %d\n", ans[i].first, ans[i].second);
			}
		}
	}
	return 0;
}

