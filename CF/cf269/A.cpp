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

int main(){
	int a[7];
	for(int i = 0; i < 6; i++)
		cin >> a[i];
	sort(a,a+6);
	if(a[0] == a[1] && a[1] == a[2] && a[2] == a[3]){
		if(a[4] < a[5]) printf("Bear\n");
		if(a[4] == a[5]) printf("Elephant\n");
	}
	else if(a[1] == a[2] && a[2] == a[3] && a[3] == a[4]){
		if(a[0] < a[5]) printf("Bear\n");
		if(a[0] == a[5]) printf("Elephant\n");
	}
	else if(a[2] == a[3] && a[3] == a[4] && a[4] == a[5]){
		if(a[0] < a[1]) printf("Bear\n");
		if(a[0] == a[1]) printf("Elephant\n");
	}
	else
		printf("Alien\n");
	return 0;
}