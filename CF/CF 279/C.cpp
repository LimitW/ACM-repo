//============================================================================
// Name        : Template.cpp
// Author      : LimitW
// Date        :
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <iostream>
#include <iomanip>
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
#include <utility>
#include <bitset>
#include <functional>
#include <algorithm>
#include <fstream>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 5;

int pre[maxn], suf[maxn];

int main(){
	char s[maxn];
	scanf("%s",&s);
	int p,q;
	scanf("%d%d",&p,&q);
	int n = strlen(s);
	pre[0] = (s[0]-'0') % p;
	for(int i = 1; i < n; i++)
		pre[i] = ((pre[i-1]*(10%p))%p + (s[i]-'0')%p)%p;
	suf[n-1] = (s[n-1]-'0') % p;
	for(int i = n-2; i >= 0; i++)
		suf[i] = (suf[i+1] + (((s[i]-'0')%p)*(10%p))%p)%p;
	bool fail = true;
	int pos;
	for(int i = 1; i < n-1; i++)
		if(pre[i] == 0 && suf[i+1] == 0)
		{ fail = false; pos = i; }
	if(fail) printf("NO\n");
	else{
		printf("YES\n");
		for(int i = 0; i <= pos; i++)
			printf("%c",s[i]);
		puts("");
		for(int i = pos+1; i < n; i++)
			printf("%c",s[i]);
		puts("");
	}
    return 0;
}
