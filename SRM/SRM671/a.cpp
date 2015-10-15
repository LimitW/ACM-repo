#include<bits/stdc++.h>
using namespace std;

class BearPaints{
public:
long long maxArea(int W, int H, long long M){
	long long ans = 0;
	if(W > H) swap(W,H);
	long long a = W, b = H;
	long long s = 0;
	for(long long i = 1; i <= a; ++i){
		long long l = 1, r = b;
		while(l <= r){
			long long mid = l + r >> 1;
			if(1ll * mid * i > M){
				r = mid - 1;
			}
			else {
				s = max(s, 1ll * mid * i);
				l = mid + 1;
			}
		}
	}
	return s;
}
};
