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

const long long MAX_INT = 2147483647;

map< long long,vector<long long> > mp;

int main(){
	int n , kase = 0;
	while( (cin >> n) != NULL){
		mp.clear();
		for(int i = 0; i < n; i++)
		{
			long long val; cin >> val;
			mp[val].push_back(i);
		}
		if(mp.size() == 1) { printf("Case #%d: -1\n",++kase); continue; }
		int ans = 0;
		map< long long,vector<long long> >::iterator it , L , R;
		for(it = mp.begin(); it != mp.end(); ++it){
			map< long long,vector<long long> >::iterator tmp = ++it; it--;
			if(tmp == mp.end()){
				R = mp.begin();
				if(mp.size() == 2) L = R;
				else { L = --it; it++; }
			}
			else if(it == mp.begin()){
				R = tmp; L = mp.end(); L--;
			}
			else{
				R = tmp; L = --it; ++it;
			}
			if( ( it->first + L->first) % MAX_INT == R->first)
				ans += it->second.size();
		}
		printf("Case #%d: %d\n",++kase,ans);
	}
    return 0;
}
