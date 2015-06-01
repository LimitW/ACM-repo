//============================================================================
// Name        : B.cpp
// Author      : LimitW
// Date        : 2014.11.8
// Version     :
// Copyright   : Bestcoder #17 B
// Description : Inclusion–exclusion principle
//============================================================================
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

using namespace std;

#define LL long long
#define pii pair<int,int>
const int INF = 0x3f3f3f3f;

vector<int> G[1010];
vector<int> all_student;

int main(){
	int T; cin >> T;
	while(T--){
		int n , k;
		cin >> n >> k;
		all_student.clear();
		for(int i = 0; i < n; i++) G[i].clear();
		for(int i = 0; i < n; i++)
		{
			int m; scanf("%d",&m);
			for(int j = 0; j < m; j++)
			{
				int tmp;
				scanf("%d",&tmp);
				all_student.push_back(tmp);
				G[i].push_back(tmp);
			}
		}
		sort(all_student.begin(),all_student.end());
		LL ans_all = 0 , all_part = 0;
		for(int i = 0; i < all_student.size(); i++)
		{
			int f = k - all_student[i];
			int pos = upper_bound(all_student.begin() + i + 1,all_student.end(),f) - all_student.begin();
			if(f >= all_student[pos] && pos != G[i].size()) pos++;
			ans_all += (LL)(all_student.size() - pos);
		}
		for(int i = 0;i < n; i++)
			sort(G[i].begin(),G[i].end());
		LL ans_part = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < G[i].size(); j++){
				int f = k - G[i][j];
				int pos = upper_bound(G[i].begin() + j + 1,G[i].end(),f) - G[i].begin();
				if(f  >= G[i][pos] && pos != G[i].size()) pos++;
				ans_part += (LL)(G[i].size() - pos);
			}
		}
		LL ans = ans_all - ans_part;
		cout << ans << endl;
	}
	return 0;
}
