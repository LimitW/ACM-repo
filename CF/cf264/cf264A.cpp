/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.8.30
 * Source:
 * Note:
*************************************************/

#include <iostream>
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
#include <bitset>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int sugar[110];

int main(){
	int n,s;
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		int x,y;
		cin >> x >> y;
		sugar[i] = x*100+y;
	}
	sort(sugar,sugar+n);
	int ans = 0;
	if(s * 100 < sugar[0])
		printf("-1\n");
	else{
		for(int i = 0; i < n; i++){
			if(sugar[i] <= s * 100){
				int t = s*100 - sugar[i];
				t %= 100;
				ans = max(ans,t);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}