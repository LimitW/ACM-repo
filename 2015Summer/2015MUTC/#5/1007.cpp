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
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 3;

int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int main(){
	multiset<int> x;
    int n;
    while(~scanf("%d",&n)){
    	x.clear();
    	for(int i = 0; i < n; ++i){
    		int op; scanf("%d",&op);
    		if(op == 1){
    			int tmp; scanf("%d",&tmp);
    			x.insert(tmp);
    		}
    		else if(op == 2){
    			if(x.size() != 0){
    				x.erase(x.begin());
    			}
    		}
    		else{
    			int ans = 0;
    			if(x.size() != 0){
    				multiset<int>::iterator it = x.end();
    				--it;
    				ans = *it;
    			}
    			printf("%d\n",ans);
    		}
    	}
    }
	return 0;
}

