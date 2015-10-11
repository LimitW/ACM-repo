#include <bits/stdc++.h>
using namespace std;

int pre[52];

class Drbalance{
public:
int lesscng(string s, int k){
	memset(pre, 0, sizeof(pre));
	int n = s.length();
	int cnt = 0;
	if(s[0] == '+') pre[0] = 1, cnt++;
	else pre[0] = -1;
	for(int i = 1; i < n; ++i){
		if(s[i] == '+') pre[i] = pre[i-1] + 1;
		else pre[i] = pre[i-1] - 1;
		if(pre[i] >= 0) cnt++;
	}
	k = n - k;
	if(cnt >= k) return 0;
	int ans = 0;
	for(int i = 0; i < n && cnt < k; ++i){
		if(s[i] == '-'){
			++ans;
			for(int j = i; j < n; ++j){
				pre[j] += 2;
				if(pre[j] - 2 < 0 && pre[j] >= 0) ++cnt;
			}
		}
	}
	return ans;
}
};
