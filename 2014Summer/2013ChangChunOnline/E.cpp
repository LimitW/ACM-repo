/*
 * Title:Theme Section
 * Author:LimitW
 * Date:2014.8.15
 * Source:2013 ChangChunSite online E
 * Note:kmp 思路：在中间部分找和前后缀匹配的最大长度
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>

using namespace std;

char str[1000010];
bool f[1000010];
int next[1000010];

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>str;
		memset(f,0,sizeof(f));
		memset(next,0,sizeof(next));
		int p=0,q=-1;
		next[0] = -1;
		int n = strlen(str);
		while(p < n){
			if(q == -1 || str[p] == str[q])
				next[++p] = ++q;
			else
				q = next[q];
		}
		int ans = 0;
		int tmp = n;
		while(tmp > 0){
			if(n >= 2*tmp) f[tmp] = 1;
			tmp = next[tmp];
		}
		int i;
		for(i=n-1;i>1;i--){
			tmp = i;
			while(tmp > 0){
				if(f[tmp] && i >= 2*tmp && n >= i + tmp){
					ans = max(ans,tmp);
					break;
				}
				tmp = next[tmp];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}