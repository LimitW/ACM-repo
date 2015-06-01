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

string s[110];
bool is_ok[110];

int main(){
	memset(is_ok,0,sizeof(is_ok));
	int n,m; scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++)
		cin >> s[i];
	int cnt = 0;
	for(int i = 0; i < m; i++){
		int ok = 0; vector<int> v;
		for(int j = 1; j < n; j++){
			if(is_ok[j]) continue;
			if(s[j-1][i] > s[j][i]){
				cnt++; ok = 0;
				for(int k = 0; k < v.size(); k++)
					is_ok[v[k]] = 0;
				break;
			}
			else if(s[j-1][i] > s[j][i]) { ok = 1; is_ok[j] = 1; v.push_back(j); }
			else if(s[j-1][i] == s[j][i]) ok = 0;
		}
		if(ok) break;
	}
	printf("%d\n",cnt);
    	return 0;
}

