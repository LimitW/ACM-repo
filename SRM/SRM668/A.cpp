#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);

class VerySecureEncryption{
public:
	string encrypt(string message, vector <int> key, int K){
		char k[52][2];
		for(int i = 0; i < message.length(); ++i)
			k[i][0] = message[i];
		for(int i = 1; i <= K; ++i){
			int nxt = i & 1;
			for(int j = 0; j < message.length(); ++j){
				k[key[j]][nxt] = k[j][!nxt];
			}
		}
		k[message.length()][K&1] = 0;
		string ans = "";
		for(int i = 0; i < message.length(); ++i)
			ans += k[i][K&1];
		return ans;
	}
};
