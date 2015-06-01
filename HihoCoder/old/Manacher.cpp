#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 10;

char s[maxn];
char Manacher_s[2*maxn];
int p[2*maxn];//p[i]为以i为中心的回文串半径长
int n;

void Manacher(){
	int i;
	int maxlen = 0;
	int id;
	for(i=1;i<n;i++){
		if(maxlen > i) p[i] = min(p[2*id-i],p[id]+id-i); //左项关于id的对称点，右项id右边界
		else p[i] = 1;
		for(; Manacher_s[i + p[i]] == Manacher_s[i - p[i]]; p[i]++);
		if(p[i] + i > maxlen){//回文串可覆盖的最远右边界为maxlen，该回文串中心为id
			id = i;
			maxlen = p[i] + i;
		}
	}
}

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>s;
        Manacher_s[0] = '$';//防越界，i=1，p[i]=1时的延伸
        Manacher_s[1] = '#';
        int i;
		for(i=0;s[i];i++){
			Manacher_s[2*i+2] = s[i];
			Manacher_s[2*i+3] = '#';
		}
		n = 2*strlen(s) + 2;
		Manacher();
		int ans = 0;
		for(i=0;i<n;i++)
			ans = max(ans,p[i]);
		cout<<ans-1<<endl;
	}
	return 0;
}