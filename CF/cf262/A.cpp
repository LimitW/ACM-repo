/*
 * Title:
 * Author:LimitW
 * Date:2014.8.21
 * Source:Codeforces round 262 A
 * Note:水题
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

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int i = 1;
	for(;;){
		if(n <= 0)
			break;
		if(i % m == 0)
			n++;
		n-=1;
		i++;
	}
	printf("%d\n",i-1);
	return 0;
}