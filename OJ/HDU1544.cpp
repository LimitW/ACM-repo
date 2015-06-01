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
int hs[5010];

int main(){
		char s[5010] , sh[5010];
		while(~scanf("%s",s)){
		memset(hs,0,sizeof(hs));
		int n = strlen(s) , c = 0 , ans = 0;
		sh[0] = s[0]; ++hs[0];
		for(int i = 1; i < n; i++){
			if(s[i] != sh[c]) sh[++c] = s[i];
			++hs[c];
		}
		for(int i = 0; i <= c; ++i){
			int l = i , r = i;
			while(l >= 0 && r <= c && sh[l] == sh[r] && hs[l] == hs[r]){
				ans +=  (l == r ? hs[l] * (hs[r] + 1) / 2 : hs[l]);
				l--; r++;
			}
			if(l >= 0 && r <= c && sh[l] == sh[r] && hs[l] != hs[r]){
				ans += min(hs[r] , hs[l]);
			}
			l = i , r = i + 1;
			while(l >= 0 && r <= c && sh[l] == sh[r] && hs[l] == hs[r]){
				ans += hs[l];
				l--; r++;
			}
			if(l >= 0 && r <= c && sh[l] == sh[r] && hs[l] != hs[r])
				ans += min(hs[l],hs[r]);
		}
		printf("%d\n",ans);
	}
    return 0;
}

