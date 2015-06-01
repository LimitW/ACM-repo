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

const string yes = "Possible";
const string no = "Impossible";

class ShufflingCardsDiv2{
public:
	string shuffle(vector<int> permutation)
	{
		int n = permutation.size();
		int p1 = 0 , p2 = 0;
		for(int i = 0; i < n; i++){
			if(permutation[i] <= n / 2){
				if((i+1)% 2 == 0) p2++;
				else p1++;
			}
		}
		if(p1 == (n+2)/4 && p2 == n/4) return yes;
		else return no;
	}
};