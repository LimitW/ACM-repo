#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cstdlib>
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
#include <functional>
#include <algorithm>
#include <fstream>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
char s[maxn];
int ans[maxn];
int main(){
	scanf("%s",s);
	int n = strlen(s);
	int left = 0 , fail = 0 , c = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '(') left++;
		else if(s[i] == ')' ){
			if(left > 0) left--;
			else if(c > 0 && ans[c-1] > 1){ ans[c-1]--; }
			else { fail = 1; break; }
		}
		else{
			if(left > 0) {
				ans[c] = left;
				if(c > 0) { ans[c] += ans[c-1] - 1;  ans[c-1] = 1; }
				c++; left = 0;
			}
			else if(c > 0 && ans[c-1] > 1) {
				ans[c] = ans[c-1] - 1; ans[c-1] = 1; c++;
			}
			else { fail = 1; break; }
		}
	}
	if(left != 0) fail = 1;
	if(fail) printf("-1\n");
	else{
		for(int i = 0; i < c; i++)
			printf("%d\n",ans[i]);
	}
    return 0;
}
