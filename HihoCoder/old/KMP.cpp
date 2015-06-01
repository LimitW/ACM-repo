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

int main(){
	int T;
	cin>>T;
	while(T--){
		string a,b;
		cin>>a>>b;
		int next[10005]={};
		int p=0,q=-1;
		next[0] = -1;
		while(p < a.length()){
			if(q == -1 || a[p] == a[q])
				next[++p] = ++q;
			else
				q = next[q];
		}
		int ans = 0;
		p = q = 0;
		while(p < b.length()){
			if(q == -1 || b[p] == a[q]){
				++p; ++q;
			}
			else q = next[q];
			if(q == a.length()) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}