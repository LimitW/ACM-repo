#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, t;
	cin >> n >> t;
	int cnt = 0;
	string s = "";
	while(t > 0){
		s += t % 10 + '0';
		++cnt;
		t /= 10;
	}
	reverse(s.begin(), s.end());
	if(cnt > n) cout << "-1" << '\n';
	else if(cnt == n) cout << s << '\n';
	else {
		n -= cnt;
		for(int i = 0; i < n; ++i)
			s += '0';
		cout << s << '\n';
	}
	return 0;
}
