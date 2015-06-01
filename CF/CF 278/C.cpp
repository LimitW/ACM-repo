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

int h1,a1,d1,h2,a2,d2,ph,pa,pd;

int w(int a,int d)
{
	int _h1 = h1 , _h2 = h2;
	if(a <= d2) return INF;
	while(1){
		_h2 -= a - d2;
		_h1 -= max(a2 - d,0);
		if(_h2 <= 0) break;
	}
	int ans = (a - a1) * pa + (d - d1) * pd;
	if(_h1 <= 0) ans += (1 - _h1) * ph;
	return ans;
}

int main(){
	cin >> h1 >> a1 >> d1 >> h2 >> a2 >> d2 >> ph >> pa >> pd;
    int ans = INF;
	for(int a = a1; a <= 200; a++)
    	for(int d = d1; d <= 200; d++)
    		ans = min(ans,w(a,d));
	cout << ans << endl;
	return 0;
}
