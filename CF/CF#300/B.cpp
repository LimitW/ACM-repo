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
const long long INFL = 1LL << 62;

vector<int> p;
vector<pii> d;

int main(){
	string s; cin >> s;
	for(int i = 0; i < s.length(); ++i){
		d.push_back(make_pair(s[i]-'0',i));
	}
	sort(d.begin(),d.end());
	int ans = d[s.length()-1].first,  x;
	for(int i = 0; i < ans; ++i){
		string k = ""; x = 0;
		for(int j = 0; j < s.length(); ++j){
			if(s[j] > '0') { --s[j]; x = 10 * x + 1; }
			else if(x != 0) x = 10 * x;
		}
		p.push_back(x);
	}
	printf("%d\n",ans);
	for(int i = p.size()-1; i >= 0; --i)
		printf("%d%c", p[i] , i == 0 ? '\n' : ' ');
    return 0;
}

