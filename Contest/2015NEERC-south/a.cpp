#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

struct node{
	string ori, login, domain;
	node(string a = ""):ori(a){
		int n = a.length();
		string x[2];
		x[0] = x[1] = "";
		bool at = 0;
		for(int i = 0; i < n; ++i){
			if(a[i] == '.'){
				x[at] += a[i];
			}
			else if(a[i] >= 'A' && a[i] <= 'Z'){
				x[at] += a[i] - 'A' + 'a';
			}
			else if(a[i] >= 'a' && a[i] <= 'z'){
				x[at] += a[i];
			}
			else if(a[i] == '@') at = 1;
		}
		login = x[0], domain = x[1];
		if(domain == "bmail.com"){
			login = "";
			for(int i = 0; i < n; ++i){
				if(a[i] == '@' || a[i] == '+') break;
				else if(a[i] >= 'A' && a[i] <= 'Z'){
					login += a[i] - 'A' + 'a';
				}
				else if(a[i] >= 'a' && a[i] <= 'z'){
					login += a[i];
				}
			}
		}
	}
	bool operator < (node b) const {
		pair<string, string> x = make_pair(domain, login),
				y = make_pair(b.domain, b.login);
		return x < y || (x == y && ori < b.ori);
	}
	bool operator == (node b) const {
		return login == b.login && domain == b.domain;
	}
}s[20010];

int ans[20010];

int main(){
	int n; cin >> n;
	string c;
	for(int i = 0; i < n; ++i){
		cin >> c;
		s[i] = node(c);
	}
	sort(s, s + n);
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		ans[cnt] = 0;
		int j = i;
		while(s[j] == s[i] && j < n){
			++j, ++ans[cnt];
		}
		i = j - 1;
		++cnt;
	}
	cout << cnt << '\n';
	for(int i = 0, j = 0; j < cnt; ++j){
		cout << ans[j] << ' ';
		while(ans[j]--){
			if(ans[j] != 0) cout << s[i].ori << ' ';
			else cout << s[i].ori << '\n';
			++i;
		}
	}
	return 0;
}

