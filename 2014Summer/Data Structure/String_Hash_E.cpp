/*
 * Title:Crazy Search
 * Author:LimitW
 * Date:2014.8.15
 * Source:poj 1200
 * Note:字符串哈希 转化为NC进制
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

bool hash[16000010];
int ascii[256];
char str[16000010];

int main(){
	int N,NC;
	while(scanf("%d%d",&N,&NC) != EOF){
		memset(hash,0,sizeof(hash));
		memset(ascii,0,sizeof(ascii));
		scanf("%s",&str);
		int s = strlen(str);
		int i;
		for(i=0;i<s;i++)
			ascii[str[i]] = 1;
		int v = 0;
		for(i=0;i<256;i++)
			if(ascii[i])
                ascii[i] = v++;
		int l=0,r=N-1;
		int hash_v;
		int ans = 0;
		while(r<s){
			hash_v = 0;
			for(i=l;i<=r;i++){
				hash_v *= NC;
				hash_v += ascii[(int)str[i]];
			}
			if(!hash[hash_v]){
				hash[hash_v] = 1;
				ans++;
			}
			l++; r++;
		}
		printf("%d\n",ans);
	}
	return 0;
}