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
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

int main(){
	int bits[110] = {0};
	int m,s;
	cin >> m >> s;
	if(9*m < s || (1 > s && m > 1)){
		cout << -1 << ' ' << -1 << endl;
		return 0;
	}
	int res = s;
	if(s > 0) { bits[0] = 1; res = s - 1; }
	for(int i = m-1; i > 0; i--)
	{
		if(res >= 9) { bits[i] = 9; res -= 9; }
		else{ bits[i] = res; res = 0; break; }
	}
	if(res != 0) bits[0] += res;
	for(int i = 0; i < m; i++)
			cout << bits[i];
	cout << ' ';
	memset(bits,0,sizeof(bits));
	res = s;
	if(res >= 9) { res -= 9; bits[0] += 9;}
	else { bits[0] += res; res = 0; }
	for(int i = 1; i < m; i++){
		if(res >= 9) { bits[i] += 9; res -= 9; }
		else{ bits[i] += res; break; }
	}
	for(int i = 0; i < m; i++)
		cout << bits[i];
	cout << endl;
	return 0;
}
