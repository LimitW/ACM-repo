#include <bits/stdc++.h>

using namespace std;

map<unsigned int, int> v[33];

int N, M;

int main(){
	scanf("%d%d", &N, &M);
	for(int i = 0; i < 33; ++i){
		v[i].clear();
	}
	unsigned int a1, a2, a3, a4;
	unsigned int res;
	for(int i = 1; i <= N; ++i){
		static char s[35];
		scanf("%s", s);
		scanf("%d.%d.%d.%d", &a1, &a2, &a3, &a4);
		int suf = 32;
		if(getchar() == '/') scanf("%d", &suf);
		res = (a1 << 24) + (a2 << 16) + (a3 << 8) + a4;
		if(suf == 0) res = 0;
		else res >>= (32 - suf);
		if(s[0] == 'a'){
			if(v[suf][res] == 0)
				v[suf][res] = i;
		}
		else{
			if(v[suf][res] == 0)
				v[suf][res] = -i;
		}
	}
	for(int i = 0; i < M; ++i){
		scanf("%d.%d.%d.%d", &a1, &a2, &a3, &a4);
        res = (a1 << 24) + (a2 << 16) + (a3 << 8) + a4;
		int flag = N + 1;
		unsigned int cur;
		for(int j = 0; j < 33; ++j){
			if(j == 0) cur = 0;
			else cur = res >> (32 - j);
			if(v[j].find(cur) != v[j].end()){
				if(abs(v[j][cur]) < abs(flag))
					flag = v[j][cur];
			}
		}
		puts(flag > 0 ? "YES" : "NO");
	}
    return 0;
}

