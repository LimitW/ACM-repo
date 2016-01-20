#include <bits/stdc++.h>
using namespace std;

class ListeningSongs{
public:
int listen(vector <int> durations1, vector <int> durations2, int minutes, int T){
	sort(durations1.begin(), durations1.end());
	sort(durations2.begin(), durations2.end());
	int time = minutes * 60;
	if(T > durations1.size() || T > durations2.size())
		return -1;
	for(int i = 0; i < T; ++i){
		time -= durations1[i];
		time -= durations2[i];
	}
	if(time < 0)
		return -1;
	vector<int> c; c.clear();
	for(int i = T; i < durations1.size(); ++i)
		c.push_back(durations1[i]);
	for(int i = T; i < durations2.size(); ++i)
		c.push_back(durations2[i]);
	sort(c.begin(), c.end());
	int cnt = 0;
	while(cnt < c.size() && time >= c[cnt]){
		time -= c[cnt++];
	}
	return 2 * T + cnt;
}
};
