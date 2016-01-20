#include <bits/stdc++.h>

using namespace std;

long long a[100010];
long long sum[100010];

int main(){
	int T; scanf("%d", &T);
	sum[0] = 0;
	for(int kase = 1; kase <= T; ++kase){
		int N; long long P;
		scanf("%d%lld", &N, &P);
		for(int i = 0; i < N; ++i){
			scanf("%lld", &a[i]);
			sum[i+1] = sum[i] + a[i];
		}
		long long ans = 0;
		for(int i = 1; i <= N; ++i){
			ans += (long long)(upper_bound(sum + i, sum + N + 1, P + sum[i-1]) - sum - i);
		}
		printf("Case #%d: %lld\n", kase, ans);
	}
	return 0;
}
