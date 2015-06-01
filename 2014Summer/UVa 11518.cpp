/*
 * Title:Dominos 2
 * Author:LimitW
 * Date:
 * Source:UVa 11518
 * Note:dfs vector
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
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>

using namespace std;
const int MAXN = 10010;
int dominos[10010];
vector<int> net[10010];
void push(int key){
	if(key < 1 || key > MAXN) return;
	else if(dominos[key] == -1) return;
	else dominos[key] = -1;
	if(!net[key].empty()){
		vector<int>::iterator it = net[key].begin();
		for(;it!=net[key].end();it++)
			push(*it);
	}
}

int main(){
	int T;
	cin>>T;
	while(T--){
		memset(dominos,0,sizeof(dominos));
		int n,m,l;
		cin>>n>>m>>l;
		int i;
		for(i=1;i<=n;i++)
			net[i].clear();
		for(i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			net[x].push_back(y);
		}
		int ans = 0;
		for(i=0;i<l;i++){
			int knock_no;
			cin>>knock_no;
			push(knock_no);
		}
		for(i=1;i<=n;i++){
			if(dominos[i] == -1) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}