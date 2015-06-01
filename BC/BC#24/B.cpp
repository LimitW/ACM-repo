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

int it[4] , u[4];

int main(){
	int T; scanf("%d",&T);
	for(int kase = 0; kase < T; kase++){
		int mi = INF;
		for(int i = 0; i < 4; i++){
			scanf("%d",&it[i]);
			mi = min(mi,it[i]);
		}
		bool ok = false;
		if(mi >= 3) ok = true;
		else{
			for(int a = 0; a < 4 && !ok; a++)
				for(int b = 0; b < 4 && !ok; b++)
					for(int c = 0; c < 4 && !ok; c++){
						u[0] = a + c;
						u[1] = u[2] = a + b + c;
						u[3] =  b + c;
						for(int i = 0; i < 4; i++) {
							if(it[i] - u[i] >= 3 || it[i] == u[i]) ok = true;
							else { ok = false; break; }
						}
					}
		}
		if(ok) printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}

