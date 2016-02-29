#include <bits/stdc++.h>
using namespace std;
class MoveStonesEasy{
public:
int get(vector <int> a, vector <int> b){
	int n = a.size();
	int sum1 = 0, sum2 = 0;
	for(int i = 0; i < n; ++i) sum1 += a[i];
	for(int i = 0; i < n; ++i) sum2 += b[i];
	if(sum1 != sum2) return -1;
	if(n <= 2) return abs(a[0] - b[0]);
	int ans = 0;
	for(int i = 0; i < n - 1; ++i){
		ans += abs(a[i] - b[i]);
		a[i+1] -= b[i] - a[i];
	}
	return ans;
}
};
