/************************************************
 * Title :
 * Author : LimitW
 * Date : 2014.10.18
 * Source : BestCoder #14 A
 * Note : 
*************************************************/

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

const int INF = 0x3f3f3f3f;

int main(){
	LL v,v0;
	while(scanf("%I64d%I64d",&v,&v0))
	{
		printf("%I64d\n",2*v-v0);
	}
	return 0;
}
