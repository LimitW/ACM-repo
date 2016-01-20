#include <bits/stdc++.h>

using namespace std;

set<int> vals;
vector<vector<pair<int, int> > > scs;
vector<string> name;

vector<pair<int,int> > solve(string s){
	vector<pair<int,int> > res;
	res.clear();
	int i = 0;
	string x = "";
	while(s[i] != ' '){
		x += s[i];
		++i;
	}
	name.push_back(x);
	++i;
	while(i < s.length()){
		int v = 0, t = 0;
		while(s[i] != '/'){
			v = v * 10 + s[i] - '0';
			++i;
		}
		++i;
		while(i < s.length() && s[i] != ' '){
			t = t * 10 + s[i] - '0';
			++i;
		}
		++i;
		res.push_back(make_pair(v, t));
		if(t != 0) vals.insert(t + 1);
	}
	return res;
}

int solve2(vector<pair<int, int> > s, int time){
	int sc = 0;
	for(int i = 0; i < s.size(); ++i){
		if(s[i].second < time)
			sc += s[i].first;
	}
	return sc;
}

class ContestScoreboard{
public:
vector <int> findWinner(vector <string> scores){
	scs.clear();
	vals.clear();
	vals.insert(1);
	name.clear();
	vector<int> c;
	for(int i = 0; i < scores.size(); ++i)
		c.push_back(0);
	for(int i = 0; i < scores.size(); ++i){
		scs.push_back(solve(scores[i]));
	}
	for(auto curval : vals){
		int res = 0;
		int curv = solve2(scs[0], curval);
		for(int i = 1; i < scores.size(); ++i){
			int vv = solve2(scs[i], curval);
			if(vv > curv || (vv == curv && name[i] < name[res])){
				res = i;
				curv = vv;
			}
		}
		c[res] = 1;
	}
	return c;
}
};
