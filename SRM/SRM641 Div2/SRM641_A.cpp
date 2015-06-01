/************************************************
 * Title:
 * Author:LimitW
 * Date:
 * Source:
 * Note:
*************************************************/

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

using namespace std;

const int INF = 0x3f3f3f3f;


class BuyingTshirts{
public:
	int meet(int T,vector<int> Q,vector<int> P){
		vector<int> q,p;
		int ans = 0 , qleft = 0, pleft = 0;
		for(int i = 0; i < Q.size(); i++){
			qleft += Q[i];
			pleft += P[i];
			if(qleft >= T){
				qleft -= T; q.push_back(i);
			}
			if(pleft >= T){
				pleft -= T; p.push_back(i);
			}
		}
		for(int i = 0, j = 0; i < q.size() && j < p.size(); ){
			if(q[i] == p[j]){ ans++; i++; j++; }
			else if(q[i] > p[j]) { j++; }
			else { i++; }
		}
		return ans;
	}
};