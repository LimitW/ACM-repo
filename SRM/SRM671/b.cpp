#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6;

int hs[maxn + 2];

class BearDartsDiv2{
public:
long long count(vector <int> w){
	memset(hs, 0, sizeof(hs));
	int n = w.size();
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j)
			if(w[j] % w[i] == 0)
				ans += hs[w[j]/w[i]];
		for(int j = 0; j < i; ++j)
			if(1ll*w[j]*w[i] <= maxn)
				++hs[w[j]*w[i]];
	}
	return ans;
}
};
