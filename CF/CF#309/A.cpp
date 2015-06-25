#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
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
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

int main(){
	map<string,int> mp;
	string s; cin >> s;
	for(int i = 0; i < 26; ++i){
		for(int j = 0; j <= s.length(); ++j){
			string ss = s;
			ss = ss.insert(j,1,(char)(i+'a'));
			++mp[ss];
		}
	}
	cout << mp.size() << '\n';
	return 0;
}

