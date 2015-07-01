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

int a[3],b[3];

int main(){
	int n; cin >> n;
	for(int i = 0; i < 3; ++i){
		cin >> a[i] >> b[i];
	}
	for(int z = min(n-a[0]-a[1],b[2]); z >= a[2]; --z)
		for(int j = min(n-z-a[0],b[1]); j >= a[1],; --j){
			if(n - z - j >= a[0] && n - z - j <= b[0]){
				printf("%d %d %d\n",n-j-z,j,z);
				return 0;
			}
		}
    return 0;
}