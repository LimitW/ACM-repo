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


int main(){
	double n,m,x,y;
	cin >> n >> m;
	int ans = 0;
	if(n / 2 >= m) {
		ans = m;
	}
	else if(n >= m / 2){
		x = 2*m - n; x = (int) (x / 3);
		int nn = n - x , mm = m - 2*x;
		ans = x + min(nn/2,mm);
		y = 2*n - m; y = (int) (y / 3);
		nn = n - 2*y; mm = m - y;
		ans = max( (int)y + min(nn,mm/2), ans);
	}
	else {
		ans = n;
	}
	printf("%d\n",ans);
    return 0;
}
