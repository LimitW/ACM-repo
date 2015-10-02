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
const int maxn = 2e5 + 10;

int feed[maxn];
int pos[maxn];
map<pii,bool> mp;
vector<pii> vec;

int main(){
	freopen("intouch.in","r",stdin);
	freopen("intouch.out","w",stdout);
	int n,m;
	while( scanf("%d %d%*c",&n,&m) != EOF){
        mp.clear(); vec.clear();
		memset(pos,0,sizeof(pos));
		memset(feed,0,sizeof(feed));
		char op;
		int x,y;
		for(int t = 0; t < m; t++) {
			op = getchar();
			if(op == '!'){
				scanf(" %d%*c", &x); pos[x]++;
			}
			else if(op == '+')
			{
				scanf(" %d %d%*c",&x,&y);
				if(x > y) swap(x,y);
				if( !mp[make_pair(x,y)] ){
					feed[x] -= pos[y]; feed[y] -= pos[x];
					mp[make_pair(x,y)] = true;
					vec.push_back(make_pair(x,y));
				}
			}
			else if(op == '-')
			{
				scanf(" %d %d%*c",&x,&y);
				if(x > y) swap(x,y);
				if( mp[make_pair(x,y)] ){
					feed[x] += pos[y]; feed[y] += pos[x];
					mp[make_pair(x,y)] = false;
				}
			}
		}
		for(int i = 0; i < vec.size(); i++)
			if( mp[ vec[i] ] ) {
				int x = vec[i].first , y = vec[i].second;
				feed[ vec[i].first ] += pos[ vec[i].second ]; feed[ vec[i].second ] += pos[ vec[i].first ];
				mp[ vec[i] ] = false;
			}
		for(int i = 1; i < n; i++)
			printf("%d ",feed[i]);
		printf("%d\n",feed[n]);
	}
	return 0;
}
