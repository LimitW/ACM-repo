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

LL a[1010];

int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		LL t1 = 0 , t2 = 0;
		for(int i = 1; i <= n; i++){
			scanf("%I64d",&a[i]);
			if(i % 2 != 0) t1+=a[i];
			else t2+=a[i];
		}
		if(t1 != t2) { printf("No\n"); continue; }
		bool is_good = 1;
		for(int i = 1 , j = n; i <= j; i++,j--)
			if(a[i] != a[j]) { is_good = 0; break; }
		if(!is_good) printf("Yes\n"); else printf("No\n");
	}
    return 0;
}
