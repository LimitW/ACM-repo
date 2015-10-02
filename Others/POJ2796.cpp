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
#define pll pair<LL,LL>

const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

LL a[maxn],sum[maxn];
LL ans[maxn];
pii pos[maxn];

int main(){
	int n; scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld",&a[i]);
		sum[i] = sum[i-1] + a[i];
		pos[i].first = pos[i].second = i;
	}
	stack<int> st;
	st.push(1);
	for(int i = 2; i <= n; i++)
	{
		if(a[i] >= a[st.top()])
		{
			st.push(i);
		}
		else{
			while(!st.empty() && a[st.top()] > a[i])
			{
				int tmp = st.top();
				st.pop();
				if(!st.empty()) pos[st.top()].second = pos[tmp].second;
			}
			if(st.empty() || a[st.top()] <= a[i]) st.push(i);
		}
	}
	while(!st.empty()) {
		int tmp = st.top();
		st.pop();
		if(!st.empty()) pos[st.top()].second = pos[tmp].second;
	}
	st.push(n);
	for(int i = n - 1; i >= 1; i--)
	{
		if(a[i] >= a[st.top()])
		{
			st.push(i);
		}
		else{
			while(!st.empty() && a[st.top()] > a[i])
			{
				int tmp = st.top();
				st.pop();
				if(!st.empty()) pos[st.top()].first = pos[tmp].first;
			}
			if(st.empty() || a[st.top()] <= a[i]) st.push(i);
		}
	}
	while(!st.empty()) {
		int tmp = st.top();
		st.pop();
		if(!st.empty()) pos[st.top()].first = pos[tmp].first;
	}
	pii p = pos[1];
	LL ans = a[1] * (sum[p.second] - sum[p.first-1]);
	for(int i = 2; i <= n; i++)
	{
		LL tmp = a[i] * (sum[pos[i].second] - sum[pos[i].first-1]);
		if(tmp > ans) { ans = tmp; p = pos[i]; }
	}
	printf("%lld\n",ans);
	printf("%d %d\n",p.first,p.second);
    return 0;
}
