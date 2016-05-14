#include <bits/stdc++.h>

using namespace std;

bool a[110];

int main(){
	int T; cin >> T;
	for(int kase = 1; kase <= T; ++kase){
		string s; cin >> s;
		int n = s.length();
		for(int i = 0; i < n; ++i){
			a[i] = s[i] == '+';
		}
		int ans = 0;
		for(int i = n - 1; i >= 0; --i){
			if(a[i]) continue;
			++ans;
			for(int j = i; j >= 0; --j)
				a[j] = !a[j];
		}
		printf("Case #%d: %d\n", kase, ans);
	}
    return 0;
}

