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

const int maxn = 1e6 + 5;



int main(){
	int T; scanf("%d",&T);
	for(int kase = 0; kase < T; kase++){
		string s1,s2; cin >> s1 >> s2;
		int nxt[10010];
		int n1 = s1.length() , n2 = s2.length();
		nxt[0] = -1; nxt[1] = 0;
		int p = 1, q = 0 , ans = 0;
		while(p < n1){
			if(q == -1 || s1[p] == s1[q]){
				p++, q++; nxt[p] = q;
			}
			else q = nxt[q];
		}
		p = 0; q = 0;
		while(p < n2){
			if(q == -1 || s1[q] == s2[p]){
				p++; q++;
			}
			else q = nxt[q];
			if(q == n1) ans++;
		}
		printf("%d\n",ans);
	}
    return 0;
}
