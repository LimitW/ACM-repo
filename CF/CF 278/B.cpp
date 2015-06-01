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

int a[5] , vis[5];
int main(){
	int n; scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int fail = 1;
	if(n == 0) { a[0] = 1; a[1] = 1; a[2] = 3; a[3] = 3; fail = 0; }
	else if(n == 1){ a[1] = a[0]; a[2] = 4*a[0] - a[1]; a[3] = 3*a[0]; fail = 0; vis[0] = 1; }
	else if(n == 2){
		if(4*a[0] - a[1] >= a[1] && 3*a[0] >= 4*a[0] - a[1]){ a[2] = 4*a[0] - a[1]; a[3] = 3*a[0]; fail = 0; vis[0] = vis[1] = 1;} // 1,2
		else if(a[1] == 3*a[0]) { a[3] = a[1]; a[1] = a[0]; a[2] = 4*a[0] - a[1]; fail = 0; vis[0] = vis[3] = 1; }//1,4
		else if(4 * a[0] - a[1] >= a[0] && 3*a[0] >= 4*a[0] - a[1]) { a[2] = a[1]; a[1] = 4*a[0] - a[2]; a[3] = 3*a[0]; fail = 0; vis[0] = vis[2] = 1; }//1,3,
		else if((a[0] + a[1]) % 4 == 0 && (a[0] + a[1]) / 4 <= a[0] && 3*(a[1] + a[0])/4 >= a[1])
		{ a[2] = a[1]; a[1] = a[0]; a[0] = (a[1]+a[2]) / 4; a[3] = 3*a[0]; fail = 0; vis[1] = vis[2] = 1; }//2,3
		else if(a[1] % 3 == 0 && 4 * a[1] / 3 - a[0] >= a[0] && 4*a[1] / 3 - a[0] <= a[1] && a[0] / 3 <= a[0]) //2,4
		{
			a[3] = a[1]; a[1] = a[0]; a[0] = a[3] / 3; a[2] = 4*a[0] - a[1]; fail = 0; vis[1] = vis[3] = 1;
		}
		else if(a[1] % 3 == 0) // 3,4
		{
			a[3] = a[1]; a[2] = a[0]; a[0] = a[3] / 3; a[1] = 4*a[0] - a[2];
			if(a[1] <= a[2] && a[0] <= a[1]) { fail = 0; vis[2] = vis[3] = 1; }
		}
	}
	else if(n == 3){
		if(a[2] == 4*a[0] - a[1] && 3*a[0] >= a[2]) { a[3] = 3*a[0]; fail = 0; vis[0] = vis[1] = vis[2] = 1; } //1,2,3
		else if(a[2] == 3*a[0] && 4*a[0] - a[1] >= a[1] && 4*a[0] - a[1] <= a[2]) { a[3] = a[2]; a[2] = 4*a[0] - a[1]; fail = 0; vis[1] = vis[0] = vis[3] = 1;  }//1,2,4
		else if(a[2] == 3*a[0] && a[0] + a[2] - a[1] >= a[0] && a[0] + a[2] - a[1] <= a[1]) { a[3] = a[2]; a[2] = a[1]; a[1] = a[0]+a[3]-a[2]; fail = 0; vis[0] = vis[2] = vis[3] = 1;  }//1,3,4
		else if((a[1] + a[0]) % 4 == 0 && a[2] % 3 == 0) {
			a[3] = a[2]; a[2] = a[1]; a[1] = a[0]; a[0] = a[3] / 3;
			if(a[0] <= a[1]) { fail = 0; vis[1] = vis[2] = vis[3] = 1; }
		}//2,3,4
	}
	else if(n == 4){
		if(a[2] == 4*a[0] - a[1] && a[3] == 3*a[0]){ fail = 0; vis[0] = vis[1] = vis[2] = vis[3] = 1; }
	}
	if(fail){ printf("NO\n"); }
	else{
		printf("YES\n");
		for(int i = 0; i < 4; i++)
			if(!vis[i]) printf("%d\n",a[i]);
	}
    return 0;
}
