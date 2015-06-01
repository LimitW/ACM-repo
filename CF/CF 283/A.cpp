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

int a[110];

int main(){
	int n; scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	int ans = INF;
	for(int i = 1; i < n - 1; i++){
		int tmp = a[0] , dif = 0;
		for(int j = 1; j < n; j++){
			if(j == i) continue;
			dif = max(dif,a[j]-tmp);
			tmp = a[j];
		}
		ans = min(ans,dif);
	}
	printf("%d\n",ans);
    return 0;
}
