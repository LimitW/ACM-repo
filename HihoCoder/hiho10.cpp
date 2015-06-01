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

string post_order(string f,string m)
{
	if(f.length() <= 1) return f;
	char root = f[0];
	string f1 = "", m1 = "";
	string ans;
	int ltree = 0;
	for(int i = 0; m[i] != root; i++)
	{
		ltree++;
		m1 += m[i];
		if(f[i+1]) f1 += f[i+1];
	}
	ans = post_order(f1,m1);
	f1 = ""; m1 = "";
	for(int i = ltree+1; i < m.length(); i++)
	{ m1 += m[i]; f1 += f[i]; }
	ans += post_order(f1,m1);
	ans += root;
	return ans;
}

int main(){
	string f,m;
	cin >> f >> m;
	cout << post_order(f,m) << endl;
	return 0;
}