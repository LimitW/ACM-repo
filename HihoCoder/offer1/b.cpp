#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

int n;
long long q;
int a[maxn];

bool solve(int v){
	priority_queue<int> pq;
	while(!pq.empty()) pq.pop();
	int cnt = v;
	long long res = 0;
	int no = 1;
	for(int i = 0; i < n; ++i){
		if(cnt == 0){
			res += 1ll * pq.top() * no;
			pq.pop();
			pq.push(a[i]);
			no++;
		}
		else{
			pq.push(a[i]);
			cnt--;
		}
	}
	while(!pq.empty()){
		res += 1ll * pq.top() * no;
		no++;
		pq.pop();
	}
	return res <= q;
}

int main(){
	scanf("%d%lld", &n, &q);
	for(int i = 0; i < n; ++i){
		scanf("%d", a + i);
	}
	solve(1);
	int l = 1, r = n, ans = r;
	while(l <= r){
		int mid = l + r >> 1;
		if(solve(mid)){
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	if(!solve(ans)) ans = -1;
	cout << ans << '\n';
	return 0;
}

