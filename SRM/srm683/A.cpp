#include <bits/stdc++.h>
using namespace std;

class EqualSubstrings2{
public:
int get(string s){
	int n = s.length();
	int res = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j + i < n; ++j){
			for(int k = j + i; k + i <= n; ++k){
				if(s.substr(j, i) == s.substr(k, i))
					++res;
			}
		}
	}
	return res;
}
};
