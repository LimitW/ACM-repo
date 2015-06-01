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
	char s[100];
	while(scanf("%s",s) && s[0] != '0'){
		int len = strlen(s);
		int num[100];
		int i;
		for(i = 0; s[i]; i++)
			num[i] = (int) (s[i] - '0');
		int ans = 0;
		for(i = len; i > 0; i--){
			int k = pow(2,i) - 1;
			ans += k * num[len - i];
		}
		printf("%d\n",ans);
	}
	return 0;
}