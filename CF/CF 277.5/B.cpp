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

int a[110],b[110];
int n,m;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	for(int i = 0; i < m; i++)
		cin >> b[i];
	sort(a,a+n);sort(b,b+m);
	int ans = 0;
	int i ,j;
	for(i = 0 , j = 0; i < n && j < m;)
	{
		if(abs(a[i]-b[j]) <=1) { i++; j++; ans++;}
		else if(a[i] < b[j] - 1) i++;
		else if(a[i] > b[j] + 1) j++;
	}
	cout << ans << endl;
	return 0;
}


