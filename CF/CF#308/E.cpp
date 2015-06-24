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

vector<int> x;

LL sp;

LL calc(string a){
	int n = a.length();
	LL ans = 0;
	stack<LL> st;
	while(!st.empty()) st.pop();
	for(int i = 0; i < n; ++i){
		if(a[i] >= '0' && a[i] <= '9')
			st.push((LL)(a[i]-'0'));
		else if(a[i] == '*'){
			LL u = st.top(); st.pop();
			if(a[i+1] == 'x') u *= sp;
			else u *= (LL)(a[i+1] - '0');
			st.push(u);
			++i;
		}
	}
	while(!st.empty()){
		ans += st.top();
		st.pop();
	}
	return ans;
}

int main(){
	string s; cin >> s;
	s = "1*" + s + "*1"; //wa
	int n = s.length();
	LL ans = calc(s);
	for(int i = 0; i < n; ++i)
		if(s[i] == '*') x.push_back(i);
	int sz = x.size();
	for(int i = 0; i < sz; ++i)
		for(int j = i+1; j < sz; ++j){
			int l = x[i] , r = x[j];
			if(l + 1 == r - 1) continue;
			sp = calc(s.substr(l+1,r-l-1)); // start , length
			string ss = s.substr(0,l+1) + "x" + s.substr(r);
			ans = max(ans,calc(ss));
		}
	cout << ans << '\n';
	return 0;
}

