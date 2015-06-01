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
	string a[3];
	a[0] = "qwertyuiop";
	a[1] = "asdfghjkl;";
	a[2] = "zxcvbnm,./";
	char o;
	cin >> o;
	int op = 1;
	if(o == 'L') op = 1;
	string t;
	cin >> t;
	for(int j = 0; j < t.size(); j++){
		for(int k = 0; k < 3; k++)
			for(int i = 0; i < 10; i++)
			{
				if(c[i] == a[k][i])
					printf("%c",a[k][i+op]);
			}
		}
	printf("\n");
	return 0;
}