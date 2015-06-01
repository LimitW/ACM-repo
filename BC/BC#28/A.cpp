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

int a[1010];

int main(){
	int T; scanf("%d",&T);
	for(int kase = 0; kase < T; kase++){
		memset(a,0,sizeof(a));
		int n; scanf("%d",&n);
		int ma = -1;
		for(int i = 0; i < n; i++){
			int tmp; scanf("%d",&tmp);
			a[tmp] = 1; ma = max(ma,tmp);
		}
		int l[5] , c = 0;
		for(int i = 1; i <= ma; i++){
			if(a[i] == 0) l[c++] = i;
		}
		if(c == 0){
			l[0] = ma+1; l[1] = ma+2;
		}
		if(c == 1) l[1] = ma+1;
		printf("%d %d\n",l[0],l[1]);
	}
	return 0;
}
