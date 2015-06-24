#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
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
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

int main(){
	LL n , m , tmp = n;
	cin >> n >> m;
	while(1){
		if(m == 1){
			puts("YES"); return 0;
		}
		if((m - 1) % n == 0){
			m = (m - 1) / n;
		}
		else if((m + 1) % n == 0){
			m = (m + 1) / n;
		}
		else if(m % n == 0){
			m /= n;
		}
		else {
			puts("NO"); return 0;
		}
	}
    return 0;
}

