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

struct aa{
	int v,x;
	bool operator < (aa b){
		return x < b.x;
	}
}a[110];

int main(){
	int n; cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i].x >> a[i].v;
	}
	sort(a,a+n);
	int tmp = -1;
	for(int i = 0; i < n; ++i){
		if(a[i] > 0) tmp = i;
	}
	int ans = 0;
	if(tmp == 0) ans = a[0].v;
	else if(tmp == -1) ans = a[n-1].v;
	else{
		for(int i = tmp-1,j=tmp+1; i >= 0 && j < n; --i,++j){
			ans += a[i].v;
			ans += a[j].v;
		}
	}
	cout << ans << '\n';
    return 0;
}
