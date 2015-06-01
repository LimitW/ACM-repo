/*
ID: LimitW
PROG: barn1
LANG: C++11
*/

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
#include <fstream>

using namespace std;

const int INF = 0x3f3f3f3f;
int a[210];
pair<int,int> res[210];
vector<int> pos;

int main(){
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
	int m,s,c;
	scanf("%d%d%d",&m,&s,&c);
	for(int i = 1; i <= c; i++)
		scanf("%d",&a[i]);
	if(m >= c){ printf("%d\n",c); return 0; }
	sort(a+1,a+c+1);
	if(m == 1) { printf("%d\n",a[c]-a[1]+1); return 0; }
	for(int i = 1; i < c; i++){
		res[i].first = a[i+1] - a[i] - 1;
		res[i].second = i;
	}
	sort(res+1,res+c);
	for(int i = 0; i < m-1; i++)
		pos.push_back(res[c-i-1].second);
	sort(pos.begin(),pos.end());
	int cnt = a[pos[0]] - a[1] + 1;
	for(int i = 1; i < pos.size(); i++)
		cnt += a[pos[i]] - a[pos[i-1]+1] + 1;
	cnt += a[c] - a[*(pos.end()-1)+1] + 1;
	printf("%d\n",cnt);
    return 0;
}
