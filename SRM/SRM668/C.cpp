#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);

long long gcd(long long a, long long b){
	return b == 0 ? a : gcd(b, a % b);
}

int f[2010], dp[2010][2010], hs[1000010];

class AnArray{
public:
	int solveProblem(vector <int> A, int K){
		int n = A.size();
		int l = 0;
		for(int i = 1; i * i <= K; ++i){
			if(K % i == 0){
				f[l++] = i;
				hs[i] = l - 1;
				if(i * i != K){
					f[l++] = K / i;
					hs[K / i] = l - 1;
				}
			}
		}
		memset(dp, 0, sizeof(dp));
		for(int i = n - 1; i >= 0; --i)
			for(int j = 0; j < l; ++j){
				if(A[i] % f[j] == 0) dp[i][j] = 1;
				dp[i][j] += dp[i+1][j];
			}
		long long ans = 0;
		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j < n; ++j){
				long long x = gcd((LL)A[i]*A[j], K);
				ans += dp[j+1][hs[K/x]];
			}
		return ans;
	}
};

