#include <bits/stdc++.h>
using namespace std;

class Cdgame{
public:
int rescount(vector <int> a, vector <int> b){
	int n = a.size(), m = b.size();
	map<int, int> mp;
	mp.clear();
	for(int i = 0; i < n; ++i)
	for(int j = 0; j < m; ++j){
		swap(a[i], b[j]);
		int x = 0, y = 0;
		for(int k = 0; k < n; ++k)
			x += a[k];
		for(int k = 0; k < m; ++k)
			y += b[k];
		mp[x*y]++;
		swap(a[i], b[j]);
	}
	map<int, int>::iterator it = mp.begin();
		int cnt = 0;
		for(; it != mp.end(); ++it)
			++cnt;
		return cnt;
}
};
