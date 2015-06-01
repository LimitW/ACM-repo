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

const int INF = 0x3f3f3f3f;

int main(){
	LL a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a,a+3);
	if(a[0]*2 + a[1]*2 < a[2]) cout << a[0] + a[1] << endl;
	else cout << (a[0] + a[1] + a[2])/3 << endl;
    return 0;
}
