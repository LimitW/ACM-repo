#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

bool isprime(int x){
	for(int j = 2; j * j <= x; ++j)
		if(x % j == 0) return 0;
	return 1;
}

int main(){
	int n; cin >> n;
	int cnt = 0;
	while(!isprime(n)) ++cnt, --n;
	if(cnt == 0){
		cout << "1" << '\n';
		cout << n + cnt << '\n';
	}
	else if(isprime(cnt)){
		cout << "2" << '\n';
		cout << cnt << ' ' << n << '\n';
	}
	else{
		for(int i = 2; i < cnt; ++i){
			if(isprime(cnt - i) && isprime(i)){
				cout << "3" << '\n';
				cout << i << ' ' << cnt - i << ' ' << n << '\n';
				return 0;
			}
		}
	}
    return 0;
}

