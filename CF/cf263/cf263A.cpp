/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.8.27
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

char m[110][110];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			cin >> m[i][j];
		}
	int flag = 1;
	int sum = 0;
	for(int i = 0; i < n && flag; i++)//r
		for(int j = 0; j < n && flag; j++){//c
			if(j < n - 1 && m[i][j+1]=='o') sum++;
			if(j > 0 && m[i][j-1]=='o') sum++;
			if(i > 0 && m[i-1][j]=='o') sum++;
			if(i < n - 1 && m[i+1][j]=='o') sum++;
			if(sum % 2 != 0) flag = 0;
			sum = 0;
		}
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}